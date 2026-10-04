#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;
typedef unsigned long long ull;
int main(){
	// lambda recursiva generica: recibe a si misma como parametro
	auto fact = [](auto self, int n) -> ull { return n <= 1 ? 1 : n * self(self, n - 1); };
	cout << "10! = " << fact(fact, 10) << endl;

	// lambda recursiva con std::function y memoizacion
	unordered_map<int, ull> memo;
	long llamadas = 0;
	function<ull(int)> fib = [&](int n) -> ull {
		llamadas++;
		if (n < 2) return n;
		if (auto it = memo.find(n); it != memo.end()) return it->second;
		return memo[n] = fib(n - 1) + fib(n - 2);
	};
	cout << "fib(80) = " << fib(80) << " (" << llamadas << " llamadas)" << endl;

	// plantilla que memoiza cualquier funcion recursiva
	auto memoizar = [](auto f){
		unordered_map<int, ull> cache;
		return [f, cache](auto &self, int n) mutable -> ull {
			if (auto it = cache.find(n); it != cache.end()) return it->second;
			return cache[n] = f(self, n);
		};
	};
	auto tribonacci = memoizar([](auto &self, int n) -> ull {
		return n < 3 ? (n == 2 ? 1 : 0) : self(self, n - 1) + self(self, n - 2) + self(self, n - 3);
	});
	cout << "tribonacci(40) = " << tribonacci(tribonacci, 40) << endl;

	// recursion de profundidad moderada con std::function
	function<int(int)> sumaHasta = [&](int n){ return n == 0 ? 0 : n + sumaHasta(n - 1); };
	cout << "Suma 1..100 = " << sumaHasta(100) << endl;
	return 0;
}
