# Soluciones Conceptuales — Problemas Avanzados de C++20

## Gestión Dinámica, Estructuras y Archivos

---

# Problema 1 — Registro de Estudiantes en Archivo de Texto

## Idea de Solución

Utilizar un arreglo dinámico de estructuras `Estudiante`. Los datos ingresados por el usuario se almacenan temporalmente en memoria y luego se escriben en un archivo de texto usando `ofstream`.

Posteriormente, se abre el archivo con `ifstream` para recuperar la información y determinar el estudiante con mayor promedio.

## Algoritmo

1. Leer cantidad de estudiantes.
2. Reservar memoria dinámica.
3. Leer los datos de cada estudiante.
4. Abrir archivo `estudiantes.txt`.
5. Guardar los registros.
6. Cerrar archivo.
7. Reabrir archivo para lectura.
8. Mostrar contenido.
9. Determinar estudiante con mayor promedio.
10. Liberar memoria.

---

# Problema 2 — Sistema de Inventario en Archivo Binario

## Idea de Solución

Utilizar un arreglo dinámico de estructuras `Producto`. Los registros se almacenan en un archivo binario mediante `write()` y posteriormente se recuperan mediante `read()`.

## Algoritmo

1. Leer número de productos.
2. Reservar memoria dinámica.
3. Leer información de productos.
4. Abrir archivo binario.
5. Escribir todos los registros.
6. Cerrar archivo.
7. Leer nuevamente los registros.
8. Hallar producto más caro.
9. Calcular valor total del inventario.
10. Liberar memoria.

---

# Problema 3 — Directorio Telefónico de Acceso Aleatorio

## Idea de Solución

Guardar los contactos en un archivo binario de tamaño fijo.

La posición de cada registro se obtiene mediante:

```cpp
posicion = (id - 1) * sizeof(Contacto);
```

Utilizar `seekg()` y `seekp()` para acceder directamente a un registro.

## Algoritmo

1. Crear archivo binario.
2. Registrar contactos.
3. Solicitar ID.
4. Calcular posición.
5. Acceder directamente al registro.
6. Mostrar datos.
7. Modificar teléfono.
8. Sobrescribir registro.
9. Mostrar contenido actualizado.

---

# Problema 4 — Gestión de Bibliotecas

## Idea de Solución

Utilizar estructuras anidadas para representar libros y autores.

Los registros se almacenan en archivo binario. Luego se generan estadísticas y reportes en un archivo de texto.

## Algoritmo

1. Leer libros.
2. Guardar archivo binario.
3. Recorrer registros.
4. Filtrar por nacionalidad.
5. Hallar libro con más páginas.
6. Generar reporte de texto.

---

# Problema 5 — Sistema Bancario

## Idea de Solución

Cada cuenta ocupa una posición fija dentro del archivo.

Las operaciones de depósito y retiro se realizan directamente sobre el registro usando acceso aleatorio.

## Algoritmo

1. Crear archivo de cuentas.
2. Buscar cuenta por número.
3. Calcular posición.
4. Leer registro.
5. Actualizar saldo.
6. Reescribir registro.
7. Generar reporte.

---

# Problema 6 — Historia Clínica Electrónica

## Idea de Solución

Los pacientes se almacenan en un archivo binario.

Las búsquedas y actualizaciones se realizan usando identificadores únicos.

## Algoritmo

1. Registrar pacientes.
2. Guardar archivo.
3. Buscar paciente por ID.
4. Mostrar información.
5. Actualizar fecha de ingreso.
6. Exportar archivo de texto.

---

# Problema 7 — Sistema de Ventas

## Idea de Solución

Guardar cada venta como un registro binario.

Posteriormente recorrer el archivo para calcular estadísticas.

## Algoritmo

1. Registrar ventas.
2. Guardar archivo binario.
3. Leer registros.
4. Acumular montos.
5. Hallar venta máxima.
6. Generar reporte mensual.

---

# Problema 8 — Gestión de Vuelos

## Idea de Solución

Cada vuelo se almacena como registro de tamaño fijo.

La actualización de pasajeros se realiza mediante acceso aleatorio.

## Algoritmo

1. Registrar vuelos.
2. Guardar archivo.
3. Solicitar código.
4. Buscar vuelo.
5. Actualizar pasajeros.
6. Sobrescribir registro.
7. Generar informe.

---

# Problema 9 — Inventario de Equipos de Laboratorio

## Idea de Solución

Almacenar equipos en archivo binario y permitir actualizaciones directas sobre registros específicos.

## Algoritmo

1. Registrar equipos.
2. Guardar archivo.
3. Buscar por código.
4. Actualizar costo.
5. Reescribir registro.
6. Ordenar inventario.
7. Exportar reporte.

---

# Problema 10 — Registro de Sensores

## Idea de Solución

Cada lectura de sensor se almacena en archivo binario.

Posteriormente se procesan los datos para obtener estadísticas.

## Algoritmo

1. Registrar sensores.
2. Guardar archivo.
3. Leer registros.
4. Calcular temperatura promedio.
5. Calcular humedad promedio.
6. Detectar anomalías.
7. Generar reporte.

---

# Problema 11 — Catálogo Astronómico

## Idea de Solución

Las estrellas se almacenan en archivo binario de acceso aleatorio.

Las magnitudes pueden actualizarse sin recorrer todo el archivo.

## Algoritmo

1. Registrar estrellas.
2. Guardar archivo.
3. Buscar por ID.
4. Actualizar magnitud.
5. Reescribir registro.
6. Generar catálogo de texto.

---

# Problema 12 — Sistema de Reservas de Hotel

## Idea de Solución

Las reservas se almacenan en archivo binario y pueden modificarse mediante acceso directo.

## Algoritmo

1. Registrar reservas.
2. Guardar archivo.
3. Buscar reserva.
4. Modificar días.
5. Sobrescribir registro.
6. Calcular ocupación.
7. Generar informe.

---

# Problema 13 — Gestión de Empleados

## Idea de Solución

Los empleados se almacenan en archivo binario.

Los salarios pueden actualizarse mediante acceso aleatorio.

## Algoritmo

1. Registrar empleados.
2. Guardar archivo.
3. Buscar empleado.
4. Actualizar salario.
5. Calcular salario promedio.
6. Generar nómina.

---

# Problema 14 — Sistema de Competencias Deportivas

## Idea de Solución

Los participantes se almacenan en archivo binario y los puntajes se modifican directamente sobre el archivo.

## Algoritmo

1. Registrar participantes.
2. Guardar archivo.
3. Buscar participante.
4. Actualizar puntaje.
5. Reescribir registro.
6. Ordenar ranking.
7. Mostrar clasificación final.

---

# Problema 15 — Sistema Integrado de Gestión Universitaria

## Idea de Solución

Combina estructuras anidadas, memoria dinámica, archivos binarios y acceso aleatorio.

Cada alumno posee información académica y de cursos.

Las actualizaciones se realizan directamente sobre el archivo.

## Algoritmo

1. Leer número de alumnos.
2. Reservar memoria dinámica.
3. Registrar alumnos y cursos.
4. Guardar archivo binario.
5. Buscar alumno por código.
6. Actualizar promedio.
7. Reescribir registro.
8. Calcular promedio general.
9. Hallar mejor alumno.
10. Determinar curso con más inscritos.
11. Generar reporte académico en archivo de texto.
12. Liberar memoria.

---

---

# Nivel C++20 — Programación moderna

Programas completos en [`codigo/`](codigo/) (`solucion16.cpp` … `solucion20.cpp`). Compilar con `g++ -std=c++20 -Wall -Wextra`.

---

# Problema 16 — `std::filesystem`

## Idea de solución

`filesystem::path` representa rutas de forma portable (`/` compone rutas), y las funciones del espacio de nombres reemplazan comandos del sistema operativo.

## Algoritmo

1. `temp_directory_path() / "lab"` y `create_directories`.
2. Crear archivos con `ofstream(ruta) << texto`.
3. Cargar `directory_iterator` en un `vector<directory_entry>` y ordenarlo con `ranges::sort(v, {}, proyeccion)`.
4. `is_directory()`, `file_size()`, `path().extension()`.
5. `copy_file(..., overwrite_existing)`, `rename`, `exists`.
6. `recursive_directory_iterator` + `is_regular_file()`.
7. `remove_all` retorna cuántos elementos eliminó.

---

# Problema 17 — Reportes con `format`

## Idea de solución

`format` produce un `string` ya alineado; se envía al archivo con `<<`. El ámbito del `ofstream` garantiza el cierre y el volcado.

## Algoritmo

1. Abrir `ofstream out(ruta)` en un bloque `{ ... }`; verificar `if (!out)`.
2. Título: `format("{:^52}\n", "REPORTE")`.
3. Por cada venta: `format("{:<20}{:>8}{:>12.2f}{:>12.2f}\n", ...)` y acumular el total.
4. Al terminar el bloque se cierra el archivo.
5. Reabrir con `ifstream`, `getline` y numerar con `{:02d}`.

---

# Problema 18 — Importar CSV

## Idea de solución

Leer todo a memoria y analizar con vistas evita copias. `from_chars` informa errores sin excepciones.

## Algoritmo

1. `string contenido(istreambuf_iterator<char>(in), {})`.
2. Mantener `string_view resto = contenido`; en cada iteración `fin = resto.find('\n')`, `linea = resto.substr(0, fin)`, `resto.remove_prefix(...)`.
3. `analizar`: dividir por `,`; exigir 3 campos; convertir edad y nota con `from_chars`; devolver `nullopt` si algo falla.
4. Contar errores y mostrar el número de línea.
5. `ranges::sort(validos, ranges::greater{}, &Registro::nota)`.

---

# Problema 19 — Binario con `span`

## Idea de solución

Un tipo trivialmente copiable se puede volcar byte a byte. `span<const T>` aporta `data()` y `size_bytes()` para escribir el arreglo completo con una sola llamada.

## Algoritmo

1. `static_assert(is_trivially_copyable_v<Sensor>)` evita volcar tipos con punteros internos (como `string`).
2. `out.write(reinterpret_cast<const char *>(datos.data()), datos.size_bytes())`.
3. Leer: `seekg(0, end)`, `tellg()` = bytes; `v(bytes / sizeof(T))`; `in.read(...)`.
4. Acceso aleatorio: el registro `i` empieza en `i * sizeof(Sensor)`; leer, modificar, `seekp` y escribir.
5. `as_bytes(span(&d, 1))` expone los 8 bytes del `double` (en little-endian `1.0` es `00 00 00 00 00 00 f0 3f`).

> Los archivos binarios de este tipo dependen de la arquitectura y del relleno (*padding*): no son portables entre sistemas.

---

# Problema 20 — RAII y `source_location`

## Idea de solución

Si el recurso se adquiere en el constructor y se libera en el destructor, el archivo se cierra aunque se lance una excepción. `source_location::current()` como argumento por defecto captura el lugar de la **llamada**.

## Algoritmo

1. `ArchivoTexto(path, source_location loc = current())`: `in.open(ruta)`; si falla, `throw runtime_error(format(..., loc.line()))`.
2. Copia eliminada: `ArchivoTexto(const ArchivoTexto &) = delete;`.
3. Destructor: mostrar `[cerrando ...]`.
4. `contarLineas` crea el objeto; si el constructor lanza, el destructor **no** se ejecuta (el objeto no llegó a existir); si la lectura termina, se ejecuta al salir.
5. `registrarError` imprime `loc.file_name()`, `loc.line()` y `loc.function_name()`.
6. `fs::file_size` de una ruta inexistente lanza `filesystem_error`.

---

# Competencias Evaluadas

* Gestión dinámica de memoria.
* Estructuras simples y anidadas.
* Archivos de texto.
* Archivos binarios.
* Acceso aleatorio.
* Búsqueda y actualización de registros.
* Programación modular.
* C++20.
