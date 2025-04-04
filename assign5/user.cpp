#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity]; // Crea un nuevo arreglo con el doble de capacidad
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends; // Libera la memoria
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}


std::ostream& operator<<(std::ostream& os, const User& user){
    os << "User(name=" << user._name << ", friends=[";
    for (size_t i = 0; i < user._size; ++i) {
        os<< user._friends[i];
        if (i < user._size - 1) {
            os << ", ";
        };
    };
    os << "])";
    return os;
}

User& User::operator+=(User& other) {
  this->add_friend(other.get_name());
  
  other.add_friend(this->_name);
  
  return *this;
}

bool User::operator<(const User& other) const {
  return _name < other._name;
}

User::User(const User& user)
  : _name(user._name),
  _size(user._size),
  _capacity(user._capacity)
{
  if (user._capacity > 0) {
    _friends = new std::string[user._capacity]; // Crea un nuevo arreglo con la misma capacidad
    for (size_t i = 0; i < user._size; ++i) {
      _friends[i] = user._friends[i]; 
    }
  } else {
    _friends = nullptr; // Si no hay amigos, inicializa a nullptr
  }
}





User& User::operator=(const User& user) {
  if (this == &user) {
        return *this; // Evita la autoasignación
  }
  //En el objeto ya existe y ya tiene memoria reservada, por ello es importante eliminarla
  delete[] _friends;
    
    // Copiar los datos básicos
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    
    // Asignar nuevo espacio y copiar amigos
    if (_capacity > 0) {
        _friends = new std::string[_capacity];
        for (size_t i = 0; i < _size; i++) {
            _friends[i] = user._friends[i];
        }
    } else {
        _friends = nullptr;
    }
    
    // Devolver referencia al objeto actual
    return *this;
}

User::~User() {
  delete[] _friends; // Libera la memoria del arreglo dinámico
}
