# Soluciones Conceptuales — C++20
## Semanas 2 y 3 — Ordenamiento y búsqueda

Los programas completos están en la carpeta [`codigo/`](codigo/) (`solucion01.cpp` … `solucion20.cpp`). Compilar con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

---

# Problema 1 — Búsqueda lineal

## Idea de solución

Se recorre el arreglo comparando cada elemento con la clave. Complejidad O(n); no requiere orden.

## Algoritmo

1. Para `i = 0..n-1`: contar comparación; si `a[i] == clave`, retornar `i`.
2. Si termina el ciclo, retornar `-1`.
3. Para todas las apariciones: no retornar, guardar `i` en `pos[k++]`.

---

# Problema 2 — Burbuja

## Idea de solución

Cada pasada lleva el mayor de los restantes hasta su posición final comparando pares adyacentes. Si una pasada completa no intercambia nada, el arreglo ya está ordenado.

## Algoritmo

1. Para `i = 0..n-2`: `huboCambio = false`.
2. Para `j = 0..n-2-i`: si `a[j] > a[j+1]`, intercambiar y marcar.
3. Si `!huboCambio`, `break`.
4. Sin bandera siempre hace `n(n-1)/2` comparaciones; con bandera, un arreglo ordenado necesita solo `n-1`.

---

# Problema 3 — Selección

## Idea de solución

En cada paso se ubica el menor (o el mayor) del tramo no ordenado y se coloca en su lugar con **un** intercambio.

## Algoritmo

1. Para `i = 0..n-2`: `k = i`.
2. Para `j = i+1..n-1`: si `a[j] < a[k]` (o `>` para descendente), `k = j`.
3. Si `k != i`, intercambiar y contar.
4. Siempre hace `n(n-1)/2` comparaciones, sin importar el orden inicial; a lo sumo `n-1` intercambios. No es estable.

---

# Problema 4 — Inserción

## Idea de solución

Se mantiene un prefijo ordenado y cada elemento nuevo se inserta desplazando los mayores una posición.

## Algoritmo

1. Para `i = 1..n-1`: `x = a[i]`, `j = i-1`.
2. Mientras `j >= 0 && a[j] > x`: `a[j+1] = a[j]; j--`.
3. `a[j+1] = x`.
4. `insertarOrdenado` es exactamente el cuerpo del paso anterior aplicado a un único elemento.
5. En datos casi ordenados cada elemento se mueve muy poco: casi O(n). Es estable.

---

# Problema 5 — Búsqueda binaria

## Idea de solución

Se compara con el elemento central y se descarta la mitad donde la clave no puede estar. Requiere arreglo ordenado; complejidad O(log n).

## Algoritmo

1. `ini = 0`, `fin = n-1`.
2. Mientras `ini <= fin`: `mid = ini + (fin - ini) / 2`.
3. Si `a[mid] == clave`, retornar; si `a[mid] < clave`, `ini = mid + 1`; si no, `fin = mid - 1`.
4. `ini + fin` puede exceder `INT_MAX`; la forma con resta no.
5. *Lower bound*: con `fin = n` (exclusivo), si `a[mid] < clave`, `ini = mid + 1`; si no, `fin = mid`. Al final `ini` es la primera posición `>= clave`.
6. `log2(1 000 000) ≈ 20`.

---

# Problema 6 — Merge sort

## Idea de solución

Dividir el arreglo por la mitad, ordenar cada mitad recursivamente y **fusionar** dos mitades ordenadas en tiempo lineal. Complejidad O(n log n) en todos los casos; usa O(n) memoria auxiliar.

## Algoritmo

1. Caso base: `ini >= fin`.
2. `mid = ini + (fin - ini) / 2`; `mergeSort(ini, mid)`; `mergeSort(mid+1, fin)`.
3. `fusionar`: copiar las mitades a `L` y `R`; comparar sus cabezas y copiar la menor (`L[i] <= R[j]` mantiene la estabilidad).
4. Copiar lo que quede de cualquiera de las dos.

---

# Problema 7 — Quick sort

## Idea de solución

Elegir un **pivote**, colocar a su izquierda los menores y a su derecha los mayores (partición) y ordenar recursivamente ambos lados. Promedio O(n log n); peor caso O(n²).

## Algoritmo

1. `pivote = a[fin]`, `i = ini - 1`.
2. Para `j = ini..fin-1`: si `a[j] <= pivote`, `i++` e intercambiar `a[i]` con `a[j]`.
3. Intercambiar `a[i+1]` con `a[fin]` y retornar `i+1`.
4. Recurrir en `[ini, p-1]` y `[p+1, fin]`.
5. Con el pivote en el extremo y un arreglo ya ordenado, la partición queda totalmente desbalanceada (`n-1` y `0` elementos): `n(n-1)/2` comparaciones.

---

# Problema 8 — Ordenar estructuras

## Idea de solución

El algoritmo no cambia: solo cambia la **relación de orden**, que se entrega como puntero a función.

## Algoritmo

1. `bool (*antes)(const Estudiante &, const Estudiante &)`.
2. Inserción: mientras `antes(x, v[j])`, desplazar `v[j]`.
3. `porNotaDesc`: `a.nota > b.nota` (estricto: los empates no se mueven, por eso es estable).
4. `porNombre`: `strcmp(a.nombre, b.nombre) < 0`.

---

# Problema 9 — Ordenar y buscar cadenas

## Idea de solución

Mismos algoritmos, con `strcmp` como comparador y `strcpy` para mover los elementos.

## Algoritmo

1. Inserción: copiar `x = nombres[i]`; mientras `strcmp(nombres[j], x) > 0`, `strcpy(nombres[j+1], nombres[j])`.
2. Binaria: `c = strcmp(nombres[mid], clave)`; `c == 0` éxito, `c < 0` buscar a la derecha, `c > 0` a la izquierda.
3. `strcmp` distingue mayúsculas de minúsculas, por eso todos los nombres deben escribirse igual.

---

# Problema 10 — Comparación experimental

## Idea de solución

Medir operaciones (no tiempo) es independiente de la máquina y reproducible.

## Algoritmo

1. Generar los tres tipos de entrada con `srand(42)`.
2. Pasar cada algoritmo con un puntero a función `void (*)(int *, int, Conteo &)`.
3. Mostrar `comparaciones / movimientos`.

| Entrada | Burbuja | Selección | Inserción |
|---|---|---|---|
| Ordenada | `n-1` comparaciones, 0 movimientos | `n(n-1)/2` comparaciones | `n-1` comparaciones |
| Inversa | peor caso: `n(n-1)/2` | `n/2` intercambios | peor caso |
| Aleatoria | ≈ mitad de los pares invertidos | ≈ `n(n-1)/2` comparaciones | ≈ `n²/4` |

---

# Problema 11 — Contar inversiones

## Idea de solución

En la fusión, si `a[j]` (derecha) es menor que `a[i]` (izquierda), entonces es menor que **todos** los restantes de la izquierda (están ordenados): aporta `mid - i + 1` inversiones de una vez.

## Algoritmo

1. `contar(ini, fin)` = `contar(izq) + contar(der) + fusionarContando`.
2. En `fusionarContando`: si `a[i] <= a[j]`, copiar `a[i]`; si no, copiar `a[j]` y `inv += mid - i + 1`.
3. Copiar el resultado de `tmp` a `a`.
4. Complejidad O(n log n) frente a O(n²) de la fuerza bruta.

---

# Problema 12 — Quickselect

## Idea de solución

Después de particionar, el pivote queda en su posición final `p`. Si `k == p`, es la respuesta; si `k < p`, solo se explora la izquierda; si `k > p`, solo la derecha. Se descarta la otra mitad sin ordenarla.

## Algoritmo

1. `p = particion(ini, fin)`.
2. `k == p` → `a[p]`.
3. `k < p` → `quickSelect(ini, p-1, k)`; si no → `quickSelect(p+1, fin, k)`.
4. Mediana = `k = n/2`; mayor = `k = n-1`.
5. Promedio O(n); peor caso O(n²).

---

# Problema 13 — Búsqueda binaria sobre la respuesta

## Idea de solución

Si se puede decidir de forma monótona si un valor candidato es "demasiado grande", se aplica búsqueda binaria sobre el espacio de respuestas, no sobre un arreglo.

## Algoritmo

**Raíz entera**: buscar el mayor `mid` con `mid * mid <= n` (usar `mid <= n / mid` para evitar desbordamiento); si se cumple, guardar `res = mid` y subir `ini`.

**Arreglo rotado**: en cada paso al menos una mitad está ordenada. Si `a[ini] <= a[mid]`, la izquierda es la ordenada: si la clave está en `[a[ini], a[mid])`, buscar allí; si no, a la derecha. Análogo en el otro caso.

**Índice de rotación**: si `a[mid] > a[fin]`, el mínimo está a la derecha; si no, en `[ini, mid]`.

---

# Problema 14 — Counting sort

## Idea de solución

Si los valores están en un rango pequeño `[0, k)`, se cuentan las ocurrencias y se calcula la posición final de cada valor sin comparar elementos entre sí.

## Algoritmo

1. `cuenta[v]++` para cada elemento.
2. Acumulados: `cuenta[v] += cuenta[v-1]` (posición final + 1).
3. Recorrer la entrada **de atrás hacia adelante**: `salida[--cuenta[a[i]]] = a[i]` (estable).
4. Por frecuencia: guardar frecuencia y primera aparición de cada valor; ordenar los valores distintos por (frecuencia desc, primera aparición asc) y expandirlos.

---

# Problema 15 — Quicksort híbrido

## Idea de solución

La mediana de tres evita el peor caso con datos ordenados, y la inserción es más rápida que la recursión para tramos pequeños.

## Algoritmo

1. Si el tramo tiene `<= 8` elementos: inserción.
2. Ordenar `a[ini]`, `a[mid]`, `a[fin]`; el pivote es el del medio, que se esconde en `fin-1`.
3. Partición de Hoare: `i` avanza mientras `a[++i] < p`, `j` retrocede mientras `a[--j] > p`; intercambiar y repetir hasta cruzarse.
4. Colocar el pivote en `i` y recurrir en ambos lados.
5. Con un arreglo ordenado el pivote cae en el centro: ≈ `n log n` comparaciones en vez de `n²/2`.

---

# Problema 16 — `ranges` y proyecciones

## Idea de solución

La biblioteca estándar ya trae algoritmos ordenados y de selección; conviene conocerlos y usarlos en producción, entendiendo qué hacen por dentro.

## Algoritmo

1. `ranges::sort(v)`, `ranges::sort(v, ranges::greater{})`.
2. `partial_sort(v, v.begin() + 3)`: deja los 3 menores ordenados al inicio; el resto queda sin orden específico.
3. `nth_element(v, v.begin() + n/2)`: es quickselect; `v[n/2]` queda en su posición final.
4. `stable_sort` conserva el orden de los empates: ordenar primero por la clave secundaria y después por la primaria.
5. `ranges::is_sorted(v, {}, &T::campo)` verifica con proyección.

---

# Problema 17 — Búsqueda binaria estándar

## Idea de solución

Con el rango ordenado, `lower_bound` da la primera posición `>= x` y `upper_bound` la primera `> x`; todo lo demás se deriva de ellas.

## Algoritmo

1. `binary_search(s, x)` informa si existe.
2. Apariciones: `upper_bound(s, x) - lower_bound(s, x)`.
3. `equal_range` devuelve ambos iteradores a la vez.
4. Inserción ordenada: `v.insert(lower_bound(v, x), x)`.
5. Con proyección: `lower_bound(catalogo, 310, {}, &Producto::id)`.
6. `s.subspan(4, 6)` restringe la búsqueda a un sub-rango sin copiar.

---

# Problema 18 — Algoritmos genéricos con `concepts`

## Idea de solución

Si el algoritmo se escribe sobre **iteradores** y un comparador, sirve para cualquier contenedor que cumpla los requisitos, y los `concepts` documentan esos requisitos.

## Algoritmo

1. `requires sortable<It, Comp>`: el iterador permite intercambiar elementos y el comparador define un orden.
2. Inserción con `std::move` de los elementos (no copia cadenas).
3. `busquedaBinaria` con `distance`/`advance`: es O(log n) comparaciones en cualquier iterador `forward`, aunque O(n) avances si no es de acceso aleatorio.
4. `list<int>` no tiene iteradores de acceso aleatorio, así que `insercion(list...)` no satisface `random_access_iterator`.

---

# Problema 19 — `<=>`

## Idea de solución

`a <=> b` devuelve un valor comparable con 0 (`< 0`, `== 0`, `> 0`) e indica la relación completa. Un único operador define todo el orden.

## Algoritmo

1. `Version`: el `<=>` por defecto compara `mayor`, `menor`, `parche`.
2. `Jugador`: `if (auto c = o.puntos <=> puntos; c != 0) return c; return tiempo <=> o.tiempo;` (se invierten los operandos para que más puntos vaya primero).
3. `ranges::sort(ranking)` usa `operator<` generado desde `<=>`.
4. `compare_three_way{}(x, y)` invoca `x <=> y`.
5. `strong_ordering` si equivalente implica idéntico; `partial_ordering` para reales (por `NaN`).

---

# Problema 20 — Ordenar y buscar al compilar

## Idea de solución

Los algoritmos son funciones comunes; marcarlos `constexpr` permite ejecutarlos durante la compilación y verificar su corrección con `static_assert`.

## Algoritmo

1. `template <typename T, size_t N> constexpr array<T,N> burbuja(array<T,N> a)`: recibe una copia y la devuelve ordenada.
2. `constexpr auto ORDENADO = burbuja(DESORDENADO);` y `static_assert(ranges::is_sorted(ORDENADO))`.
3. `ranges::sort` es `constexpr` desde C++20 para tipos simples.
4. La tabla de palabras queda ordenada en el ejecutable: en ejecución solo se hace `binary_search`.
5. Un error en el algoritmo se convierte en un error de compilación.
