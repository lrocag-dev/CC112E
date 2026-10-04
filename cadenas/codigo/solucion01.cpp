#include <iostream>
using namespace std;
int main(){
	char c;
	cout << "Ingrese un caracter: ";
	cin >> c;
	cout << "Codigo ASCII de '" << c << "': " << static_cast<int>(c) << endl;

	int codigo;
	cout << "Ingrese un codigo (32-126): ";
	cin >> codigo;
	cout << "Caracter del codigo " << codigo << ": " << static_cast<char>(codigo) << endl;

	cout << "\nLetras mayusculas: ";
	for (char x = 'A'; x <= 'Z'; x++) cout << x;
	cout << "\nLetras minusculas: ";
	for (char x = 'a'; x <= 'z'; x++) cout << x;
	cout << "\nDigitos: ";
	for (char x = '0'; x <= '9'; x++) cout << x;
	cout << "\n\nDiferencia 'a' - 'A' = " << 'a' - 'A' << endl;
	cout << "Valor numerico del digito '7': " << '7' - '0' << endl;
	return 0;
}
