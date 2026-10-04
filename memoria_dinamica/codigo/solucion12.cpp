#include <iostream>
using namespace std;
class PilaDinamica {
	int *datos;
	int tope, capacidad;
	void crecer(){
		int nueva = capacidad * 2;
		int *n = new int[nueva];
		for (int i = 0; i < tope; i++) n[i] = datos[i];
		delete[] datos;
		datos = n;
		capacidad = nueva;
	}
public:
	PilaDinamica() : datos(new int[2]), tope(0), capacidad(2) {}
	~PilaDinamica(){ delete[] datos; }
	PilaDinamica(const PilaDinamica &) = delete;
	PilaDinamica &operator=(const PilaDinamica &) = delete;
	void apilar(int x){ if (tope == capacidad) crecer(); datos[tope++] = x; }
	bool desapilar(int &x){ if (tope == 0) return false; x = datos[--tope]; return true; }
	bool vacia() const { return tope == 0; }
	int tamano() const { return tope; }
	int cap() const { return capacidad; }
};
class ColaCircular {
	int *datos;
	int ini, cant, capacidad;
public:
	explicit ColaCircular(int cap) : datos(new int[cap]), ini(0), cant(0), capacidad(cap) {}
	~ColaCircular(){ delete[] datos; }
	ColaCircular(const ColaCircular &) = delete;
	ColaCircular &operator=(const ColaCircular &) = delete;
	bool encolar(int x){
		if (cant == capacidad) return false;
		datos[(ini + cant) % capacidad] = x;
		cant++;
		return true;
	}
	bool desencolar(int &x){
		if (cant == 0) return false;
		x = datos[ini];
		ini = (ini + 1) % capacidad;
		cant--;
		return true;
	}
	int tamano() const { return cant; }
};
// aplicacion de la pila: verificar parentesis balanceados
bool balanceado(const char *s){
	PilaDinamica p;
	for (; *s; s++){
		if (*s == '(' || *s == '[' || *s == '{') p.apilar(*s);
		else if (*s == ')' || *s == ']' || *s == '}'){
			int t;
			if (!p.desapilar(t)) return false;
			if ((*s == ')' && t != '(') || (*s == ']' && t != '[') || (*s == '}' && t != '{')) return false;
		}
	}
	return p.vacia();
}
int main(){
	PilaDinamica p;
	for (int i = 1; i <= 9; i++) p.apilar(i * i);
	cout << "Tamano " << p.tamano() << ", capacidad " << p.cap() << endl;
	int x;
	cout << "Desapilando: ";
	while (p.desapilar(x)) cout << x << " ";
	cout << endl;
	cout << boolalpha << balanceado("{[()()]}") << " " << balanceado("([)]") << " " << balanceado("((") << endl;

	ColaCircular c(3);
	cout << c.encolar(1) << c.encolar(2) << c.encolar(3) << c.encolar(4) << " (la cuarta falla: cola llena)" << endl;
	c.desencolar(x);
	cout << "Salio " << x << "; ahora entra 5: " << c.encolar(5) << endl;
	cout << "Orden de salida: ";
	while (c.desencolar(x)) cout << x << " ";
	cout << endl;
	return 0;
}
