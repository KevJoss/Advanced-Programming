#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>
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
  std::string get_match(std::queue<std::string> matches) {
    if (matches.empty()) {
        return "NO MATCHES FOUND. Better luck next year";
    }
    
    // Transferir elementos de la cola a un vector para acceso aleatorio
    std::vector<std::string> candidates;
    while (!matches.empty()) {
        candidates.push_back(matches.front());
        matches.pop();
    }
    
    // Seleccionar un índice aleatorio
    int random_index = rand() % candidates.size();
    return candidates[random_index];
}

    

int main(){
  srand(time(0)); // Inicializar la semilla para números aleatorios
    
  auto applicants = get_applicants("students.txt");
  std::string nombre = "Kevin Sanchez";
  
  std::queue<std::string> matches = find_matches(nombre, applicants);
  std::string true_match = get_match(matches);
  
  if (true_match == "NO MATCHES FOUND. Better luck next year") {
      std::cout << true_match << std::endl;
  } else {
      std::cout << "Your one true match is: " << true_match << std::endl;
  }
  
  return 0;
}