#include <iostream>
#include <filesystem>
#include <fstream>
#include <format>
#include <vector>
#include <algorithm>
namespace fs = std::filesystem;
using namespace std;
int main(){
	fs::path carpeta = fs::temp_directory_path() / "lab_cc112e";
	fs::create_directories(carpeta / "reportes");

	// crear algunos archivos de prueba
	for (auto [nombre, texto] : vector<pair<string, string>>{
		{"notas.txt", "20 18 15\n"}, {"datos.csv", "a,b,c\n1,2,3\n"}, {"leeme.txt", "hola"}})
		ofstream(carpeta / nombre) << texto;

	cout << "Carpeta: " << carpeta << endl;
	vector<fs::directory_entry> entradas(fs::directory_iterator(carpeta), fs::directory_iterator{});
	ranges::sort(entradas, {}, [](const auto &e){ return e.path().filename(); });

	for (const auto &e : entradas){
		if (e.is_directory())
			cout << format("{:<12} <DIR>", e.path().filename().string()) << endl;
		else
			cout << format("{:<12} {:>5} bytes  ext={}", e.path().filename().string(),
			               e.file_size(), e.path().extension().string()) << endl;
	}

	// operaciones sobre archivos
	fs::path origen = carpeta / "notas.txt";
	fs::path copia = carpeta / "reportes" / "notas_copia.txt";
	fs::copy_file(origen, copia, fs::copy_options::overwrite_existing);
	fs::rename(copia, carpeta / "reportes" / "notas_final.txt");
	cout << "Existe notas_copia.txt? " << boolalpha << fs::exists(copia) << endl;
	cout << "Existe notas_final.txt? " << fs::exists(carpeta / "reportes" / "notas_final.txt") << endl;
	cout << "Nombre sin extension: " << origen.stem() << ", padre: " << origen.parent_path().filename() << endl;

	uintmax_t total = 0;
	int cantidad = 0;
	for (const auto &e : fs::recursive_directory_iterator(carpeta))
		if (e.is_regular_file()){ total += e.file_size(); cantidad++; }
	cout << cantidad << " archivos, " << total << " bytes en total" << endl;

	cout << "Eliminados: " << fs::remove_all(carpeta) << " elementos" << endl;
	return 0;
}
