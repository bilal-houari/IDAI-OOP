#include <iostream>
#include <string>

void swapChars(char &charA, char &charB) {
  char tempChar = charA;
  charA = charB;
  charB = tempChar;
}

void permuteRecursive(std::string &currentString, size_t startIndex,
                      size_t endIndex) {
  if (startIndex == endIndex) {
    std::cout << currentString << "\n";
  } else {
    for (size_t i = startIndex; i <= endIndex; i++) {
      swapChars(currentString[startIndex], currentString[i]);

      permuteRecursive(currentString, startIndex + 1, endIndex);

      swapChars(currentString[startIndex], currentString[i]);
    }
  }
}

int main() {
  std::string inputString;
  std::cout << "Veuillez entrer une chaîne de caractères : ";
  std::cin >> inputString;

  size_t stringLength = inputString.length();

  if (stringLength == 0) {
    std::cout << "La chaîne est vide.\n";
    return 0;
  }

  std::cout << "\nToutes les permutations possibles de '" << inputString
            << "' sont :\n";

  permuteRecursive(inputString, 0, stringLength - 1);

  return 0;
}