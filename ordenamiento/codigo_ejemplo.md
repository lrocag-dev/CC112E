# Framework de Solución — Semanas 2 y 3 — Ordenamiento y búsqueda

## Objetivo

Plantillas reutilizables para resolver los ejercicios de esta sesión. Las plantillas con C++20 están al final de la sección de plantillas.

---


# Plantilla 1 — Búsqueda lineal

```cpp
int buscar(const int *a, int n, int clave)
{
    for (int i = 0; i < n; i++)
        if (a[i] == clave) return i;
    return -1;
}
```

---

# Plantilla 2 — Burbuja con bandera

```cpp
void burbuja(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool cambio = false;
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1]) { swap(a[j], a[j + 1]); cambio = true; }
        if (!cambio) break;
    }
}
```

---

# Plantilla 3 — Selección e inserción

```cpp
void seleccion(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++) if (a[j] < a[k]) k = j;
        if (k != i) swap(a[i], a[k]);
    }
}

void insercion(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], j = i - 1;
        while (j >= 0 && a[j] > x) { a[j + 1] = a[j]; j--; }
        a[j + 1] = x;
    }
}
```

---

# Plantilla 4 — Búsqueda binaria

```cpp
int binaria(const int *a, int n, int clave)
{
    int ini = 0, fin = n - 1;
    while (ini <= fin)
    {
        int mid = ini + (fin - ini) / 2;
        if (a[mid] == clave) return mid;
        if (a[mid] < clave) ini = mid + 1; else fin = mid - 1;
    }
    return -1;
}
```

---

# Plantilla 5 — Merge sort

```cpp
void fusionar(int *a, int ini, int mid, int fin)
{
    int n1 = mid - ini + 1, n2 = fin - mid;
    int *L = new int[n1], *R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = a[ini + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = ini;
    while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    delete[] L; delete[] R;
}
void mergeSort(int *a, int ini, int fin)
{
    if (ini >= fin) return;
    int mid = ini + (fin - ini) / 2;
    mergeSort(a, ini, mid);
    mergeSort(a, mid + 1, fin);
    fusionar(a, ini, mid, fin);
}
```

---

# Plantilla 6 — Quick sort (Lomuto)

```cpp
int particion(int *a, int ini, int fin)
{
    int pivote = a[fin], i = ini - 1;
    for (int j = ini; j < fin; j++)
        if (a[j] <= pivote) swap(a[++i], a[j]);
    swap(a[i + 1], a[fin]);
    return i + 1;
}
void quickSort(int *a, int ini, int fin)
{
    if (ini >= fin) return;
    int p = particion(a, ini, fin);
    quickSort(a, ini, p - 1);
    quickSort(a, p + 1, fin);
}
```

---

# Plantilla 7 — Ordenar con un criterio recibido

```cpp
bool porNota(const Est &a, const Est &b) { return a.nota > b.nota; }

void ordenar(Est *v, int n, bool (*antes)(const Est &, const Est &))
{
    for (int i = 1; i < n; i++)
    {
        Est x = v[i];
        int j = i - 1;
        while (j >= 0 && antes(x, v[j])) { v[j + 1] = v[j]; j--; }
        v[j + 1] = x;
    }
}
```

---

# Plantillas C++20

```cpp
#include <algorithm>

ranges::sort(v);                                // ascendente
ranges::sort(v, ranges::greater{});             // descendente
ranges::sort(items, {}, &Item::campo);          // por un campo (proyeccion)
ranges::stable_sort(items, {}, &Item::grupo);   // estable
ranges::partial_sort(v, v.begin() + k);
ranges::nth_element(v, v.begin() + n / 2);
bool ok = ranges::is_sorted(v);

auto it = ranges::lower_bound(v, x);            // primer >= x
auto jt = ranges::upper_bound(v, x);            // primer > x
bool esta = ranges::binary_search(v, x);

struct P { int a, b; auto operator<=>(const P &) const = default; };

template <random_access_iterator It, typename Comp = ranges::less>
requires sortable<It, Comp>
void mi_orden(It ini, It fin, Comp comp = {});

constexpr auto ORD = burbuja(array<int, 5>{5, 3, 1, 4, 2});
static_assert(ranges::is_sorted(ORD));
```

---

# Resumen de complejidades

| Algoritmo | Mejor | Promedio | Peor | Memoria | Estable |
|---|---|---|---|---|---|
| Burbuja (con bandera) | O(n) | O(n²) | O(n²) | O(1) | Sí |
| Selección | O(n²) | O(n²) | O(n²) | O(1) | No |
| Inserción | O(n) | O(n²) | O(n²) | O(1) | Sí |
| Merge sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Sí |
| Quick sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Counting sort | O(n + k) | O(n + k) | O(n + k) | O(k) | Sí |
| Búsqueda lineal | O(1) | O(n) | O(n) | O(1) | — |
| Búsqueda binaria | O(1) | O(log n) | O(log n) | O(1) | — |

---

# Errores frecuentes

| Error | Consecuencia |
|---|---|
| Búsqueda binaria sobre un arreglo sin ordenar | Resultados incorrectos |
| `mid = (ini + fin) / 2` con valores grandes | Desbordamiento de entero |
| Usar `<` en lugar de `<=` al fusionar | Pierde la estabilidad |
| Ciclo interno `j < n - 1` en burbuja sin restar `i` | Comparaciones innecesarias |
| Pivote siempre en el extremo con datos ordenados | Quick sort O(n²) |
| Comparador que no es un orden estricto (`<=` en `sort`) | Comportamiento indefinido en `std::sort` |
