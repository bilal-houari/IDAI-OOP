#include "Client.hpp"
#include <iostream>

// Constructeur par défaut
Client::Client() : id(0), name(""), firstName("") {
  std::cout << "Constructeur par défaut de Client appelé." << std::endl;
}

// Constructeur paramétré
Client::Client(int id, const std::string &name, const std::string &firstName)
    : id(id), name(name), firstName(firstName) {
  std::cout << "Constructeur paramétré de Client appelé." << std::endl;
}

// Constructeur de copie
Client::Client(const Client &other)
    : id(other.id), name(other.name), firstName(other.firstName) {
  std::cout << "Constructeur de copie de Client appelé." << std::endl;
}

Client::~Client() {
  std::cout << "Destructeur de Client appelé pour " << firstName << " " << name
            << std::endl;
}

void Client::displayClient() const {
  std::cout << "ID Client : " << id << ", Nom : " << firstName << " " << name
            << std::endl;
}