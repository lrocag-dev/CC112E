# Soluciones Conceptuales — C++20
## Punteros I y II (Semana 5)

Los programas completos están en la carpeta [`codigo/`](codigo/) (`solucion01.cpp` … `solucion15.cpp`). Compilar con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

---

# Problema 1 — Variables, direcciones y valores

## Idea de solución

Un puntero es una variable que guarda una dirección. `&` obtiene la dirección y `*` accede al contenido.

## Algoritmo

1. Declarar `int x` y `int *p = &x`.
2. Mostrar `x`, `&x`, `p`, `*p` y `&p`.
3. Asignar `*p = ...` y verificar el cambio en `x`.
4. Repetir con `double`.
5. Mostrar `sizeof`: todos los punteros miden lo mismo (8 bytes en 64 bits) aunque apunten a tipos distintos.

---

# Problema 2 — Intercambio con punteros

## Idea de solución

Las funciones reciben direcciones y modifican las variables del llamador desde `*a`, `*b`.

## Algoritmo

1. `intercambiar`: `aux = *a; *a = *b; *b = aux;`.
2. `rotar`: guardar `*a`, luego `*a = *b`, `*b = *c`, `*c = aux`.
3. Llamar con `&x, &y, &z`.

---

# Problema 3 — Aritmética de punteros

## Idea de solución

`p + 1` avanza `sizeof(*p)` bytes. Dos punteros al mismo arreglo se pueden comparar y restar; la resta da el número de elementos.

## Algoritmo

1. Recorrer `for (int *p = a; p < a + n; p++)` para leer.
2. Acumular la suma con un puntero `const`.
3. Recorrer desde `a + n - 1` hasta `a` con `--p`.
4. Cantidad de elementos: `(a + n - 1) - a + 1`.

---

# Problema 4 — Arreglo visto como puntero

## Idea de solución

El nombre de un arreglo decae a un puntero a su primer elemento; `a[i]` es azúcar sintáctico de `*(a+i)`. Como la suma es conmutativa, `i[a]` también es válido.

## Algoritmo

1. Mostrar las seis expresiones para cada `i`.
2. `sizeof(a)/sizeof(a[0])` da el número de elementos solo donde `a` es realmente un arreglo.
3. En un parámetro `int a[]` el compilador lo trata como `int *a`, por eso `sizeof(a)` es el tamaño de un puntero.
4. `a` no es un *l-value* modificable, `p` sí.

---

# Problema 5 — Invertir un arreglo

## Idea de solución

Dos punteros, uno al inicio y otro al final, intercambian valores y se acercan hasta cruzarse.

## Algoritmo

1. `ini = a`, `fin = a + n - 1`.
2. Mientras `ini < fin`: intercambiar `*ini` y `*fin`, `ini++`, `fin--`.

---

# Problema 6 — Máximo y mínimo

## Idea de solución

Una función solo puede retornar un valor; para devolver varios se pasan direcciones de salida.

## Algoritmo

1. Inicializar `*maximo = *minimo = *a` y posiciones en 0.
2. Recorrer desde 1 comparando `*(a+i)`.
3. Actualizar valor y posición cuando corresponda.
4. En `main` llamar con `&mx, &mn, &pmx, &pmn`.

---

# Problema 7 — Ordenamiento indirecto

## Idea de solución

Se ordena un arreglo auxiliar de punteros comparando los valores apuntados. Es útil cuando mover los datos es costoso o hay que conservar el orden original.

## Algoritmo

1. `ptr[i] = &datos[i]`.
2. Burbuja comparando `*ptr[j] > *ptr[j+1]` e intercambiando los **punteros**.
3. Imprimir `*ptr[i]` para ver el orden.
4. La posición original es `ptr[i] - datos`.

---

# Problema 8 — Puntero a puntero

## Idea de solución

Para que una función cambie **a dónde apunta** un puntero del llamador hay que pasarle la dirección de ese puntero (`int **`).

## Algoritmo

1. `*resultado = a`.
2. Recorrer; si `*p > **resultado`, `*resultado = p`.
3. En `main`, `*mayor = 0` modifica el arreglo.
4. `avanzar`: `*p += k` mueve el puntero original.

---

# Problema 9 — Punteros y `const`

## Idea de solución

Leer la declaración de derecha a izquierda: `const int *p` (puntero a constante), `int *const p` (puntero constante), `const int *const p` (ambos).

## Algoritmo

1. Declarar los tres tipos y comentar las asignaciones prohibidas.
2. `buscar` recorre con `const int *p`; retorna `p` si `*p == clave`, `nullptr` al final.
3. En `main`, si el resultado no es nulo, la posición es `r - a`.

---

# Problema 10 — Puntero a `void`

## Idea de solución

`void *` guarda cualquier dirección pero no se puede desreferenciar: hay que convertirlo (`static_cast`) al tipo real. Sirve para código genérico.

## Algoritmo

1. `imprimir`: `switch` sobre el `Tipo` y convertir a `const int *`, `const double *` o `const char *`.
2. `intercambiarGenerico`: convertir a `char *` y permutar `bytes` bytes.
3. Probar con `int` (`sizeof(int)`) y `double` (`sizeof(double)`).

---

# Problema 11 — Rotación de un arreglo

## Idea de solución

Rotar a la izquierda `k` posiciones equivale a invertir `[0,k)`, invertir `[k,n)` e invertir todo.

## Algoritmo

1. `k %= n`; si `k < 0` sumar `n`.
2. `invertir(a, a+k-1)`.
3. `invertir(a+k, a+n-1)`.
4. `invertir(a, a+n-1)`.

Complejidad: O(n) tiempo, O(1) memoria.

---

# Problema 12 — Punteros a funciones

## Idea de solución

El nombre de una función es su dirección. Un puntero a función permite elegir el comportamiento en tiempo de ejecución (callbacks).

## Algoritmo

1. `using Operacion = double (*)(double,double)`.
2. Arreglo `Operacion ops[]` y arreglo paralelo de símbolos; llamar `ops[i](x, y)`.
3. `ordenar` usa `antes(*(a+j), *(a+j+1))`; si no está en orden, intercambia.
4. `aplicar` hace `*p = f(*p)` para cada elemento.

---

# Problema 13 — Fusión e intersección

## Idea de solución

Con ambos arreglos ordenados, dos punteros avanzan en paralelo sin retroceder (técnica de *dos punteros*).

## Algoritmo

**Fusión**: mientras ambos tengan elementos copiar el menor y avanzar ese puntero; luego copiar el resto.

**Intersección**:
1. Si `*pa < *pb` avanzar `pa`; si `*pb < *pa` avanzar `pb`.
2. Si son iguales, guardar el valor salvo que ya sea el último guardado (evita repetidos), y avanzar ambos.
3. Retornar `ps - salida`.

---

# Problema 14 — Punteros inteligentes

## Idea de solución

RAII: el recurso se libera en el destructor del puntero inteligente. `unique_ptr` tiene un único dueño (solo movible); `shared_ptr` cuenta referencias y libera con la última.

## Algoritmo

1. `make_unique<Recurso>("A")`; `move` a otro `unique_ptr`; el original queda en `nullptr`.
2. `make_shared<Recurso>("B")`; copiar en un ámbito interno y observar `use_count()`.
3. Al salir de cada ámbito aparece el mensaje del destructor, sin `delete`.
4. `make_unique<int[]>(5)` se indexa con `[]` y libera con `delete[]` automáticamente.

---

# Problema 15 — Precedencia y punteros a arreglos

## Idea de solución

Los operadores postfijos (`[]`, `()`, `++` postfijo) tienen mayor precedencia que los prefijos (`*`, `&`, `++` prefijo).

| Expresión | Significado |
|---|---|
| `*p++` | usa `*p` y luego avanza `p` |
| `(*p)++` | incrementa el dato apuntado |
| `*++p` | avanza `p` y usa el nuevo `*p` |
| `++*p` | incrementa el dato apuntado y lo usa |
| `int *ap[3]` | arreglo de 3 punteros a `int` |
| `int (*fila)[4]` | puntero a un arreglo de 4 `int` |

## Algoritmo

1. Evaluar cada expresión en sentencias separadas (evita comportamiento indefinido por modificar `p` varias veces en una sentencia).
2. `m[i][j]` es `*(*(m+i)+j)`: `m+i` apunta a la fila `i`, `*(m+i)` es esa fila decaída a `int *`.
3. `fila++` avanza una fila completa (4 enteros).
4. `sizeof(ap)` = 3 punteros; `sizeof(fila)` = un puntero.

---

# Nivel C++20 — Programación moderna

Programas completos en [`codigo/`](codigo/) (`solucion16.cpp` … `solucion20.cpp`). Compilar con `g++ -std=c++20 -Wall -Wextra`.

---

# Problema 16 — `std::span`

## Idea de solución

Un `span<T>` es un par (puntero, tamaño) que no es dueño de los datos. Elimina el parámetro `n` y permite crear sub-vistas sin copiar.

## Algoritmo

1. `span<const int>` para solo lectura, `span<int>` para modificar.
2. Un arreglo se convierte automáticamente en `span`.
3. `first(k)`, `last(k)` y `subspan(pos, cnt)` devuelven nuevas vistas del mismo almacenamiento.
4. `invertir` intercambia `v[i]` con `v[size-1-i]` hasta la mitad.
5. `size_bytes() = size() * sizeof(int)`.

---

# Problema 17 — Algoritmos con rangos

## Idea de solución

Los algoritmos de `std::ranges` reciben el contenedor completo (sin `begin`/`end`) y aceptan **proyecciones**: una función que se aplica a cada elemento antes de comparar.

## Algoritmo

1. `ranges::sort(v)`, `ranges::sort(v, ranges::greater{})`.
2. `auto [mn, mx] = ranges::minmax(v)`.
3. `ranges::find` devuelve un iterador; la posición es `it - v.begin()`.
4. `ranges::rotate(v, v.begin() + k)` rota a la izquierda `k` posiciones.
5. `v | views::filter(pred)` es una vista perezosa: no copia nada.
6. `ranges::sort(p, {}, &Producto::precio)` ordena por el campo indicado.

---

# Problema 18 — `concepts`

## Idea de solución

Un *concept* es un predicado sobre tipos evaluado en compilación. Con él, la plantilla rechaza tipos inadecuados con un error legible y se evita perder el tipo como ocurre con `void *`.

## Algoritmo

1. `intercambiar<T>` funciona para cualquier `T` copiable.
2. `concept Numerico = integral<T> || floating_point<T>`.
3. `template <Numerico T> T suma(span<const T>)`.
4. `esPar(2.5)` falla: `double` no satisface `integral`.
5. `mayor` recorre con punteros y retorna `nullptr` si el span está vacío.

---

# Problema 19 — Punteros inteligentes avanzados

## Idea de solución

RAII: el destructor del puntero inteligente libera el recurso. Se puede personalizar *cómo* se libera mediante un eliminador.

## Algoritmo

1. `make_unique_for_overwrite<int[]>(n)` reserva sin inicializar.
2. `unique_ptr<FILE, decltype(cerrar)> f(fopen(...), cerrar)`: `cerrar` se invoca al salir del ámbito.
3. `Nodo` guarda `unique_ptr<Nodo> sig`; `insertarInicio` hace `nuevo->sig = move(cabeza); cabeza = move(nuevo);`.
4. `invertir` recorre moviendo cada nodo al frente de una lista `prev`.
5. Al destruirse `Lista` se libera toda la cadena (para listas muy largas la destrucción recursiva podría agotar la pila).

---

# Problema 20 — `constexpr` y `consteval`

## Idea de solución

`constexpr` permite ejecutar una función en compilación **o** en ejecución; `consteval` obliga a hacerlo en compilación. Pueden usar punteros y aritmética de punteros mientras no escapen del cálculo.

## Algoritmo

1. `sumaPtr` recorre `[ini, fin)` y retorna la suma; `static_assert(TOTAL == 31)`.
2. `tablaCuadrados()` es `consteval` y llena un `array`.
3. `buscar(span<const int>, clave)` retorna un puntero o `nullptr`.
4. La misma función se evalúa en compilación (`constexpr bool hay9`) y en ejecución con la entrada del usuario.
5. Resumen: `const` = no modificable; `constexpr` = conocido en compilación si es posible; `consteval` = obligatoriamente en compilación.
