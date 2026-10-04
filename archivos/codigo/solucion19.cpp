#include <iostream>
#include <fstream>
#include <span>
#include <vector>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <type_traits>
using namespace std;
struct Sensor {
	int32_t id;
	double lectura;
	char nombre[16];
};
static_assert(is_trivially_copyable_v<Sensor>, "solo tipos triviales se pueden volcar a binario");

// escribe cualquier arreglo de tipos triviales
template <typename T>
requires is_trivially_copyable_v<T>
void escribir(ofstream &out, span<const T> datos){
	out.write(reinterpret_cast<const char *>(datos.data()), datos.size_bytes());
}
template <typename T>
requires is_trivially_copyable_v<T>
vector<T> leer(const filesystem::path &ruta){
	ifstream in(ruta, ios::binary);
	in.seekg(0, ios::end);
	size_t bytes = in.tellg();
	in.seekg(0);
	vector<T> v(bytes / sizeof(T));
	in.read(reinterpret_cast<char *>(v.data()), v.size() * sizeof(T));
	return v;
}
int main(){
	auto ruta = filesystem::temp_directory_path() / "sensores.bin";
	Sensor s[3] = {{1, 21.5, "Temperatura"}, {2, 63.0, "Humedad"}, {3, 1013.2, "Presion"}};
	{
		ofstream out(ruta, ios::binary);
		escribir<Sensor>(out, s);
	}
	cout << "Archivo: " << filesystem::file_size(ruta) << " bytes (3 x " << sizeof(Sensor) << ")" << endl;

	auto v = leer<Sensor>(ruta);
	for (const auto &x : v) cout << x.id << " " << x.nombre << " " << x.lectura << endl;

	// acceso aleatorio: modificar solo el registro 1
	{
		fstream f(ruta, ios::in | ios::out | ios::binary);
		f.seekg(1 * sizeof(Sensor));
		Sensor r;
		f.read(reinterpret_cast<char *>(&r), sizeof r);
		r.lectura = 70.5;
		f.seekp(1 * sizeof(Sensor));
		f.write(reinterpret_cast<const char *>(&r), sizeof r);
	}
	cout << "Tras actualizar: " << leer<Sensor>(ruta)[1].lectura << endl;

	// vista de bytes con as_bytes
	double d = 1.0;
	auto bytes = as_bytes(span(&d, 1));
	cout << "1.0 como bytes: ";
	for (auto b : bytes) cout << hex << static_cast<int>(to_integer<unsigned>(b)) << " ";
	cout << dec << endl;
	filesystem::remove(ruta);
	return 0;
}
