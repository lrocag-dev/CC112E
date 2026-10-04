#include <iostream>
#include <fstream>
#include <charconv>
#include <filesystem>
#include <optional>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
using namespace std;
struct Registro { string nombre; int edad; double nota; };

optional<Registro> analizar(string_view linea){
	vector<string_view> campos;
	while (true){
		size_t pos = linea.find(',');
		campos.push_back(linea.substr(0, pos));
		if (pos == string_view::npos) break;
		linea.remove_prefix(pos + 1);
	}
	if (campos.size() != 3) return nullopt;
	Registro r{string(campos[0]), 0, 0.0};
	auto [p1, e1] = from_chars(campos[1].data(), campos[1].data() + campos[1].size(), r.edad);
	auto [p2, e2] = from_chars(campos[2].data(), campos[2].data() + campos[2].size(), r.nota);
	if (e1 != errc{} || e2 != errc{}) return nullopt;
	return r;
}
int main(){
	auto ruta = filesystem::temp_directory_path() / "alumnos.csv";
	ofstream(ruta) << "Ana,19,16.5\nLuis,x,12\nRosa,20,18.25\nlinea mal formada\nPedro,22,9.5\n";

	// leer todo el archivo de una vez
	ifstream in(ruta, ios::binary);
	string contenido(istreambuf_iterator<char>(in), {});
	cout << "Leidos " << contenido.size() << " bytes" << endl;

	vector<Registro> validos;
	int numLinea = 0, errores = 0;
	string_view resto = contenido;
	while (!resto.empty()){
		size_t fin = resto.find('\n');
		string_view linea = resto.substr(0, fin);
		resto.remove_prefix(fin == string_view::npos ? resto.size() : fin + 1);
		numLinea++;
		if (auto r = analizar(linea)) validos.push_back(*r);
		else { errores++; cout << "Linea " << numLinea << " invalida: \"" << linea << "\"" << endl; }
	}
	ranges::sort(validos, ranges::greater{}, &Registro::nota);
	for (const auto &[nombre, edad, nota] : validos)
		cout << nombre << " (" << edad << " anios) nota " << nota << endl;
	cout << validos.size() << " validos, " << errores << " con errores" << endl;
	filesystem::remove(ruta);
	return 0;
}
