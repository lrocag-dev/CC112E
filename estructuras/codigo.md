# Código Fuente C++20 — Problemas Avanzados con Structs

## Problema 1 — Sistema de Gestión de Satélites

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Fecha {
    int dia, mes, anio;
};

struct Orbita {
    double altura;
    double inclinacion;
    double velocidad;
};

struct Satelite {
    string nombre;
    string pais;
    double masa;
    Fecha lanzamiento;
    Orbita orbita;
};

void leer(Satelite& s) {
    cin >> s.nombre >> s.pais >> s.masa;
    cin >> s.lanzamiento.dia >> s.lanzamiento.mes >> s.lanzamiento.anio;
    cin >> s.orbita.altura >> s.orbita.inclinacion >> s.orbita.velocidad;
}

void imprimir(const Satelite& s) {
    cout << s.nombre << " " << s.pais << " " << s.masa << endl;
}

int main() {
    int n;
    cin >> n;

    vector<Satelite> v(n);

    for (auto& x : v)
        leer(x);

    for (const auto& x : v)
        imprimir(x);
}
```

---

## Problema 2 — Registro de Estudiantes Investigadores

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Proyecto {
    string nombre;
    string area;
    int duracion;
};

struct Estudiante {
    int codigo;
    string nombre;
    double promedio;
    vector<Proyecto> proyectos;
};

int main() {
    vector<Estudiante> estudiantes(3);

    for (auto& e : estudiantes) {
        cin >> e.codigo >> e.nombre >> e.promedio;
    }

    sort(estudiantes.begin(), estudiantes.end(),
    [](const Estudiante& a, const Estudiante& b){
        return a.promedio > b.promedio;
    });

    for (const auto& e : estudiantes)
        cout << e.nombre << " " << e.promedio << endl;
}
```

---

## Problema 3 — Biblioteca Digital

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Autor {
    string nombre;
    string nacionalidad;
};

struct Libro {
    string titulo;
    string isbn;
    int paginas;
    vector<Autor> autores;
};

Libro* buscarISBN(vector<Libro>& libros, string isbn) {
    for (auto& l : libros)
        if (l.isbn == isbn)
            return &l;

    return nullptr;
}

int main() {
    vector<Libro> libros(2);

    libros[0].isbn = "123";
    libros[0].titulo = "C++";

    Libro* p = buscarISBN(libros, "123");

    if (p)
        cout << p->titulo << endl;
}
```

---

## Problema 4 — Sistema Bancario

```cpp
#include <iostream>
using namespace std;

struct Cuenta {
    int numero;
    string titular;
    double saldo;
};

void depositar(Cuenta* c, double monto) {
    c->saldo += monto;
}

bool retirar(Cuenta* c, double monto) {
    if (monto > c->saldo)
        return false;

    c->saldo -= monto;
    return true;
}

int main() {
    Cuenta c{1001, "Luis", 500};

    depositar(&c, 100);
    retirar(&c, 50);

    cout << c.saldo << endl;
}
```

---

## Problema 5 — Inventario de Reactivos

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Fecha {
    int dia, mes, anio;
};

struct Reactivo {
    string nombre;
    double concentracion;
    double volumen;
    Fecha vencimiento;
};

int main() {
    vector<Reactivo> r(2);

    r[0].nombre = "HCl";
    r[0].concentracion = 0.5;

    r[1].nombre = "NaOH";
    r[1].concentracion = 0.8;

    Reactivo mayor = r[0];

    for (const auto& x : r)
        if (x.concentracion > mayor.concentracion)
            mayor = x;

    cout << mayor.nombre << endl;
}
```

---

## Problema 6 — Gestión de Vuelos

```cpp
#include <iostream>
using namespace std;

struct Hora {
    int hora, minuto;
};

struct Aeropuerto {
    string nombre;
    string ciudad;
};

struct Vuelo {
    string codigo;
    Aeropuerto origen;
    Aeropuerto destino;
    int capacidad;
    int pasajeros;
};

float ocupacion(const Vuelo& v) {
    return 100.0f * v.pasajeros / v.capacidad;
}

int main() {
    Vuelo v{"LA101", {"JorgeChavez","Lima"}, {"Ezeiza","BuenosAires"}, 200, 150};

    cout << ocupacion(v) << "%" << endl;
}
```

---

## Problema 7 — Historia Clínica

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Diagnostico {
    string enfermedad;
    string tratamiento;
};

struct Paciente {
    string nombre;
    vector<Diagnostico> historial;
};

void agregarDiagnostico(Paciente& p, Diagnostico d) {
    p.historial.push_back(d);
}

int main() {
    Paciente p{"Ana"};

    agregarDiagnostico(p, {"Gripe", "Reposo"});

    cout << p.historial[0].enfermedad << endl;
}
```

---

## Problema 8 — Red de Sensores

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Sensor {
    int id;
    double temperatura;
};

int main() {
    vector<Sensor> sensores(3);

    for (int i = 0; i < 3; i++) {
        sensores[i].id = i;
        sensores[i].temperatura = 20 + i;
    }

    Sensor* p = &sensores[0];

    cout << p->temperatura << endl;
}
```

---

## Problema 9 — Plataforma de Videojuegos

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Item {
    string nombre;
    int poder;
};

struct Jugador {
    string nombre;
    vector<Item> items;
};

int poderTotal(const Jugador& j) {
    int suma = 0;

    for (const auto& x : j.items)
        suma += x.poder;

    return suma;
}

int main() {
    Jugador j{"Link"};

    j.items.push_back({"Espada", 50});
    j.items.push_back({"Escudo", 20});

    cout << poderTotal(j) << endl;
}
```

---

## Problema 10 — Administración Empresarial

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Empleado {
    string nombre;
    double salario;
};

struct Departamento {
    string nombre;
    vector<Empleado> empleados;
};

int main() {
    Departamento d{"Sistemas"};

    d.empleados.push_back({"Luis", 3000});
    d.empleados.push_back({"Ana", 3500});

    double total = 0;

    for (const auto& e : d.empleados)
        total += e.salario;

    cout << total << endl;
}
```

---

## Problema 11 — Simulación de Partículas

```cpp
#include <iostream>
#include <cmath>
using namespace std;

struct Vector3D {
    double x, y, z;
};

struct Particula {
    Vector3D velocidad;
    double masa;
};

double energia(const Particula& p) {
    double v2 = p.velocidad.x*p.velocidad.x
              + p.velocidad.y*p.velocidad.y
              + p.velocidad.z*p.velocidad.z;

    return 0.5 * p.masa * v2;
}

int main() {
    Particula p{{1,2,3}, 5};

    cout << energia(p) << endl;
}
```

---

## Problema 12 — Sistema Meteorológico

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Medicion {
    double temperatura;
    double humedad;
};

int main() {
    vector<Medicion> v = {
        {20, 60},
        {25, 50},
        {30, 45}
    };

    double suma = 0;

    for (const auto& x : v)
        suma += x.temperatura;

    cout << suma / v.size() << endl;
}
```

---

## Problema 13 — Competencias Deportivas

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Jugador {
    string nombre;
    int goles;
};

struct Equipo {
    string nombre;
    vector<Jugador> jugadores;
};

int main() {
    Equipo e{"Peru"};

    e.jugadores.push_back({"Paolo", 10});

    cout << e.jugadores[0].nombre << endl;
}
```

---

## Problema 14 — Comercio Electrónico

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Producto {
    string nombre;
    double precio;
};

struct Pedido {
    vector<Producto> productos;
    double total;
};

void calcularTotal(Pedido& p) {
    p.total = 0;

    for (const auto& x : p.productos)
        p.total += x.precio;
}

int main() {
    Pedido p;

    p.productos.push_back({"Laptop", 3000});
    p.productos.push_back({"Mouse", 100});

    calcularTotal(p);

    cout << p.total << endl;
}
```

---

## Problema 15 — Observaciones Astronómicas

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Coordenada {
    double ascension;
    double declinacion;
};

struct Estrella {
    string nombre;
    double magnitud;
    Coordenada posicion;
};

int main() {
    vector<Estrella> estrellas = {
        {"Sirio", -1.46, {1,2}},
        {"Canopus", -0.74, {2,3}}
    };

    Estrella mejor = estrellas[0];

    for (const auto& e : estrellas)
        if (e.magnitud < mejor.magnitud)
            mejor = e;

    cout << mejor.nombre << endl;
}
```

