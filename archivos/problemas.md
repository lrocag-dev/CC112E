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
