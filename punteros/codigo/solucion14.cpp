#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;
class Recurso {
	string nombre;
public:
	Recurso(string n) : nombre(n){ cout << "  [+] " << nombre << " creado" << endl; }
	~Recurso(){ cout << "  [-] " << nombre << " destruido" << endl; }
	void usar() const { cout << "  usando " << nombre << endl; }
};
int main(){
	cout << "unique_ptr:" << endl;
	{
		unique_ptr<Recurso> u = make_unique<Recurso>("A");
		u->usar();
		unique_ptr<Recurso> v = move(u);          // la propiedad se transfiere
		cout << "  u vacio? " << (u == nullptr) << endl;
		v->usar();
	}                                               // A se libera aqui sin delete
	cout << "shared_ptr:" << endl;
	{
		shared_ptr<Recurso> s1 = make_shared<Recurso>("B");
		cout << "  use_count = " << s1.use_count() << endl;
		{
			shared_ptr<Recurso> s2 = s1;
			cout << "  use_count = " << s1.use_count() << endl;
		}
		cout << "  use_count = " << s1.use_count() << endl;
	}                                               // B se libera con el ultimo dueno
	cout << "unique_ptr de arreglo:" << endl;
	unique_ptr<int[]> v = make_unique<int[]>(5);
	for (int i = 0; i < 5; i++) v[i] = i * i;
	for (int i = 0; i < 5; i++) cout << v[i] << " ";
	cout << endl;
	return 0;
}
