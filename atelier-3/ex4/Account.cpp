#include "Account.hpp"
#include <iostream>

int Account::totalOpenAccounts = 0;

// Constructeur par défaut
Account::Account() : number(0), balance(0.0f), client(new Client()) {
  totalOpenAccounts++;
  std::cout << "Constructeur par défaut de Compte appelé." << std::endl;
}

// Constructeur paramétré
Account::Account(int number, float balance, Client *client)
    : number(number), balance(balance), client(client) {
  totalOpenAccounts++;
  std::cout << "Constructeur paramétré de Compte appelé." << std::endl;
}

// Constructeur de copie (Copie profonde)
Account::Account(const Account &other)
    : number(other.number), balance(other.balance) {
  // Copie profonde de l'objet client
  this->client = new Client(*(other.client));
  totalOpenAccounts++;
  std::cout << "Constructeur de copie de Compte appelé (copie profonde)."
            << std::endl;
}

Account::~Account() {
  delete client; // Libérer la mémoire pour le client associé
  totalOpenAccounts--;
  std::cout << "Destructeur de Compte appelé pour le compte n°" << number
            << std::endl;
}

void Account::displayAccount() const {
  std::cout << "Numéro de Compte : " << number << ", Solde : " << balance
            << "\n";
  client->displayClient();
}

void Account::displayTotalAccounts() {
  std::cout << "Nombre total de comptes ouverts : " << totalOpenAccounts
            << std::endl;
}

float Account::getBalance() const { return balance; }

void Account::setBalance(float newBalance) { balance = newBalance; }