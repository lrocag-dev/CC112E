# Soluciones Conceptuales — C++20
## Semana 1 — Recursividad e iteración

Los programas completos están en la carpeta [`codigo/`](codigo/) (`solucion01.cpp` … `solucion20.cpp`). Compilar con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

---

# Problema 1 — Factorial

## Idea de solución

Una función recursiva se define con un **caso base** (se resuelve directo) y un **caso recursivo** (se reduce a un problema más pequeño): `n! = n · (n-1)!`, `0! = 1`.

## Algoritmo

1. Caso base: `n <= 1` retorna 1.
2. Caso recursivo: `n * factorialRec(n - 1)`.
3. Iterativa: `r = 1; for i = 2..n: r *= i`.
4. `20! = 2 432 902 008 176 640 000` es el mayor que cabe en 64 bits.

---

# Problema 2 — Fibonacci

## Idea de solución

`fib(n) = fib(n-1) + fib(n-2)` recalcula los mismos valores muchas veces: el número de llamadas crece como `φ^n`. La **memoización** guarda cada resultado en un arreglo la primera vez que se calcula.

## Algoritmo

1. Ingenua: dos llamadas por cada una (exponencial).
2. Iterativa: dos variables `a`, `b` que avanzan `n` veces (lineal, memoria constante).
3. Memoizada: `if (conocido[n]) return memo[n];` — cada valor se calcula una sola vez (lineal).
4. `fib(90)` es el mayor que cabe en `unsigned long long`.

---

# Problema 3 — Dígitos de un número

## Idea de solución

Dividir entre 10 elimina el último dígito; `n % 10` lo obtiene.

## Algoritmo

1. Cantidad: `n < 10 ? 1 : 1 + cantidad(n / 10)`.
2. Suma: `n % 10 + suma(n / 10)`.
3. Inversión con acumulador: `invertir(n / 10, acum * 10 + n % 10)`; cuando `n == 0` retorna `acum`. Al ser lo último que hace la función, es recursión de cola.
4. Capicúa: `n == invertir(n)`.

---

# Problema 4 — Potencia

## Idea de solución

`x^n = (x^(n/2))²` reduce el exponente a la mitad: O(log n) en lugar de O(n).

## Algoritmo

1. Caso base `n == 0` retorna 1.
2. `mitad = potenciaRapida(x, n / 2)`; si `n` es par, `mitad * mitad`; si es impar, `mitad * mitad * x`.
3. Importante: calcular `mitad` **una sola vez** (si se llamara dos veces volvería a ser lineal).
4. Iterativa: recorrer los bits de `n`; si el bit es 1, `r *= x`; luego `x *= x`.

---

# Problema 5 — MCD y MCM

## Idea de solución

`mcd(a, b) = mcd(b, a mod b)` porque ambos tienen los mismos divisores comunes.

## Algoritmo

1. Caso base: `b == 0` → `a`.
2. Iterativa: mientras `b != 0`, `r = a % b; a = b; b = r`.
3. `mcm = a / mcd * b` (dividir primero evita desbordamiento).
4. Fracción simplificada: dividir numerador y denominador por el MCD.

---

# Problema 6 — Arreglos con recursión

## Idea de solución

Se procesa el primer elemento y se delega el resto: `a + 1` con `n - 1` elementos.

## Algoritmo

1. Suma: `n == 0 ? 0 : *a + suma(a+1, n-1)`.
2. Máximo: caso base `n == 1`; luego compara `*a` con el máximo del resto.
3. Búsqueda: si `*a == clave` retorna 0; si el resto devuelve `-1`, retorna `-1`; si no, `1 + posición`.
4. Inversión: intercambia los extremos y recurre sobre `a + 1` con `n - 2` elementos; caso base `n < 2`.

---

# Problema 7 — Cadenas con recursión

## Idea de solución

Se comparan o intercambian los extremos y se recurre sobre el interior. Para imprimir al revés, la impresión se hace al **regresar** de la llamada.

## Algoritmo

1. Palíndromo: saltar no alfanuméricos en ambos extremos; si `ini >= fin` retorna `true`; si los extremos difieren, `false`; si no, recurre con `ini+1`, `fin-1`.
2. `invertirCadena`: intercambia `s[ini]` y `s[fin]`; recurre.
3. `imprimirAlReves(s)`: `if (*s == '\0') return; imprimirAlReves(s+1); cout << *s;`.

---

# Problema 8 — Conversión entre bases

## Idea de solución

El último dígito en base `b` es `n % b`; el resto del número es `n / b`.

## Algoritmo

1. Caso base: `n < base` → el dígito `DIG[n]`.
2. Recursivo: `aBase(n / base, base) + DIG[n % base]` (primero lo más significativo).
3. `deBase`: `acum = acum * base + valor(c)` para cada carácter.
4. Iterativa: dividir sucesivamente e insertar al inicio.

---

# Problema 9 — El orden importa

## Idea de solución

Lo que se ejecuta **antes** de la llamada ocurre en el orden de entrada (n, n−1, …); lo que se ejecuta **después** ocurre al regresar (1, 2, …, n).

## Algoritmo

1. `descendente`: imprimir `n` y luego recurrir con `n-1`.
2. `ascendente`: recurrir con `n-1` y luego imprimir `n`.
3. `ambos`: imprimir antes y después de la llamada.
4. `triangulo(n)`: recurrir primero con `n-1`, luego imprimir una fila de `n` asteriscos (filas crecientes); el invertido imprime primero.

---

# Problema 10 — Torres de Hanoi

## Idea de solución

Para mover `n` discos de A a C: mover `n-1` a B, mover el mayor a C, mover `n-1` de B a C.

## Algoritmo

1. Caso base `n == 0`: no hace nada.
2. `hanoi(n-1, origen, auxiliar, destino)`.
3. Mover el disco `n` de `origen` a `destino` y contar.
4. `hanoi(n-1, auxiliar, destino, origen)`.
5. `T(n) = 2T(n-1) + 1` ⇒ `T(n) = 2^n − 1`.

---

# Problema 11 — Permutaciones

## Idea de solución

*Backtracking*: elegir un elemento para la posición `k`, explorar el resto y **deshacer** la elección.

## Algoritmo

1. Si `k == n-1`, imprimir la permutación.
2. Para `i = k..n-1`: `swap(s[k], s[i])`, `permutar(k+1)`, `swap(s[k], s[i])`.
3. Sin repetidos: `usado[256]` por nivel; si el carácter ya se usó en esa posición, saltar.
4. Total: `n!` (o `n!/(r1! r2! ...)` sin repetidos).

---

# Problema 12 — Suma de subconjuntos

## Idea de solución

Para cada elemento hay dos opciones: incluirlo (el objetivo disminuye) o no. Se explora un árbol binario de decisiones.

## Algoritmo

1. Caso base éxito: `objetivo == 0`.
2. Caso base fracaso: sin elementos o `objetivo < 0`.
3. `existe` = incluir **o** no incluir; `contar` = incluir **+** no incluir.
4. `mostrar`: guardar en `elegidos[k]` al incluir y imprimir al llegar a `objetivo == 0`.

---

# Problema 13 — N reinas

## Idea de solución

Una reina por fila; se prueban las columnas y se retrocede cuando no hay columna segura.

## Algoritmo

1. `col[f]` guarda la columna de la reina de la fila `f`.
2. `seguro(f, c)`: para cada fila anterior `i`, rechazar si `col[i] == c` o `|col[i] - c| == f - i`.
3. `resolver(f)`: si `f == n`, solución; si no, para cada columna segura, colocar y recurrir con `f+1`.
4. Contar soluciones (`n = 6` → 4, `n = 8` → 92).

---

# Problema 14 — Laberinto

## Idea de solución

Probar los cuatro movimientos desde la celda actual, marcándola; si ninguno conduce a la salida, **desmarcar** y retroceder.

## Algoritmo

1. Rechazar celdas fuera de rango, paredes o ya visitadas.
2. Marcar `*`; si es la salida, éxito.
3. Probar abajo, derecha, arriba, izquierda; el primero que tenga éxito propaga `true`.
4. Si ninguno funciona, marcar `.` (explorada) y retornar `false`.
5. Iterativa: pila con la celda inicial; sacar, validar, marcar visitada y apilar los cuatro vecinos. La pila explícita reemplaza a la pila de llamadas.

---

# Problema 15 — Paréntesis balanceados

## Idea de solución

Una cadena es válida si en ningún prefijo hay más cierres que aperturas y al final hay `n` de cada uno.

## Algoritmo

1. Si `pos == 2n`, imprimir.
2. Si `abiertos < n`, colocar `(` y recurrir.
3. Si `cerrados < abiertos`, colocar `)` y recurrir.
4. Número de Catalan: `C(0) = 1`, `C(n) = Σ C(i)·C(n-1-i)`.

---

# Problema 16 — `constexpr` y `consteval`

## Idea de solución

Una función `constexpr` puede ejecutarse en compilación **o** en ejecución según el contexto; `consteval` obliga a hacerlo en compilación. Incluso las funciones recursivas pueden evaluarse al compilar.

## Algoritmo

1. Marcar `factorial`, `fib`, `potencia` como `constexpr`.
2. `static_assert(fib(20) == 6765)` verifica en compilación.
3. `consteval array<ull,21> tablaFactorial()` llena la tabla con un ciclo; `constexpr auto TABLA = tablaFactorial();`.
4. `constexpr ull f30 = fib(30);` fuerza el cálculo al compilar: en ejecución solo se lee la constante.
5. El compilador limita la profundidad y el número de operaciones evaluadas; una recursión desmedida produce un error de compilación.

---

# Problema 17 — Lambdas recursivas y memoización

## Idea de solución

Una lambda no puede nombrarse a sí misma; se le pasa como parámetro (`auto self`) o se guarda en un `std::function`.

## Algoritmo

1. `auto fact = [](auto self, int n) -> ull { return n <= 1 ? 1 : n * self(self, n-1); };` y se llama `fact(fact, 10)`.
2. Con `function<ull(int)> fib` y un `unordered_map` de resultados: `fib(80)` en 159 llamadas.
3. `memoizar(f)` devuelve una lambda `mutable` con su propia caché; `f` recibe `self` para que las llamadas recursivas también pasen por la caché.
4. `self` se declara `auto &`: si se copiara, cada llamada duplicaría la caché y se perdería la memoización (el programa se vuelve exponencial).

---

# Problema 18 — Recursión genérica con `concepts`

## Idea de solución

Las restricciones de plantilla documentan y verifican los tipos aceptados por la función recursiva.

## Algoritmo

1. `mcd` restringida a `integral`: `b == 0 ? |a| : mcd(b, a % b)`.
2. `sumaDigitos` restringida a `unsigned_integral` (evita el problema de los negativos).
3. `Numerico = integral<T> || floating_point<T>`; `potencia` rápida funciona con `int` y `double`.
4. `static_assert(mcd(48L, 180L) == gcd(48L, 180L))` valida contra la biblioteca estándar.
5. `mcd(2.5, 1.5)` falla: `double` no satisface `integral`.

---

# Problema 19 — Recursión con `span`

## Idea de solución

`subspan` produce una vista más corta del mismo arreglo, sin copiar: es el equivalente seguro de `a + 1` y `n - 1`.

## Algoritmo

1. Suma: `v.empty() ? 0 : v.front() + suma(v.subspan(1))`.
2. Inversión: `swap(v.front(), v.back()); invertir(v.subspan(1, v.size() - 2));`.
3. Binaria: `mid = size/2`; si `clave < v[mid]`, `v.first(mid)`; si no, `v.subspan(mid+1)` y se acumula el desplazamiento para informar el índice original.
4. Palíndromo: `front == back && esPalindromo(subspan(1, size-2))`.

---

# Problema 20 — Subconjuntos: recursión vs. máscaras de bits

## Idea de solución

Un subconjunto de `n` elementos equivale a un número de `n` bits (bit `i` = el elemento `i` está en el subconjunto). Recorrer `0 .. 2^n − 1` genera todos sin recursión.

## Algoritmo

1. Recursiva: en cada elemento, excluir (recurre) o incluir (`push_back`, recurre, `pop_back`).
2. Iterativa: `for mascara in [0, 1<<n)`; incluir `v[i]` si `mascara >> i & 1`.
3. `popcount(m) == 2` selecciona subconjuntos de tamaño 2.
4. `has_single_bit(x)` indica potencia de 2; `bit_width(x)` los bits necesarios; `bit_ceil(100) = 128`.
5. La versión iterativa no usa pila de llamadas, pero está limitada a `n` ≤ bits del tipo.
