#include <iostream>
#include <string>
#include <vector>

// Déclarations anticipées pour résoudre les dépendances circulaires pour le
// mot-clé 'friend'
class BankAccount;
class BankingAgent;
class Bank;

// 1. Créer une classe Client
class Client {
private:
  int clientId;
  std::string name;
  std::string nationalId;

public:
  Client(int id, const std::string &clientName, const std::string &natId)
      : clientId(id), name(clientName), nationalId(natId) {}

  void displayInfo() const {
    std::cout << "Client " << clientId << ": " << name << " (" << nationalId
              << ")" << std::endl;
  }

  int getClientId() const { return clientId; }
  const std::string &getName() const { return name; }
};

// 2. Créer une classe BankAccount (Compte Bancaire)
class BankAccount {
private:
  std::string accountNumber;
  double balance;
  int secretCode;
  Client &owner;

  BankAccount(const std::string &accNum, double initialBalance, int code,
              Client &accOwner)
      : accountNumber(accNum), balance(initialBalance), secretCode(code),
        owner(accOwner) {}

public:
  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      std::cout << "Dépôt de " << amount << " sur " << accountNumber
                << ". Solde: " << balance << std::endl;
    }
  }

  bool withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
      balance -= amount;
      std::cout << "Retrait de " << amount << " de " << accountNumber
                << ". Solde: " << balance << std::endl;
      return true;
    }
    std::cout << "Échec retrait : fonds insuffisants." << std::endl;
    return false;
  }

  const std::string &getAccountNumber() const { return accountNumber; }

  const Client &getOwner() const { return owner; }

  // Déclarations 'friend' pour accorder un accès spécial
  friend class BankingAgent;
  friend class Bank;
};

// 3. Créer une classe BankingAgent (Agent Bancaire)
class BankingAgent {
public:
  void viewConfidentialDetails(const BankAccount &account) const {
    std::cout << "[AGENT] Compte: " << account.accountNumber
              << ", Solde: " << account.balance
              << ", Code: " << account.secretCode << std::endl;
  }

  bool performTransfer(BankAccount &fromAccount, BankAccount &toAccount,
                       double amount, int providedCode) const {
    std::cout << "\nTransfert de " << amount << " de "
              << fromAccount.accountNumber << " vers "
              << toAccount.accountNumber << std::endl;
    if (fromAccount.secretCode != providedCode) {
      std::cout << "Échec transfert : Code secret incorrect." << std::endl;
      return false;
    }

    if (fromAccount.balance >= amount) {
      fromAccount.balance -= amount;
      toAccount.balance += amount;
      std::cout << "Transfert réussi." << std::endl;
      return true;
    }

    std::cout << "Échec transfert : Fonds insuffisants." << std::endl;
    return false;
  }
};

// 4. Créer une classe Bank (Banque) pour centraliser la gestion
class Bank {
private:
  std::vector<Client *> clients;
  std::vector<BankAccount *> accounts;
  int nextClientId = 1;
  int nextAccountNumber = 1001;

public:
  Bank() = default;

  // Destructeur pour nettoyer la mémoire allouée
  ~Bank() {
    for (BankAccount *acc : accounts) {
      delete acc;
    }
    for (Client *client : clients) {
      delete client;
    }
  }

  Client *createClient(const std::string &name, const std::string &nationalId) {
    Client *newClient = new Client(nextClientId++, name, nationalId);
    clients.push_back(newClient);
    return newClient;
  }

  BankAccount *createAccount(Client &owner, double initialDeposit,
                             int secretCode) {
    std::string newAccountNumber = "ACC" + std::to_string(nextAccountNumber++);
    BankAccount *newAccount =
        new BankAccount(newAccountNumber, initialDeposit, secretCode, owner);
    accounts.push_back(newAccount);
    return newAccount;
  }

  BankAccount *findAccount(const std::string &accountNumber) const {
    for (BankAccount *acc : accounts) {
      if (acc->getAccountNumber() == accountNumber) {
        return acc;
      }
    }
    return nullptr;
  }

  // Cette méthode peut accéder aux données privées car Bank est un 'friend' de
  // BankAccount
  void generateInternalAuditReport() const {
    std::cout << "\n--- Audit Interne ---" << std::endl;
    for (const BankAccount *acc : accounts) {
      std::cout << acc->owner.getName() << " | " << acc->accountNumber
                << " | Solde: " << acc->balance
                << " | Code: " << acc->secretCode << std::endl;
    }
    std::cout << "--- Fin Audit ---" << std::endl;
  }
};

int main() {
  Bank myBank;
  BankingAgent agent;

  std::cout << "Clients en création..." << std::endl;
  Client *client1 = myBank.createClient("Elon Musk", "ID12345");
  Client *client2 = myBank.createClient("Jeff Bezos", "ID67890");

  std::cout << "\nComptes en création..." << std::endl;
  BankAccount *acc1 = myBank.createAccount(*client1, 1000.0, 1234);
  BankAccount *acc2 = myBank.createAccount(*client2, 500.0, 5678);

  std::cout << "Infos comptes (Agent):" << std::endl;
  agent.viewConfidentialDetails(*acc1);
  agent.viewConfidentialDetails(*acc2);

  std::cout << "\nTransactions..." << std::endl;
  acc1->deposit(200.0);
  acc2->withdraw(100.0);
  acc1->withdraw(2000.0); // Échec

  // Simuler un transfert en utilisant l'Agent Bancaire
  agent.performTransfer(*acc1, *acc2, 300.0,
                        9999);                      // Échec
  agent.performTransfer(*acc1, *acc2, 300.0, 1234); // Réussi

  myBank.generateInternalAuditReport();

  return 0;
  // Les destructeurs sont appelés automatiquement ici
}