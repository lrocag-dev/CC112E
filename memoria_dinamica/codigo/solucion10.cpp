#include <iostream>
#include <new>
using namespace std;
// Errores clasicos de memoria dinamica y su version corregida
void erroresComentados(){
	// 1. FUGA: se pierde el unico puntero al bloque
	//    int *p = new int[10]; p = new int[20];      // el primer bloque nunca se libera
	// 2. DOBLE LIBERACION
	//    int *q = new int; delete q; delete q;
	// 3. USO DESPUES DE LIBERAR (puntero colgante)
	//    int *r = new int(5); delete r; cout << *r;
	// 4. MEZCLAR new[] con delete
	//    int *s = new int[5]; delete s;               // debe ser delete[] s
	// 5. SALIRSE DEL BLOQUE
	//    int *t = new int[3]; t[3] = 1;
}
int main(){
	int *p = new int[10];
	delete[] p;
	p = nullptr;                    // delete sobre nullptr es seguro: protege contra doble liberacion
	delete[] p;
	cout << "Doble delete sobre nullptr: sin problema" << endl;

	// new que reporta el fallo por excepcion
	volatile size_t enorme = static_cast<size_t>(1) << 60;     // ~1 exabyte: imposible de reservar
	try {
		int *grande = new int[enorme];
		delete[] grande;
	} catch (const bad_alloc &e){
		cout << "bad_alloc capturada: " << e.what() << endl;
	}
	// new que devuelve nullptr en lugar de lanzar excepcion
	int *g = new (nothrow) int[enorme];
	if (g == nullptr) cout << "new(nothrow) devolvio nullptr" << endl;
	else delete[] g;

	erroresComentados();
	cout << "Compile con -fsanitize=address para detectar estos errores en ejecucion." << endl;
	return 0;
}
