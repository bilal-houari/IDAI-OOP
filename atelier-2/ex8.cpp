#include <algorithm>
#include <iostream>
#include <string>

class Car {
private:
  std::string brand;
  std::string model;
  int year;
  float mileage;
  float speed;

public:
  // Constructeur par défaut
  Car()
      : brand("Inconnue"), model("Base"), year(2025), mileage(0.0f),
        speed(0.0f) {
    std::cout << "--- Voiture créée (Par défaut) ---" << std::endl;
  }

  // Constructeur paramétré
  Car(const std::string &initialBrand, const std::string &initialModel,
      int initialYear, float initialMileage, float initialSpeed)
      : brand(initialBrand), model(initialModel), year(initialYear),
        mileage(initialMileage), speed(initialSpeed) {
    std::cout << "--- Voiture créée (Paramétrée) ---" << std::endl;
  }

  ~Car() {
    std::cout << "--- Voiture (" << brand << " " << model
              << ") est détruite ---" << std::endl;
  }

  void accelerate(float accelerationValue) {
    if (accelerationValue > 0) {
      speed += accelerationValue;
      std::cout << "Accélération de " << accelerationValue
                << " km/h. Nouvelle vitesse : " << speed << " km/h."
                << std::endl;
    } else {
      std::cout << "Valeur d'accélération invalide." << std::endl;
    }
  }

  void brake(float brakeValue) {
    if (brakeValue > 0) {
      // Utilise std::max pour s'assurer que la vitesse ne descend pas en
      // dessous de 0.0f
      speed = std::max(0.0f, speed - brakeValue);
      std::cout << "Freinage de " << brakeValue
                << " km/h. Nouvelle vitesse : " << speed << " km/h."
                << std::endl;
    } else {
      std::cout << "Valeur de freinage invalide." << std::endl;
    }
  }

  void advance(float distance) {
    if (distance > 0) {
      mileage += distance;
      std::cout << "A parcouru " << distance
                << " km. Kilométrage total : " << mileage << " km."
                << std::endl;
    } else {
      std::cout << "Impossible d'avancer d'une distance non positive."
                << std::endl;
    }
  }

  void displayInfo() const {
    std::cout << "\n--- Informations sur la voiture ---" << std::endl;
    std::cout << "Marque : " << brand << std::endl;
    std::cout << "Modèle : " << model << std::endl;
    std::cout << "Année : " << year << std::endl;
    std::cout << "Kilométrage : " << mileage << " km" << std::endl;
    std::cout << "Vitesse : " << speed << " km/h" << std::endl;
    std::cout << "---------------------------------" << std::endl;
  }
};

int main() {
  Car defaultCar;
  defaultCar.displayInfo();

  defaultCar.accelerate(10.5f);
  defaultCar.advance(5.0f);
  defaultCar.brake(5.0f);
  defaultCar.displayInfo();

  std::cout << "\n---\n" << std::endl;

  Car UltimateCar("Volkswagen", "Beetle (Type 1)", 1970, 320000.0f, 0.0f);
  UltimateCar.displayInfo();

  UltimateCar.accelerate(50.0f);
  UltimateCar.accelerate(30.0f);

  UltimateCar.advance(100.5f);

  UltimateCar.brake(40.0f);
  UltimateCar.brake(50.0f); // Devrait arrêter la voiture (vitesse = 0)
  UltimateCar.brake(
      10.0f); // Ne devrait pas devenir négatif (la vitesse reste 0)

  UltimateCar.displayInfo();

  std::cout << "\n---\n" << std::endl;

  // Les destructeurs seront appelés automatiquement lorsque main se termine.

  return 0;
}