#include <iostream>
#include <string>
#include <vector>

// 3. Créer une classe Téléchargeable (Downloadable)
class Downloadable {
public:
  // Le destructeur virtuel est une bonne pratique pour les classes de base
  virtual ~Downloadable() = default;

  virtual void download() const {
    std::cout << "Téléchargement en cours..." << std::endl;
  }

  void displayMessage() const {
    std::cout << "Disponible au téléchargement." << std::endl;
  }
};

// 1. Créer une classe de base Ressource
class Resource {
protected:
  int id;
  std::string title;
  std::string author;
  int year;

public:
  Resource(int id, const std::string &title, const std::string &author,
           int year)
      : id(id), title(title), author(author), year(year) {}

  virtual ~Resource() = default;

  virtual void displayInfo() const {
    std::cout << id << ", " << title << ", " << author << ", " << year;
  }

  virtual void download() const {
    std::cout << "Prêt pour téléchargement : " << title << std::endl;
  }

  // 5. Surcharger l'opérateur ==
  bool operator==(const Resource &other) const { return this->id == other.id; }

  // Accesseurs (Getters)
  int getId() const { return id; }
  const std::string &getTitle() const { return title; }
  const std::string &getAuthor() const { return author; }
  int getYear() const { return year; }
};

// 2. & 3. Créer des classes dérivées avec héritage multiple
class Book : public Resource, public Downloadable {
private:
  std::string isbn;

public:
  Book(int id, const std::string &title, const std::string &author, int year,
       const std::string &isbn)
      : Resource(id, title, author, year), isbn(isbn) {}

  void displayInfo() const override {
    Resource::displayInfo();
    std::cout << ", " << isbn << std::endl;
  }

  void download() const override {
    std::cout << "Téléchargement du livre : " << title << " (" << isbn << ")."
              << std::endl;
    Downloadable::displayMessage();
  }
};

class Magazine : public Resource, public Downloadable {
private:
  int issueNumber;

public:
  Magazine(int id, const std::string &title, const std::string &author,
           int year, int issueNumber)
      : Resource(id, title, author, year), issueNumber(issueNumber) {}

  void displayInfo() const override {
    Resource::displayInfo();
    std::cout << ", N°: " << issueNumber << std::endl;
  }

  void download() const override {
    std::cout << "Téléchargement du magazine : " << title
              << " (N°: " << issueNumber << ")." << std::endl;
    Downloadable::displayMessage();
  }
};

class Video : public Resource, public Downloadable {
private:
  int durationMinutes;

public:
  Video(int id, const std::string &title, const std::string &author, int year,
        int duration)
      : Resource(id, title, author, year), durationMinutes(duration) {}

  void displayInfo() const override {
    Resource::displayInfo();
    std::cout << ", " << durationMinutes << " min" << std::endl;
  }

  void download() const override {
    std::cout << "Téléchargement de la vidéo : " << title << " ("
              << durationMinutes << " min)." << std::endl;
    Downloadable::displayMessage();
  }
};

// 4. Créer la classe Médiathèque (MediaLibrary)
class MediaLibrary {
private:
  std::vector<Resource *> resources;

public:
  // Destructeur pour nettoyer la mémoire allouée dynamiquement
  ~MediaLibrary() {
    for (Resource *res : resources) {
      delete res;
    }
  }

  void addResource(Resource *resource) { resources.push_back(resource); }

  void displayAll() const {
    std::cout << "--- Médiathèque ---" << std::endl;
    if (resources.empty()) {
      std::cout << "Vide." << std::endl;
    }
    for (const Resource *res : resources) {
      res->displayInfo();
    }
    std::cout << "-------------------" << std::endl;
  }

  // Méthodes de recherche surchargées
  std::vector<Resource *> search(const std::string &title) const {
    std::vector<Resource *> results;
    for (const Resource *res : resources) {
      if (res->getTitle() == title) {
        results.push_back(const_cast<Resource *>(res));
      }
    }
    return results;
  }

  std::vector<Resource *> search(int year) const {
    std::vector<Resource *> results;
    for (const Resource *res : resources) {
      if (res->getYear() == year) {
        results.push_back(const_cast<Resource *>(res));
      }
    }
    return results;
  }

  std::vector<Resource *> search(const std::string &author, int year) const {
    std::vector<Resource *> results;
    for (const Resource *res : resources) {
      if (res->getAuthor() == author && res->getYear() == year) {
        results.push_back(const_cast<Resource *>(res));
      }
    }
    return results;
  }
};

void printSearchResults(const std::string &header,
                        const std::vector<Resource *> &results) {
  std::cout << "--- " << header << " ---" << std::endl;
  if (results.empty()) {
    std::cout << "Aucun résultat." << std::endl;
  } else {
    for (const Resource *res : results) {
      res->displayInfo();
    }
  }
  std::cout << std::endl;
}

// 6. fonction main() pour tester toutes les fonctionnalités
int main() {
  MediaLibrary myLibrary;

  myLibrary.addResource(
      new Book(101, "Manuel Scolaire 101", "Auteur A", 2005, "123-4567890123"));
  myLibrary.addResource(
      new Magazine(201, "Revue Mensuelle", "Éditeur B", 2024, 12));
  myLibrary.addResource(
      new Video(301, "Long Métrage", "Réalisateur C", 1998, 95));
  myLibrary.addResource(
      new Book(102, "Roman de Fiction", "Auteur D", 2018, "987-6543210987"));
  myLibrary.addResource(
      new Video(302, "Série de Tutoriels", "Réalisateur E", 2021, 42));
  myLibrary.addResource(
      new Video(303, "Court Métrage", "Réalisateur F", 2012, 178));

  myLibrary.displayAll();

  // Recherche par Titre
  auto resultsByTitle = myLibrary.search("Long Métrage");
  printSearchResults("Recherche par titre 'Long Métrage'", resultsByTitle);

  // Recherche par Année
  auto resultsByYear = myLibrary.search(2018);
  printSearchResults("Recherche par année 2018", resultsByYear);

  // Recherche par Auteur et Année
  auto resultsByAuthorAndYear = myLibrary.search("Auteur A", 2005);
  printSearchResults("Recherche par 'Auteur A' et année 2005",
                     resultsByAuthorAndYear);

  // Tester l'opérateur == en utilisant des objets alloués sur la pile
  std::cout << "--- Test Op. == ---" << std::endl;
  Book book1(401, "Livre Test A", "Auteur A", 2020, "111");
  Book book2(402, "Livre Test B", "Auteur B", 2021, "222");
  Book book3(401, "Livre Test C", "Auteur C", 2022, "333");

  std::cout << "401 vs 402: " << (book1 == book2 ? "Égal" : "Non Égal")
            << std::endl;
  std::cout << "401 vs 401: " << (book1 == book3 ? "Égal" : "Non Égal")
            << std::endl;
  std::cout << std::endl;

  // Tester download() et la qualification de classe pour la résolution de
  // conflits
  std::cout << "--- Test Téléchargement ---" << std::endl;
  Magazine testMagazine(202, "Périodique Général", "Éditeur X", 2023, 10);

  std::cout << "1. Téléchargement surchargé :" << std::endl;
  testMagazine.download();

  std::cout << "\n2. Téléchargement Resource:::" << std::endl;
  testMagazine.Resource::download();

  std::cout << "\n3. Téléchargement Downloadable:::" << std::endl;
  testMagazine.Downloadable::download();

  return 0;
  // Le destructeur de myLibrary est appelé automatiquement ici
}