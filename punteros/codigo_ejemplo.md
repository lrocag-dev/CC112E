# Framework de Solución para Problemas de Punteros en C++20

## Objetivo

Plantillas reutilizables para resolver ejercicios de:

- Punteros y aritmética de punteros
- Arreglos como punteros
- Paso por referencia mediante punteros
- Arreglos de punteros y punteros a punteros
- `const`, `void *` y punteros a funciones
- Punteros inteligentes

---

# Plantilla 1 — Declaración y uso básico

```cpp
int x = 10;
int *p = &x;       // p guarda la direccion de x
*p = 20;           // modifica x
int *q = nullptr;  // puntero nulo: siempre inicializar
if (q != nullptr) { /* seguro desreferenciar */ }
```

---

# Plantilla 2 — Recorrido de arreglos con punteros

```cpp
// lectura / escritura
for (int *p = a; p < a + n; p++)
    cin >> *p;

// solo lectura
for (const int *p = a; p != a + n; ++p)
    cout << *p << " ";

// inverso
for (const int *p = a + n - 1; p >= a; --p)
    cout << *p << " ";

// posicion de un puntero dentro del arreglo
int pos = p - a;
```

---

# Plantilla 3 — Función que recibe un arreglo

```cpp
void procesar(int *a, int n);        // equivale a int a[]
void leer(const int *a, int n);      // no modifica los datos

// llamada
procesar(a, n);
procesar(a + 2, n - 2);              // sub-arreglo desde la posicion 2
```

Recuerde: dentro de la función `sizeof(a)` es el tamaño de un puntero, por eso **siempre** se pasa `n`.

---

# Plantilla 4 — Parámetros de salida

```cpp
void calcular(const int *a, int n, int *suma, double *promedio)
{
    *suma = 0;
    for (const int *p = a; p < a + n; p++)
        *suma += *p;
    *promedio = static_cast<double>(*suma) / n;
}

int s; double prom;
calcular(a, n, &s, &prom);
```

---

# Plantilla 5 — Puntero a puntero

```cpp
void buscar(int *a, int n, int clave, int **resultado)
{
    *resultado = nullptr;
    for (int *p = a; p < a + n; p++)
        if (*p == clave) { *resultado = p; return; }
}

int *r;
buscar(a, n, 7, &r);
if (r) cout << "Pos: " << r - a;
```

---

# Plantilla 6 — Reglas de `const`

```cpp
const int *p1;        // dato constante, puntero libre
int *const p2 = &x;   // puntero fijo, dato modificable
const int *const p3 = &x;
```

---

# Plantilla 7 — Puntero a función

```cpp
using Criterio = bool (*)(int, int);

bool asc(int a, int b) { return a < b; }
bool desc(int a, int b) { return a > b; }

void ordenar(int *a, int n, Criterio antes)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (!antes(*(a + j), *(a + j + 1)))
                swap(*(a + j), *(a + j + 1));
}
```

---

# Plantilla 8 — Punteros inteligentes

```cpp
#include <memory>

auto u = make_unique<Clase>(args);        // un solo dueño
auto v = move(u);                         // transferir propiedad
auto s = make_shared<Clase>(args);        // dueños compartidos
cout << s.use_count();
auto arr = make_unique<int[]>(n);         // arreglo dinamico
```

Prefiera estos tipos a `new`/`delete` manuales.

---

# Errores frecuentes

| Error | Consecuencia |
|---|---|
| Desreferenciar un puntero sin inicializar o `nullptr` | Comportamiento indefinido |
| Salirse del arreglo (`p < a + n` mal escrito) | Corrupción de memoria |
| Retornar la dirección de una variable local | Puntero colgante |
| Modificar `p` varias veces en una misma expresión (`*p++ + *p`) | Comportamiento indefinido |
| Usar `sizeof(a)` con `a` parámetro | Devuelve el tamaño del puntero |
