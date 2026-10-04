#include <iostream>
#include <memory>
#include <string>
using namespace std;
// Lista doblemente enlazada: 'sig' fuerte (shared) y 'ant' debil (weak) para evitar ciclos
struct Nodo {
	string dato;
	shared_ptr<Nodo> sig;
	weak_ptr<Nodo> ant;
	Nodo(string d) : dato(std::move(d)){}
	~Nodo(){ cout << "  libera " << dato << endl; }
};
class Lista {
	shared_ptr<Nodo> cabeza, cola;
public:
	void agregar(const string &d){
		auto n = make_shared<Nodo>(d);
		if (!cabeza) cabeza = cola = n;
		else { cola->sig = n; n->ant = cola; cola = n; }
	}
	void mostrarAdelante() const {
		for (auto p = cabeza; p; p = p->sig) cout << p->dato << " ";
		cout << endl;
	}
	void mostrarAtras() const {
		for (auto p = cola; p; p = p->ant.lock()) cout << p->dato << " ";    // lock(): shared_ptr o nulo
		cout << endl;
	}
	size_t usos(const string &d) const {
		for (auto p = cabeza; p; p = p->sig) if (p->dato == d) return p.use_count();
		return 0;
	}
};
// demostracion del problema: ciclo con shared_ptr en ambos sentidos = FUGA
struct Malo {
	string nombre;
	shared_ptr<Malo> otro;
	Malo(string n) : nombre(std::move(n)){}
	~Malo(){ cout << "  libera Malo " << nombre << endl; }
};
int main(){
	cout << "Lista con weak_ptr hacia atras:" << endl;
	{
		Lista l;
		for (auto s : {"A", "B", "C"}) l.agregar(s);
		l.mostrarAdelante();
		l.mostrarAtras();
		cout << "use_count de B (cabeza y A->sig...): " << l.usos("B") << endl;
		cout << "Fin del bloque:" << endl;
	}
	cout << "Ciclo de shared_ptr (fuga):" << endl;
	{
		auto a = make_shared<Malo>("X");
		auto b = make_shared<Malo>("Y");
		a->otro = b;
		b->otro = a;
		cout << "use_count(a)=" << a.use_count() << ", use_count(b)=" << b.use_count() << endl;
		cout << "Fin del bloque (no se libera nada!):" << endl;
	}
	cout << "weak_ptr observando sin poseer:" << endl;
	weak_ptr<Nodo> observador;
	{
		auto n = make_shared<Nodo>("temporal");
		observador = n;
		cout << "expirado? " << boolalpha << observador.expired() << endl;
	}
	cout << "expirado? " << observador.expired() << ", lock() nulo? " << (observador.lock() == nullptr) << endl;
	return 0;
}
