#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	// cada linea: nombre,edad,nota
	const char *lineas[] = {"Ana,19,16.5", "Luis,21,12", "Rosa,20,18.25", "Pedro,22,9.5"};
	double suma = 0;
	int n = 0;
	char mejor[50] = "";
	double mejorNota = -1;
	for (const char *l : lineas){
		char copia[100];
		strcpy(copia, l);                     // strtok modifica la cadena
		char *nombre = strtok(copia, ",");
		char *edad = strtok(nullptr, ",");
		char *nota = strtok(nullptr, ",");
		if (!nombre || !edad || !nota) continue;
		double nt = atof(nota);
		cout << nombre << " | edad " << atoi(edad) << " | nota " << nt << endl;
		suma += nt;
		n++;
		if (nt > mejorNota){ mejorNota = nt; strcpy(mejor, nombre); }
	}
	cout << "Promedio: " << suma / n << endl;
	cout << "Mejor nota: " << mejor << " (" << mejorNota << ")" << endl;
	return 0;
}
