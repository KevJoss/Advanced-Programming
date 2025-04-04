/*
 * CS106L Assignment 5: TreeBook
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include <string>

class User
{
public:
  User(const std::string& name);
  void add_friend(const std::string& name);
  std::string get_name() const;
  size_t size() const; // I don't understand what is size_t
  void set_friend(size_t index, const std::string& name);

  friend std::ostream& operator<<(std::ostream& os, const User& user);
  User& operator+=(User& other); 
  bool operator<(const User& other) const; 

  User(const User& user); // Constructor de copia
  User(User&& user) = delete; // Previene la construcción por movimiento
  User& operator=(const User& user); // Asignación de copia
  User& operator=(User&& user) = delete; // Previene la asignación por movimiento
  ~User(); // Asigno un destructor para liberar la memoria del arreglo de strings

private:
  std::string _name;
  // Este puntero apunta al primer elemento de un arreglo de strings que existe en el heap
  std::string* _friends;
  size_t _size;
  size_t _capacity;
};