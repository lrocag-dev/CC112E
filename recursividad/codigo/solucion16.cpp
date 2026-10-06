#include <iostream>
#include <array>
using namespace std;
typedef unsigned long long ull;
// Recursion evaluada en TIEMPO DE COMPILACION
constexpr ull factorial(int n){ return n <= 1 ? 1 : n * factorial(n - 1); }
constexpr ull fib(int n){ return n < 2 ? n : fib(n - 1) + fib(n - 2); }
constexpr ull potencia(ull x, int n){
	if (n == 0) return 1;
	ull m = potencia(x, n / 2);
	return n % 2 ? m * m * x : m * m;
}
static_assert(factorial(10) == 3628800);
static_assert(fib(20) == 6765);
static_assert(potencia(2, 40) == 1099511627776ULL);

// consteval: la tabla SIEMPRE se genera al compilar
consteval array<ull, 21> tablaFactorial(){
	array<ull, 21> t{};
	for (int i = 0; i <= 20; i++) t[i] = factorial(i);
	return t;
}
constexpr auto TABLA = tablaFactorial();

// la misma funcion tambien sirve en ejecucion
int main(){
	int n;
	cout << "n (0-20): ";
	cin >> n;
	cout << n << "! en ejecucion   = " << factorial(n) << endl;
	cout << n << "! de la tabla    = " << TABLA[n] << endl;
	constexpr ull f30 = fib(30);                 // se calcula al compilar: costo cero en ejecucion
	cout << "fib(30) constante = " << f30 << endl;
	cout << "2^40 = " << potencia(2, 40) << endl;
	return 0;
}
