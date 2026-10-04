#include <iostream>
#include <concepts>
#include <string>
#include <string_view>
#include <cstring>
using namespace std;
// Una sola funcion para char*, const char*, string y string_view
template <typename T>
concept TextoLike = convertible_to<T, string_view>;

template <TextoLike T>
int contarVocales(const T &texto){
	string_view s = texto;
	int n = 0;
	for (char c : s){
		switch (c | 0x20){          // pasa a minuscula si es letra
			case 'a': case 'e': case 'i': case 'o': case 'u': n++;
		}
	}
	return n;
}
template <TextoLike T>
string mayusculas(const T &texto){
	string r{string_view(texto)};
	for (char &c : r)
		if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
	return r;
}
template <typename T>
concept Contenedor = requires(T t){ t.size(); t.begin(); t.end(); };

template <Contenedor T>
size_t longitud(const T &t){ return t.size(); }

int main(){
	char a[] = "Programacion en C++";
	const char *b = "Fundamentos";
	string c = "Ciencia de la Computacion";
	string_view d = "UNI";
	cout << contarVocales(a) << " " << contarVocales(b) << " "
	     << contarVocales(c) << " " << contarVocales(d) << endl;
	cout << mayusculas(a) << " | " << mayusculas(c) << endl;
	cout << longitud(c) << " " << longitud(d) << endl;
	// contarVocales(42);   // ERROR de compilacion: int no es convertible a string_view
	// longitud(a);         // ERROR: char[] no tiene .size()
	return 0;
}
