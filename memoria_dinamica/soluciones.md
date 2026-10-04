# Soluciones Conceptuales — C++20
## Semanas 9 y 11 — Memoria dinámica

Los programas completos están en la carpeta [`codigo/`](codigo/) (`solucion01.cpp` … `solucion20.cpp`). Compilar con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

---

# Problema 1 — `new` y `delete`

## Idea de solución

`new` reserva memoria en el *heap* (dura hasta que se libere); las variables locales viven en la pila y se destruyen al salir de la función. Todo `new` debe tener su `delete`, y todo `new[]` su `delete[]`.

## Algoritmo

1. `int *p = new int(25);` ... `delete p; p = nullptr;`.
2. Leer `n` y `double *notas = new double[n];`.
3. Acumular, promediar y `delete[] notas;`.
4. Asignar `nullptr` evita usar por error un puntero colgante.

---

# Problema 2 — Arreglo dinámico de enteros

## Idea de solución

El tamaño se conoce en ejecución, por lo que no puede ser un arreglo automático. `new int[n]()` inicializa en cero.

## Algoritmo

1. Validar `n > 0`.
2. Reservar y leer con un puntero que recorre `[a, a+n)`.
3. `maxMin` devuelve ambos valores por referencia.
4. `delete[] a`: `delete` sin corchetes destruye solo un elemento y el resto no se libera correctamente (comportamiento indefinido).

---

# Problema 3 — Arreglo que crece

## Idea de solución

Cuando se llena, se reserva un bloque mayor, se copian los elementos y se libera el bloque anterior. Duplicando la capacidad, la cantidad total de copias es menor que `2n`, por lo que agregar cuesta O(1) amortizado.

## Algoritmo

1. `iniciar`: capacidad inicial 2, tamaño 0.
2. `agregar`: si `tamano == capacidad`, reservar `2 * capacidad`, copiar, `delete[]` el anterior y actualizar el puntero.
3. Guardar el dato en `datos[tamano++]`.
4. `liberar`: `delete[] datos`, `datos = nullptr`, contadores a 0.

---

# Problema 4 — Funciones que devuelven memoria dinámica

## Idea de solución

La memoria del *heap* sobrevive a la función que la creó; por eso puede devolverse su dirección. Una variable local no: devolver su dirección deja un puntero colgante.

## Algoritmo

1. `rango`: `n = fin - ini + 1`, reservar y llenar.
2. `filtrarPares`: primer recorrido para contar, segundo para copiar.
3. El llamador hace `delete[]` de cada resultado.
4. `int *mal(){ int a[3]; return a; }` devuelve una dirección que deja de ser válida al terminar la función.

---

# Problema 5 — Matriz dinámica con `int **`

## Idea de solución

Una matriz dinámica es un arreglo de punteros a filas. Se reservan `f + 1` bloques y se deben liberar los `f + 1`.

## Algoritmo

1. `m = new int*[f]` y para cada `i`, `m[i] = new int[c]()`.
2. `liberarMatriz`: `delete[] m[i]` para cada fila y luego `delete[] m`. Si se libera `m` primero, se pierden las direcciones de las filas (fuga).
3. Transpuesta: `t[j][i] = m[i][j]`, con `t` de `c × f`.

---

# Problema 6 — Matriz en un bloque contiguo

## Idea de solución

Una sola reserva de `f * c` elementos; el elemento `(i, j)` está en la posición `i * c + j`.

## Algoritmo

1. `datos = new double[f * c]()`.
2. `en(m, i, j)` devuelve `m.datos[i * m.columnas + j]` por referencia (sirve para leer y escribir).
3. Producto: `r(i, j) += a(i, k) * b(k, j)`.
4. Ventajas: una reserva, una liberación, datos adyacentes (caché) y copia con una sola operación.

---

# Problema 7 — Matriz irregular

## Idea de solución

Cada fila es un bloque independiente y puede tener un tamaño distinto: ideal cuando la estructura no es rectangular.

## Algoritmo

1. `t[i] = new int[i + 1]`.
2. `t[i][0] = t[i][i] = 1`; para `j = 1..i-1`, `t[i][j] = t[i-1][j-1] + t[i-1][j]`.
3. Elementos almacenados: `n(n+1)/2` en lugar de `n²`.
4. Liberar cada fila y luego `t`.

---

# Problema 8 — Arreglo dinámico de estructuras

## Idea de solución

`new Estudiante[n]` crea `n` estructuras contiguas. Con un puntero a estructura se accede con `->`.

## Algoritmo

1. `Estudiante *v = new Estudiante[n];` y `leer(v + i)` que usa `e->campo`.
2. Selección sobre `(v + j)->nota`; el intercambio copia estructuras completas.
3. Recorrer con `Estudiante *p = v; p < v + n; p++`.
4. `new Estudiante(*v)` crea un objeto independiente (copia); se libera con `delete`, mientras `v` se libera con `delete[]`.

---

# Problema 9 — Copia superficial y profunda

## Idea de solución

Copiar una estructura copia el **puntero**, no el bloque al que apunta: ambas copias comparten el mismo bloque (copia superficial). La copia profunda reserva un bloque nuevo y copia su contenido.

## Algoritmo

1. Superficial: `return o;` (mismo `datos`).
2. Profunda: `t.datos = new char[o.longitud + 1]; strcpy(t.datos, o.datos);`.
3. Modificar `a.datos[0]`: se ve el cambio en la superficial, no en la profunda.
4. Dos estructuras con el mismo bloque: liberar **solo una** vez; liberar ambas es doble liberación.

---

# Problema 10 — Errores de memoria

## Idea de solución

Los errores de memoria dinámica no siempre fallan de inmediato: pueden pasar desapercibidos y aparecer después. Conviene conocerlos y usar herramientas de detección.

## Algoritmo

1. **Fuga**: perder el único puntero de un bloque.
2. **Doble liberación** y **uso tras liberar**: se evitan poniendo `nullptr` tras `delete`.
3. **`new[]` con `delete`**: siempre `delete[]`.
4. **Desbordamiento**: escribir fuera de `[0, n)`.
5. `new` lanza `bad_alloc` si falla; `new (nothrow)` devuelve `nullptr`.
6. `g++ -fsanitize=address,undefined -g` detecta fugas, doble liberación y accesos fuera de rango (con ASan activo una reserva descomunal aborta el programa en lugar de lanzar `bad_alloc`, así que no use el problema 10 con esa opción para ese caso).

---

# Problema 11 — Lista enlazada simple

## Idea de solución

Una lista es una cadena de nodos reservados uno a uno. Cada nodo apunta al siguiente; el último apunta a `nullptr`.

## Algoritmo

1. `insertarInicio`: `cabeza = new Nodo{x, cabeza}`.
2. `insertarFinal`: recorrer hasta el último nodo y enlazar uno nuevo.
3. `eliminar`: `Nodo **pp = &cabeza; while (*pp && (*pp)->dato != x) pp = &(*pp)->sig;` luego `*pp = borrar->sig; delete borrar;` (sirve igual para la cabeza).
4. `invertir`: con `prev`, `p`, `sig` redirigir cada enlace.
5. `liberar`: guardar `sig` **antes** de borrar el nodo.

---

# Problema 12 — Pila y cola con arreglos dinámicos

## Idea de solución

La pila (LIFO) solo opera en un extremo; la cola circular (FIFO) reutiliza el espacio con aritmética módulo la capacidad. Las clases que poseen memoria no deben copiarse de forma superficial.

## Algoritmo

1. Pila: `apilar` duplica la capacidad si `tope == capacidad`; `desapilar` retorna `datos[--tope]`.
2. Cola: la posición de inserción es `(ini + cant) % capacidad`; al desencolar, `ini = (ini + 1) % capacidad`.
3. Balanceado: apilar las aperturas; al encontrar un cierre, desapilar y verificar que sea su pareja; al final la pila debe quedar vacía.
4. `= delete` en copia y asignación evita que dos objetos liberen el mismo bloque.

---

# Problema 13 — Matriz dispersa

## Idea de solución

Si la mayoría de elementos son 0, almacenar solo los no nulos con su posición ahorra memoria.

## Algoritmo

1. Contar los distintos de cero y reservar exactamente ese número de `Elemento`.
2. Transpuesta: intercambiar `fila` y `col` de cada elemento.
3. Suma: fusionar dos listas ordenadas por (fila, columna): si las posiciones coinciden, sumar los valores y descartar el resultado si es 0.
4. Los resultados temporales se copian a un bloque del tamaño exacto y el temporal se libera.

---

# Problema 14 — Clase Matriz con la regla de los tres

## Idea de solución

Si una clase administra memoria, necesita destructor, constructor de copia y asignación por copia; de lo contrario, la copia generada por el compilador comparte el bloque.

## Algoritmo

1. Destructor: `delete[] d`.
2. Constructor de copia: reservar `f*c` y `copy`.
3. Asignación: copiar primero a un bloque nuevo, **luego** liberar el anterior (segura incluso en `c = c` y si la reserva falla).
4. `operator()` con dos sobrecargas (modificable y `const`).
5. `operator*` y `transpuesta` retornan matrices por valor.

---

# Problema 15 — Estructuras anidadas dinámicas

## Idea de solución

Cada nivel tiene su propia memoria; se libera en el orden inverso al de creación (primero lo más interno).

## Algoritmo

1. `crearEstudiante`: reservar el nombre (`strlen + 1`) y las notas; copiar.
2. `crearCurso`: reservar el nombre y el arreglo de `Estudiante`.
3. `liberarCurso`: para cada estudiante, `delete[] nombre` y `delete[] notas`; luego `delete[] estudiantes` y `delete[] nombre` del curso.
4. Promedio: sumar las notas y dividir entre `numNotas`.

---

# Problema 16 — `unique_ptr` para arreglos

## Idea de solución

`unique_ptr<T[]>` es el dueño exclusivo del bloque y llama a `delete[]` automáticamente (RAII). No se copia, solo se mueve.

## Algoritmo

1. `make_unique<int[]>(n)` inicializa en cero; `make_unique_for_overwrite<double[]>(n)` no inicializa.
2. `unique_ptr<int[]> c = move(a);` deja `a == nullptr`.
3. Matriz: `unique_ptr<unique_ptr<int[]>[]>` y cada fila con `make_unique<int[]>(c)`; `operator[]` retorna `filas[i].get()`.
4. `vector<unique_ptr<int[]>>` guarda arreglos de distinta longitud.
5. No hay `delete`: todo se libera al salir del ámbito, incluso con excepciones.

---

# Problema 17 — `vector`, `span` y `erase_if`

## Idea de solución

`vector` administra su propio bloque dinámico: capacidad ≥ tamaño y crecimiento geométrico. Un `span` ofrece una vista sobre una parte sin copiar.

## Algoritmo

1. Observar `capacity()` tras cada `push_back` (en GCC: 1, 2, 4, 8, ...).
2. `reserve(100)` evita reubicaciones; `shrink_to_fit()` devuelve el exceso.
3. `erase_if(x, pred)` y `erase(x, valor)` (C++20) devuelven la cantidad eliminada.
4. Matriz contigua: `fila(i) = span<int>(d).subspan(i * c, c)`.
5. `ranges::reverse(m.fila(1))` modifica la fila dentro del vector.

---

# Problema 18 — `pmr`

## Idea de solución

Los contenedores `pmr::` piden memoria a un `memory_resource` elegido en ejecución. Un `monotonic_buffer_resource` entrega memoria avanzando un puntero y libera todo de una vez al destruirse: es muy rápido.

## Algoritmo

1. `array<byte,4096> buffer; pmr::monotonic_buffer_resource pool(buffer.data(), buffer.size(), pmr::null_memory_resource());`.
2. `pmr::vector<int> v(&pool)`: sus elementos están en la pila.
3. `RecursoVerbose` hereda de `memory_resource` e implementa `do_allocate`, `do_deallocate` y `do_is_equal`.
4. El `vector` normal hace una reserva por cada crecimiento (11 para 1000 elementos); la arena pide pocos bloques grandes (6 para dos vectores de 1000).
5. Con `null_memory_resource` como respaldo, agotar el buffer lanza `bad_alloc`.

---

# Problema 19 — `construct_at` y `destroy_at`

## Idea de solución

Reservar memoria y construir objetos son pasos distintos. `std::vector` reserva con capacidad de sobra y construye solo los elementos usados.

## Algoritmo

1. `::operator new(bytes, align_val_t(alignof(T)))` reserva memoria cruda.
2. `construct_at(p, args...)` construye un objeto en `p` (equivalente moderno del *placement new*).
3. `destroy_at(p)` llama al destructor sin liberar memoria; `destroy(ini, fin)` lo hace para un rango.
4. Crecer: para cada elemento, `construct_at(nuevo + i, move(datos[i]))` y `destroy_at(datos + i)`; luego `operator delete` del bloque viejo.
5. Los mensajes `[+]`/`[-]` confirman que cada objeto se construye y se destruye una vez.

---

# Problema 20 — `shared_ptr` y `weak_ptr`

## Idea de solución

`shared_ptr` cuenta propietarios y libera cuando llega a cero. Si dos objetos se poseen mutuamente, el contador nunca llega a cero (ciclo). `weak_ptr` observa sin aumentar el contador y rompe el ciclo.

## Algoritmo

1. `Nodo { shared_ptr<Nodo> sig; weak_ptr<Nodo> ant; }`: el enlace hacia adelante posee, el de atrás solo observa.
2. Recorrer hacia atrás con `p = p->ant.lock()` (devuelve un `shared_ptr` o nulo si ya no existe).
3. Al salir del ámbito de `Lista` se destruyen los tres nodos.
4. Con `Malo` (`otro` es `shared_ptr` en ambos sentidos) los contadores valen 2 al terminar el bloque y los destructores **no** se ejecutan; ASan reporta la fuga.
5. `expired()` informa si el objeto ya no existe; `lock()` lo promueve a `shared_ptr`.
