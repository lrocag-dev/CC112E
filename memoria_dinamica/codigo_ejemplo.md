# Framework de Solución — Semanas 9 y 11 — Memoria dinámica

## Objetivo

Plantillas reutilizables para resolver los ejercicios de esta sesión. Las plantillas con C++20 están al final de la sección de plantillas.

---


# Plantilla 1 — Variable y arreglo dinámicos

```cpp
int *p = new int(5);
delete p;
p = nullptr;

int n;
cin >> n;
double *v = new double[n]();      // () = inicializa en cero
for (int *q = v; q < v + n; q++) cin >> *q;
delete[] v;
v = nullptr;
```

---

# Plantilla 2 — Arreglo que crece

```cpp
void agregar(int *&datos, int &n, int &cap, int x)
{
    if (n == cap)
    {
        int nueva = cap * 2;
        int *nuevo = new int[nueva];
        for (int i = 0; i < n; i++) nuevo[i] = datos[i];
        delete[] datos;
        datos = nuevo;
        cap = nueva;
    }
    datos[n++] = x;
}
```

---

# Plantilla 3 — Matriz dinámica

```cpp
// arreglo de punteros
int **m = new int *[f];
for (int i = 0; i < f; i++) m[i] = new int[c]();
// ...
for (int i = 0; i < f; i++) delete[] m[i];
delete[] m;

// bloque contiguo
double *d = new double[f * c]();
d[i * c + j] = 1.0;
delete[] d;
```

---

# Plantilla 4 — Estructuras dinámicas

```cpp
Estudiante *v = new Estudiante[n];
(v + i)->nota = 15;
v[i].nota = 15;
Estudiante *copia = new Estudiante(v[0]);
delete copia;
delete[] v;
```

---

# Plantilla 5 — Lista enlazada

```cpp
struct Nodo { int dato; Nodo *sig; };

void insertarInicio(Nodo *&cab, int x) { cab = new Nodo{x, cab}; }

void liberar(Nodo *&cab)
{
    while (cab)
    {
        Nodo *sig = cab->sig;     // guardar ANTES de borrar
        delete cab;
        cab = sig;
    }
}
```

---

# Plantilla 6 — Clase que administra memoria (regla de los tres)

```cpp
class Buffer {
    int n; int *d;
public:
    explicit Buffer(int n) : n(n), d(new int[n]()) {}
    ~Buffer() { delete[] d; }
    Buffer(const Buffer &o) : n(o.n), d(new int[o.n]) { copy(o.d, o.d + n, d); }
    Buffer &operator=(const Buffer &o)
    {
        if (this != &o)
        {
            int *nuevo = new int[o.n];
            copy(o.d, o.d + o.n, nuevo);
            delete[] d;
            d = nuevo; n = o.n;
        }
        return *this;
    }
};
```

---

# Plantillas C++20 y modernas

```cpp
#include <memory>
#include <memory_resource>

auto a = make_unique<int[]>(n);                    // liberado automaticamente
auto b = make_unique_for_overwrite<double[]>(n);   // C++20: sin inicializar
auto s = make_shared<Clase>(args);
weak_ptr<Clase> w = s;                             // observa sin poseer
if (auto p = w.lock()) { /* sigue vivo */ }

vector<int> v;
v.reserve(100);
erase_if(v, [](int x){ return x % 2 == 0; });      // C++20

array<std::byte, 4096> buf;
pmr::monotonic_buffer_resource pool(buf.data(), buf.size());
pmr::vector<int> pv(&pool);

T *p = construct_at(memoria_cruda, args...);       // construir en memoria ya reservada
destroy_at(p);                                     // destruir sin liberar
```

---

# Errores frecuentes

| Error | Consecuencia |
|---|---|
| Olvidar `delete` / `delete[]` | Fuga de memoria |
| `delete` en lugar de `delete[]` | Comportamiento indefinido |
| Usar el puntero después de liberar | Puntero colgante |
| Liberar dos veces el mismo bloque | Corrupción del *heap* |
| Devolver la dirección de una variable local | Puntero colgante |
| Copiar una estructura con punteros sin copia profunda | Dos objetos comparten el bloque |
| Perder el único puntero antes de liberar | Fuga |
| Liberar `m` antes que las filas en `int **` | Fugas de todas las filas |
| Ciclos de `shared_ptr` | Fuga: usar `weak_ptr` |
