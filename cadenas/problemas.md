# Problemas de C++20
## Cadenas de caracteres I y II (Semanas 6 y 7)

Temas: caracteres ASCII, aritmética limitada de caracteres, arreglo de caracteres y cadenas terminadas en `'\0'`, puntero a cadena, funciones de entrada y salida, funciones de `<cstring>`, `<cctype>` y `<cstdlib>`, conversión de cadenas.

Los problemas 1 al 10 son de nivel básico/intermedio y del 11 al 15 de nivel avanzado.

> **Restricción general:** trabaje con cadenas de estilo C (`char[]` y `char *`), no con `std::string`, salvo que se indique lo contrario. Cuando el enunciado diga "sin usar" una función de la biblioteca, impleméntela usted.

---

# Nivel básico / intermedio

---

# Problema 1 — Códigos ASCII

## Requerimientos

- Leer un carácter y mostrar su código ASCII.
- Leer un código (32–126) y mostrar su carácter.
- Mostrar con ciclos `for` sobre `char` las mayúsculas, las minúsculas y los dígitos.
- Mostrar `'a' - 'A'` y el valor numérico del carácter `'7'` (`'7' - '0'`).

---

# Problema 2 — Clasificación de caracteres

## Requerimientos

- Leer una línea con `cin.getline`.
- Contar vocales, consonantes, dígitos, espacios y otros símbolos, sin usar `<cctype>`.
- Considerar mayúsculas y minúsculas por igual.

## Ejemplo

```
Entrada: Hola Mundo 123!
Vocales: 4  Consonantes: 5  Digitos: 3  Espacios: 2  Otros: 1
```

---

# Problema 3 — Longitud de una cadena

## Requerimientos

- Implementar `int longitud(const char *s)` usando un puntero que recorra hasta `'\0'`.
- Comparar con `strlen`.
- Mostrar también `sizeof(s)` y explicar por qué no es la longitud de la cadena.
- Mostrar el último carácter de la cadena.

---

# Problema 4 — Mayúsculas y minúsculas con ASCII

## Requerimientos

- Implementar `aMayuscula` y `aMinuscula` sumando o restando `'a' - 'A'`, sin `toupper`/`tolower`.
- Generar cuatro versiones de la cadena: todo mayúsculas, todo minúsculas, alternando mayúscula/minúscula e invirtiendo el caso de cada letra.

---

# Problema 5 — Inversión y palíndromos

## Requerimientos

- Implementar `void invertir(char *s)` in situ con dos punteros.
- Implementar `bool esPalindromo(const char *s)` que ignore espacios, signos de puntuación y diferencias de mayúsculas.

## Ejemplo

```
"Anita lava la tina" -> Es palindromo
```

---

# Problema 6 — `strcpy` y `strcat` propios

## Requerimientos

- Implementar `char *miStrcpy(char *destino, const char *origen)` y `char *miStrcat(char *destino, const char *origen)` con punteros.
- Leer nombre y apellido y construir el nombre completo con ambas funciones.
- Asegurar que el destino tenga espacio suficiente.

---

# Problema 7 — Ordenar nombres

## Requerimientos

- Leer 5 nombres (hasta 29 caracteres) en una matriz `char nombres[5][30]`.
- Ordenarlos alfabéticamente con `strcmp` y `strcpy`.
- Mostrar el resultado e indicar qué ocurre con mayúsculas y minúsculas (`strcmp` distingue el caso).

---

# Problema 8 — Palabras de una línea

## Requerimientos

- Leer una línea y contar las palabras (secuencias separadas por uno o más espacios o tabuladores).
- Identificar la palabra más larga y mostrar su longitud.
- Manejar espacios iniciales, finales y repetidos.

---

# Problema 9 — Cifrado César

## Requerimientos

- Implementar `void cesar(char *s, int k)` que desplace cada letra `k` posiciones, conservando mayúsculas/minúsculas y sin alterar otros caracteres.
- Aceptar `k` negativo y `k` mayor que 26.
- Mostrar el mensaje cifrado y luego descifrarlo.

## Ejemplo

```
"Hola, Mundo" con k = 3 -> "Krod, Pxqgr"
```

---

# Problema 10 — Conversión entre cadenas y números

## Requerimientos

- Implementar `bool aEntero(const char *s, long &resultado)` sin `atoi`: admite espacios iniciales y signo, y devuelve `false` si hay caracteres no numéricos o la cadena está vacía.
- Comparar con `atoi` y con `strtod`, mostrando la parte no convertida (`fin`).
- Convertir un número a texto con `to_string`.

---

# Nivel avanzado

---

# Problema 11 — Registros en formato CSV

Cada línea tiene el formato `nombre,edad,nota`.

## Requerimientos

- Procesar un conjunto de líneas usando `strtok` (recuerde que modifica la cadena: trabaje sobre una copia).
- Convertir edad con `atoi` y nota con `atof`.
- Mostrar el promedio de notas y el estudiante con mejor nota.
- Ignorar las líneas con campos faltantes.

---

# Problema 12 — Anagramas

## Requerimientos

- Implementar `void frecuencias(const char *s, int f[26])` que cuente las letras sin distinguir mayúsculas y minúsculas e ignore todo lo que no sea letra.
- Implementar `bool anagramas(const char *a, const char *b)` comparando las frecuencias.
- Mostrar las frecuencias de la primera frase.

## Ejemplo

```
"Dormitory" y "Dirty room" -> Son anagramas
```

---

# Problema 13 — Subcadena palíndroma más larga

## Requerimientos

- Dada una cadena, hallar la subcadena palíndroma de mayor longitud.
- Usar la técnica de *expansión desde el centro* considerando centros impares (`c, c`) y pares (`c, c+1`); complejidad O(n²).
- Copiar el resultado a otra cadena con `strncpy` y terminarla correctamente.

## Ejemplo

```
"babad" -> "bab"
```

---

# Problema 14 — Compresión *run-length*

## Requerimientos

- Implementar `void comprimir(const char *s, char *out)` que reemplace cada racha de caracteres iguales por el carácter y su cantidad (`"aaabccdd"` → `"a3b1c2d2"`).
- Implementar `void descomprimir(const char *s, char *out)` usando `strtol` para leer la cantidad.
- Verificar que `descomprimir(comprimir(s)) == s` para cadenas sin dígitos.

---

# Problema 15 — Evaluador de expresiones aritméticas

## Requerimientos

- Leer una línea con una expresión que contenga números reales y los operadores `+ - * /`, con espacios opcionales, **sin paréntesis**.
- Evaluarla respetando la precedencia (`*` y `/` antes que `+` y `-`) mediante tres funciones recursivas: `expresion`, `termino` y `numero`; esta última usa `strtod`.
- Detectar y reportar: división por cero, número esperado y caracteres inesperados.

## Ejemplo

```
2 + 3 * 4 - 10 / 4  ->  11.5
5/0                 ->  Error: division por cero
```

---

# Nivel C++20 — Programación moderna

Los problemas 1 al 15 se resuelven con C++11 o anterior. Los problemas 16 al 20 usan características de C++20 (y de C++14/17 que se consolidan en él). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior (o MSVC 19.29+). Verifique su compilador con `g++ --version`.

---

# Problema 16 — `string_view`: ver cadenas sin copiarlas (C++17/20)

## Requerimientos

- Implementar `vector<string_view> dividir(string_view s, char sep)` sin copiar ninguna subcadena.
- Implementar `string_view recortar(string_view s)` que quite espacios al inicio y al final usando `remove_prefix` y `remove_suffix`.
- Probar con `"  Ana ; Luis;Rosa  ;  Pedro "`.
- Con una URL, extraer el protocolo y usar `starts_with` y `ends_with` (C++20).
- Explicar por qué un `string_view` no debe sobrevivir a la cadena que observa.

---

# Problema 17 — `std::format` y `from_chars` (C++20)

## Requerimientos

- Mostrar una tabla de productos con columnas alineadas (`{:<12}`, `{:>8}`, `{:>10.2f}`), una línea de separación y el total.
- Mostrar un número en hexadecimal, en binario, con ceros a la izquierda y un texto centrado y con relleno.
- Implementar `optional<double> aReal(string_view s)` con `from_chars`, que rechace entradas como `"7x"` o `""`.
- Convertir un entero a texto con `to_chars` sobre un `char[]`.

## Ejemplo

```
Producto    |   Unid.|    Precio|  Subtotal
Lapiz       |      12|      1.50|     18.00
```

---

# Problema 18 — Vistas de rangos sobre texto (C++20)

## Requerimientos

- Implementar `normalizar(string_view)` como una cadena de vistas: `views::filter` (solo letras) y `views::transform` (a minúscula).
- Reescribir `esPalindromo` con `ranges::equal(n, n | views::reverse)`.
- Dividir una frase con `views::split(' ')`, mostrando cada palabra y su longitud.
- Usar `views::take` para mostrar los primeros caracteres.
- Explicar qué significa que una vista sea *perezosa*.

---

# Problema 19 — `concepts` para cadenas (C++20)

## Requerimientos

- Definir `concept TextoLike = convertible_to<T, string_view>`.
- Implementar `contarVocales` y `mayusculas` como plantillas restringidas por ese concepto que funcionen con `char[]`, `const char *`, `string` y `string_view`.
- Definir `concept Contenedor` con una expresión `requires` (que tenga `size()`, `begin()` y `end()`) y una función `longitud`.
- Dejar comentadas las llamadas inválidas (`contarVocales(42)`, `longitud` sobre un `char[]`) y explicar por qué fallan.

---

# Problema 20 — Operador `<=>` y ordenamiento con proyecciones (C++20)

## Requerimientos

- Definir `struct Persona { string apellido, nombre; int edad; }` con `auto operator<=>(const Persona &) const = default`.
- Ordenar un `vector<Persona>` con `ranges::sort` (orden natural), luego por apellido **sin distinguir mayúsculas** (proyección con lambda) y por edad descendente (`&Persona::edad` con `ranges::greater{}`).
- Implementar `strong_ordering compararSinCaso(const string &, const string &)` usando `<=>`.
- Mostrar que `"Ana" < "ana"` es verdadero en ASCII y que `compararSinCaso("Ana", "ana")` las considera iguales.
