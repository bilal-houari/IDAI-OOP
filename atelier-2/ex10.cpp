#include <cmath>
#include <iostream>
#include <limits> // Nécessaire pour numeric_limits afin de gérer les erreurs de saisie

class ComplexNumber {
private:
  double realPart;
  double imaginaryPart;

public:
  ComplexNumber(double r = 0.0, double i = 0.0)
      : realPart(r), imaginaryPart(i) {}

  // Fonction utilitaire pour obtenir la saisie
  static ComplexNumber readComplexNumber(const std::string &prompt) {
    double r, i;
    std::cout << prompt << " (Partie Réelle) : ";
    std::cin >> r;
    std::cout << prompt << " (Partie Imaginaire) : ";
    std::cin >> i;

    // Validation de la saisie
    if (std::cin.fail()) {
      std::cerr << "Saisie invalide. Utilisation des valeurs par défaut (0, 0)."
                << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return ComplexNumber();
    }

    return ComplexNumber(r, i);
  }

  // Fonction utilitaire pour afficher le résultat
  void displayNumber(const std::string &description = "Résultat") const {
    std::cout << description << ": ";

    // Gérer correctement l'affichage du signe de la partie imaginaire
    if (imaginaryPart >= 0) {
      std::cout << realPart << " + " << imaginaryPart << "i" << std::endl;
    } else {
      // La partie imaginaire est négative, affiche le signe moins naturellement
      std::cout << realPart << " - " << std::abs(imaginaryPart) << "i"
                << std::endl;
    }
  }

  // Operator Overloading

  // 1. Addition (+)
  ComplexNumber operator+(const ComplexNumber &other) const {
    return ComplexNumber(realPart + other.realPart,
                         imaginaryPart + other.imaginaryPart);
  }

  // 2. Soustraction (-)
  ComplexNumber operator-(const ComplexNumber &other) const {
    return ComplexNumber(realPart - other.realPart,
                         imaginaryPart - other.imaginaryPart);
  }

  // 3. Multiplication (*)
  ComplexNumber operator*(const ComplexNumber &other) const {
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    double newReal =
        (realPart * other.realPart) - (imaginaryPart * other.imaginaryPart);
    double newImaginary =
        (realPart * other.imaginaryPart) + (imaginaryPart * other.realPart);
    return ComplexNumber(newReal, newImaginary);
  }

  // 4. Division (/)
  ComplexNumber operator/(const ComplexNumber &other) const {
    // (a + bi) / (c + di) = [(ac + bd) / (c^2 + d^2)] + [(bc - ad) / (c^2 +
    // d^2)]i

    double denominator = (other.realPart * other.realPart) +
                         (other.imaginaryPart * other.imaginaryPart);

    // Vérification de la division par zéro
    if (denominator == 0.0) {
      std::cerr << "Erreur : Division par un nombre complexe nul." << std::endl;
      return ComplexNumber(); // Retourne 0 + 0i en cas d'erreur
    }

    double newReal =
        (realPart * other.realPart + imaginaryPart * other.imaginaryPart) /
        denominator;
    double newImaginary =
        (imaginaryPart * other.realPart - realPart * other.imaginaryPart) /
        denominator;

    return ComplexNumber(newReal, newImaginary);
  }

  // 5. Égalité (==)
  bool operator==(const ComplexNumber &other) const {
    return (realPart == other.realPart) &&
           (imaginaryPart == other.imaginaryPart);
  }
};

void displayMenu() {
  std::cout << "\n--- Menu de la Calculatrice de Nombres Complexes ---"
            << std::endl;
  std::cout << "1. Addition (N1 + N2)" << std::endl;
  std::cout << "2. Soustraction (N1 - N2)" << std::endl;
  std::cout << "3. Multiplication (N1 * N2)" << std::endl;
  std::cout << "4. Division (N1 / N2)" << std::endl;
  std::cout << "5. Vérifier l'Égalité (N1 == N2)" << std::endl;
  std::cout << "6. Quitter" << std::endl;
  std::cout << "Entrez votre choix : ";
}

int main() {

  ComplexNumber number1 =
      ComplexNumber::readComplexNumber("Entrez le Nombre Complexe 1");
  ComplexNumber number2 =
      ComplexNumber::readComplexNumber("Entrez le Nombre Complexe 2");

  int menuChoice = 0;

  do {
    displayMenu();
    if (!(std::cin >> menuChoice)) {
      // Gérer la saisie non-entière
      std::cerr << "Saisie invalide. Veuillez entrer un nombre." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    ComplexNumber result;

    switch (menuChoice) {
    case 1:
      result = number1 + number2; // Équivalent à number1.operator+(number2)
      result.displayNumber("Somme");
      break;
    case 2:
      result = number1 - number2; // Équivalent à number1.operator-(number2)
      result.displayNumber("Différence");
      break;
    case 3:
      result = number1 * number2; // Équivalent à number1.operator*(number2)
      result.displayNumber("Produit");
      break;
    case 4:
      result = number1 / number2; // Équivalent à number1.operator/(number2)
      result.displayNumber("Quotient");
      break;
    case 5:
      if (number1 == number2) {
        std::cout << "Égalité : N1 est égal à N2." << std::endl;
      } else {
        std::cout << "Égalité : N1 n'est PAS égal à N2." << std::endl;
      }
      break;
    case 6:
      std::cout << "Fermeture du programme. Au revoir !" << std::endl;
      break;
    default:
      std::cout << "Choix invalide. Veuillez réessayer." << std::endl;
      break;
    }

  } while (menuChoice != 6);

  return 0;
}