#include <iostream>
#include <cstring>
using namespace std;
int longitud(const char *s){
	const char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
int main(){
	char s[200];
	cout << "Cadena: ";
	cin.getline(s, 200);
	cout << "Longitud propia: " << longitud(s) << endl;
	cout << "strlen:          " << strlen(s) << endl;
	cout << "sizeof(s):       " << sizeof(s) << " (capacidad, no longitud)" << endl;
	cout << "Ultimo caracter: " << (longitud(s) > 0 ? s[longitud(s) - 1] : ' ') << endl;
	return 0;
}
