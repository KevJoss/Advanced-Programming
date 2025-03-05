#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

struct Course {
    std::string title;
    int number_of_units;
    std::string quarter;
  };
  // Sobrecarga del operador << para Course
std::ostream& operator<<(std::ostream& os, const Course& course) {
    os << course.title << ", " << course.number_of_units << ", " << course.quarter;
    return os;
  }
  
  // Sobrecarga el operador == para comparar cursos
bool operator==(const Course& lhs, const Course& rhs) {
  return lhs.title == rhs.title && lhs.number_of_units == rhs.number_of_units &&
         lhs.quarter == rhs.quarter;
}



void parse_csv(std::string filename, std::vector<Course>& courses);
std::vector<std::string> split(const std::string& s, char delim);
void print_courses(const std::vector<Course>& vector_of_courses);
void write_courses_offered(const std::vector<Course>& all_courses);
void delete_elem_from_vector(std::vector<Course>& v, const Course& elem);
void write_courses_not_offered(const std::vector<Course>& all_courses);

int main(){
    std::vector<Course> courses;
    parse_csv("courses.csv",  courses);
    //auto index_50 = courses.at(335);
    //std::cout << index_50.title << "\n";
    write_courses_offered(courses);
    print_courses(courses);
    write_courses_not_offered(courses);
}




std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> return_vec;
    std::stringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delim)) {
      return_vec.push_back(token);
    }
    return return_vec;
  }

void parse_csv(std::string filename, std::vector<Course>& courses) {
    std::ifstream oneCourse("courses.csv");
    if (oneCourse.is_open()){
      std::string line;
      std::getline(oneCourse, line);
      while (std::getline(oneCourse, line)){
        auto vector = split(line, ',');
        std::string unit = vector.at(1);
        std::stringstream ss(unit);
        int NumberUnit;
        ss >> NumberUnit;
        Course indCourse = {vector.at(0), NumberUnit, vector.at(2)};
        courses.push_back(indCourse);
      }
    }
}

void print_courses(const std::vector<Course>& vector_of_courses) {
    for (const Course& course : vector_of_courses) {
      std::cout << course << std::endl;
    }
  }

void delete_elem_from_vector(std::vector<Course>& v, const Course& elem) {
    std::vector<Course>::iterator it = std::find(v.begin(), v.end(), elem);
    v.erase(it);
  }

 void write_courses_offered(const std::vector<Course>& all_courses) {
    std::vector<Course> filtered = all_courses;
    // Iterar en orden inverso para eliminar de forma segura
    for (int i = filtered.size() - 1; i >= 0; i--) {
        if (filtered[i].quarter == "null") {
            delete_elem_from_vector(filtered, filtered[i]);
        }
    }
    std::ofstream coursesOffered("courses_offered.csv");
    if (coursesOffered.is_open()){
      for (const Course& v_course : filtered){
        coursesOffered << v_course << '\n';
      }
    }
}

void write_courses_not_offered(const std::vector<Course>& all_courses) {
  std::vector<Course> filtered = all_courses;
  // Iterar en orden inverso para eliminar de forma segura
  for (int i = filtered.size() - 1; i >= 0; i--) {
      if (filtered[i].quarter != "null") {
          delete_elem_from_vector(filtered, filtered[i]);
      }
  }
  std::ofstream coursesNotOffered("courses_not_offered.csv");
  if (coursesNotOffered.is_open()){
    for (const Course& v_course : filtered){
      coursesNotOffered << v_course << '\n';
    }
  }
  coursesNotOffered.close();
}


