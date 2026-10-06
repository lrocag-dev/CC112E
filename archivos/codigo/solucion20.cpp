#include <iostream>
#include <fstream>
#include <filesystem>
#include <source_location>
#include <stdexcept>
#include <string>
#include <format>
using namespace std;
namespace fs = filesystem;

// source_location: archivo, linea y funcion donde se llamo, sin macros __LINE__
void registrarError(const string &mensaje, source_location loc = source_location::current()){
	cerr << format("[ERROR] {}:{} en {}(): {}", fs::path(loc.file_name()).filename().string(),
	               loc.line(), loc.function_name(), mensaje) << endl;
}
// RAII: abre en el constructor, cierra en el destructor; lanza excepcion si falla
class ArchivoTexto {
	ifstream in;
	fs::path ruta;
public:
	explicit ArchivoTexto(fs::path r, source_location loc = source_location::current()) : ruta(std::move(r)){
		in.open(ruta);
		if (!in)
			throw runtime_error(format("no se pudo abrir {} (pedido en la linea {})", ruta.string(), loc.line()));
	}
	ArchivoTexto(const ArchivoTexto &) = delete;
	ArchivoTexto &operator=(const ArchivoTexto &) = delete;
	~ArchivoTexto(){ cout << "[cerrando " << ruta.filename().string() << "]" << endl; }

	bool leerLinea(string &s){ return static_cast<bool>(getline(in, s)); }
};
int contarLineas(const fs::path &ruta){
	ArchivoTexto f(ruta);
	string s;
	int n = 0;
	while (f.leerLinea(s)) n++;
	return n;
}
int main(){
	fs::path buena = fs::temp_directory_path() / "texto.txt";
	ofstream(buena) << "uno\ndos\ntres\n";
	try {
		cout << "Lineas: " << contarLineas(buena) << endl;
		cout << "Lineas: " << contarLineas("/ruta/que/no/existe.txt") << endl;
	} catch (const exception &e){
		registrarError(e.what());
	}
	try {
		(void)fs::file_size("/ruta/que/no/existe.txt");        // lanza filesystem_error
	} catch (const fs::filesystem_error &e){
		cout << "filesystem_error: " << e.code().message() << endl;
	}
	fs::remove(buena);
	return 0;
}
