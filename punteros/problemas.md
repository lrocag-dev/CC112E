# Problemas de C++20
## Punteros I y II (Semana 5)

Temas: variables y memoria, puntero a un arreglo de una dimensión, aritmética de punteros, arreglo visto como puntero, paso de punteros como parámetro, arreglo de punteros, punteros a punteros, reglas de precedencia de `*`, `()` y `[]`, punteros a `void` y a `const`, paso de argumentos por referencia, punteros inteligentes.

Los problemas 1 al 10 son de nivel básico/intermedio y del 11 al 15 de nivel avanzado.

> **Restricción general:** salvo que se indique lo contrario, no use el operador `[]` para recorrer arreglos; use aritmética de punteros.

---

# Nivel básico / intermedio

---

# Problema 1 — Variables, direcciones y valores

Declare un `int`, un `double` y un puntero a cada uno.

## Requerimientos

- Mostrar el valor de la variable, su dirección (`&x`), el valor del puntero y el valor apuntado (`*p`).
- Mostrar también la dirección del propio puntero (`&p`).
- Modificar las variables únicamente a través de sus punteros.
- Mostrar `sizeof` de cada puntero y de cada tipo apuntado.

---

# Problema 2 — Intercambio con punteros

## Requerimientos

- Implementar `void intercambiar(int *a, int *b)`.
- Implementar `void rotar(int *a, int *b, int *c)` que haga `a ← b`, `b ← c`, `c ← a` (valor original de `a`).
- Leer tres enteros y mostrar el resultado de ambas operaciones.

---

# Problema 3 — Aritmética de punteros

Lea hasta 100 enteros en un arreglo.

## Requerimientos

- Leer, sumar y mostrar el promedio usando solo punteros.
- Mostrar los elementos en orden inverso con un puntero que decrece.
- Mostrar la cantidad de elementos usando la resta de punteros.

---

# Problema 4 — Arreglo visto como puntero

## Requerimientos

- Para un arreglo de 5 enteros mostrar `a[i]`, `*(a+i)`, `*(i+a)`, `i[a]`, `&a[i]` y `a+i` y comprobar que son equivalentes.
- Mostrar `sizeof(a)` en `main` y dentro de una función que reciba `int a[]`; explicar la diferencia.
- Explicar por qué `a++` es un error de compilación pero `p++` (con `int *p = a`) no lo es.

---

# Problema 5 — Invertir un arreglo

## Requerimientos

- Implementar `void invertir(int *ini, int *fin)` usando dos punteros que se acercan.
- No usar arreglos auxiliares.
- Leer `n` y los datos, e imprimir el arreglo invertido.

---

# Problema 6 — Máximo y mínimo (parámetros de salida)

## Requerimientos

- Implementar una función que reciba el arreglo y devuelva, mediante punteros, el máximo, el mínimo y sus posiciones:

```cpp
void extremos(const int *a, int n, int *maximo, int *minimo, int *posMax, int *posMin);
```

- Mostrar los cuatro resultados en `main`.

---

# Problema 7 — Arreglo de punteros: ordenamiento indirecto

## Requerimientos

- Dado un arreglo de 6 enteros, crear un arreglo de 6 punteros a sus elementos.
- Ordenar de forma ascendente **los punteros** (burbuja) sin mover los datos originales.
- Mostrar el arreglo original (sin cambios), el orden ascendente y la posición original de cada elemento (`ptr[i] - datos`).

---

# Problema 8 — Puntero a puntero

## Requerimientos

- Implementar `void apuntarAlMayor(int *a, int n, int **resultado)` que haga que `*resultado` apunte al mayor elemento.
- Usando ese puntero, anular el mayor elemento del arreglo original.
- Implementar `void avanzar(int **p, int k)` que desplace un puntero `k` posiciones y probarla con `int **pp = &p`.

---

# Problema 9 — Punteros y `const`

## Requerimientos

- Declarar y probar: `const int *p`, `int *const p` y `const int *const p`. Dejar comentadas las líneas que no compilan indicando por qué.
- Implementar `const int *buscar(const int *a, int n, int clave)` que devuelva un puntero al elemento hallado o `nullptr`.
- Informar la posición hallada (resta de punteros) o que no existe.

---

# Problema 10 — Puntero a `void`

## Requerimientos

- Implementar `void imprimir(const void *dato, Tipo t)` con `enum Tipo { ENTERO, REAL, CARACTER }` que haga el `static_cast` adecuado.
- Implementar `void intercambiarGenerico(void *a, void *b, size_t bytes)` que intercambie dos valores de cualquier tipo byte a byte.
- Probarla con `int` y `double`.

---

# Nivel avanzado

---

# Problema 11 — Rotación de un arreglo

## Requerimientos

- Implementar `void rotarIzquierda(int *a, int n, int k)` en tiempo O(n) y memoria adicional O(1).
- Pista: tres inversiones (primeros `k`, restantes `n-k` y todo el arreglo).
- Manejar `k > n` y `k` negativo (rotación a la derecha).

## Ejemplo

```
n = 5, k = 2
Entrada: 1 2 3 4 5
Salida : 3 4 5 1 2
```

---

# Problema 12 — Punteros a funciones

## Requerimientos

- Crear un arreglo de punteros a función `double (*)(double,double)` con suma, resta, producto y cociente (manejar la división por cero) y mostrar las cuatro operaciones entre dos números.
- Implementar `void ordenar(int *a, int n, bool (*antes)(int,int))` que ordene con el criterio que reciba (ascendente o descendente).
- Implementar `void aplicar(int *a, int n, int (*f)(int))` que transforme cada elemento.

---

# Problema 13 — Fusión e intersección con dos punteros

Dados dos arreglos **ordenados** ascendentemente.

## Requerimientos

- `int fusionar(const int *a, int na, const int *b, int nb, int *salida)` genera un arreglo ordenado con todos los elementos y devuelve su tamaño.
- `int interseccion(...)` genera los elementos comunes **sin repetidos**.
- Recorrer los arreglos solo con punteros, en una sola pasada (O(na + nb)).

---

# Problema 14 — Punteros inteligentes

## Requerimientos

- Crear una clase `Recurso` que muestre mensajes en su constructor y destructor.
- Con `unique_ptr`: crear un recurso con `make_unique`, transferir su propiedad con `std::move` y comprobar que el origen queda vacío.
- Con `shared_ptr`: mostrar cómo cambia `use_count()` al copiar y al salir de un ámbito.
- Usar `unique_ptr<int[]>` para un arreglo de 5 elementos.
- Verificar con los mensajes que ningún recurso se libera dos veces ni queda sin liberar, sin escribir `delete`.

---

# Problema 15 — Precedencia y punteros a arreglos

## Requerimientos

- Dado `int a[] = {10,20,30,40}` y `int *p = a`, predecir y luego comprobar el resultado de `*p++`, `(*p)++`, `*++p` y `++*p`.
- Con una matriz `int m[3][4]` demostrar que `m[1][2] == *(*(m+1)+2)`.
- Recorrer `m` con un `int (*fila)[4]` y mostrar la suma de cada fila.
- Crear un `int *ap[3]` que apunte a las filas y acceder con `ap[2][3]`.
- Explicar la diferencia entre `int *ap[3]` y `int (*fila)[4]` con ayuda de `sizeof`.

---

# Nivel C++20 — Programación moderna

Los problemas 1 al 15 se resuelven con C++11 o anterior. Los problemas 16 al 20 usan características de C++20 (y de C++14/17 que se consolidan en él). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior (o MSVC 19.29+). Verifique su compilador con `g++ --version`.

---

# Problema 16 — `std::span`: punteros con tamaño (C++20)

## Requerimientos

- Implementar `int suma(span<const int> v)` e `void invertir(span<int> v)` sin recibir `n` por separado.
- Llamarlas con un arreglo completo, con `span(a).first(3)`, `span(a).last(3)` y `span(a).subspan(2, 4)`.
- Comprobar que modificar un `span` modifica el arreglo original.
- Mostrar `size()`, `size_bytes()`, `front()` y `data()` de un subspan.

---

# Problema 17 — Algoritmos con rangos sobre arreglos (C++20)

## Requerimientos

- Con `std::ranges`: ordenar un arreglo ascendente y descendente (`ranges::greater{}`), obtener mínimo y máximo con `ranges::minmax`, buscar con `ranges::find`, invertir y rotar.
- Usar `views::filter` para mostrar solo los pares sin crear otro arreglo.
- Ordenar un arreglo de `struct Producto` por precio con una **proyección** (`&Producto::precio`).
- Calcular la posición de un iterador con `it - v.begin()`.

---

# Problema 18 — Plantillas con `concepts` en lugar de `void *` (C++20)

## Requerimientos

- Implementar `template <typename T> void intercambiar(T *a, T *b)`.
- Definir `concept Numerico = integral<T> || floating_point<T>` y funciones `suma` y `promedio` restringidas a ese concepto que reciban `span<const T>`.
- Definir `esPar` restringida a `integral` y `mayor` restringida a `totally_ordered`; esta última devuelve un puntero al mayor.
- Dejar comentadas las llamadas que **no** compilan y explicar el mensaje de error.
- Comparar con el problema 10 (`void *`): ¿qué ventajas aporta el sistema de tipos?

---

# Problema 19 — Punteros inteligentes avanzados (C++20)

## Requerimientos

- Crear un arreglo con `make_unique_for_overwrite<int[]>(n)`, llenarlo y observarlo mediante un `span`.
- Crear un `unique_ptr<FILE, decltype(cerrar)>` con un eliminador personalizado (lambda) que cierre el archivo y muestre un mensaje.
- Implementar una lista enlazada simple cuyos nodos sean `unique_ptr<Nodo>`: `insertarInicio`, `mostrar` e `invertir` (solo con `move`).
- Verificar que no hay `new`, `delete` ni fugas de memoria.

---

# Problema 20 — Punteros en tiempo de compilación: `constexpr` y `consteval` (C++20)

## Requerimientos

- Implementar `constexpr int sumaPtr(const int *ini, const int *fin)` y evaluarla en compilación sobre un `constexpr array<int, 8>`; verificar con `static_assert`.
- Implementar una función `consteval` que genere una tabla de cuadrados.
- Implementar una búsqueda `constexpr` con punteros y usarla tanto en compilación (`static_assert`) como en ejecución.
- Explicar la diferencia entre `const`, `constexpr` y `consteval`.
