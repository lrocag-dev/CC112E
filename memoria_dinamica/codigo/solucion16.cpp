#include <iostream>
#include <memory>
#include <vector>
using namespace std;
// Matriz de filas independientes: cada fila es un unique_ptr<int[]>; se libera sola
class Matriz {
	int f, c;
	unique_ptr<unique_ptr<int[]>[]> filas;
public:
	Matriz(int f, int c) : f(f), c(c), filas(make_unique<unique_ptr<int[]>[]>(f)){
		for (int i = 0; i < f; i++) filas[i] = make_unique<int[]>(c);       // inicializadas en 0
	}
	int *operator[](int i){ return filas[i].get(); }
	int nf() const { return f; }
	int nc() const { return c; }
};
int main(){
	// 1) arreglo dinamico sin new/delete
	int n = 5;
	auto a = make_unique<int[]>(n);
	for (int i = 0; i < n; i++) a[i] = (i + 1) * 10;
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;

	// 2) sin inicializar (C++20): util si se va a llenar de inmediato
	auto b = make_unique_for_overwrite<double[]>(n);
	for (int i = 0; i < n; i++) b[i] = i * 0.5;
	cout << "b[4] = " << b[4] << endl;

	// 3) transferir la propiedad
	unique_ptr<int[]> c = move(a);
	cout << "a es nulo: " << boolalpha << (a == nullptr) << ", c[0] = " << c[0] << endl;

	// 4) matriz con liberacion automatica
	Matriz m(3, 4);
	for (int i = 0; i < 3; i++) for (int j = 0; j < 4; j++) m[i][j] = i * 4 + j;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 4; j++) cout << m[i][j] << "\t";
		cout << endl;
	}
	// 5) vector de arreglos de distinto tamano (matriz irregular)
	vector<unique_ptr<int[]>> irregular;
	for (int i = 1; i <= 4; i++){
		irregular.push_back(make_unique<int[]>(i));
		for (int j = 0; j < i; j++) irregular[i - 1][j] = i * 10 + j;
	}
	cout << "irregular[3][2] = " << irregular[3][2] << endl;
	cout << "No hay new ni delete: todo se libera al salir de main." << endl;
	return 0;
}
