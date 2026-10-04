#include <iostream>
#include <string>
#include <utility>
using namespace std;
class Cuenta {
	string titular;
	double saldo = 0;                           // inicializador de miembro
	inline static int total = 0;                // miembro estatico inline (C++17)
public:
	// constructor delegado: los demas llaman a este
	Cuenta(string titular, double saldo) : titular(std::move(titular)), saldo(saldo){ total++; }
	explicit Cuenta(string titular) : Cuenta(std::move(titular), 0.0) {}
	Cuenta() : Cuenta("Anonimo") {}

	[[nodiscard]] double consultar() const noexcept { return saldo; }
	[[nodiscard]] bool retirar(double m){
		if (m <= 0 || m > saldo) return false;
		saldo -= m;
		return true;
	}
	Cuenta &depositar(double m){ saldo += m; return *this; }
	static int cantidad(){ return total; }
	const string &nombre() const { return titular; }
};
class Base {
public:
	virtual ~Base() = default;
	virtual string tipo() const { return "Base"; }
	virtual void usar() const final { cout << "usar() de " << tipo() << endl; }   // no se puede redefinir
};
class Derivada final : public Base {                   // nadie puede heredar de Derivada
public:
	string tipo() const override { return "Derivada"; }   // override: error si no coincide la firma
	// string Tipo() const override { ... }                // ERROR: no existe tal metodo virtual
};
class NoCopiable {
public:
	NoCopiable() = default;
	NoCopiable(const NoCopiable &) = delete;
	NoCopiable &operator=(const NoCopiable &) = delete;
};
int main(){
	Cuenta a("Ana", 100);
	Cuenta b("Luis");
	Cuenta c;
	a.depositar(50).depositar(25);
	cout << a.nombre() << ": " << a.consultar() << ", " << b.nombre() << ": " << b.consultar()
	     << ", " << c.nombre() << endl;
	if (!a.retirar(1000)) cout << "Fondos insuficientes" << endl;
	// a.retirar(10);                // WARNING: se ignora un valor [[nodiscard]]
	cout << "Cuentas creadas: " << Cuenta::cantidad() << endl;
	Derivada d;
	d.usar();
	[[maybe_unused]] NoCopiable n1;
	// NoCopiable n2 = n1;           // ERROR: copia eliminada
	// Cuenta e = "Pedro";           // ERROR: constructor explicit
	return 0;
}
