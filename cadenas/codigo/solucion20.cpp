#include <iostream>
#include <algorithm>
#include <compare>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
struct Persona {
	string apellido;
	string nombre;
	int edad;
	// comparacion lexicografica generada: apellido, luego nombre, luego edad
	auto operator<=>(const Persona &) const = default;
};
string minusculas(string s){
	for (char &c : s) c = tolower(static_cast<unsigned char>(c));
	return s;
}
// ignora mayusculas/minusculas; devuelve strong_ordering
strong_ordering compararSinCaso(const string &a, const string &b){
	return minusculas(a) <=> minusculas(b);
}
int main(){
	vector<Persona> v = {
		{"Perez", "Luis", 30}, {"garcia", "Ana", 25}, {"Perez", "Ana", 41},
		{"Zegarra", "Rosa", 19}, {"Garcia", "Beto", 33}
	};
	ranges::sort(v);                             // usa operator<=> (distingue mayusculas)
	cout << "Orden natural:" << endl;
	for (const auto &p : v) cout << "  " << p.apellido << ", " << p.nombre << " (" << p.edad << ")" << endl;

	ranges::sort(v, {}, [](const Persona &p){ return minusculas(p.apellido); });  // proyeccion
	cout << "Apellido sin distinguir caso:" << endl;
	for (const auto &p : v) cout << "  " << p.apellido << ", " << p.nombre << endl;

	ranges::sort(v, ranges::greater{}, &Persona::edad);     // por edad descendente
	cout << "Por edad descendente:" << endl;
	for (const auto &p : v) cout << "  " << p.nombre << " " << p.edad << endl;

	auto r = compararSinCaso("Ana", "ana");
	cout << "Ana vs ana: " << (r == 0 ? "iguales" : r < 0 ? "menor" : "mayor") << endl;
	cout << "\"Ana\" < \"ana\" (ASCII): " << boolalpha << (string("Ana") < string("ana")) << endl;
	return 0;
}
