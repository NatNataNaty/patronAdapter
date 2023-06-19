#include <iostream>
#include <cmath>

class Triangulo {
public:
	Triangulo(double lado1, double lado2, double lado3) : lado1(lado1), lado2(lado2), lado3(lado3) {}
	double obtenerPerimetro() const {
		return lado1 + lado2 + lado3;
	}
	double obtenerLado1() const { return lado1; }
	double obtenerLado2() const { return lado2; }
	double obtenerLado3() const { return lado3; }
private:
	double lado1, lado2, lado3;
};

class Figura {
public:
	virtual ~Figura() {}
	virtual double obtenerArea() const = 0;
};

class TrianguloAdapter : public Figura {
public:
	TrianguloAdapter(Triangulo* triangulo) : triangulo_(triangulo) {}
	double obtenerArea() const override {
		double s = triangulo_->obtenerPerimetro() / 2;
		return std::sqrt(s * (s - triangulo_->obtenerLado1()) * (s - triangulo_->obtenerLado2()) * (s - triangulo_->obtenerLado3()));
	}
private:
	Triangulo* triangulo_;
};

int main() {
	Triangulo* triangulo = new Triangulo(3, 4, 5);
	Figura* figura = new TrianguloAdapter(triangulo);
	std::cout << "Area: " << figura->obtenerArea() << std::endl; // Area: 6
	delete figura;
	delete triangulo;
	return 0;
}
