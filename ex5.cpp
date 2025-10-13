#include <iostream>

using namespace std;

void remplir(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << "Entrer l'element [" << i << "] : ";
    cin >> *(arr + i);
  }
}

void afficher(const int *arr, int n) {
  cout << "Tableau : [";
  for (int i = 0; i < n; i++) {
    cout << *(arr + i);
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int &trouverMax(int *arr, int n) {
  int *maxPtr = arr;

  for (int i = 1; i < n; i++) {
    if (*(arr + i) > *maxPtr) {
      maxPtr = arr + i;
    }
  }
  return *maxPtr;
}

void inverser(int *arr, int n) {
  int i = 0;
  int j = n - 1;

  while (i < j) {
    int temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp;

    i++;
    j--;
  }
}

int main() {
  int n;
  cout << "Entrer la taille du tableau (n) : ";
  cin >> n;

  if (n <= 0) {
    return 0;
  }

  int *arr = new int[n];

  remplir(arr, n);

  cout << "\n--- Etat initial ---" << endl;
  afficher(arr, n);

  int &refMax = trouverMax(arr, n);

  cout << "\nMaximum trouve : " << refMax << endl;

  refMax = 999;
  cout << "Maximum modifie a 999 via la reference." << endl;
  afficher(arr, n);

  cout << "\n--- Inversion du tableau ---" << endl;
  inverser(arr, n);
  afficher(arr, n);

  delete[] arr;
  cout << "\nMemoire liberee." << endl;

  return 0;
}