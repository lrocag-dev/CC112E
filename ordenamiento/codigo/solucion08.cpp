#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct Estudiante {
	char nombre[20];
	int codigo;
	double nota;
};
// criterios de comparacion: devuelven true si 'a' debe ir antes que 'b'
bool porNotaDesc(const Estudiante &a, const Estudiante &b){ return a.nota > b.nota; }
bool porNombre(const Estudiante &a, const Estudiante &b){ return strcmp(a.nombre, b.nombre) < 0; }
bool porCodigo(const Estudiante &a, const Estudiante &b){ return a.codigo < b.codigo; }

void ordenar(Estudiante *v, int n, bool (*antes)(const Estudiante &, const Estudiante &)){
	for (int i = 1; i < n; i++){                      // insercion (estable)
		Estudiante x = v[i];
		int j = i - 1;
		while (j >= 0 && antes(x, v[j])){ v[j + 1] = v[j]; j--; }
		v[j + 1] = x;
	}
}
void mostrar(const Estudiante *v, int n){
	for (int i = 0; i < n; i++)
		cout << "  " << left << setw(8) << v[i].nombre << right << setw(6) << v[i].codigo
		     << setw(7) << fixed << setprecision(2) << v[i].nota << endl;
}
int main(){
	Estudiante v[] = {{"Luis", 2203, 14.5}, {"Ana", 2101, 18.0}, {"Rosa", 2305, 14.5}, {"Beto", 2002, 11.25}};
	cout << "Por nota (desc, estable):" << endl;  ordenar(v, 4, porNotaDesc); mostrar(v, 4);
	cout << "Por nombre:" << endl;                ordenar(v, 4, porNombre);   mostrar(v, 4);
	cout << "Por codigo:" << endl;                ordenar(v, 4, porCodigo);   mostrar(v, 4);
	return 0;
}
