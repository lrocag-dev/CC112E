#include <iostream>
#include <algorithm>
#include <compare>
#include <map>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
struct Estudiante {
	string nombre;
	int codigo;
	double nota;
	// comparacion automatica por (nombre, codigo, nota)
	auto operator<=>(const Estudiante &) const = default;
};
struct Resumen { double promedio; double maximo; double minimo; };

Resumen resumir(const vector<Estudiante> &v){
	double suma = 0, mx = v[0].nota, mn = v[0].nota;
	for (const auto &e : v){
		suma += e.nota;
		mx = max(mx, e.nota);
		mn = min(mn, e.nota);
	}
	return {suma / v.size(), mx, mn};
}
int main(){
	vector<Estudiante> v = {
		{"Luis", 2021, 14.5}, {"Ana", 2023, 18.0}, {"Rosa", 2022, 11.25}, {"Ana", 2020, 16.0}
	};
	// enlaces estructurados: desempaquetar un struct
	for (const auto &[nombre, codigo, nota] : v)
		cout << nombre << " (" << codigo << "): " << nota << endl;

	auto [prom, mx, mn] = resumir(v);
	cout << "Promedio " << prom << ", max " << mx << ", min " << mn << endl;

	ranges::sort(v);                                      // usa <=>
	cout << "Orden natural: ";
	for (const auto &e : v) cout << e.nombre << "/" << e.codigo << " ";
	cout << endl;

	ranges::sort(v, ranges::greater{}, &Estudiante::nota); // proyeccion sobre un campo
	cout << "Por nota desc: ";
	for (const auto &e : v) cout << e.nombre << "=" << e.nota << " ";
	cout << endl;

	// enlaces estructurados con pair/map
	map<string, vector<double>> notas;
	for (const auto &e : v) notas[e.nombre].push_back(e.nota);
	for (const auto &[nombre, lista] : notas){
		double s = 0;
		for (double x : lista) s += x;
		cout << nombre << ": " << lista.size() << " nota(s), promedio " << s / lista.size() << endl;
	}
	cout << boolalpha << (v[0] == v[0]) << " " << (v[0] != v[1]) << endl;
	return 0;
}
