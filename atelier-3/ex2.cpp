#include <cstddef> // Pour size_t
#include <iostream>

class File {
private:
  char *dataPointer;
  size_t length;

public:
  File() : dataPointer(nullptr), length(0) {
    std::cout << "Objet Fichier créé.\n";
  }

  ~File() {
    if (dataPointer != nullptr) {
      std::cout << "\nDestructeur déclenché : Suppression du tampon alloué "
                   "dynamiquement ("
                << length << " octets).\n";
      // Important : Utilisez delete[] pour la mémoire allouée avec new[]
      delete[] dataPointer;
      dataPointer = nullptr;
    } else {
      std::cout << "\nDestructeur déclenché : Aucun tampon à supprimer.\n";
    }
  }

  void create(size_t size) {
    if (dataPointer != nullptr) {
      // Nettoyer l'ancienne mémoire si 'create' est appelé à plusieurs reprises
      delete[] dataPointer;
    }

    dataPointer = new char[size];
    length = size;
    std::cout << "1. Création : Alloué " << length
              << " octets à l'adresse P = " << (void *)dataPointer << "\n";
  }

  void fill() {
    if (dataPointer == nullptr) {
      std::cout << "Erreur : Impossible de remplir, mémoire non allouée.\n";
      return;
    }

    for (size_t i = 0; i < length; ++i) {
      // Utiliser les valeurs ASCII pour un remplissage arbitraire (par exemple,
      // 'A', 'B', 'C'...)
      dataPointer[i] = (char)('A' + (i % 26));
    }
    std::cout << "2. Remplissage : Mémoire remplie avec succès.\n";
  }

  void display() const {
    if (dataPointer == nullptr) {
      std::cout << "Erreur : Impossible d'afficher, mémoire non allouée.\n";
      return;
    }

    std::cout << "3. Affichage : Contenu du tampon :\n";
    for (size_t i = 0; i < length; ++i) {
      // Afficher le contenu en tant que caractère, suivi de l'index d'octet
      std::cout << dataPointer[i] << "(" << i << ") ";
    }
    std::cout << "\n";
  }
};

int main() {
  File *myFilePtr = new File();

  const size_t fileSize = 20;

  myFilePtr->create(fileSize);

  myFilePtr->fill();

  myFilePtr->display();

  // Détruire l'objet en utilisant 'delete', ce qui appelle le destructeur et
  // libère la mémoire de l'objet.
  delete myFilePtr;

  return 0;
}