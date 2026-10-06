#include <iostream>
using namespace std;
char aMayuscula(char c){ return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c; }
char aMinuscula(char c){ return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c; }
int main(){
	char s[200];
	cout << "Cadena: ";
	cin.getline(s, 200);
	char may[200], min[200], alt[200], inv[200];
	int i;
	for (i = 0; s[i]; i++){
		may[i] = aMayuscula(s[i]);
		min[i] = aMinuscula(s[i]);
		alt[i] = (i % 2 == 0) ? aMayuscula(s[i]) : aMinuscula(s[i]);
		inv[i] = (s[i] >= 'a' && s[i] <= 'z') ? aMayuscula(s[i]) : aMinuscula(s[i]);
	}
	may[i] = min[i] = alt[i] = inv[i] = '\0';
	cout << "Mayusculas:  " << may << "\nMinusculas:  " << min
	     << "\nAlternado:   " << alt << "\nInvertido:   " << inv << endl;
	return 0;
}
