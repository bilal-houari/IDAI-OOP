#include <iostream>

void incrementerPtr(int *varPtr) { (*varPtr)++; }

void permuterPtr(int *ptrA, int *ptrB) {
  int temp = *ptrA;
  *ptrA = *ptrB;
  *ptrB = temp;
}

void incrementerRef(int &varRef) { varRef++; }

void permuterRef(int &refA, int &refB) {
  int temp = refA;
  refA = refB;
  refB = temp;
}

// Fonction utilitaire pour afficher les variables
void displayVariables(int valA, int valB) {
  std::cout << "Valeur de a : " << valA << ", Valeur de b : " << valB << "\n";
}

int main() {
  std::cout << "### Test des fonctions par Pointeur ###\n";
  int aPointer = 10;
  int bPointer = 20;

  std::cout << "Initial :\n";
  displayVariables(aPointer, bPointer);

  // Test de l'incrémentation par pointeur
  incrementerPtr(&aPointer);
  std::cout << "\nAprès incrementerPtr(&a) :\n";
  displayVariables(aPointer, bPointer);

  // Test de la permutation par pointeur
  permuterPtr(&aPointer, &bPointer);
  std::cout << "\nAprès permuterPtr(&a, &b) :\n";
  displayVariables(aPointer, bPointer);

  std::cout << "\n" << std::string(50, '=') << "\n";

  std::cout << "### Test des fonctions par Référence ###\n";
  int aReference = 100;
  int bReference = 200;

  std::cout << "Initial :\n";
  displayVariables(aReference, bReference);

  // Test de l'incrémentation par référence
  incrementerRef(aReference);
  std::cout << "\nAprès incrementerRef(a) :\n";
  displayVariables(aReference, bReference);

  // Test de la permutation par référence
  permuterRef(aReference, bReference);
  std::cout << "\nAprès permuterRef(a, b) :\n";
  displayVariables(aReference, bReference);

  return 0;
}