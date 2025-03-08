/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

 #include <fstream>
 #include <iostream>
 #include <queue>
 #include <set>
 #include <string>
 #include <unordered_set>
 #include <sstream>
 #include <cstdlib>  
  #include <ctime>  
 
 std::string kYourName = "Kevin Sanchez"; 
 
 /**
  * Takes in a file name and returns a set containing all of the applicant names as a set.
  *
  * @param filename  The name of the file to read.
  *                  Each line of the file will be a single applicant's name.
  * @returns         A set of all applicant names read from the file.
  *
  * @remark Feel free to change the return type of this function (and the function
  * below it) to use a `std::unordered_set` instead. If you do so, make sure
  * to also change the corresponding functions in `utils.h`.
  */
 std::set<std::string> get_applicants(std::string filename) {
   std::set<std::string> applicants;
   std::ifstream Applicants(filename);
   if (Applicants.is_open()){
     std::string line;
     while (std::getline(Applicants, line)) {
       applicants.insert(line);
     }
   }
   return applicants;
 }
 
 /**
  * Takes in a set of student names by reference and returns a queue of names
  * that match the given student name.
  *
  * @param name      The returned queue of names should have the same initials as this name.
  * @param students  The set of student names.
  * @return          A queue containing pointers to each matching name.
  */
 char char_name(std::string name){
   std::istringstream ss(name);
   std::string Name , LastName;
   ss >> Name >> LastName;
   return Name[0];
 }
 char char_LastName(std::string name){
   std::istringstream ss(name);
   std::string Name , LastName;
   ss >> Name >> LastName;
   return LastName[0];
 }
 std::queue<std::string> find_matches(std::string name, std::set<std::string>& students) {
       
   char Name , LastName;
   std::queue<std::string> FindTool;
   Name  = char_name(name);
   LastName = char_LastName(name);
   for (auto it = students.begin(); it != students.end(); it++){
         char TemporalName , TemporalLastName;
         TemporalName = char_name(*it);
         TemporalLastName = char_LastName(*it);
         if (TemporalName == Name && TemporalLastName == LastName){
           FindTool.push(*it);
         }
     }
 return FindTool;
 }
 /**
  * Takes in a queue of pointers to possible matches and determines the one true match!
  *
  * You can implement this function however you'd like, but try to do something a bit
  * more complicated than a simple `pop()`.
  *
  * @param matches The queue of possible matches.
  * @return        Your magical one true love.
  *                Will return "NO MATCHES FOUND." if `matches` is empty.
  */
 std::string get_match(std::queue<std::string> matches) {
   if (matches.empty()) {
       return "NO MATCHES FOUND. Better luck next year";
   }
   
   std::vector<std::string> candidates;
   while (!matches.empty()) {
       candidates.push_back(matches.front());
       matches.pop();
   }
    
   int random_index = rand() % candidates.size();
   return candidates[random_index];
 }
 

 /* #### Please don't remove this line! #### */
 #include "autograder/utils.hpp"
 
