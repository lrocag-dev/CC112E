# Soluciones Conceptuales — C++20
## Cadenas de caracteres I y II (Semanas 6 y 7)

Los programas completos están en la carpeta [`codigo/`](codigo/) (`solucion01.cpp` … `solucion15.cpp`). Compilar con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

---

# Problema 1 — Códigos ASCII

## Idea de solución

Un `char` es un entero pequeño: imprimirlo con `static_cast<int>` muestra su código, y un entero convertido con `static_cast<char>` muestra su carácter. Las letras y los dígitos son consecutivos en la tabla.

## Algoritmo

1. Leer `char c` y mostrar `static_cast<int>(c)`.
2. Leer un entero y mostrar `static_cast<char>(codigo)`.
3. Recorrer `for (char x = 'A'; x <= 'Z'; x++)`, igual para minúsculas y dígitos.
4. `'a' - 'A'` = 32; `'7' - '0'` = 7.

---

# Problema 2 — Clasificación de caracteres

## Idea de solución

Recorrer la cadena hasta `'\0'` y clasificar cada carácter por rangos.

## Algoritmo

1. Leer con `cin.getline(s, 200)`.
2. Para cada `c`, convertir a minúscula si está en `'A'..'Z'`.
3. Si es `a,e,i,o,u` → vocal; si está en `'a'..'z'` → consonante; en `'0'..'9'` → dígito; `' '` → espacio; otro → símbolo.
4. Mostrar los contadores.

---

# Problema 3 — Longitud de una cadena

## Idea de solución

La longitud es la distancia entre el inicio y el terminador `'\0'`.

## Algoritmo

1. `p = s`; mientras `*p != '\0'`, `p++`.
2. Retornar `p - s`.
3. `sizeof(s)` es la capacidad del arreglo (200), no la longitud; la longitud depende del contenido.
4. El último carácter es `s[longitud - 1]` si la cadena no está vacía.

---

# Problema 4 — Mayúsculas y minúsculas con ASCII

## Idea de solución

Entre una letra minúscula y su mayúscula hay siempre 32 posiciones.

## Algoritmo

1. `aMayuscula(c)`: si `'a' <= c <= 'z'`, `c - 32`.
2. `aMinuscula(c)`: si `'A' <= c <= 'Z'`, `c + 32`.
3. Recorrer la cadena construyendo las cuatro versiones (alternado según `i % 2`; invertido según el caso original).
4. Terminar cada resultado con `'\0'`.

---

# Problema 5 — Inversión y palíndromos

## Idea de solución

Dos punteros, uno al inicio y otro al final, se acercan. Para el palíndromo se saltan los caracteres que no son alfanuméricos.

## Algoritmo

**invertir**: ubicar `fin` en el último carácter; mientras `ini < fin` intercambiar y acercar.

**esPalindromo**:
1. `i` al inicio, `j` al último.
2. Avanzar `i` y retroceder `j` mientras no apunten a letras o dígitos (`isalnum`).
3. Comparar con `tolower`; si difieren retornar `false`.
4. Si se cruzan, retornar `true`.

---

# Problema 6 — `strcpy` y `strcat` propios

## Idea de solución

Copiar carácter a carácter hasta copiar también el `'\0'`; para concatenar, primero ubicarse en el fin del destino.

## Algoritmo

1. `miStrcpy`: `while ((*d++ = *origen++) != '\0');` y retornar el inicio.
2. `miStrcat`: avanzar `d` hasta `'\0'` y copiar desde ahí.
3. Declarar `completo` con espacio para nombre + espacio + apellido + `'\0'`.
4. Encadenar: `copy(nombre)`, `cat(" ")`, `cat(apellido)`.

---

# Problema 7 — Ordenar nombres

## Idea de solución

`strcmp(a, b)` devuelve negativo, cero o positivo según el orden lexicográfico por código ASCII. Las mayúsculas (65–90) preceden a las minúsculas (97–122).

## Algoritmo

1. Leer 5 cadenas con `cin.getline(nombres[i], 30)`.
2. Burbuja: si `strcmp(nombres[j], nombres[j+1]) > 0`, intercambiar con un `aux[30]` y `strcpy`.
3. Observar que `"Zoe"` queda antes de `"ana"`; para ignorar el caso habría que convertir antes de comparar.

---

# Problema 8 — Palabras de una línea

## Idea de solución

Máquina de dos estados: *dentro* o *fuera* de una palabra. Cada transición fuera→dentro inicia una palabra.

## Algoritmo

1. Recorrer incluyendo el `'\0'` final como separador.
2. Si el carácter no es separador y estábamos fuera: `palabras++`, reiniciar la longitud y marcar dentro.
3. Acumular los caracteres de la palabra actual.
4. Al pasar de dentro a fuera, comparar la longitud con la máxima y guardar la palabra.

---

# Problema 9 — Cifrado César

## Idea de solución

Aritmética modular sobre el alfabeto: `(letra - base + k) mod 26 + base`.

## Algoritmo

1. Normalizar `k = ((k % 26) + 26) % 26` (cubre negativos y grandes).
2. Para mayúsculas, `base = 'A'`; para minúsculas, `base = 'a'`.
3. Otros caracteres no se tocan.
4. Descifrar es aplicar `cesar(s, -k)`.

---

# Problema 10 — Conversión entre cadenas y números

## Idea de solución

Cada dígito aporta `c - '0'`; se acumula con `v = v * 10 + dígito`.

## Algoritmo

1. Saltar espacios y leer el signo opcional.
2. Si no quedan caracteres, retornar `false`.
3. Para cada carácter: si no es dígito, `false`; si lo es, acumular.
4. Multiplicar por el signo.
5. `strtod(s, &fin)` convierte el prefijo válido y deja en `fin` el resto, útil para detectar entradas parciales como `"4x"`.

---

# Problema 11 — Registros en formato CSV

## Idea de solución

`strtok` parte la cadena por delimitadores; la primera llamada recibe la cadena y las siguientes `nullptr`. Reemplaza los delimitadores por `'\0'`, por eso se usa una copia.

## Algoritmo

1. `strcpy(copia, linea)`.
2. `nombre = strtok(copia, ",")`; luego `edad` y `nota` con `strtok(nullptr, ",")`.
3. Si alguno es `nullptr`, descartar la línea.
4. Convertir con `atoi` y `atof`; acumular suma y contar.
5. Guardar nombre y nota si superan al mejor anterior.

---

# Problema 12 — Anagramas

## Idea de solución

Dos frases son anagramas si tienen la misma cantidad de cada letra.

## Algoritmo

1. Inicializar `f[26] = {0}`.
2. Para cada carácter que sea letra, `f[tolower(c) - 'a']++`.
3. Comparar las dos tablas posición por posición.
4. Complejidad O(n) con memoria constante.

---

# Problema 13 — Subcadena palíndroma más larga

## Idea de solución

Todo palíndromo tiene un centro (un carácter o un par). Expandiendo hacia ambos lados mientras coincidan se obtiene el palíndromo máximo de ese centro.

## Algoritmo

1. Para cada `c` en `0..n-1`:
   - `impar = expandir(c, c)`, `par = expandir(c, c+1)`.
2. `expandir(i, j)`: mientras `i >= 0`, `j < n` y `s[i] == s[j]` hacer `i--`, `j++`; retornar `j - i - 1`.
3. Si la longitud supera la mejor, guardar `inicio = c - (l - 1) / 2`.
4. Copiar con `strncpy(res, s + inicio, longitud)` y poner `res[longitud] = '\0'`, porque `strncpy` no lo garantiza.

---

# Problema 14 — Compresión *run-length*

## Idea de solución

Agrupar rachas de caracteres iguales y guardar solo el carácter y la cantidad.

## Algoritmo

**comprimir**:
1. Tomar `c = *s`, contar mientras `*s == c`.
2. Escribir `c` y la cantidad con `sprintf`, avanzando `out` con lo que retorna.

**descomprimir**:
1. Leer `c`; luego `cuenta = strtol(s, &fin, 10)` y `s = fin`.
2. Escribir `c` `cuenta` veces.

Se exige que el original no tenga dígitos para que la decodificación no sea ambigua.

---

# Problema 15 — Evaluador de expresiones

## Idea de solución

Un analizador descendente recursivo codifica la precedencia en la estructura de las funciones:

```
expresion = termino { (+|-) termino }
termino   = numero  { (*|/) numero }
```

## Algoritmo

1. Un puntero global `p` recorre la entrada; `saltar()` ignora espacios.
2. `numero()` llama a `strtod(p, &fin)`; si `fin == p`, error.
3. `termino()` multiplica o divide mientras encuentre `*` o `/`; verifica división por cero.
4. `expresion()` suma o resta resultados de `termino()`.
5. Al terminar, si `*p != '\0'`, hay un carácter inesperado.

Esto garantiza que `2 + 3 * 4` se evalúe como `2 + (3 * 4)`.
