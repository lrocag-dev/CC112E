# Framework de Solución para Problemas de Cadenas en C++20

## Objetivo

Plantillas reutilizables para resolver ejercicios de:

- Caracteres ASCII y aritmética de caracteres
- Cadenas de estilo C (`char[]`, `char *`)
- Entrada y salida de cadenas
- Funciones de `<cstring>`, `<cctype>` y `<cstdlib>`
- Conversión entre cadenas y números

---

# Plantilla 1 — Declaración y entrada de cadenas

```cpp
char s[100];                 // capacidad 100: maximo 99 caracteres + '\0'
char t[] = "hola";           // tamano 5
const char *u = "literal";   // no modificable

cin >> s;                    // lee UNA palabra (corta en el espacio)
cin.getline(s, 100);         // lee la linea completa

int n;
cin >> n;
cin.ignore();                // descarta el '\n' antes de un getline
cin.getline(s, 100);
```

Salida: `cout << s << endl;` o `puts(s);`.

---

# Plantilla 2 — Recorrido de una cadena

```cpp
for (int i = 0; s[i] != '\0'; i++)
    procesar(s[i]);

for (char *p = s; *p; p++)
    procesar(*p);

int n = strlen(s);           // calcular una vez si se usa en el ciclo
```

---

# Plantilla 3 — Aritmética de caracteres

```cpp
int digito  = c - '0';                 // '7' -> 7
char letra  = 'a' + 3;                 // 'd'
int indice  = c - 'a';                 // 'c' -> 2 (para tablas de frecuencia)
char mayus  = c - ('a' - 'A');         // 'a'..'z' -> 'A'..'Z'
char rotada = 'a' + (c - 'a' + k) % 26;
```

---

# Plantilla 4 — Funciones de `<cctype>`

```cpp
#include <cctype>

isalpha(c)  isdigit(c)  isalnum(c)  isspace(c)
isupper(c)  islower(c)  ispunct(c)
toupper(c)  tolower(c)
```

Si `c` es un `char` con signo, convertir primero: `isalpha(static_cast<unsigned char>(c))`.

---

# Plantilla 5 — Funciones de `<cstring>`

```cpp
#include <cstring>

strlen(s)               // longitud (sin '\0')
strcpy(dest, src)       // copia; dest debe tener espacio
strncpy(dest, src, n)   // copia a lo mas n; NO garantiza '\0'
strcat(dest, src)       // concatena
strcmp(a, b)            // <0, 0, >0
strncmp(a, b, n)
strchr(s, c)            // puntero a la primera aparicion de c o nullptr
strrchr(s, c)           // ultima aparicion
strstr(s, sub)          // puntero a la subcadena o nullptr
strtok(s, delim)        // primera llamada con s; luego con nullptr
```

Patrón seguro para `strncpy`:

```cpp
strncpy(dest, src, n);
dest[n] = '\0';
```

---

# Plantilla 6 — Implementar una función de cadena con punteros

```cpp
char *miStrcpy(char *destino, const char *origen)
{
    char *d = destino;
    while ((*d++ = *origen++) != '\0')
        ;
    return destino;
}
```

---

# Plantilla 7 — Tabla de frecuencias

```cpp
int f[26] = {0};
for (const char *p = s; *p; p++)
    if (isalpha(static_cast<unsigned char>(*p)))
        f[tolower(*p) - 'a']++;

// para cualquier caracter
int g[256] = {0};
for (const char *p = s; *p; p++)
    g[static_cast<unsigned char>(*p)]++;
```

---

# Plantilla 8 — Dividir una cadena con `strtok`

```cpp
char copia[100];
strcpy(copia, linea);                  // strtok modifica la cadena
for (char *t = strtok(copia, ",; "); t; t = strtok(nullptr, ",; "))
    cout << t << endl;
```

---

# Plantilla 9 — Conversiones

```cpp
#include <cstdlib>
#include <string>

int    a = atoi("42");
double b = atof("3.14");

char *fin;
long   c = strtol("123abc", &fin, 10);   // fin apunta a "abc"
double d = strtod("2.5x", &fin);         // fin apunta a "x"
if (fin == texto) { /* no se convirtio nada */ }

string s = to_string(3.14);              // "3.140000"
int e = stoi("77");                      // lanza excepcion si es invalido
```

---

# Errores frecuentes

| Error | Consecuencia |
|---|---|
| Olvidar el `'\0'` al construir una cadena a mano | Se imprime basura hasta encontrar un `0` |
| Cadena destino demasiado pequeña en `strcpy`/`strcat` | Desbordamiento de buffer |
| `if (s1 == s2)` para comparar cadenas | Compara direcciones, no contenido: usar `strcmp` |
| `cin >> n` seguido de `getline` sin `cin.ignore()` | `getline` lee una línea vacía |
| Modificar un literal (`char *p = "hola"; p[0] = 'H';`) | Comportamiento indefinido |
| Usar `strtok` sobre un literal o sobre la cadena original | Falla o pierde la cadena |
| Llamar `strlen` en la condición de un ciclo largo | Complejidad O(n²) |
