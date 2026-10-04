#include <iostream>
#include <cstring>
using namespace std;
struct Estudiante {
	char nombre[30];
	int codigo;
	double nota;
};
void leer(Estudiante *e){
	cout << "Nombre: "; cin.ignore(); cin.getline(e->nombre, 30);
	cout << "Codigo: "; cin >> e->codigo;
	cout << "Nota: "; cin >> e->nota;
}
void ordenarPorNota(Estudiante *v, int n){
	for (int i = 0; i < n - 1; i++){
		int k = i;
		for (int j = i + 1; j < n; j++)
			if ((v + j)->nota > (v + k)->nota) k = j;
		if (k != i){ Estudiante aux = v[i]; v[i] = v[k]; v[k] = aux; }
	}
}
int main(){
	int n;
	cout << "Numero de estudiantes: ";
	cin >> n;
	Estudiante *v = new Estudiante[n];
	for (int i = 0; i < n; i++){
		cout << "Estudiante " << i + 1 << endl;
		leer(v + i);
	}
	ordenarPorNota(v, n);
	cout << "\nRanking:" << endl;
	for (Estudiante *p = v; p < v + n; p++)
		cout << p->nombre << " (" << p->codigo << "): " << p->nota << endl;
	Estudiante *mejor = new Estudiante(*v);            // copia del primero en el heap
	cout << "Mejor: " << mejor->nombre << endl;
	delete mejor;
	delete[] v;
	return 0;
}
