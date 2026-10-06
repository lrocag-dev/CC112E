#include <iostream>
using namespace std;
// desplazamiento k (puede ser negativo); solo letras
void cesar(char *s, int k){
	k = ((k % 26) + 26) % 26;
	for (; *s; s++){
		if (*s >= 'A' && *s <= 'Z') *s = 'A' + (*s - 'A' + k) % 26;
		else if (*s >= 'a' && *s <= 'z') *s = 'a' + (*s - 'a' + k) % 26;
	}
}
int main(){
	char s[200];
	int k;
	cout << "Mensaje: ";
	cin.getline(s, 200);
	cout << "Desplazamiento: ";
	cin >> k;
	cesar(s, k);
	cout << "Cifrado: " << s << endl;
	cesar(s, -k);
	cout << "Descifrado: " << s << endl;
	return 0;
}
