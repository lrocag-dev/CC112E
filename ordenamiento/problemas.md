# Problemas de C++20
## Semanas 2 y 3 — Ordenamiento y búsqueda

Temas: búsqueda lineal y binaria, ordenamiento por burbuja, selección e inserción (semana 2), ordenamiento por mezcla y rápido (semana 3), análisis de comparaciones e intercambios, estabilidad, complejidad.

Los problemas 1 al 10 son de nivel básico/intermedio, del 11 al 15 de nivel avanzado, y del 16 al 20 usan características modernas de C++20 (el resto se resuelve con C++11). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior. Para detectar errores de memoria compile además con `-fsanitize=address,undefined -g`.

---

# Nivel básico / intermedio

---

# Problema 1 — Búsqueda lineal (semana 2)

## Requerimientos

- `buscar(a, n, clave, comparaciones)` devuelve la primera posición o `-1` y cuenta las comparaciones.
- `buscarTodas(a, n, clave, pos)` guarda todas las posiciones y devuelve la cantidad.
- Probar con un arreglo con elementos repetidos.

---

# Problema 2 — Ordenamiento burbuja (semana 2)

## Requerimientos

- Implementar burbuja con contadores de comparaciones e intercambios.
- Agregar la **bandera de optimización** que detiene el algoritmo si una pasada no hizo intercambios.
- Comparar el costo con y sin bandera para un arreglo desordenado y uno ya ordenado (15 contra 5 comparaciones para 6 elementos ordenados).

---

# Problema 3 — Ordenamiento por selección (semana 2)

## Requerimientos

- Ordenar de forma ascendente o descendente con un parámetro `bool`.
- Contar los intercambios (a lo sumo `n - 1`).
- Explicar por qué selección hace pocos intercambios pero muchas comparaciones aun si el arreglo está ordenado.

---

# Problema 4 — Ordenamiento por inserción (semana 2)

## Requerimientos

- Implementar inserción desplazando los mayores.
- Implementar `insertarOrdenado(a, n, x)` que inserte un valor en un arreglo ya ordenado manteniendo el orden.
- Explicar por qué inserción es muy eficiente con datos casi ordenados.

---

# Problema 5 — Búsqueda binaria (semana 3)

## Requerimientos

- Versión iterativa (con `mid = ini + (fin - ini) / 2`) que cuente los pasos, y versión recursiva.
- `primera(a, n, clave)`: primera aparición cuando hay repetidos (*lower bound*).
- Explicar por qué `ini + fin` puede desbordar y por qué el arreglo debe estar ordenado.
- Justificar que con un millón de elementos bastan 20 pasos.

---

# Problema 6 — Ordenamiento por mezcla (semana 3)

## Requerimientos

- `fusionar(a, ini, mid, fin)` que combine dos mitades ordenadas usando arreglos auxiliares.
- `mergeSort(a, ini, fin)` recursivo.
- Usar `<=` al comparar para que el ordenamiento sea **estable**.
- Probar con elementos repetidos.

---

# Problema 7 — Ordenamiento rápido (semana 3)

## Requerimientos

- `particion` de Lomuto con pivote en el último elemento y `quickSort` recursivo.
- Contar las comparaciones.
- Mostrar que para un arreglo **ya ordenado** de 9 elementos se hacen 36 comparaciones (peor caso O(n²)) y explicar por qué.

---

# Problema 8 — Ordenar estructuras con distintos criterios

## Requerimientos

- `struct Estudiante { char nombre[20]; int codigo; double nota; }`.
- Función `ordenar(v, n, criterio)` por inserción que reciba un **puntero a función** `bool (*antes)(const Estudiante&, const Estudiante&)`.
- Criterios: nota descendente, nombre (con `strcmp`) y código.
- Comprobar la estabilidad: quienes tienen la misma nota conservan su orden anterior.

---

# Problema 9 — Ordenar y buscar cadenas

## Requerimientos

- Ordenar 8 nombres alfabéticamente por inserción con `strcmp` y `strcpy`.
- Búsqueda binaria de un nombre en el arreglo ordenado usando `strcmp`.
- Informar la posición o que no existe.

---

# Problema 10 — Comparación experimental de algoritmos

## Requerimientos

- Para `n = 200` y tres tipos de entrada (aleatoria, ya ordenada, en orden inverso), medir **comparaciones / movimientos** de burbuja (con bandera), selección e inserción.
- Presentar una tabla y explicar cada fila: ¿cuál gana en cada caso?
- Usar `srand(42)` para que los resultados sean reproducibles.

---

# Nivel avanzado

---

# Problema 11 — Contar inversiones con merge sort

Una **inversión** es un par `(i, j)` con `i < j` y `a[i] > a[j]`.

## Requerimientos

- Versión de fuerza bruta O(n²).
- Versión O(n log n): cuando un elemento de la mitad derecha pasa antes que `mid - i + 1` elementos de la izquierda, se suman esas inversiones.
- Verificar que un arreglo en orden inverso de `n` elementos tiene `n(n-1)/2` inversiones.

---

# Problema 12 — Selección rápida (*quickselect*)

## Requerimientos

- Encontrar el `k`-ésimo menor elemento en O(n) promedio, particionando y explorando **solo un lado**.
- Calcular la mediana y el mayor con la misma función.
- Trabajar sobre copias para no alterar el arreglo original.

---

# Problema 13 — Búsqueda binaria sobre la respuesta

## Requerimientos

- Calcular la raíz cuadrada entera de `n` con búsqueda binaria sobre el rango `[0, n]`.
- Buscar un elemento en un arreglo ordenado y **rotado** (por ejemplo `15 18 22 30 2 5 8 11`) en O(log n).
- Hallar el índice de rotación (posición del mínimo).

---

# Problema 14 — Ordenamiento por conteo

## Requerimientos

- Implementar *counting sort* estable para enteros en `[0, k)` con acumulados y recorrido de atrás hacia adelante.
- Ordenar un arreglo por **frecuencia descendente** (empate: orden de primera aparición).
- Explicar cuándo conviene a pesar de no ser comparativo (O(n + k)).

---

# Problema 15 — Quicksort híbrido

## Requerimientos

- Elegir el pivote como **mediana de tres** (inicio, centro, fin).
- Para subarreglos de 8 elementos o menos, terminar con inserción.
- Comparar el número de comparaciones contra el quicksort simple con un arreglo aleatorio y uno ya ordenado de 2000 elementos (≈ 24 000 contra ≈ 22 000, y ≈ 2 000 000 contra ≈ 17 000).
- Verificar que el resultado queda ordenado.

---

# Nivel C++20 — Programación moderna

---

# Problema 16 — `std::ranges`: sort, stable_sort, partial_sort, nth_element (C++20)

## Requerimientos

- Ordenar un `vector<int>` de forma ascendente y descendente (`ranges::greater{}`).
- Obtener los 3 menores con `ranges::partial_sort` y la mediana con `ranges::nth_element` (compare con el problema 12).
- Ordenar un `vector<Alumno>` por nota descendente con `stable_sort` y luego por grupo, mostrando que la nota queda como criterio de desempate.
- Verificar con `ranges::is_sorted` y proyecciones.

---

# Problema 17 — Búsqueda binaria de la biblioteca estándar (C++20)

## Requerimientos

- `ranges::binary_search`, `lower_bound`, `upper_bound` y `equal_range` sobre un `span<const int>`.
- Contar las apariciones de un valor con `upper_bound - lower_bound`.
- Insertar un valor manteniendo el orden con `lower_bound` + `insert`.
- Buscar por un campo de un `struct` con **proyección** (`&Producto::id`).
- Buscar solo en un sub-rango con `subspan`.

---

# Problema 18 — Algoritmos genéricos con `concepts` (C++20)

## Requerimientos

- `template <random_access_iterator It, typename Comp = ranges::less> requires sortable<It, Comp> void insercion(It, It, Comp = {})`.
- `busquedaBinaria` genérica para iteradores `forward_iterator` (usa `distance` y `advance`).
- Probar con un arreglo, con `vector<string>`, con `ranges::greater{}` y con una lambda que ordene por longitud.
- Explicar por qué `insercion(list<int>...)` no compila.

---

# Problema 19 — Comparaciones con `<=>` (C++20)

## Requerimientos

- `struct Version` con `auto operator<=>(const Version &) const = default`.
- `struct Jugador` con un `operator<=>` propio: más puntos primero y, si empatan, menor tiempo.
- Ordenar con `ranges::sort` usando solo `<=>`, y comprobar con `ranges::is_sorted` y `ranges::min_element`.
- Usar `compare_three_way` y comparar cadenas y reales con `<=>`.

---

# Problema 20 — Ordenar y buscar en tiempo de compilación (C++20)

## Requerimientos

- Burbuja y búsqueda binaria `constexpr` sobre `std::array`.
- Verificar con `static_assert` que el arreglo resultante está ordenado y que la búsqueda halla las posiciones correctas.
- `ranges::sort` también es `constexpr` en C++20: ordenar un arreglo en forma descendente al compilar.
- Ordenar una tabla de palabras reservadas (`array<string_view, 6>`) en compilación y buscar con `ranges::binary_search` en ejecución.
