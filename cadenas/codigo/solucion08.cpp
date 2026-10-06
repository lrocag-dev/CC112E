#include <iostream>
using namespace std;
int main(){
	char s[300];
	cout << "Ingrese un texto: ";
	cin.getline(s, 300);
	int palabras = 0;
	bool dentro = false;
	int longMax = 0, actual = 0;
	char masLarga[100] = "";
	char palabra[100];
	for (int i = 0; ; i++){
		char c = s[i];
		bool letra = (c != ' ' && c != '\t' && c != '\0');
		if (letra){
			if (!dentro){ palabras++; dentro = true; actual = 0; }
			if (actual < 99) palabra[actual] = c;
			actual++;
		} else if (dentro){
			dentro = false;
			if (actual > longMax && actual < 100){
				longMax = actual;
				for (int k = 0; k < actual; k++) masLarga[k] = palabra[k];
				masLarga[actual] = '\0';
			}
		}
		if (c == '\0') break;
	}
	cout << "Palabras: " << palabras << endl;
	cout << "Palabra mas larga: " << masLarga << " (" << longMax << " letras)" << endl;
	return 0;
}
