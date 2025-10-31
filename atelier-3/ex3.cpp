#include <iostream>

struct Element {
  int data;
  Element *nextElement;
};

class List {
private:
  Element *head;

public:
  List() : head(nullptr) {}

  ~List() {
    Element *current = head;
    while (current != nullptr) {
      Element *elementToDelete = current;
      current = current->nextElement;
      delete elementToDelete;
    }
    head = nullptr;
    std::cout << "\nListe détruite et mémoire libérée." << std::endl;
  }

  void addAtHead(int value) {
    Element *newElement = new Element;

    newElement->data = value;

    newElement->nextElement = head;

    head = newElement;
  }

  void removeHead() {
    if (head == nullptr) {
      std::cout
          << "Erreur : Impossible de supprimer la tête, la liste est vide."
          << std::endl;
      return;
    }

    Element *elementToDelete = head;
    head = head->nextElement;

    delete elementToDelete;
    std::cout << "Élément de tête supprimé." << std::endl;
  }

  void displayList() const {
    if (head == nullptr) {
      std::cout << "La liste est actuellement vide." << std::endl;
      return;
    }

    Element *current = head;
    std::cout << "Contenu de la liste : ";

    while (current != nullptr) {
      std::cout << current->data;
      if (current->nextElement != nullptr) {
        std::cout << " -> ";
      }
      current = current->nextElement;
    }
    std::cout << " (Fin)" << std::endl;
  }
};

int main() {
  List myList;

  std::cout << "État Initial ///" << std::endl;
  myList.displayList();

  std::cout << "\nAjout d'éléments (30, 20, 10) ///" << std::endl;
  myList.addAtHead(10);
  myList.addAtHead(20);
  myList.addAtHead(30);

  myList.displayList();

  std::cout << "\nSuppression de la Tête ///" << std::endl;
  myList.removeHead();
  myList.displayList();

  std::cout << "\nNettoyage ///" << std::endl;

  // Le destructeur est appelé automatiquement, libérant les nœuds restants (20
  // et 10).
  return 0;
}