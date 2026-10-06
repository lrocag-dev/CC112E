#include <iostream>
#include <concepts>
#include <numeric>
using namespace std;
// Recursion generica y restringida con concepts
template <integral T>
constexpr T mcd(T a, T b){
	return b == 0 ? (a < 0 ? -a : a) : mcd(b, static_cast<T>(a % b));
}
template <integral T>
constexpr T mcm(T a, T b){ return a / mcd(a, b) * b; }

template <unsigned_integral T>
constexpr int sumaDigitos(T n){ return n < 10 ? static_cast<int>(n) : static_cast<int>(n % 10) + sumaDigitos<T>(n / 10); }

template <typename T>
concept Numerico = integral<T> || floating_point<T>;

template <Numerico T>
constexpr T potencia(T x, unsigned n){
	if (n == 0) return 1;
	T m = potencia(x, n / 2);
	return n % 2 ? m * m * x : m * m;
}
static_assert(mcd(48, 18) == 6);
static_assert(mcd(48L, 180L) == gcd(48L, 180L));
static_assert(mcm(4, 6) == lcm(4, 6));
static_assert(potencia(2.0, 10) == 1024.0);

int main(){
	cout << "mcd(48,18) int:        " << mcd(48, 18) << endl;
	cout << "mcd(10^12, 6*10^9) long: " << mcd(1000000000000L, 6000000000L) << endl;
	cout << "mcm(21, 6): " << mcm(21, 6) << endl;
	cout << "Suma de digitos de 987654321u: " << sumaDigitos(987654321u) << endl;
	cout << "potencia(1.5, 4) = " << potencia(1.5, 4) << ", potencia(3, 5) = " << potencia(3, 5) << endl;
	// mcd(2.5, 1.5);      // ERROR de compilacion: double no es integral
	// sumaDigitos(-5);    // ERROR: int no es unsigned_integral
	return 0;
}
