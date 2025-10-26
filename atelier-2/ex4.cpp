#include <cstddef>
#include <iostream>

size_t readSize() {
  size_t arraySize;
  std::cout << "Veuillez entrer la taille du tableau d'entiers : ";
  std::cin >> arraySize;
  return arraySize;
}

void populateArray(int *arrayPtr, size_t size) {
  std::cout << "Veuillez entrer " << size
            << " nombres entiers pour le premier tableau :\n";
  for (size_t i = 0; i < size; ++i) {
    std::cout << "Élément [" << i << "] : ";
    std::cin >> arrayPtr[i];
  }
}

int *createSquaresArray(const int *originalArray, size_t size) {
  int *squaresArray = new int[size];

  for (size_t i = 0; i < size; ++i) {
    int val = originalArray[i] * originalArray[i];
    squaresArray[i] = val;
  }
  return squaresArray;
}

void displayArray(const int *arrayPtr, size_t size,
                  const std::string &arrayName) {
  std::cout << "Contenu du tableau " << arrayName << " :\n";
  std::cout << "[";
  for (size_t i = 0; i < size; ++i) {
    std::cout << arrayPtr[i] << (i < size - 1 ? ", " : "");
  }
  std::cout << "]\n";
}

int main() {

  int *arrayOne = nullptr;
  int *arrayTwo = nullptr;
  size_t arraySize = 0;

  arraySize = readSize();

  arrayOne = new int[arraySize];
  std::cout << "Mémoire allouée dynamiquement pour le premier tableau.\n";

  populateArray(arrayOne, arraySize);

  arrayTwo = createSquaresArray(arrayOne, arraySize);
  std::cout << "Le deuxième tableau contenant les carrés a été créé.\n";

  delete[] arrayOne;
  arrayOne = nullptr; // Bonne pratique
  std::cout << "\nLe premier tableau a été supprimé.\n";

  displayArray(arrayTwo, arraySize, "des carrés");

  delete[] arrayTwo;
  arrayTwo = nullptr;
  std::cout << "\nLe second tableau a été supprimé.\n";

  return 0;
}