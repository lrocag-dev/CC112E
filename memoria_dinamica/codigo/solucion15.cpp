#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
// Estructuras anidadas con memoria dinamica en cada nivel
struct Estudiante {
	char *nombre;           // cadena dinamica
	double *notas;          // arreglo dinamico
	int numNotas;
};
struct Curso {
	char *nombre;
	Estudiante *estudiantes;
	int cantidad;
};
Estudiante crearEstudiante(const char *nombre, const double *notas, int n){
	Estudiante e;
	e.nombre = new char[strlen(nombre) + 1];
	strcpy(e.nombre, nombre);
	e.numNotas = n;
	e.notas = new double[n];
	for (int i = 0; i < n; i++) e.notas[i] = notas[i];
	return e;
}
double promedio(const Estudiante &e){
	double s = 0;
	for (int i = 0; i < e.numNotas; i++) s += e.notas[i];
	return e.numNotas ? s / e.numNotas : 0;
}
Curso crearCurso(const char *nombre, int capacidad){
	Curso c;
	c.nombre = new char[strlen(nombre) + 1];
	strcpy(c.nombre, nombre);
	c.estudiantes = new Estudiante[capacidad];
	c.cantidad = 0;
	return c;
}
void liberarCurso(Curso &c){
	for (int i = 0; i < c.cantidad; i++){
		delete[] c.estudiantes[i].nombre;       // cada nivel, de adentro hacia afuera
		delete[] c.estudiantes[i].notas;
	}
	delete[] c.estudiantes;
	delete[] c.nombre;
	c.estudiantes = nullptr; c.nombre = nullptr; c.cantidad = 0;
}
int main(){
	Curso c = crearCurso("Fundamentos de Programacion", 5);
	double n1[] = {18, 15, 20}, n2[] = {11, 9}, n3[] = {14, 16, 12, 18};
	c.estudiantes[c.cantidad++] = crearEstudiante("Ana", n1, 3);
	c.estudiantes[c.cantidad++] = crearEstudiante("Luis", n2, 2);
	c.estudiantes[c.cantidad++] = crearEstudiante("Rosa", n3, 4);
	cout << c.nombre << endl;
	int mejor = 0;
	for (int i = 0; i < c.cantidad; i++){
		cout << "  " << left << setw(6) << c.estudiantes[i].nombre << c.estudiantes[i].numNotas
		     << " notas, promedio " << fixed << setprecision(2) << promedio(c.estudiantes[i]) << endl;
		if (promedio(c.estudiantes[i]) > promedio(c.estudiantes[mejor])) mejor = i;
	}
	cout << "Mejor promedio: " << c.estudiantes[mejor].nombre << endl;
	liberarCurso(c);
	return 0;
}
