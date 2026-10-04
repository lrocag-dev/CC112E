# Framework de Solución — Semana 1 — Recursividad e iteración

## Objetivo

Plantillas reutilizables para resolver los ejercicios de esta sesión. Las plantillas con C++20 están al final de la sección de plantillas.

---


# Plantilla 1 — Estructura de una función recursiva

```cpp
Tipo f(parametros)
{
    if (caso_base)                 // 1. siempre primero
        return valor_directo;
    // 2. reducir el problema (el parametro DEBE acercarse al caso base)
    return combinar(f(parametros_menores));
}
```

Lista de verificación: ¿hay caso base?, ¿el problema se hace más pequeño?, ¿todos los caminos llegan al caso base?

---

# Plantilla 2 — Recursión sobre números y arreglos

```cpp
int suma(const int *a, int n)
{
    return n == 0 ? 0 : *a + suma(a + 1, n - 1);
}

long digitos(long n) { return n < 10 ? 1 : 1 + digitos(n / 10); }
```

---

# Plantilla 3 — Recursión de cola y su versión iterativa

```cpp
long invertir(long n, long acum = 0)       // recursion de cola
{
    return n == 0 ? acum : invertir(n / 10, acum * 10 + n % 10);
}

long invertirIter(long n)                  // equivalente iterativo
{
    long acum = 0;
    while (n != 0) { acum = acum * 10 + n % 10; n /= 10; }
    return acum;
}
```

---

# Plantilla 4 — Memoización

```cpp
unsigned long long memo[91];
bool conocido[91];

unsigned long long fib(int n)
{
    if (n < 2) return n;
    if (conocido[n]) return memo[n];
    conocido[n] = true;
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```

---

# Plantilla 5 — *Backtracking* (elegir, explorar, deshacer)

```cpp
void explorar(estado &e, int paso)
{
    if (es_solucion(e)) { registrar(e); return; }
    for (opcion : opciones(e, paso))
    {
        if (!es_valida(e, opcion)) continue;   // poda
        aplicar(e, opcion);                    // elegir
        explorar(e, paso + 1);                 // explorar
        deshacer(e, opcion);                   // deshacer
    }
}
```

---

# Plantilla 6 — Incluir / no incluir

```cpp
int contar(const int *a, int n, int objetivo)
{
    if (n == 0) return objetivo == 0;
    return contar(a + 1, n - 1, objetivo - a[0])   // incluir a[0]
         + contar(a + 1, n - 1, objetivo);         // no incluir
}
```

---

# Plantilla 7 — De recursión a pila explícita

```cpp
#include <stack>

stack<Estado> pila;
pila.push(inicial);
while (!pila.empty())
{
    Estado e = pila.top(); pila.pop();
    if (invalido(e)) continue;
    procesar(e);
    for (auto vecino : vecinos(e)) pila.push(vecino);
}
```

---

# Plantillas C++20

```cpp
// constexpr / consteval
constexpr unsigned long long fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }
static_assert(fact(10) == 3628800);
consteval int cuadrado(int x) { return x * x; }

// lambda recursiva
auto fact2 = [](auto self, int n) -> unsigned long long { return n <= 1 ? 1 : n * self(self, n - 1); };
fact2(fact2, 10);

// concepts
template <integral T> constexpr T mcd(T a, T b) { return b == 0 ? a : mcd(b, T(a % b)); }

// span: reducir el problema sin punteros ni n
int suma(span<const int> v) { return v.empty() ? 0 : v.front() + suma(v.subspan(1)); }

// <bit>
popcount(m);  has_single_bit(x);  bit_width(x);  bit_ceil(x);
```

---

# Errores frecuentes

| Error | Consecuencia |
|---|---|
| Olvidar el caso base | Recursión infinita y desbordamiento de pila |
| El parámetro no se acerca al caso base | Recursión infinita |
| Dos llamadas recursivas cuando basta una (potencia rápida) | Se pierde la mejora logarítmica |
| Fibonacci ingenuo con `n` grande | Tiempo exponencial: usar memoización o iteración |
| Olvidar *deshacer* en backtracking | Soluciones incorrectas o faltantes |
| Variables globales sin reiniciar entre llamadas | Resultados acumulados de ejecuciones anteriores |
| Recursión muy profunda (> ~10⁵ niveles) | Desbordamiento de pila: convertir a iteración |
