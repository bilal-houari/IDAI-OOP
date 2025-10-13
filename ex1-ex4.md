# Exercice 1
Soient les déclarations :
```cpp
char c = '\x01';
short int p = 10;
```
Quels sont le type et la valeur de chacune des expressions suivantes :

p + 3: Type: int, Valeur: 13
c + 1: Type: int, Valeur: 2
p + c: Type: int, Valeur: 11
3 * p + 5 * c: Type: int, Valeur: 35

# Exercice 2
Soient les déclarations :

```cpp
char c = '\x05';
int n = 5;
long p = 1000;
float x = 1.25;
double z = 5.5;
```
Quels sont le type et la valeur de chacune des expressions suivantes :

n + c + p: Type: long, Valeur: 1010
2 * x + c: Type: float, Valeur: 7.5
(char) n + c: Type: int, Valeur: 10
(float) z + n / 2: Type: float, Valeur: 7.5

# Exercice 3
Soient les déclarations suivantes :

```cpp
int n=5, p=9;
int q;
float x;
```

Quelle est la valeur affectée aux différentes variables concernées par chacune des instructions suivantes :

---
**Instructions et Réponses**

`q = n <= p;`
Réponse: q = 1

`q = n == p;`
Réponse: q = 0

`q = p % n + p > n;`
Réponse: q = 1

`x = p / n;`
Réponse: x = 1.0

`x = (float) p / n;`
Réponse: x = 1.8

`x = (p + 0.5) / n;`
Réponse: x = 1.9

`x = (int) (p + 0.5) / n;`
Réponse: x = 1.0

`q = n * (p > n ? p : n);`
Réponse: q = 45

`q = n * (p < n ? p : p);`
Réponse: q = 45


# Exercice 4
Quels résultats fournit le programme suivant :

```cpp
#include <iostream>
using namespace std;
int main() {
  int i, j, n;
  i = 0;
  n = i++;
  cout << "A: i=" << i << " j=" << j << " n=" << n << "\n";
  i = 10;
  n = ++i;
  cout << "B: i=" << i << " j=" << j << " n=" << n << "\n";
  i = 20;
  j = 5;
  n = i++ + j;
  cout << "C: i=" << i << " j=" << j << " n=" << n << "\n";
  i = 15;
  n += i + 3;
  cout << "D: i=" << i << " j=" << j << " n=" << n << "\n";
  j = 5;
  n *= - --j;
  cout << "E: i=" << i << " j=" << j << " n=" << n << "\n";

  return 0;
}
```

Résultats:
A: i=1 j=0 n=0
B: i=11 j=0 n=11
C: i=21 j=5 n=25
D: i=15 j=5 n=43
E: i=15 j=4 n=-172