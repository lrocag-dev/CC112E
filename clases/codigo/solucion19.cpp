#include <iostream>
#include <algorithm>
#include <memory>
#include <utility>
#include <vector>
using namespace std;
// Regla de los CINCO: si se gestiona un recurso crudo hay que definir los 5 miembros especiales
class Buffer {
	size_t n;
	int *datos;
public:
	explicit Buffer(size_t n) : n(n), datos(new int[n]()){ cout << "  ctor(" << n << ")" << endl; }
	~Buffer(){ delete[] datos; cout << "  dtor(" << n << ")" << endl; }
	Buffer(const Buffer &o) : n(o.n), datos(new int[o.n]){
		copy(o.datos, o.datos + n, datos);
		cout << "  copia(" << n << ")" << endl;
	}
	Buffer &operator=(const Buffer &o){
		if (this != &o){
			int *nuevo = new int[o.n];
			copy(o.datos, o.datos + o.n, nuevo);
			delete[] datos;
			datos = nuevo; n = o.n;
		}
		cout << "  asignacion copia(" << n << ")" << endl;
		return *this;
	}
	Buffer(Buffer &&o) noexcept : n(exchange(o.n, 0)), datos(exchange(o.datos, nullptr)){
		cout << "  movimiento(" << n << ")" << endl;
	}
	Buffer &operator=(Buffer &&o) noexcept {
		if (this != &o){
			delete[] datos;
			n = exchange(o.n, 0);
			datos = exchange(o.datos, nullptr);
		}
		cout << "  asignacion movimiento(" << n << ")" << endl;
		return *this;
	}
	int &operator[](size_t i){ return datos[i]; }
	size_t tamano() const { return n; }
};
// Regla del CERO: con unique_ptr/vector el compilador genera todo correctamente
class BufferSimple {
	vector<int> datos;
public:
	explicit BufferSimple(size_t n) : datos(n) {}
	size_t tamano() const { return datos.size(); }
};
Buffer crear(size_t n){ Buffer b(n); b[0] = 7; return b; }   // se mueve (o se elide)

int main(){
	cout << "1. construir" << endl;
	Buffer a(4);
	cout << "2. copiar" << endl;
	Buffer b = a;
	cout << "3. mover" << endl;
	Buffer c = move(a);
	cout << "   a.tamano() tras mover: " << a.tamano() << endl;
	cout << "4. asignacion por movimiento" << endl;
	Buffer d(2);
	d = move(b);
	cout << "5. retorno de funcion" << endl;
	Buffer e = crear(3);
	cout << "6. vector reubica con movimiento (noexcept)" << endl;
	vector<Buffer> v;
	v.reserve(1);
	v.push_back(Buffer(1));
	v.push_back(Buffer(2));
	cout << "7. regla del cero" << endl;
	BufferSimple s(10);
	BufferSimple t = s;
	BufferSimple u = move(s);
	cout << "   t=" << t.tamano() << " u=" << u.tamano() << " s=" << s.tamano() << endl;
	cout << "fin de main" << endl;
	return 0;
}
