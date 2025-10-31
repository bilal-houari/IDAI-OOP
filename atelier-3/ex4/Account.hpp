#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Client.hpp"

class Account {
public:
  Account();
  Account(int number, float balance, Client *client);
  Account(const Account &other);

  ~Account();

  void displayAccount() const;

  static void displayTotalAccounts();

  float getBalance() const;

  void setBalance(float newBalance);

private:
  int number;
  float balance;
  Client *client;
  static int totalOpenAccounts;
};

#endif // ACCOUNT_HPP
