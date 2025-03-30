#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator start, Iterator finish, UnaryPred condition);

Corpus tokenize(const std::string& text) {
  Corpus words;

  auto spaces = find_all(text.begin(), text.end(), ::isspace);

  std::transform(spaces.begin(), std::prev(spaces.end()),
                 std::next(spaces.begin()),
                 std::inserter(words, words.end()),
                 [&text](auto first, auto second) {
                     return Token(text, first, second);
                 });

  std::erase_if(words, [](const Token& word) {
      return word.content.empty();
  });

  return words;
}

std::set<Mispelling> spellcheck(const Corpus& words, const Dictionary& dict) {
  namespace rv = std::ranges::views;

  auto invalid_words = words | rv::filter([&dict](const Token& word) {
      return !dict.contains(word.content);
  });

  auto suggestions_view = invalid_words | rv::transform([&dict](const Token& word) {
      auto suggestions = dict 
          | rv::filter([&](const std::string& entry) {
              return levenshtein(word.content, entry) == 1;
            })
          | rv::transform([](const std::string& entry) {
              return entry;
            });

      return Mispelling{word, std::set<std::string>(suggestions.begin(), suggestions.end())};
  });

  std::set<Mispelling> result;
  std::ranges::copy_if(suggestions_view, std::inserter(result, result.end()),
                       [](const Mispelling& suggestion) {
                           return !suggestion.suggestions.empty();
                       });

  return result;
}

#include "utils.cpp"