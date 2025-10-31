#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>

class Client {
public:
  Client();
  Client(int id, const std::string &name, const std::string &firstName);
  Client(const Client &other);

  ~Client();

  void displayClient() const;

private:
  int id;
  std::string name;
  std::string firstName;
};

#endif // CLIENT_HPP
