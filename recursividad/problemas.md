# Problemas de C++20
## Semana 1 — Recursividad e iteración

Temas: funciones recursivas versus funciones iterativas, caso base y caso recursivo, pila de llamadas, recursión lineal y múltiple, memoización, retroceso (*backtracking*), eliminación de la recursión.

Los problemas 1 al 10 son de nivel básico/intermedio, del 11 al 15 de nivel avanzado, y del 16 al 20 usan características modernas de C++20 (el resto se resuelve con C++11). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior. Para detectar errores de memoria compile además con `-fsanitize=address,undefined -g`.

---

# Nivel básico / intermedio

---

# Problema 1 — Factorial recursivo e iterativo

## Requerimientos

- Implementar `factorialRec(n)` y `factorialIter(n)` con `unsigned long long`.
- Validar `0 <= n <= 20` (con 21 se desborda el tipo).
- Mostrar una tabla de factoriales de 0 a `n`.
- Identificar en el código el caso base y el caso recursivo.

---

# Problema 2 — Fibonacci: ingenuo, iterativo y memoizado

## Requerimientos

- Implementar las tres versiones y contar las llamadas de la ingenua y de la memoizada.
- Mostrar que `fib(25)` ingenuo realiza 242 785 llamadas y que la versión con memoria realiza menos de 50.
- Calcular `fib(90)` de forma iterativa.
- Explicar por qué la versión ingenua es de orden exponencial.

---

# Problema 3 — Dígitos de un número

## Requerimientos

- Funciones recursivas: cantidad de dígitos y suma de dígitos.
- Inversión de un número con una función recursiva de **cola** con acumulador.
- Versión iterativa de la suma de dígitos.
- Usar la inversión para decidir si un número es capicúa.

---

# Problema 4 — Potencia: lineal vs. exponenciación rápida

## Requerimientos

- `potenciaLineal(x, n)`: `x^n = x * x^(n-1)`.
- `potenciaRapida(x, n)`: `x^n = (x^(n/2))^2`, multiplicando por `x` si `n` es impar.
- Versión iterativa por exponenciación binaria.
- Comparar el número de llamadas para `3^13` (14 contra 5).

---

# Problema 5 — MCD y MCM (Euclides)

## Requerimientos

- `mcd(a, b) = mcd(b, a % b)` con caso base `b == 0`, en versión recursiva e iterativa.
- `mcm(a, b) = a / mcd(a, b) * b`.
- Simplificar una fracción `a/b`.

---

# Problema 6 — Arreglos con recursión

## Requerimientos

- Con un puntero y `n`: suma, máximo, búsqueda (retorna la posición o `-1`) e inversión de un arreglo.
- En cada llamada, el problema se reduce avanzando el puntero (`a + 1`) y disminuyendo `n`.
- No usar ciclos.

---

# Problema 7 — Cadenas con recursión

## Requerimientos

- `palindromo(s, ini, fin)` ignorando espacios, signos y mayúsculas.
- `invertirCadena(s, ini, fin)` in situ.
- `imprimirAlReves(s)` sin modificar la cadena (la impresión ocurre **después** de la llamada recursiva).

---

# Problema 8 — Conversión entre bases

## Requerimientos

- `string aBase(unsigned long n, int base)` recursiva para bases 2 a 16.
- `long deBase(const string &s, int base)` recursiva con acumulador.
- Versión iterativa para binario.
- Verificar con `255` en base 16 → `FF`.

---

# Problema 9 — El orden importa: patrones recursivos

## Requerimientos

- Mostrar con tres funciones distintas: `n..1`, `1..n` y `n..1 1..n`, cambiando solo la posición de la impresión respecto de la llamada recursiva.
- Dibujar un triángulo de asteriscos creciente y otro decreciente de `n` filas, con recursión.

---

# Problema 10 — Torres de Hanoi

## Requerimientos

- `hanoi(n, origen, destino, auxiliar)` que muestre cada movimiento.
- Contar los movimientos y verificar que son `2^n - 1`.
- Explicar la relación de recurrencia `T(n) = 2 T(n-1) + 1`.

---

# Nivel avanzado

---

# Problema 11 — Permutaciones (*backtracking*)

## Requerimientos

- Generar todas las permutaciones de una cadena de hasta 8 caracteres intercambiando elementos (elegir, explorar, deshacer).
- Variante que **no repita** permutaciones cuando la cadena tiene letras iguales (marcar los caracteres ya usados en cada posición).
- Mostrar el total.

---

# Problema 12 — Suma de subconjuntos

Dado un arreglo de enteros positivos y un objetivo.

## Requerimientos

- `existeSubconjunto`: ¿algún subconjunto suma el objetivo? (incluir / no incluir cada elemento).
- `contarSubconjuntos`: cuántos hay.
- `mostrar`: imprimir cada subconjunto solución.
- Explicar la complejidad O(2^n).

---

# Problema 13 — Problema de las N reinas

## Requerimientos

- Colocar `n` reinas en un tablero `n × n` sin que se ataquen (fila por fila, probando columnas).
- Función `seguro(f, c)` que verifique columna y diagonales.
- Mostrar la primera solución y el total de soluciones (para `n = 6` hay 4; para `n = 8`, 92).

---

# Problema 14 — Laberinto: recursión vs. pila explícita

## Requerimientos

- Representar un laberinto como matriz de `0` (libre) y `1` (pared).
- Buscar un camino de la esquina superior izquierda a la inferior derecha con recursión y retroceso, marcando el camino.
- Implementar una versión **iterativa** con `std::stack` que indique si existe un camino.
- Explicar la equivalencia entre la pila de llamadas y la pila explícita.

---

# Problema 15 — Paréntesis balanceados

## Requerimientos

- Generar todas las cadenas de `n` pares de paréntesis bien formadas con recursión (abrir si `abiertos < n`, cerrar si `cerrados < abiertos`).
- Verificar que el total coincide con el número de Catalan `C(n)` calculado recursivamente.
- Para `n = 3` deben ser 5 cadenas.

---

# Nivel C++20 — Programación moderna

---

# Problema 16 — Recursión en tiempo de compilación: `constexpr` y `consteval` (C++20)

## Requerimientos

- Declarar `factorial`, `fib` y `potencia` como `constexpr` y verificarlas con `static_assert`.
- Generar con una función `consteval` una tabla de factoriales de 0 a 20.
- Usar las mismas funciones en ejecución con datos del usuario.
- Explicar qué cambia entre `constexpr` y `consteval`, y por qué `fib(30)` ingenuo no cuesta nada en ejecución cuando se evalúa al compilar.

---

# Problema 17 — Lambdas recursivas y memoización (C++14/20)

## Requerimientos

- Escribir un factorial con una lambda genérica que reciba una referencia a sí misma (`auto self`).
- Escribir Fibonacci con `std::function` y memoización con `unordered_map`; contar las llamadas.
- Escribir una lambda *memoizadora* que envuelva cualquier función recursiva (ejemplo: tribonacci).
- Explicar por qué la lambda interna debe recibir `self` por **referencia** (si se copia, se copia también la caché).

---

# Problema 18 — Recursión genérica con `concepts` (C++20)

## Requerimientos

- `template <integral T> constexpr T mcd(T, T)` y `mcm`.
- `template <unsigned_integral T> constexpr int sumaDigitos(T)`.
- `concept Numerico` y `potencia` genérica para enteros y reales.
- Validar con `static_assert` y comparar con `std::gcd` y `std::lcm`.
- Dejar comentadas las llamadas que no compilan (`mcd(2.5, 1.5)`, `sumaDigitos(-5)`) y explicar el error.

---

# Problema 19 — Recursión con `std::span` (C++20)

## Requerimientos

- Reescribir suma, máximo e inversión de un arreglo reduciendo el problema con `subspan`, sin pasar `n`.
- Búsqueda binaria recursiva con `first(mid)` y `subspan(mid + 1)`, devolviendo el índice relativo al arreglo original.
- Palíndromo recursivo sobre `span<const char>`.
- Comparar con el problema 6.

---

# Problema 20 — Recursión vs. iteración con máscaras de bits (C++20)

## Requerimientos

- Generar los subconjuntos de `{a, b, c, d}` de forma recursiva (incluir/excluir) y de forma iterativa (cada número de 0 a `2^n - 1` es una máscara).
- Usar `<bit>`: `popcount` para filtrar subconjuntos de tamaño 2, `has_single_bit`, `bit_width` y `bit_ceil`.
- Mostrar las máscaras en binario con `format("{:04b}")`.
- Comparar las dos soluciones: ¿cuál es más legible?, ¿cuál evita la pila de llamadas?
