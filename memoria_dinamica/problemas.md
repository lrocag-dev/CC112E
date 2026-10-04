# Problemas de C++20
## Semanas 9 y 11 — Memoria dinámica

Temas: el área de memoria dinámica (*heap*), operadores `new` y `delete`, arreglos dinámicos de una y varias dimensiones, estructuras y memoria dinámica, copia superficial y profunda, fugas y errores comunes, listas enlazadas, pilas y colas, punteros inteligentes y herramientas modernas.

Los problemas 1 al 10 son de nivel básico/intermedio, del 11 al 15 de nivel avanzado, y del 16 al 20 usan características modernas de C++20 (el resto se resuelve con C++11). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior. Para detectar errores de memoria compile además con `-fsanitize=address,undefined -g`.

---

# Nivel básico / intermedio

---

# Problema 1 — `new` y `delete` (semana 9)

## Requerimientos

- Reservar un `int` con `new int(25)`, mostrar su valor y su dirección, modificarlo y liberarlo con `delete`.
- Reservar un arreglo de `double` cuyo tamaño `n` se lee del teclado, calcular el promedio y liberarlo con `delete[]`.
- Asignar `nullptr` tras liberar cada puntero.

---

# Problema 2 — Arreglo dinámico de enteros

## Requerimientos

- Validar `n > 0`, reservar con `new int[n]()` (inicializado en cero), leer los datos y mostrarlos.
- Funciones `leer(a, n)` y `maxMin(a, n, mx, mn)`.
- Liberar con `delete[]`. Explicar por qué `delete a` sería incorrecto.

---

# Problema 3 — Arreglo que crece

## Requerimientos

- `struct ArregloDinamico { int *datos; int tamano; int capacidad; }` con `iniciar`, `agregar` y `liberar`.
- Cuando el arreglo se llena, **duplicar** la capacidad: reservar uno nuevo, copiar, liberar el anterior.
- Leer enteros hasta que el usuario ingrese 0 y mostrar tamaño y capacidad finales.
- Explicar por qué duplicar (y no sumar 1) hace que agregar sea O(1) amortizado.

---

# Problema 4 — Funciones que devuelven memoria dinámica

## Requerimientos

- `int *rango(int ini, int fin, int &n)` que devuelva `ini, ini+1, ..., fin`.
- `int *filtrarPares(const int *a, int n, int &cantidad)` que devuelva solo los pares.
- Documentar quién es responsable de liberar la memoria (el **llamador**).
- Dejar comentada una función que devuelva la dirección de un arreglo **local** y explicar el error.

---

# Problema 5 — Matriz dinámica con `int **`

## Requerimientos

- `crearMatriz(f, c)`, `liberarMatriz(m, f)` y `transpuesta(m, f, c)`.
- Llenar la matriz, mostrarla y calcular la suma de cada fila.
- Liberar primero cada fila y después el arreglo de punteros.

---

# Problema 6 — Matriz en un bloque contiguo

## Requerimientos

- `struct Matriz { int filas, columnas; double *datos; }` con acceso `datos[i * columnas + j]`.
- Función `en(m, i, j)` que devuelva una referencia, y `multiplicar(a, b)`.
- Probar con matrices 2×3 por 3×2.
- Comparar con el problema 5: una sola reserva, una sola liberación, mejor localidad de caché.

---

# Problema 7 — Matriz irregular: triángulo de Pascal

## Requerimientos

- Reservar `n` filas donde la fila `i` tiene `i + 1` elementos.
- Llenar con `t[i][j] = t[i-1][j-1] + t[i-1][j]`.
- Mostrar el triángulo y la cantidad de elementos almacenados frente a los de una matriz cuadrada (15 contra 25 para `n = 5`).
- Liberar correctamente.

---

# Problema 8 — Arreglo dinámico de estructuras

## Requerimientos

- `struct Estudiante { char nombre[30]; int codigo; double nota; }`.
- Reservar `n` estudiantes con `new Estudiante[n]`, leerlos con una función que reciba un puntero y use `->`.
- Ordenar por nota descendente con aritmética de punteros.
- Crear una copia del mejor con `new Estudiante(*v)` y liberarla.

---

# Problema 9 — Copia superficial y profunda

## Requerimientos

- `struct Texto { char *datos; int longitud; }` con `crear`, `copiaSuperficial`, `copiaProfunda` y `concatenar`.
- Modificar el original y mostrar que la copia superficial **cambia** y la profunda **no**.
- Explicar por qué liberar ambas copias superficiales provocaría una doble liberación.

---

# Problema 10 — Errores de memoria y su prevención

## Requerimientos

- Documentar en comentarios los 5 errores clásicos: fuga, doble liberación, uso tras liberar, mezclar `new[]` con `delete` y salirse del bloque.
- Demostrar que `delete` sobre `nullptr` es seguro.
- Capturar `bad_alloc` al pedir una cantidad imposible de memoria y mostrar la alternativa `new (nothrow)`.
- Indicar cómo detectar estos errores con `-fsanitize=address`.

---

# Nivel avanzado

---

# Problema 11 — Lista enlazada simple (semana 11)

## Requerimientos

- `struct Nodo { int dato; Nodo *sig; }` con `insertarInicio`, `insertarFinal`, `eliminar(x)`, `invertir`, `mostrar` y `liberar`.
- Eliminar mediante un puntero al enlace (`Nodo **pp`) para tratar igual la cabeza y los demás nodos.
- Invertir la lista cambiando enlaces, sin crear nodos nuevos.
- Verificar que se liberan todos los nodos.

---

# Problema 12 — Pila y cola con arreglos dinámicos

## Requerimientos

- Clase `PilaDinamica` que duplique su capacidad al llenarse, con destructor y copia eliminada.
- Clase `ColaCircular` de capacidad fija con índices módulo `capacidad`.
- Aplicar la pila para verificar si una cadena con `()[]{}` está **balanceada**.
- Explicar por qué se prohíbe la copia de estas clases (`= delete`).

---

# Problema 13 — Matriz dispersa

## Requerimientos

- Guardar solo los elementos distintos de cero: `struct Elemento { int fila, col; double valor; }` en un arreglo dinámico.
- Construirla desde una matriz densa, calcular su transpuesta y la **suma de dos dispersas** fusionando los elementos ordenados por (fila, columna).
- Comparar la memoria usada con la de la matriz densa.
- Eliminar de la suma los resultados que se anulan (valor 0).

---

# Problema 14 — Clase Matriz con la regla de los tres

## Requerimientos

- Clase `Matriz` con arreglo dinámico contiguo, destructor, constructor de copia (copia profunda) y asignación segura ante la autoasignación.
- Operadores `operator()(i, j)`, `operator*` y método `transpuesta()`.
- Sobrecargar `operator<<`.
- Probar copia, asignación y `c = c`.

---

# Problema 15 — Estructuras anidadas con memoria dinámica

## Requerimientos

- `Estudiante { char *nombre; double *notas; int numNotas; }` y `Curso { char *nombre; Estudiante *estudiantes; int cantidad; }`.
- Funciones `crearEstudiante`, `crearCurso`, `promedio` y `liberarCurso`.
- Mostrar el promedio de cada estudiante y el mejor.
- Liberar de adentro hacia afuera: nombre y notas de cada estudiante, luego el arreglo de estudiantes y finalmente el nombre del curso.

---

# Nivel C++20 — Programación moderna

---

# Problema 16 — `unique_ptr` para arreglos y matrices (C++14/20)

## Requerimientos

- Crear un arreglo con `make_unique<int[]>(n)` y otro con `make_unique_for_overwrite<double[]>(n)` (C++20, sin inicializar).
- Transferir la propiedad con `move` y comprobar que el origen queda nulo.
- Implementar una clase `Matriz` con `unique_ptr<unique_ptr<int[]>[]>` cuyas filas se liberan solas.
- Guardar arreglos de distinto tamaño en un `vector<unique_ptr<int[]>>`.
- Verificar que el programa no contiene `new` ni `delete`.

---

# Problema 17 — `vector`, `span` y `erase_if` (C++20)

## Requerimientos

- Mostrar cómo crece la capacidad de un `vector` al hacer `push_back` (1, 2, 4, 8, ...), y el efecto de `reserve` y `shrink_to_fit`.
- Eliminar elementos con `erase_if` y `erase` (C++20) y mostrar cuántos se eliminaron.
- Matriz irregular con `vector<vector<int>>`.
- Matriz contigua con un solo `vector<int>` que exponga cada fila como un `span<int>` y use `ranges::reverse` sobre una fila.

---

# Problema 18 — Recursos de memoria polimórficos: `std::pmr` (C++17/20)

## Requerimientos

- Crear un `pmr::monotonic_buffer_resource` sobre un `array<byte, 4096>` de la pila, con `null_memory_resource` como respaldo, y un `pmr::vector<int>` que lo use.
- Implementar un recurso propio (`RecursoVerbose`) que cuente reservas y liberaciones.
- Comparar cuántas reservas hace un `vector` normal para 1000 elementos con las de una *arena* compartida por dos vectores.
- Mostrar que un buffer demasiado pequeño con `null_memory_resource` lanza `bad_alloc`.

---

# Problema 19 — `construct_at` y `destroy_at`: separar memoria y objetos (C++20)

## Requerimientos

- Implementar `template <typename T> class MiVector` con memoria cruda obtenida con `operator new` alineado.
- Construir cada elemento con `construct_at` (`emplace_back`) y destruirlo con `destroy_at` (`pop_back`) y `destroy` (destructor).
- Al reubicar (crecer), mover cada elemento a la nueva memoria y destruir el original.
- Usar una clase `Dato` que imprima mensajes en su constructor y destructor para comprobar que cada objeto se construye y destruye exactamente una vez.

---

# Problema 20 — `shared_ptr` y `weak_ptr`: listas sin fugas (C++11/20)

## Requerimientos

- Lista doblemente enlazada con `shared_ptr<Nodo> sig` y `weak_ptr<Nodo> ant`; recorrerla en ambos sentidos con `lock()`.
- Demostrar con `use_count` y mensajes en el destructor que todos los nodos se liberan.
- Demostrar el **ciclo** de dos `shared_ptr` que se apuntan entre sí: ninguno se libera (fuga). Comprobarlo con `-fsanitize=address`.
- Mostrar `weak_ptr::expired()` y `lock()` para observar un objeto sin poseerlo.
