#include <iostream>

void getCallCount();

int main() {
  for (int i = 0; i < 5; i++) {
    getCallCount();
  }
  return 0;
}

void getCallCount() {
  // Quand locale, une variable static est initialisée seulement une fois.
  // Elle garde sa valeur lors de l'exécution.
  static int callCount = 0;
  callCount++;
  std::cout << "Numéro d'appel : " << callCount << std::endl;
}