#include <iostream>

using namespace std;

int isMultipleOfTwo(int number) {
  // Le modulo % 2 retourne 0 si le nombre est pair.
  if (number % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int isMultipleOfThree(int number) {
  // Le modulo % 3 retourne 0 si le nombre est multiple de 3.
  if (number % 3 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  int inputNumber;

  cout << "Donnez un entier : ";
  cin >> inputNumber;

  int checkTwo = isMultipleOfTwo(inputNumber);
  int checkThree = isMultipleOfThree(inputNumber);

  if (checkTwo) {
    cout << "- Il est pair." << endl;
  }

  if (checkThree) {
    cout << "- Il est multiple de 3." << endl;
  }

  // Si le nombre est multiple de 2 ET multiple de 3, il est multiple de 6.
  if (checkTwo && checkThree) {
    cout << "- Il est divisible par 6." << endl;
  }
}