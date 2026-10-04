# Soluciones — Problemas Avanzados de C++20 con Structs

# Problema 1 — Sistema de Gestión de Satélites

## Idea de solución

### Estructuras

```cpp
struct Fecha {
    int dia, mes, anio;
};

struct Orbita {
    double altura;
    double inclinacion;
    double velocidad;
};

struct Satelite {
    std::string nombre;
    std::string pais;
    double masa;
    Fecha lanzamiento;
    Orbita orbita;
};
```

### Funciones principales

```cpp
void leerSatelite(Satelite& s);
void imprimirSatelite(const Satelite& s);
double alturaPromedio(const std::vector<Satelite>& v);
int indiceMayorMasa(const std::vector<Satelite>& v);
```

### Algoritmo

1. Leer cantidad de satélites.
2. Crear `vector<Satelite>`.
3. Leer datos.
4. Recorrer para hallar:
   - mayor masa
   - promedio orbital
5. Imprimir resultados.

---

# Problema 2 — Registro de Estudiantes Investigadores

## Estructuras

```cpp
struct Proyecto {
    std::string nombre;
    std::string area;
    int duracion;
};

struct Estudiante {
    int codigo;
    std::string nombre;
    double promedio;
    std::vector<Proyecto> proyectos;
};
```

## Funciones

```cpp
void leerEstudiante(Estudiante& e);
void imprimirEstudiante(const Estudiante& e);
double promedioGlobal(const std::vector<Estudiante>& v);
```

## Ordenamiento

Usar:

```cpp
std::sort(v.begin(), v.end(),
[](const Estudiante& a, const Estudiante& b){
    return a.promedio > b.promedio;
});
```

---

# Problema 3 — Biblioteca Digital

## Estructuras

```cpp
struct Autor {
    std::string nombre;
    std::string nacionalidad;
};

struct Libro {
    std::string titulo;
    std::string isbn;
    int paginas;
    std::vector<Autor> autores;
};
```

## Funciones

```cpp
Libro* buscarISBN(std::vector<Libro>& libros, const std::string& isbn);
void imprimirLibro(const Libro& l);
```

## Idea

- Buscar ISBN recorriendo vector.
- Calcular promedio de páginas acumulando total.

---

# Problema 4 — Sistema Bancario

## Estructura

```cpp
struct Cuenta {
    int numero;
    std::string titular;
    double saldo;
    std::string tipo;
};
```

## Operaciones

```cpp
void depositar(Cuenta* c, double monto) {
    c->saldo += monto;
}

bool retirar(Cuenta* c, double monto) {
    if (monto > c->saldo) return false;
    c->saldo -= monto;
    return true;
}
```

## Transferencia

```cpp
bool transferir(Cuenta* a, Cuenta* b, double monto) {
    if (!retirar(a, monto)) return false;
    depositar(b, monto);
    return true;
}
```

---

# Problema 5 — Inventario de Reactivos

## Estructuras

```cpp
struct Fecha {
    int dia, mes, anio;
};

struct Reactivo {
    std::string nombre;
    double concentracion;
    double volumen;
    Fecha vencimiento;
};
```

## Funciones

```cpp
bool vencido(const Reactivo& r);
Reactivo mayorConcentracion(const std::vector<Reactivo>& v);
```

## Ordenamiento

Ordenar por fecha usando `std::sort`.

---

# Problema 6 — Gestión de Vuelos

## Estructuras

```cpp
struct Hora {
    int hora, minuto;
};

struct Aeropuerto {
    std::string nombre;
    std::string ciudad;
    std::string pais;
};

struct Vuelo {
    std::string codigo;
    Aeropuerto origen;
    Aeropuerto destino;
    int capacidad;
    int pasajeros;
    Hora salida;
};
```

## Cálculo de ocupación

```cpp
float ocupacion(const Vuelo& v) {
    return 100.0f * v.pasajeros / v.capacidad;
}
```

---

# Problema 7 — Historia Clínica

## Estructuras

```cpp
struct Diagnostico {
    std::string enfermedad;
    std::string tratamiento;
    std::string fecha;
};

struct Paciente {
    std::string dni;
    std::string nombre;
    int edad;
    std::vector<Diagnostico> historial;
};
```

## Funciones

```cpp
void agregarDiagnostico(Paciente& p, const Diagnostico& d);
void imprimirHistorial(const Paciente& p);
```

---

# Problema 8 — Red de Sensores

## Estructura

```cpp
struct Sensor {
    int id;
    std::string ubicacion;
    double temperatura;
    double humedad;
    double presion;
};
```

## Funciones

```cpp
bool anomalo(const Sensor& s);
double promedioTemperatura(const std::vector<Sensor>& v);
```

## Uso de punteros

```cpp
Sensor* p = &sensores[i];
std::cout << p->temperatura;
```

---

# Problema 9 — Plataforma de Videojuegos

## Estructuras

```cpp
struct Item {
    std::string nombre;
    int poder;
    int rareza;
};

struct Inventario {
    std::vector<Item> items;
};

struct Jugador {
    std::string nombre;
    int nivel;
    Inventario inventario;
};
```

## Poder total

```cpp
int poderTotal(const Jugador& j) {
    int suma = 0;
    for (const auto& x : j.inventario.items)
        suma += x.poder;
    return suma;
}
```

---

# Problema 10 — Administración Empresarial

## Estructuras

```cpp
struct Empleado {
    std::string nombre;
    double salario;
    std::string cargo;
};

struct Departamento {
    std::string nombre;
    std::vector<Empleado> empleados;
};

struct Empresa {
    std::string nombre;
    std::vector<Departamento> departamentos;
};
```

## Cálculo de gastos

```cpp
double gastoDepartamento(const Departamento& d) {
    double total = 0;
    for (const auto& e : d.empleados)
        total += e.salario;
    return total;
}
```

---

# Problema 11 — Simulación de Partículas

## Estructuras

```cpp
struct Vector3D {
    double x, y, z;
};

struct Particula {
    Vector3D posicion;
    Vector3D velocidad;
    double masa;
};
```

## Energía cinética

```cpp
double energia(const Particula& p) {
    double v2 = p.velocidad.x*p.velocidad.x
              + p.velocidad.y*p.velocidad.y
              + p.velocidad.z*p.velocidad.z;

    return 0.5 * p.masa * v2;
}
```

---

# Problema 12 — Sistema Meteorológico

## Estructuras

```cpp
struct Medicion {
    double temperatura;
    double humedad;
    double viento;
};
```

## Funciones

```cpp
double maximaTemperatura(const std::vector<Medicion>& v);
double promedioHumedad(const std::vector<Medicion>& v);
```

---

# Problema 13 — Competencias Deportivas

## Estructuras

```cpp
struct Jugador {
    std::string nombre;
    int goles;
};

struct Equipo {
    std::string nombre;
    std::vector<Jugador> jugadores;
    int puntos;
};
```

## Tabla de posiciones

```cpp
void actualizarPuntos(Equipo& e, int resultado);
```

Donde:
- 3 → victoria
- 1 → empate
- 0 → derrota

---

# Problema 14 — Comercio Electrónico

## Estructuras

```cpp
struct Producto {
    int codigo;
    std::string nombre;
    double precio;
};

struct Cliente {
    std::string nombre;
    std::string dni;
};

struct Pedido {
    Cliente cliente;
    std::vector<Producto> productos;
    double total;
};
```

## Total de pedido

```cpp
void calcularTotal(Pedido& p) {
    p.total = 0;
    for (const auto& x : p.productos)
        p.total += x.precio;
}
```

---

# Problema 15 — Observaciones Astronómicas

## Estructuras

```cpp
struct Coordenada {
    double ascension;
    double declinacion;
};

struct Estrella {
    std::string nombre;
    double magnitud;
    Coordenada posicion;
};

struct Observacion {
    std::string fecha;
    std::string telescopio;
    std::vector<Estrella> estrellas;
};
```

## Estrella más brillante

```cpp
Estrella masBrillante(const Observacion& o) {
    Estrella mejor = o.estrellas[0];

    for (const auto& e : o.estrellas)
        if (e.magnitud < mejor.magnitud)
            mejor = e;

    return mejor;
}
```

---

---

# Nivel C++20 — Programación moderna

Programas completos en [`codigo/`](codigo/) (`solucion16.cpp` … `solucion20.cpp`). Compilar con `g++ -std=c++20 -Wall -Wextra`.

---

# Problema 16 — Inicializadores designados

## Idea de solución

C++20 permite `T{.campo = valor, ...}` para tipos agregados (sin constructores). Los campos omitidos toman su valor por defecto o `0`.

## Algoritmo

1. Declarar valores por defecto en la estructura (`double altitudKm = 400.0`).
2. Inicializar con `.nombre = ...` y los campos necesarios, **en el orden declarado**.
3. Guardar en el `vector` (puede ir un inicializador designado directamente dentro de `{...}`).
4. Contar `activo == true` y sumar `masaKg` en un solo recorrido.
5. Usar `format("{:<10} {:>7.1f}", ...)` para la tabla.

---

# Problema 17 — Enlaces estructurados y `<=>`

## Idea de solución

Los enlaces estructurados (`auto [a, b, c] = obj`) desempaquetan estructuras, pares y tuplas. `= default` en `<=>` genera todas las comparaciones por orden de declaración.

## Algoritmo

1. `for (const auto &[n, c, nt] : v)` recorre sin copiar.
2. La función `resumir` retorna `Resumen{prom, mx, mn}`; el llamador usa `auto [p, mx, mn] = resumir(v);`.
3. `ranges::sort(v)` ordena por nombre, luego código y luego nota.
4. `ranges::sort(v, ranges::greater{}, &Estudiante::nota)`.
5. `notas[e.nombre].push_back(e.nota)` agrupa; al recorrer el `map`, cada elemento es `[clave, valor]`.

---

# Problema 18 — `optional`

## Idea de solución

`optional<T>` representa "un `T` o nada" en el sistema de tipos, evitando valores centinela (`-1`) y punteros nulos para ausencia.

## Algoritmo

1. `buscar`: recorrer; `return l;` si coincide, `return nullopt;` al final.
2. Uso: `if (auto l = buscar(id)) { l->titulo ... }` (el `optional` se evalúa como booleano).
3. `prestar`: `if (auto *l = buscarRef(id); l && l->stock > 0)` limita el alcance de `l` al `if`.
4. `value_or(valor)` entrega un valor alternativo si está vacío.

---

# Problema 19 — `variant` y `visit`

## Idea de solución

`variant<A, B, C>` es una unión segura: guarda exactamente uno de los tipos y sabe cuál. `visit` aplica un visitante al valor activo.

## Algoritmo

1. Objeto-función con `operator()(int)`, `(double)` y `(const string &)`: `visit(Mostrar{}, m.valor)`.
2. Lambda genérica: `if constexpr (is_arithmetic_v<T>) suma += v;` ignora el caso `string` en compilación.
3. `m.valor.index()` es 0, 1 o 2 según el tipo.
4. `get_if<double>(&m.valor)` devuelve puntero o `nullptr`.
5. `get<int>` con el tipo equivocado lanza `bad_variant_access`.

---

# Problema 20 — Estructuras `constexpr`

## Idea de solución

Una estructura simple con funciones miembro `constexpr` puede usarse en cálculos de compilación. `static_assert` convierte propiedades matemáticas en pruebas que se ejecutan al compilar.

## Algoritmo

1. Operadores `constexpr` que retornan `Punto{...}`.
2. `static_assert((Punto{1,2} + Punto{3,4}) == Punto{4,6})`.
3. Area: `|(x1-x0)(y2-y0) - (x2-x0)(y1-y0)| / 2` (para (0,0), (4,0), (0,3) da 6).
4. `consteval trayectoria(inicio, vel)`: `t[i] = inicio + vel * i`.
5. `ranges::find(constantes, buscado, &Constante::nombre)` busca por campo; `max_element(..., &Constante::valor)` halla la mayor.

---

# Recomendaciones Finales

## Buenas prácticas

- Usar `const` correctamente.
- Pasar estructuras grandes por referencia.
- Utilizar `std::vector`.
- Modularizar funciones.
- Validar entradas.
- Separar archivos `.h` y `.cpp`.

## Temas aplicados

- Structs
- Arreglos de estructuras
- Structs anidados
- Funciones con structs
- Punteros a structs
- Programación modular
- C++20

