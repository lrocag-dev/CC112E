#include <iostream>
#include <fstream>
#include <format>
#include <string>
#include <vector>
#include <filesystem>
using namespace std;
struct Venta { string producto; int cantidad; double precio; };
int main(){
	vector<Venta> ventas = {
		{"Laptop", 2, 3499.9}, {"Mouse", 15, 25.5}, {"Teclado mecanico", 6, 180.0}, {"Monitor", 3, 899.99}
	};
	auto ruta = filesystem::temp_directory_path() / "reporte_ventas.txt";
	{
		ofstream out(ruta);
		if (!out){ cerr << "No se pudo abrir " << ruta << endl; return 1; }
		out << format("{:^52}\n", "REPORTE DE VENTAS");
		out << format("{:<20}{:>8}{:>12}{:>12}\n", "Producto", "Cant.", "Precio", "Importe");
		out << string(52, '=') << "\n";
		double total = 0;
		for (const auto &v : ventas){
			double imp = v.cantidad * v.precio;
			total += imp;
			out << format("{:<20}{:>8}{:>12.2f}{:>12.2f}\n", v.producto, v.cantidad, v.precio, imp);
		}
		out << string(52, '-') << "\n";
		out << format("{:>52}\n", format("TOTAL: S/ {:.2f}", total));
	}   // el ofstream se cierra aqui (RAII)

	ifstream in(ruta);
	string linea;
	int n = 0;
	while (getline(in, linea)) cout << format("{:02d}| {}\n", ++n, linea);
	cout << "Archivo: " << ruta.filename() << " (" << filesystem::file_size(ruta) << " bytes)" << endl;
	filesystem::remove(ruta);
	return 0;
}
