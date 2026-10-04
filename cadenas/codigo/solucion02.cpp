#include <iostream>
using namespace std;
int main(){
	char s[200];
	cout << "Ingrese una linea: ";
	cin.getline(s, 200);
	int vocales = 0, consonantes = 0, digitos = 0, espacios = 0, otros = 0;
	for (int i = 0; s[i] != '\0'; i++){
		char c = s[i];
		if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';   // a minuscula
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vocales++;
		else if (c >= 'a' && c <= 'z') consonantes++;
		else if (c >= '0' && c <= '9') digitos++;
		else if (c == ' ') espacios++;
		else otros++;
	}
	cout << "Vocales: " << vocales << "\nConsonantes: " << consonantes
	     << "\nDigitos: " << digitos << "\nEspacios: " << espacios
	     << "\nOtros: " << otros << endl;
	return 0;
}
