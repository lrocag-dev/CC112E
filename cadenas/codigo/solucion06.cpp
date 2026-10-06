#include <iostream>
using namespace std;
char *miStrcpy(char *destino, const char *origen){
	char *d = destino;
	while ((*d++ = *origen++) != '\0')
		;
	return destino;
}
char *miStrcat(char *destino, const char *origen){
	char *d = destino;
	while (*d) d++;
	while ((*d++ = *origen++) != '\0')
		;
	return destino;
}
int main(){
	char nombre[50], apellido[50], completo[101];
	cout << "Nombre: ";
	cin.getline(nombre, 50);
	cout << "Apellido: ";
	cin.getline(apellido, 50);
	miStrcpy(completo, nombre);
	miStrcat(completo, " ");
	miStrcat(completo, apellido);
	cout << "Nombre completo: " << completo << endl;
	return 0;
}
