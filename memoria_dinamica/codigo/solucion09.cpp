#include <iostream>
#include <cstring>
using namespace std;
struct Texto {
	char *datos;
	int longitud;
};
Texto crear(const char *s){
	Texto t;
	t.longitud = strlen(s);
	t.datos = new char[t.longitud + 1];
	strcpy(t.datos, s);
	return t;
}
Texto copiaSuperficial(const Texto &o){ return o; }          // comparte el MISMO bloque
Texto copiaProfunda(const Texto &o){                          // reserva un bloque nuevo
	Texto t;
	t.longitud = o.longitud;
	t.datos = new char[o.longitud + 1];
	strcpy(t.datos, o.datos);
	return t;
}
Texto concatenar(const Texto &a, const Texto &b){
	Texto t;
	t.longitud = a.longitud + b.longitud;
	t.datos = new char[t.longitud + 1];
	strcpy(t.datos, a.datos);
	strcat(t.datos, b.datos);
	return t;
}
int main(){
	Texto a = crear("Hola");
	Texto sup = copiaSuperficial(a);
	Texto prof = copiaProfunda(a);
	a.datos[0] = 'J';                                          // modifica el original
	cout << "original:    " << a.datos << " (" << (void *)a.datos << ")" << endl;
	cout << "superficial: " << sup.datos << " (misma direccion: se ve el cambio)" << endl;
	cout << "profunda:    " << prof.datos << " (independiente)" << endl;
	Texto c = concatenar(a, prof);
	cout << "concatenada: " << c.datos << " (" << c.longitud << ")" << endl;
	// 'sup' y 'a' apuntan al mismo bloque: liberar UNA sola vez (delete[] a.datos y delete[] sup.datos seria doble liberacion)
	delete[] a.datos;
	delete[] prof.datos;
	delete[] c.datos;
	return 0;
}
