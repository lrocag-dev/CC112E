#include <iostream>
using namespace std;
long mcdRec(long a, long b){
	return b == 0 ? a : mcdRec(b, a % b);
}
long mcdIter(long a, long b){
	while (b != 0){
		long r = a % b;
		a = b;
		b = r;
	}
	return a;
}
long mcm(long a, long b){
	return a / mcdRec(a, b) * b;
}
int main(){
	long a, b;
	cout << "a y b: ";
	cin >> a >> b;
	cout << "MCD recursivo: " << mcdRec(a, b) << endl;
	cout << "MCD iterativo: " << mcdIter(a, b) << endl;
	cout << "MCM: " << mcm(a, b) << endl;
	cout << "Se simplifica " << a << "/" << b << " a "
	     << a / mcdRec(a, b) << "/" << b / mcdRec(a, b) << endl;
	return 0;
}
