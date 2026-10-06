#include <iostream>
#include <string>
#include <variant>
#include <vector>
using namespace std;
// Un sensor puede reportar valores de distinto tipo
struct Medicion {
	string sensor;
	variant<int, double, string> valor;
};
struct Mostrar {
	void operator()(int v) const { cout << "entero " << v; }
	void operator()(double v) const { cout << "real " << v; }
	void operator()(const string &v) const { cout << "texto \"" << v << "\""; }
};
int main(){
	vector<Medicion> datos = {
		{"contador", 42}, {"temperatura", 36.6}, {"estado", string("OK")}, {"humedad", 71.25}
	};
	for (const auto &m : datos){
		cout << m.sensor << ": ";
		visit(Mostrar{}, m.valor);
		cout << endl;
	}
	double suma = 0;
	for (const auto &m : datos){
		// visit con lambda generica + if constexpr
		visit([&suma](const auto &v){
			using T = decay_t<decltype(v)>;
			if constexpr (is_arithmetic_v<T>) suma += v;
		}, m.valor);
	}
	cout << "Suma de valores numericos: " << suma << endl;

	for (const auto &m : datos){
		if (const double *d = get_if<double>(&m.valor))
			cout << m.sensor << " es real: " << *d << endl;
		cout << m.sensor << " guarda el tipo #" << m.valor.index() << endl;
	}
	try {
		get<int>(datos[1].valor);
	} catch (const bad_variant_access &e){
		cout << "Error: se pidio int pero hay otro tipo" << endl;
	}
	return 0;
}
