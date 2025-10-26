#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

// Fonction pour lire n nombres entiers dans un tableau
vector<int> readVector(int size) {
  vector<int> numbers;
  cout << "Entrez " << size << " nombres entiers :" << endl;

  for (int i = 0; i < size; ++i) {
    int input;
    cout << "Nombre " << i + 1 << " : ";
    cin >> input;
    numbers.push_back(input);
  }
  return numbers;
}

// Implémentation utilisant std::vector.
vector<int> findMinMaxVector(const vector<int> &numbers) {
  if (numbers.empty()) {
    return {}; // Retourne un tableau vide si le vecteur est vide
  }

  int minVal = numbers[0];
  int maxVal = numbers[0];

  for (size_t i = 1; i < numbers.size(); ++i) {
    if (numbers[i] < minVal) {
      minVal = numbers[i];
    }
    if (numbers[i] > maxVal) {
      maxVal = numbers[i];
    }
  }

  return {minVal, maxVal};
}

// Implémentation utilisant les pointeurs.
void findMinMaxPointerStrict(const vector<int> &numbers, int *minValPtr,
                             int *maxValPtr) {
  if (numbers.empty()) {
    return;
  }

  // Obtenir un pointeur vers le début des données brutes du vecteur
  const int *start = numbers.data();
  size_t size = numbers.size();

  *minValPtr = *start;
  *maxValPtr = *start;

  for (size_t i = 1; i < size; ++i) {
    const int *current = start + i;

    if (*current < *minValPtr) {
      *minValPtr = *current;
    }
    if (*current > *maxValPtr) {
      *maxValPtr = *current;
    }
  }
}

int main() {

  vector<int> numbers = readVector(10);

  cout << "\nFormalisme Tableau ///////////" << endl;
  vector<int> resultArray = findMinMaxVector(numbers);

  if (!resultArray.empty()) {
    cout << "Minimum : " << resultArray[0] << endl;
    cout << "Maximum : " << resultArray[1] << endl;
  } else {
    cout << "Vecteur vide." << endl;
  }

  cout << "\nFormalisme Pointeur ///////////" << endl;
  int minPtr, maxPtr;
  findMinMaxPointerStrict(numbers, &minPtr, &maxPtr);

  if (!numbers.empty()) {
    cout << "Minimum : " << minPtr << endl;
    cout << "Maximum : " << maxPtr << endl;
  } else {
    cout << "Vecteur vide." << endl;
  }

  return 0;
}