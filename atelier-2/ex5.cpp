
#include <iostream>

int main() {
  int anInteger = 74;
  int &refA = anInteger;
  int *pA = &anInteger;

  std::cout << "--- Propriétés des variables ---\n";

  // Affichage de l'entier
  std::cout << "\n[ Variable : anInteger ]\n";
  std::cout << "  Valeur (anInteger) : " << anInteger << "\n";
  std::cout << "  Adresse (&anInteger) : " << std::hex << (void *)&anInteger
            << std::dec << "\n";

  // Affichage de la référence
  std::cout << "\n[ Référence : refA ]\n";
  std::cout << "  Valeur (refA) : " << refA << "\n";
  std::cout << "  Adresse (&refA) : " << std::hex << (void *)&refA << std::dec
            << "\n";

  // Affichage du pointeur
  std::cout << "\n[ Pointeur : pA ]\n";
  std::cout << "  Valeur du pointeur (pA) : " << std::hex << (void *)pA
            << std::dec << " (Adresse de anInteger)\n";
  std::cout << "  Adresse propre du pointeur (&pA) : " << std::hex
            << (void *)&pA << std::dec << "\n";
  std::cout << "  Valeur pointée (*pA) : " << *pA << "\n";

  return 0;
}