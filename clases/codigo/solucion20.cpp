#include <iostream>
#include <algorithm>
#include <format>
#include <memory>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>
using namespace std;
class Empleado {
protected:
	string nombre;
	double base;
public:
	Empleado(string n, double b) : nombre(std::move(n)), base(b) {}
	virtual ~Empleado() = default;
	virtual double sueldo() const { return base; }
	virtual string cargo() const = 0;
	const string &getNombre() const { return nombre; }
};
class Operario : public Empleado {
	int horasExtra;
public:
	Operario(string n, double b, int h) : Empleado(std::move(n), b), horasExtra(h) {}
	double sueldo() const override { return base + horasExtra * 25.0; }
	string cargo() const override { return "Operario"; }
};
class Gerente : public Empleado {
	double bono;
public:
	Gerente(string n, double b, double bono) : Empleado(std::move(n), b), bono(bono) {}
	double sueldo() const override { return base + bono; }
	string cargo() const override { return "Gerente"; }
};
class Practicante : public Empleado {
public:
	using Empleado::Empleado;
	double sueldo() const override { return base * 0.5; }
	string cargo() const override { return "Practicante"; }
};
int main(){
	vector<unique_ptr<Empleado>> plantilla;
	plantilla.push_back(make_unique<Operario>("Luis", 1500, 10));
	plantilla.push_back(make_unique<Gerente>("Ana", 4000, 1500));
	plantilla.push_back(make_unique<Practicante>("Rosa", 1200));
	plantilla.push_back(make_unique<Operario>("Pedro", 1500, 4));
	plantilla.push_back(make_unique<Gerente>("Marta", 3800, 900));

	auto mostrar = [](auto &&rango){
		for (const auto &e : rango)
			cout << format("  {:<8}{:<12}{:>9.2f}", e->getNombre(), e->cargo(), e->sueldo()) << endl;
	};
	cout << "Plantilla:" << endl;
	mostrar(plantilla);

	// ordenar por sueldo descendente usando una proyeccion que invoca un metodo virtual
	ranges::sort(plantilla, ranges::greater{}, [](const auto &e){ return e->sueldo(); });
	cout << "Por sueldo descendente:" << endl;
	mostrar(plantilla);

	// vista filtrada (perezosa): empleados con sueldo > 2000
	auto altos = plantilla | views::filter([](const auto &e){ return e->sueldo() > 2000; });
	cout << "Sueldo > 2000:" << endl;
	mostrar(altos);

	auto sueldos = plantilla | views::transform([](const auto &e){ return e->sueldo(); });
	double total = accumulate(sueldos.begin(), sueldos.end(), 0.0);
	cout << format("Planilla total: {:.2f}, promedio: {:.2f}", total, total / plantilla.size()) << endl;

	auto it = ranges::find_if(plantilla, [](const auto &e){ return e->cargo() == "Practicante"; });
	if (it != plantilla.end()) cout << "Practicante: " << (*it)->getNombre() << endl;
	cout << "Cantidad de gerentes: "
	     << ranges::count_if(plantilla, [](const auto &e){ return e->cargo() == "Gerente"; }) << endl;
	return 0;
}
