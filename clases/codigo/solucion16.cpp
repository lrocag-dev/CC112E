#include <iostream>
#include <concepts>
#include <numbers>
#include <string>
#include <vector>
#include <variant>
using namespace std;
// Polimorfismo ESTATICO: no hay clase base ni virtual; basta cumplir el concepto
template <typename T>
concept Figura = requires(const T &f){
	{ f.area() } -> convertible_to<double>;
	{ f.perimetro() } -> convertible_to<double>;
	{ f.nombre() } -> convertible_to<string>;
};
class Circulo {
	double r;
public:
	explicit Circulo(double r) : r(r) {}
	double area() const { return numbers::pi * r * r; }
	double perimetro() const { return 2 * numbers::pi * r; }
	string nombre() const { return "Circulo"; }
};
class Rectangulo {
	double b, h;
public:
	Rectangulo(double b, double h) : b(b), h(h) {}
	double area() const { return b * h; }
	double perimetro() const { return 2 * (b + h); }
	string nombre() const { return "Rectangulo"; }
};
class Triangulo {          // no cumple el concepto: falta perimetro()
public:
	double area() const { return 1; }
	string nombre() const { return "Triangulo"; }
};
template <Figura F>
void describir(const F &f){
	cout << f.nombre() << ": area=" << f.area() << " perimetro=" << f.perimetro() << endl;
}
template <Figura F>
bool masGrande(const F &a, const F &b){ return a.area() > b.area(); }

static_assert(Figura<Circulo>);
static_assert(!Figura<Triangulo>);
static_assert(!Figura<int>);

int main(){
	describir(Circulo(2));
	describir(Rectangulo(3, 4));
	cout << boolalpha << masGrande(Rectangulo(5, 5), Rectangulo(3, 4)) << endl;
	// describir(Triangulo());          // ERROR claro: Triangulo no satisface Figura
	// masGrande(Circulo(1), Rectangulo(1, 1));   // ERROR: tipos distintos

	// Para mezclar tipos distintos sin herencia: variant
	vector<variant<Circulo, Rectangulo>> v = {Circulo(1), Rectangulo(2, 3), Circulo(0.5)};
	double total = 0;
	for (const auto &f : v)
		total += visit([](const auto &x){ return x.area(); }, f);
	cout << "Area total: " << total << endl;
	return 0;
}
