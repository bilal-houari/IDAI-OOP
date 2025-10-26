#include <cmath>
#include <iostream>
#include <string>

class Vector3D {
public:
  float x, y, z;

  Vector3D(float vx = 0.0f, float vy = 0.0f, float vz = 0.0f)
      : x(vx), y(vy), z(vz) {}

  void display() const {
    std::cout << "(" << x << ", " << y << ", " << z << ")";
  }

private:
  float calculateNormSq() const { return x * x + y * y + z * z; }

  float calculateNorm() const { return std::sqrt(calculateNormSq()); }

public:
  // Somme de Vecteurs

  Vector3D addValue(const Vector3D v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
  }

  Vector3D &addRef(const Vector3D &v, Vector3D &result) const {
    result.x = x + v.x;
    result.y = y + v.y;
    result.z = z + v.z;
    return result;
  }

  Vector3D *addPtr(const Vector3D *v, Vector3D *result) const {
    result->x = x + v->x;
    result->y = y + v->y;
    result->z = z + v->z;
    return result;
  }

  // Produit Scalaire

  float dotValue(const Vector3D v) const {
    return (x * v.x) + (y * v.y) + (z * v.z);
  }

  float &dotRef(const Vector3D &v, float &result) const {
    result = (x * v.x) + (y * v.y) + (z * v.z);
    return result;
  }

  float *dotPtr(const Vector3D *v, float *result) const {
    *result = (x * v->x) + (y * v->y) + (z * v->z);
    return result;
  }

  // Coïncidence
  // Note : Utilise un petit epsilon (1e-6) pour la robustesse de la comparaison
  // des flottants

  static constexpr float EPSILON = 1e-6f;

  bool coincideValue(const Vector3D v) const {
    return (std::abs(x - v.x) < EPSILON) && (std::abs(y - v.y) < EPSILON) &&
           (std::abs(z - v.z) < EPSILON);
  }

  bool coincideRef(const Vector3D &v) const {
    return (std::abs(x - v.x) < EPSILON) && (std::abs(y - v.y) < EPSILON) &&
           (std::abs(z - v.z) < EPSILON);
  }

  bool coincidePtr(const Vector3D *v) const {
    return (std::abs(x - v->x) < EPSILON) && (std::abs(y - v->y) < EPSILON) &&
           (std::abs(z - v->z) < EPSILON);
  }

  // Norme du Vecteur

  float normValue() const { return calculateNorm(); }

  float &normRef(float &result) const {
    result = calculateNorm();
    return result;
  }

  float *normPtr(float *result) const {
    *result = calculateNorm();
    return result;
  }

  // Normax (Vecteur avec la plus grande Norme)

  Vector3D normaxValue(const Vector3D v) const {
    if (calculateNormSq() >= v.calculateNormSq()) {
      return *this;
    } else {
      return v;
    }
  }

  const Vector3D &normaxRef(const Vector3D &v) const {
    if (calculateNormSq() >= v.calculateNormSq()) {
      return *this;
    } else {
      return v;
    }
  }

  const Vector3D *normaxPtr(const Vector3D *v) const {
    if (calculateNormSq() >= v->calculateNormSq()) {
      return this;
    } else {
      return v;
    }
  }
};

void printVectorOp(const std::string &label, const Vector3D &v) {
  std::cout << "  " << label << " : ";
  v.display();
  std::cout << std::endl;
}

void printScalarOp(const std::string &label, float f) {
  std::cout << "  " << label << " : " << f << std::endl;
}

void printBoolOp(const std::string &label, bool b) {
  std::cout << "  " << label << " : " << (b ? "Coïncidence" : "Incompatibilité")
            << std::endl;
}

int main() {
  // Initialisation
  Vector3D v1(1.0f, 2.0f, 3.0f);
  Vector3D v2(4.0f, 5.0f, 6.0f);
  Vector3D vEqual(1.0f, 2.0f, 3.0f);

  std::cout << "Vecteurs Initiaux : >>>" << std::endl;
  std::cout << "V1 ";
  v1.display();
  std::cout << std::endl;
  std::cout << "V2 ";
  v2.display();
  std::cout << std::endl;
  std::cout << "V_égal ";
  vEqual.display();
  std::cout << std::endl << std::endl;

  // Somme
  std::cout << "Somme de Vecteurs (V1 + V2) : >>>" << std::endl;

  // Configuration des variables auxiliaires pour les versions ref/ptr
  Vector3D sumRefResult;
  Vector3D sumPtrResult;

  Vector3D sumVal = v1.addValue(v2);
  printVectorOp("Valeur (retourne copie)", sumVal);

  v1.addRef(v2, sumRefResult);
  printVectorOp("Référence (résultat dans ref)", sumRefResult);

  v1.addPtr(&v2, &sumPtrResult);
  printVectorOp("Pointeur (résultat dans ptr)", sumPtrResult);

  std::cout << std::endl;

  // Produit Scalaire
  std::cout << "Produit Scalaire (V1 . V2) : >>>" << std::endl;

  // Configuration des variables auxiliaires
  float dotRefResult;
  float dotPtrResult;

  float dotVal = v1.dotValue(v2);
  printScalarOp("Valeur (retourne flottant)", dotVal);

  v1.dotRef(v2, dotRefResult);
  printScalarOp("Référence (résultat dans ref)", dotRefResult);

  v1.dotPtr(&v2, &dotPtrResult);
  printScalarOp("Pointeur (résultat dans ptr)", dotPtrResult);

  std::cout << std::endl;

  // Norme
  std::cout << "Norme de V2 : >>>" << std::endl;

  // Configuration des variables auxiliaires
  float normRefResult;
  float normPtrResult;

  float normVal = v2.normValue();
  printScalarOp("Valeur (retourne flottant)", normVal);

  v2.normRef(normRefResult);
  printScalarOp("Référence (résultat dans ref)", normRefResult);

  v2.normPtr(&normPtrResult);
  printScalarOp("Pointeur (résultat dans ptr)", normPtrResult);

  std::cout << std::endl;

  // Coïncidence
  std::cout << "Vérification de Coïncidence (V1 vs V_égal) : >>>" << std::endl;

  bool coincideVal = v1.coincideValue(vEqual);
  printBoolOp("Valeur (V1 vs V_égal)", coincideVal);

  bool coincideRef = v1.coincideRef(vEqual);
  printBoolOp("Référence (V1 vs V_égal)", coincideRef);

  bool coincidePtr = v1.coincidePtr(&vEqual);
  printBoolOp("Pointeur (V1 vs V_égal)", coincidePtr);

  std::cout << std::endl;

  // Normax
  std::cout << "Normax (V1 vs V2) : >>>" << std::endl;

  Vector3D normaxVal = v1.normaxValue(v2);
  printVectorOp("Valeur (retourne copie)", normaxVal);

  const Vector3D &normaxRef = v1.normaxRef(v2);
  printVectorOp("Référence (retourne ref const)", normaxRef);

  const Vector3D *normaxPtr = v1.normaxPtr(&v2);
  printVectorOp("Pointeur (retourne ptr const)", *normaxPtr);

  std::cout << std::endl;

  return 0;
}