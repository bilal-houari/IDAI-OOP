#include <iostream>
#include <vector>

class Stack {
private:
  std::vector<int> data;

public:
  Stack() {}

  void push(int element) { data.push_back(element); }

  bool pop(int &result) {
    if (data.empty()) {
      return false; // La pile est vide (Underflow)
    }
    result = data.back();
    data.pop_back();
    return true; // Succès
  }
};

int main() {
  Stack p1;
  Stack p2;
  int value; // Variable pour contenir le résultat dépilé

  std::cout << "Test de la Pile p1 ///\n";

  std::cout << "Empilement des valeurs 10, 20, 30 sur p1.\n";
  p1.push(10);
  p1.push(20);
  p1.push(30);

  std::cout << "Dépilement des éléments de p1 :\n";
  while (p1.pop(value)) {
    std::cout << "  Dépilé : " << value << "\n";
  }

  std::cout << "\nTest de la Pile p2 ///\n";

  std::cout << "Empilement de 5, puis 15 sur p2.\n";
  p2.push(5);
  p2.push(15);

  if (p2.pop(value)) {
    std::cout << "  Dépilé (15) : " << value << "\n";
  }

  std::cout << "Empilement de 25, puis 35 sur p2.\n";
  p2.push(25);
  p2.push(35);

  std::cout << "Dépilement des éléments restants de p2 :\n";
  while (p2.pop(value)) {
    std::cout << "  Dépilé : " << value << "\n";
  }

  std::cout << "\nTentative de dépiler une pile vide (p2) :\n";
  if (!p2.pop(value)) {
    std::cout << "Sous-débordement de pile détecté : p2 est vide.\n";
  }

  return 0;
}