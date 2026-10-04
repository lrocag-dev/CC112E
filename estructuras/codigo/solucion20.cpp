#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>
#include <string_view>
using namespace std;
struct Punto {
	double x = 0, y = 0;
	constexpr Punto operator+(Punto o) const { return {x + o.x, y + o.y}; }
	constexpr Punto operator-(Punto o) const { return {x - o.x, y - o.y}; }
	constexpr Punto operator*(double k) const { return {x * k, y * k}; }
	constexpr double norma2() const { return x * x + y * y; }
	constexpr bool operator==(const Punto &) const = default;
};
static_assert((Punto{1, 2} + Punto{3, 4}) == Punto{4, 6});
static_assert(Punto{3, 4}.norma2() == 25);

struct Constante { string_view nombre; double valor; string_view unidad; };
constexpr array<Constante, 4> constantes = {{
	{"velocidad de la luz", 299792458.0, "m/s"},
	{"gravedad terrestre", 9.80665, "m/s^2"},
	{"constante de Planck", 6.62607015e-34, "J.s"},
	{"constante de Boltzmann", 1.380649e-23, "J/K"},
}};
constexpr double area(const array<Punto, 3> &t){   // area de un triangulo (formula del determinante)
	double a = (t[1].x - t[0].x) * (t[2].y - t[0].y) - (t[2].x - t[0].x) * (t[1].y - t[0].y);
	return (a < 0 ? -a : a) / 2;
}
constexpr array<Punto, 3> TRI = {{{0, 0}, {4, 0}, {0, 3}}};
static_assert(area(TRI) == 6.0);

consteval array<Punto, 5> trayectoria(Punto inicio, Punto velocidad){
	array<Punto, 5> t{};
	for (int i = 0; i < 5; i++) t[i] = inicio + velocidad * i;
	return t;
}
constexpr auto RUTA = trayectoria({1, 1}, {2, 0.5});

int main(){
	cout << "Area del triangulo (compilacion): " << area(TRI) << endl;
	for (const auto &p : RUTA) cout << "(" << p.x << ", " << p.y << ") ";
	cout << endl;
	string_view buscado = "gravedad terrestre";
	if (auto it = ranges::find(constantes, buscado, &Constante::nombre); it != constantes.end())
		cout << it->nombre << " = " << it->valor << " " << it->unidad << endl;
	cout << "Mayor constante: "
	     << ranges::max_element(constantes, {}, &Constante::valor)->nombre << endl;
	return 0;
}
