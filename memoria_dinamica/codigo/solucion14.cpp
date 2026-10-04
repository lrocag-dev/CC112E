#include <iostream>
#include <algorithm>
using namespace std;
// Clase que administra memoria: regla de los tres (destructor, copia, asignacion)
class Matriz {
	int f, c;
	double *d;
public:
	Matriz(int f = 0, int c = 0) : f(f), c(c), d(f * c != 0 ? new double[f * c]() : nullptr) {}
	~Matriz(){ delete[] d; }
	Matriz(const Matriz &o) : f(o.f), c(o.c), d(o.f * o.c != 0 ? new double[o.f * o.c] : nullptr){
		copy(o.d, o.d + f * c, d);                                 // copia PROFUNDA
	}
	Matriz &operator=(const Matriz &o){
		if (this != &o){
			double *nuevo = o.f * o.c != 0 ? new double[o.f * o.c] : nullptr;
			copy(o.d, o.d + o.f * o.c, nuevo);
			delete[] d;                                            // recien ahora se libera lo anterior
			d = nuevo; f = o.f; c = o.c;
		}
		return *this;
	}
	double &operator()(int i, int j){ return d[i * c + j]; }
	double operator()(int i, int j) const { return d[i * c + j]; }
	Matriz operator*(const Matriz &o) const {
		Matriz r(f, o.c);
		for (int i = 0; i < f; i++)
			for (int j = 0; j < o.c; j++)
				for (int k = 0; k < c; k++) r(i, j) += (*this)(i, k) * o(k, j);
		return r;
	}
	Matriz transpuesta() const {
		Matriz t(c, f);
		for (int i = 0; i < f; i++) for (int j = 0; j < c; j++) t(j, i) = (*this)(i, j);
		return t;
	}
	int filas() const { return f; }
	int cols() const { return c; }
	friend ostream &operator<<(ostream &o, const Matriz &m){
		for (int i = 0; i < m.f; i++){
			for (int j = 0; j < m.c; j++) o << m(i, j) << "\t";
			o << "\n";
		}
		return o;
	}
};
int main(){
	Matriz a(2, 2);
	a(0, 0) = 1; a(0, 1) = 2; a(1, 0) = 3; a(1, 1) = 4;
	Matriz b = a;                    // copia profunda
	b(0, 0) = 99;
	cout << "a:\n" << a << "b (copia modificada):\n" << b;
	Matriz c;
	c = a * b;                       // asignacion
	cout << "a*b:\n" << c;
	c = c;                           // autoasignacion segura
	cout << "transpuesta de a*b:\n" << c.transpuesta();
	Matriz r(2, 3);
	for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) r(i, j) = i + j;
	cout << "r (2x3) * r^T:\n" << r * r.transpuesta();
	return 0;
}
