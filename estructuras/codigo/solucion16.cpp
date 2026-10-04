#include <iostream>
#include <format>
#include <string>
#include <vector>
using namespace std;
struct Satelite {
	string nombre;
	double altitudKm = 400.0;       // valor por defecto del miembro
	double masaKg = 0.0;
	bool activo = true;
};
void mostrar(const Satelite &s){
	cout << format("{:<10} alt={:>7.1f} km  masa={:>7.1f} kg  {}",
	               s.nombre, s.altitudKm, s.masaKg, s.activo ? "activo" : "inactivo") << endl;
}
int main(){
	// inicializadores designados (C++20): se nombran los campos, en el orden de declaracion
	Satelite a{.nombre = "Chasqui-1", .masaKg = 1.0};                 // altitud y activo por defecto
	Satelite b{.nombre = "Hubble", .altitudKm = 540, .masaKg = 11110};
	Satelite c{.nombre = "Vanguard", .altitudKm = 3800, .masaKg = 1.5, .activo = false};

	vector<Satelite> flota = {
		a, b, c,
		{.nombre = "ISS", .altitudKm = 408, .masaKg = 420000},
	};
	for (const auto &s : flota) mostrar(s);

	int activos = 0;
	double masaTotal = 0;
	for (const auto &s : flota){
		if (s.activo) activos++;
		masaTotal += s.masaKg;
	}
	cout << format("Activos: {}/{}  Masa total: {:.1f} kg", activos, flota.size(), masaTotal) << endl;
	// Satelite d{.masaKg = 5, .nombre = "X"};   // ERROR: orden distinto al declarado
	return 0;
}
