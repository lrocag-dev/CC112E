#include<iostream>
using namespace std;
class Empleado {
private:
	int codigo;
	string nombre;
	double salario;
public:	
	void ingresarDatos();
	void mostrarDatos();
};
void Empleado::ingresarDatos(){	
	cout<<"Codigo: ";cin>>codigo;
	cin.ignore();
	cout<<"Nombre: "; getline(cin, nombre);
	cout<<"Salario: ";cin>>salario;
}
void Empleado::mostrarDatos(){	
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: "<< nombre<<endl;
	cout<<"Salario: "<<salario<<endl;
}
int main(){
	int n;
	cout<<"Ingrese el numero de empleados: ";
	cin>>n;
	Empleado * p = new Empleado[n];
	for (int i=0;i<n;i++)
		(p+i)->ingresarDatos();
	for (int i=0;i<n;i++)
		(p+i)->mostrarDatos();
	delete[] p;
}
