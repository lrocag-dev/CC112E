# Problemas sobre Structs y Funciones

## Temas cubiertos

- Definir estructuras (`struct`)
- Asignar, leer e imprimir estructuras
- Arreglos de estructuras
- Estructuras anidadas
- Punteros a estructuras
- Paso de estructuras a funciones
- Funciones y estructuras
- Manejo dinámico de memoria
- Programación modular en C++20

---

# Problema 1 — Sistema de Gestión de Satélites

Diseñe un programa para administrar información de satélites artificiales.

## Requerimientos

Definir las siguientes estructuras:

### `Fecha`
- día
- mes
- año

### `Orbita`
- altura orbital
- inclinación
- velocidad orbital

### `Satelite`
- nombre
- país
- masa
- fecha de lanzamiento
- órbita

## El programa debe:

1. Crear un arreglo dinámico de satélites.
2. Leer la información de cada satélite.
3. Imprimir toda la información almacenada.
4. Calcular:
   - el satélite de mayor masa,
   - la altura orbital promedio,
   - el país con más satélites registrados.

## Restricciones

- Todas las funciones deben recibir estructuras por referencia.
- Debe usarse al menos un puntero a estructura.

---

# Problema 2 — Registro de Estudiantes Investigadores

Diseñe un sistema para registrar estudiantes universitarios que participan en proyectos científicos.

## Estructuras

### `Proyecto`
- nombre
- área
- duración en meses

### `Estudiante`
- código
- nombre
- promedio
- arreglo de proyectos
- cantidad de proyectos

## El programa debe:

1. Permitir registrar múltiples estudiantes.
2. Imprimir todos los datos.
3. Hallar:
   - el estudiante con mayor promedio,
   - el estudiante con más proyectos,
   - el promedio global.

4. Ordenar los estudiantes por promedio.

---

# Problema 3 — Biblioteca Digital

Implemente un sistema de biblioteca digital.

## Estructuras

### `Autor`
- nombre
- nacionalidad

### `Libro`
- título
- ISBN
- número de páginas
- arreglo de autores

## Requerimientos

1. Registrar libros.
2. Mostrar catálogo completo.
3. Buscar libro por ISBN.
4. Mostrar autores de un libro usando punteros.
5. Calcular promedio de páginas.

---

# Problema 4 — Sistema Bancario

Diseñe un sistema bancario simplificado.

## Estructura `Cuenta`

- número de cuenta
- titular
- saldo
- tipo de cuenta

## Funciones requeridas

- depositar
- retirar
- transferir
- imprimir cuentas
- hallar saldo total del banco

## Restricciones

- Todas las operaciones deben realizarse usando punteros a estructuras.

---

# Problema 5 — Inventario de Reactivos Químicos

Diseñe un programa para administrar reactivos químicos.

## Estructuras

### `Fecha`
- día
- mes
- año

### `Reactivo`
- nombre
- concentración
- volumen
- fecha de vencimiento

## El programa debe:

1. Detectar reactivos vencidos.
2. Hallar el reactivo más concentrado.
3. Calcular volumen total.
4. Ordenar por fecha de vencimiento.

---

# Problema 6 — Gestión de Vuelos

Diseñe un sistema para administrar vuelos comerciales.

## Estructuras

### `Hora`
- hora
- minutos

### `Aeropuerto`
- nombre
- ciudad
- país

### `Vuelo`
- código
- origen
- destino
- capacidad
- pasajeros actuales
- hora de salida

## El programa debe:

1. Registrar vuelos.
2. Calcular ocupación porcentual.
3. Hallar vuelo más lleno.
4. Mostrar vuelos internacionales.

---

# Problema 7 — Historia Clínica

Diseñe un sistema de historial médico.

## Estructuras

### `Diagnostico`
- enfermedad
- tratamiento
- fecha

### `Paciente`
- DNI
- nombre
- edad
- arreglo de diagnósticos

## Funciones

- agregar diagnóstico
- imprimir historial
- buscar enfermedad
- calcular edad promedio

---

# Problema 8 — Red de Sensores Ambientales

Implemente un sistema de monitoreo ambiental.

## Estructura `Sensor`

- ID
- ubicación
- temperatura
- humedad
- presión

## Requerimientos

1. Leer sensores.
2. Detectar valores anómalos.
3. Hallar máximos y mínimos.
4. Calcular promedios.
5. Recorrer estructuras usando punteros.

---

# Problema 9 — Plataforma de Videojuegos

Diseñe una plataforma de videojuegos.

## Estructuras

### `Item`
- nombre
- poder
- rareza

### `Inventario`
- arreglo de items
- cantidad

### `Jugador`
- nombre
- nivel
- inventario

## El programa debe:

1. Agregar items.
2. Calcular poder total.
3. Hallar jugador más fuerte.
4. Imprimir inventarios.

---

# Problema 10 — Administración Empresarial

Diseñe un sistema empresarial.

## Estructuras

### `Empleado`
- nombre
- salario
- cargo

### `Departamento`
- nombre
- arreglo de empleados

### `Empresa`
- nombre
- arreglo de departamentos

## Requerimientos

1. Hallar salario promedio.
2. Hallar departamento con mayor gasto.
3. Imprimir organigrama completo.

---

# Problema 11 — Simulación de Partículas

Diseñe un simulador físico.

## Estructuras

### `Vector3D`
- x
- y
- z

### `Particula`
- posición
- velocidad
- masa

## Funciones

- actualizar posiciones
- calcular energía cinética
- hallar centro de masa
- imprimir partículas usando punteros

---

# Problema 12 — Sistema Meteorológico

Diseñe un sistema climático.

## Estructuras

### `Fecha`
- día
- mes
- año

### `Medicion`
- temperatura
- humedad
- velocidad del viento

## El programa debe:

1. Detectar anomalías.
2. Hallar máximos y mínimos.
3. Ordenar mediciones.
4. Generar reporte estadístico.

---

# Problema 13 — Competencias Deportivas

Diseñe un sistema de torneo.

## Estructuras

### `Jugador`
- nombre
- goles

### `Equipo`
- nombre
- arreglo de jugadores

### `Partido`
- equipo local
- equipo visitante
- marcador

## El programa debe:

1. Registrar partidos.
2. Calcular tabla de posiciones.
3. Hallar goleador.
4. Imprimir estadísticas.

---

# Problema 14 — Comercio Electrónico

Diseñe una tienda virtual.

## Estructuras

### `Producto`
- código
- nombre
- precio

### `Cliente`
- nombre
- DNI

### `Pedido`
- cliente
- arreglo de productos
- total

## El programa debe:

1. Calcular ventas totales.
2. Hallar cliente con mayor gasto.
3. Ordenar productos por precio.
4. Generar facturas.

---

# Problema 15 — Observaciones Astronómicas

Diseñe un sistema astronómico.

## Estructuras

### `Coordenada`
- ascensión recta
- declinación

### `Estrella`
- nombre
- magnitud
- coordenada

### `Observacion`
- fecha
- telescopio
- arreglo de estrellas

## Requerimientos

1. Hallar estrella más brillante.
2. Calcular distancia promedio.
3. Imprimir observaciones.
4. Usar punteros y funciones con estructuras.

---

# Recomendaciones Generales

- Utilizar `std::string`.
- Emplear memoria dinámica cuando sea necesario.
- Modularizar el programa usando funciones.
- Aplicar buenas prácticas de programación en C++20.
- Validar entradas del usuario.

