# Framework de Solución para Problemas de POO en C++20

## Objetivo

Estas plantillas proporcionan una estructura base reutilizable para resolver ejercicios relacionados con:

- Clases y objetos
- Constructores y destructores
- Uso de `this`
- Herencia simple
- Herencia múltiple
- Herencia jerárquica
- Herencia multinivel
- Polimorfismo
- Clases abstractas

---

# Plantilla 1 — Clase Básica

## Estructura General

```cpp
#include <iostream>
#include <string>

using namespace std;

class ClaseBase
{
private:
    int atributo1;
    string atributo2;

public:
    ClaseBase()
    {
        atributo1 = 0;
        atributo2 = "";
    }

    ClaseBase(int a1, string a2)
    {
        atributo1 = a1;
        atributo2 = a2;
    }

    void leerDatos()
    {
        cin >> atributo1;
        cin.ignore();
        getline(cin, atributo2);
    }

    void mostrarDatos() const
    {
        cout << atributo1 << " "
             << atributo2 << endl;
    }

    ~ClaseBase()
    {
        cout << "Destructor ejecutado\n";
    }
};

int main()
{
    ClaseBase obj;

    obj.leerDatos();
    obj.mostrarDatos();

    return 0;
}
```

---

# Plantilla 2 — Constructor con this

## Patrón

```cpp
class Producto
{
private:
    int codigo;
    string nombre;
    double precio;

public:

    Producto(
        int codigo,
        string nombre,
        double precio)
    {
        this->codigo = codigo;
        this->nombre = nombre;
        this->precio = precio;
    }

    void mostrar() const
    {
        cout
            << codigo << " "
            << nombre << " "
            << precio << endl;
    }
};
```

---

# Plantilla 3 — Encadenamiento con this

## Patrón

```cpp
class Producto
{
private:
    string nombre;
    double precio;

public:

    Producto& setNombre(
        const string& nombre)
    {
        this->nombre = nombre;
        return *this;
    }

    Producto& setPrecio(
        double precio)
    {
        this->precio = precio;
        return *this;
    }

    void mostrar() const
    {
        cout
            << nombre
            << " "
            << precio
            << endl;
    }
};

int main()
{
    Producto p;

    p.setNombre("Laptop")
     .setPrecio(3500);

    p.mostrar();
}
```

---

# Plantilla 4 — Herencia Simple

## Patrón

```cpp
class Persona
{
protected:
    string nombre;

public:

    Persona(string n)
        : nombre(n)
    {
    }

    void mostrarNombre() const
    {
        cout << nombre << endl;
    }
};

class Empleado
    : public Persona
{
private:
    double sueldo;

public:

    Empleado(
        string n,
        double s)
        : Persona(n),
          sueldo(s)
    {
    }

    void mostrar() const
    {
        mostrarNombre();
        cout << sueldo << endl;
    }
};
```

---

# Plantilla 5 — Herencia Multinivel

## Patrón

```cpp
class Animal
{
protected:
    string nombre;

public:
    Animal(string n)
        : nombre(n)
    {
    }
};

class Mamifero
    : public Animal
{
public:
    Mamifero(string n)
        : Animal(n)
    {
    }
};

class Perro
    : public Mamifero
{
public:
    Perro(string n)
        : Mamifero(n)
    {
    }

    void ladrar()
    {
        cout << nombre
             << " ladra\n";
    }
};
```

---

# Plantilla 6 — Herencia Jerárquica

## Patrón

```cpp
class Dispositivo
{
protected:
    string marca;

public:
    Dispositivo(string m)
        : marca(m)
    {
    }
};

class Laptop
    : public Dispositivo
{
public:
    Laptop(string m)
        : Dispositivo(m)
    {
    }
};

class Tablet
    : public Dispositivo
{
public:
    Tablet(string m)
        : Dispositivo(m)
    {
    }
};

class Celular
    : public Dispositivo
{
public:
    Celular(string m)
        : Dispositivo(m)
    {
    }
};
```

---

# Plantilla 7 — Herencia Múltiple

## Patrón

```cpp
class Empleado
{
protected:
    double sueldo;
};

class Estudiante
{
protected:
    double promedio;
};

class Becario
    : public Empleado,
      public Estudiante
{
public:

    void mostrar()
    {
        cout
            << sueldo
            << " "
            << promedio
            << endl;
    }
};
```

---

# Plantilla 8 — Polimorfismo Básico

## Patrón

```cpp
class Figura
{
public:

    virtual double area() const
    {
        return 0;
    }

    virtual ~Figura() = default;
};

class Rectangulo
    : public Figura
{
private:
    double base;
    double altura;

public:

    Rectangulo(
        double b,
        double h)
        : base(b),
          altura(h)
    {
    }

    double area() const override
    {
        return base * altura;
    }
};
```

---

# Plantilla 9 — Polimorfismo con Punteros

## Patrón

```cpp
Figura* figuras[3];

figuras[0] =
    new Rectangulo(4,5);

figuras[1] =
    new Rectangulo(3,7);

for(int i=0;i<2;i++)
{
    cout
        << figuras[i]->area()
        << endl;
}

for(int i=0;i<2;i++)
{
    delete figuras[i];
}
```

---

# Plantilla 10 — Clase Abstracta

## Patrón

```cpp
class Figura
{
public:

    virtual double area() const = 0;

    virtual ~Figura() = default;
};
```

---

# Plantilla 11 — Override

## Patrón

```cpp
class Base
{
public:

    virtual void mostrar()
    {
        cout << "Base\n";
    }
};

class Derivada
    : public Base
{
public:

    void mostrar()
        override
    {
        cout << "Derivada\n";
    }
};
```

---

# Plantilla 12 — Destructor Virtual

## Patrón

```cpp
class Persona
{
public:

    virtual ~Persona()
    {
        cout
            << "Destructor Persona\n";
    }
};

class Profesor
    : public Persona
{
public:

    ~Profesor()
    {
        cout
            << "Destructor Profesor\n";
    }
};
```

---

# Plantilla 13 — Arreglo Dinámico de Objetos

## Patrón

```cpp
int n;

cin >> n;

Empleado* empleados =
    new Empleado[n];

for(int i=0;i<n;i++)
{
    // leer datos
}

delete[] empleados;
```

---

# Plantilla 14 — Vector de Punteros Polimórficos

## Patrón

```cpp
#include <vector>

vector<Figura*> figuras;

figuras.push_back(
    new Rectangulo(4,5));

figuras.push_back(
    new Rectangulo(6,7));

for(auto figura : figuras)
{
    cout
        << figura->area()
        << endl;
}

for(auto figura : figuras)
{
    delete figura;
}
```

---

# Plantilla 15 — Framework Integral para Examen

## Esqueleto General

```cpp
class Entidad
{
public:

    virtual void mostrar() const = 0;

    virtual ~Entidad() = default;
};

class DerivadaA
    : public Entidad
{
public:

    void mostrar() const override
    {
        cout
            << "Derivada A\n";
    }
};

class DerivadaB
    : public Entidad
{
public:

    void mostrar() const override
    {
        cout
            << "Derivada B\n";
    }
};

int main()
{
    Entidad* lista[2];

    lista[0] =
        new DerivadaA();

    lista[1] =
        new DerivadaB();

    for(auto p : lista)
    {
        p->mostrar();
    }

    for(auto p : lista)
    {
        delete p;
    }

    return 0;
}
```

---

# Estrategia General para Resolver los 15 Problemas

1. Identificar entidades → clases.
2. Definir atributos privados.
3. Crear constructores adecuados.
4. Implementar destructores.
5. Utilizar `this` cuando exista ambigüedad.
6. Diseñar la jerarquía de herencia.
7. Declarar métodos virtuales.
8. Sobrescribir con `override`.
9. Utilizar punteros a clase base.
10. Liberar memoria correctamente.

---

# Buenas Prácticas C++20

- Preferir inicialización mediante listas de inicialización.
- Declarar destructores virtuales en clases base polimórficas.
- Utilizar `override`.
- Evitar fugas de memoria.
- Mantener encapsulamiento.
- Aplicar el principio de responsabilidad única.
