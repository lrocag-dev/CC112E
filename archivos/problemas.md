# Problemas Avanzados de C++20
## Gestión Dinámica, Estructuras y Archivos

### Temas cubiertos

- Memoria dinámica
- Estructuras (`struct`)
- Arreglos dinámicos de estructuras
- Archivos de texto
- Archivos binarios
- Archivos de acceso aleatorio
- Búsqueda y actualización de registros
- Persistencia de datos
- Programación modular en C++20

---

# Problema 1 — Registro de Estudiantes en Archivo de Texto

Diseñe un programa que permita registrar estudiantes universitarios.

## Estructura

```cpp
struct Estudiante {
    int codigo;
    char nombre[50];
    double promedio;
};
```

## Requerimientos

1. Crear dinámicamente un arreglo de estudiantes.
2. Leer los datos desde teclado.
3. Guardar toda la información en un archivo de texto llamado `estudiantes.txt`.
4. Leer posteriormente el archivo e imprimir su contenido.
5. Mostrar el estudiante con mayor promedio.

---

# Problema 2 — Sistema de Inventario en Archivo Binario

Diseñe un sistema para administrar productos.

## Estructura

```cpp
struct Producto {
    int codigo;
    char nombre[50];
    double precio;
    int stock;
};
```

## Requerimientos

1. Crear un arreglo dinámico de productos.
2. Guardar los registros en un archivo binario.
3. Leer el archivo binario.
4. Mostrar el producto más caro.
5. Calcular el valor total del inventario.

---

# Problema 3 — Directorio Telefónico de Acceso Aleatorio

Diseñe una aplicación para almacenar contactos.

## Estructura

```cpp
struct Contacto {
    int id;
    char nombre[50];
    char telefono[20];
};
```

## Requerimientos

1. Crear un archivo binario de acceso aleatorio.
2. Permitir acceder directamente a un contacto mediante su ID.
3. Modificar el teléfono de un contacto sin leer todo el archivo.
4. Mostrar el contenido completo del archivo.

---

# Problema 4 — Gestión de Bibliotecas

## Estructuras

```cpp
struct Autor {
    char nombre[50];
    char nacionalidad[30];
};

struct Libro {
    int codigo;
    char titulo[100];
    Autor autor;
    int paginas;
};
```

## Requerimientos

1. Almacenar libros en un archivo binario.
2. Buscar libros por nacionalidad del autor.
3. Mostrar el libro con más páginas.
4. Crear un archivo de texto con un reporte estadístico.

---

# Problema 5 — Sistema Bancario

## Estructura

```cpp
struct Cuenta {
    int numero;
    char titular[50];
    double saldo;
};
```

## Requerimientos

1. Almacenar cuentas en un archivo binario.
2. Implementar depósitos y retiros mediante acceso aleatorio.
3. Buscar cuentas por número.
4. Generar un reporte en archivo de texto.

---

# Problema 6 — Historia Clínica Electrónica

## Estructuras

```cpp
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Paciente {
    int id;
    char nombre[50];
    Fecha ingreso;
};
```

## Requerimientos

1. Registrar pacientes en archivo binario.
2. Buscar pacientes por ID.
3. Actualizar la fecha de ingreso.
4. Exportar un listado completo a archivo de texto.

---

# Problema 7 — Sistema de Ventas

## Estructura

```cpp
struct Venta {
    int codigo;
    char producto[50];
    double monto;
};
```

## Requerimientos

1. Almacenar ventas en archivo binario.
2. Calcular ventas totales.
3. Hallar la venta de mayor monto.
4. Generar un reporte mensual en archivo de texto.

---

# Problema 8 — Gestión de Vuelos

## Estructura

```cpp
struct Vuelo {
    int codigo;
    char origen[30];
    char destino[30];
    int pasajeros;
};
```

## Requerimientos

1. Crear un archivo binario de vuelos.
2. Permitir modificar el número de pasajeros usando acceso aleatorio.
3. Mostrar el vuelo con más pasajeros.
4. Crear un informe en texto.

---

# Problema 9 — Inventario de Equipos de Laboratorio

## Estructura

```cpp
struct Equipo {
    int codigo;
    char nombre[50];
    double costo;
};
```

## Requerimientos

1. Guardar equipos en archivo binario.
2. Buscar equipos por código.
3. Actualizar costos.
4. Exportar inventario ordenado por costo.

---

# Problema 10 — Registro de Sensores

## Estructura

```cpp
struct Sensor {
    int id;
    double temperatura;
    double humedad;
};
```

## Requerimientos

1. Almacenar mediciones en archivo binario.
2. Calcular promedios.
3. Detectar valores anómalos.
4. Generar reporte en texto.

---

# Problema 11 — Catálogo Astronómico

## Estructura

```cpp
struct Estrella {
    int id;
    char nombre[50];
    double magnitud;
};
```

## Requerimientos

1. Almacenar estrellas en archivo binario.
2. Buscar por ID mediante acceso aleatorio.
3. Actualizar magnitudes.
4. Generar catálogo en texto.

---

# Problema 12 — Sistema de Reservas de Hotel

## Estructura

```cpp
struct Reserva {
    int codigo;
    char cliente[50];
    int dias;
};
```

## Requerimientos

1. Registrar reservas.
2. Buscar reservas por código.
3. Modificar días de estadía.
4. Generar informe de ocupación.

---

# Problema 13 — Gestión de Empleados

## Estructura

```cpp
struct Empleado {
    int codigo;
    char nombre[50];
    double salario;
};
```

## Requerimientos

1. Guardar empleados en archivo binario.
2. Actualizar salarios mediante acceso aleatorio.
3. Hallar salario promedio.
4. Crear reporte de nómina.

---

# Problema 14 — Sistema de Competencias Deportivas

## Estructura

```cpp
struct Participante {
    int codigo;
    char nombre[50];
    int puntaje;
};
```

## Requerimientos

1. Registrar participantes.
2. Buscar por código.
3. Actualizar puntajes usando acceso aleatorio.
4. Mostrar ranking ordenado.

---

# Problema 15 — Sistema Integrado de Gestión Universitaria

## Estructuras

```cpp
struct Curso {
    int codigo;
    char nombre[50];
    int creditos;
};

struct Alumno {
    int codigo;
    char nombre[50];
    double promedio;
    Curso curso;
};
```

## Requerimientos

1. Crear dinámicamente un arreglo de alumnos.
2. Guardar información en archivo binario.
3. Buscar alumnos por código usando acceso aleatorio.
4. Actualizar promedios directamente en el archivo.
5. Generar un reporte académico en archivo de texto.
6. Mostrar:
   - alumno con mayor promedio,
   - promedio general,
   - curso con más alumnos inscritos.

---

---

# Nivel C++20 — Programación moderna

Los problemas 1 al 15 se resuelven con C++11 o anterior. Los problemas 16 al 20 usan características de C++20 (y de C++14/17 que se consolidan en él). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior (o MSVC 19.29+). Verifique su compilador con `g++ --version`.

---

# Problema 16 — `std::filesystem`: carpetas y archivos (C++17/20)

## Requerimientos

- Crear una carpeta temporal con `create_directories` y dentro algunos archivos de prueba.
- Listar su contenido ordenado por nombre indicando si es directorio, el tamaño y la extensión.
- Copiar un archivo (`copy_file`), renombrarlo (`rename`) y comprobar `exists`.
- Mostrar `stem()`, `extension()` y `parent_path()` de una ruta.
- Recorrer recursivamente con `recursive_directory_iterator` sumando tamaños y contando archivos regulares.
- Eliminar todo con `remove_all`.

---

# Problema 17 — Reportes de texto con `format` (C++20)

## Requerimientos

- Dado un `vector<Venta>` (producto, cantidad, precio), escribir en un archivo de texto un reporte con título centrado, columnas alineadas, línea de separación y total.
- Usar `format` con anchos y precisión (`{:<20}{:>8}{:>12.2f}`).
- Cerrar el archivo mediante RAII (ámbito del `ofstream`).
- Volver a leer el archivo y mostrarlo con numeración de líneas (`{:02d}`).

---

# Problema 18 — Importar CSV con `string_view` y `from_chars` (C++20)

## Requerimientos

- Crear un CSV con registros `nombre,edad,nota`, incluyendo líneas inválidas.
- Leer **todo** el archivo en un `string` con `istreambuf_iterator`.
- Recorrer las líneas con `string_view` sin crear copias y analizar cada una con `optional<Registro> analizar(string_view)`; los números se convierten con `from_chars`.
- Informar el número y el contenido de las líneas inválidas.
- Ordenar los registros válidos por nota descendente (`ranges::sort` con proyección) y mostrarlos con enlaces estructurados.

---

# Problema 19 — Archivos binarios con `span` y *concepts* (C++20)

## Requerimientos

- Definir `struct Sensor { int32_t id; double lectura; char nombre[16]; }` y verificar con `static_assert(is_trivially_copyable_v<Sensor>)`.
- Implementar `template <typename T> requires is_trivially_copyable_v<T> void escribir(ofstream &, span<const T>)` que escriba un arreglo completo con `size_bytes()`.
- Implementar `leer<T>(ruta)` que devuelva un `vector<T>` calculando la cantidad de registros desde el tamaño del archivo.
- Modificar solo el segundo registro con acceso aleatorio (`seekg`/`seekp`).
- Mostrar los bytes de un `double` con `as_bytes(span(&d, 1))`.

---

# Problema 20 — Manejo de errores con RAII y `source_location` (C++20)

## Requerimientos

- Implementar la clase `ArchivoTexto` que abra el archivo en el constructor, lance `runtime_error` si falla (indicando la línea desde la que se pidió) y muestre un mensaje en el destructor.
- Prohibir su copia con `= delete`.
- Implementar `registrarError(const string &, source_location = source_location::current())` que imprima archivo, línea y función.
- Probar con un archivo existente y con otro inexistente; capturar también `filesystem::filesystem_error`.
- Comprobar que el archivo se cierra en ambos casos (también cuando hay excepción).

---

# Requisitos Generales

Todos los programas deben:

- Utilizar memoria dinámica (`new` y `delete`).
- Utilizar estructuras (`struct`).
- Implementar funciones para lectura y escritura.
- Utilizar archivos de texto y/o binarios.
- Validar la apertura de archivos.
- Evitar fugas de memoria.
- Compilar correctamente en C++20.

---

# Criterios de Evaluación

| Criterio | Peso |
|-----------|--------|
| Gestión dinámica de memoria | 20% |
| Uso correcto de estructuras | 20% |
| Archivos de texto | 15% |
| Archivos binarios | 20% |
| Acceso aleatorio | 15% |
| Modularidad y buenas prácticas | 10% |

**Nivel:** Avanzado  
**Lenguaje:** C++20  
**Duración sugerida:** 2 a 3 horas
