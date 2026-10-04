#include <iostream>
using namespace std;
typedef unsigned long long ull;
long llamadas = 0;
ull fibIngenuo(int n){
	llamadas++;
	if (n < 2) return n;
	return fibIngenuo(n - 1) + fibIngenuo(n - 2);
}
ull fibIter(int n){
	ull a = 0, b = 1;
	for (int i = 0; i < n; i++){
		ull c = a + b;
		a = b;
		b = c;
	}
	return a;
}
ull memo[91];
bool conocido[91];
long llamadasMemo = 0;
ull fibMemo(int n){
	llamadasMemo++;
	if (n < 2) return n;
	if (conocido[n]) return memo[n];
	conocido[n] = true;
	return memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
}
int main(){
	int n;
	cout << "n (0-40): ";
	cin >> n;
	cout << "Ingenuo:   " << fibIngenuo(n) << "  (" << llamadas << " llamadas)" << endl;
	cout << "Iterativo: " << fibIter(n) << endl;
	cout << "Memoizado: " << fibMemo(n) << "  (" << llamadasMemo << " llamadas)" << endl;
	cout << "Fib(90) iterativo = " << fibIter(90) << endl;
	return 0;
}
