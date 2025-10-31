#include "Account.hpp"
#include "Client.hpp"
#include <iostream>

// Cette fonction est déclarée 'inline' car elle est courte et fréquemment
// appelée. Cela suggère au compilateur qu'il devrait substituer le corps de la
// fonction directement à l'endroit de l'appel, améliorant potentiellement la
// performance.
inline float calculateInterest(float balance, float rate) {
  return balance * (1.0f + rate);
}

int main() {
  std::cout << "--- État initial ---" << std::endl;
  Account::displayTotalAccounts();

  std::cout << "\n--- Création des clients et des comptes ---" << std::endl;
  Client *client1 = new Client(1, "Money", "John");
  Account account1(101, 99999.0f, client1);
  account1.displayAccount();

  Client *client2 = new Client(2, "Poor", "Joe");
  Account account2(102, 12.5f, client2);
  account2.displayAccount();

  std::cout << "\n--- État après la création de deux comptes ---" << std::endl;
  Account::displayTotalAccounts();

  std::cout << "\n--- Test du constructeur de copie ---" << std::endl;
  Account account3 = account1; // Copier account1
  std::cout << "Compte Original 1:" << std::endl;
  account1.displayAccount();
  std::cout << "Compte Copié 3 (copie du Compte 1):" << std::endl;
  account3.displayAccount();

  std::cout << "\n--- État après la copie d'un compte ---" << std::endl;
  Account::displayTotalAccounts();

  std::cout << "\n--- Application des intérêts ---" << std::endl;
  float newBalance =
      calculateInterest(account1.getBalance(), 0.05f); // Intérêts à 5%
  account1.setBalance(newBalance);
  std::cout << "Nouveau solde du Compte 1 après 5% d'intérêts : "
            << account1.getBalance() << std::endl;

  std::cout << "\n--- Suppression d'un compte par sortie de portée ---"
            << std::endl;
  {
    Client *client4 = new Client(4, "Test", "Scope");
    Account scopedAccount(104, 1000.0f, client4);
    std::cout << "À l'intérieur de la portée :" << std::endl;
    Account::displayTotalAccounts();
  } // scopedAccount est détruit ici

  std::cout << "\n--- État après la destruction du compte de portée ---"
            << std::endl;
  Account::displayTotalAccounts();

  std::cout
      << "\n--- Fin du programme, les comptes restants vont être détruits ---"
      << std::endl;

  return 0;
}