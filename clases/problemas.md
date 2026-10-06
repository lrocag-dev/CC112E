# Problemas Avanzados de C++20
## Clases, Objetos, Constructores, Herencia y Polimorfismo

---

# Problema 1 — Sistema de Empleados (Clases y Objetos)

Diseñe un sistema para gestionar empleados de una empresa.

## Requerimientos

- Crear una clase `Empleado`.
- Atributos:
  - código
  - nombre
  - salario
- Métodos:
  - ingresarDatos()
  - mostrarDatos()
- Crear múltiples objetos dinámicamente.

---

# Problema 2 — Cuenta Bancaria (Constructores y Destructores)

## Requerimientos

- Crear clase `Cuenta`.
- Implementar:
  - Constructor con parámetros
  - Constructor por defecto
  - Destructor que muestre mensaje
- Métodos:
  - depositar()
  - retirar()

---

# Problema 3 — Uso del puntero this

## Requerimientos

- Crear clase `Producto`.
- Usar `this` en el constructor para diferenciar atributos.
- Implementar encadenamiento de métodos:

```cpp
p.setNombre("X").setPrecio(10);
```

---

# Problema 4 — Sistema de Figuras (Herencia básica)

## Requerimientos

- Clase base: Figura
- Clases derivadas:
  - Triangulo
  - Rectangulo
- Método virtual:
  - calcularArea()

---

# Problema 5 — Sistema de Becarios

Diseñe un sistema que combine información académica y laboral.

## Clases

```cpp
Persona
Empleado
Estudiante
```

## Requerimientos

1. `Empleado` hereda de `Persona`.
2. `Estudiante` hereda de `Persona`.
3. Crear una clase `Becario` que herede simultáneamente de `Empleado` y `Estudiante`.
4. Mostrar toda la información del becario.
5. Resolver adecuadamente los posibles problemas de ambigüedad.

---

# Problema 6 — Catálogo de Dispositivos Electrónicos

Diseñe una clase base:

```cpp
Dispositivo
```

y las clases derivadas:

```cpp
Laptop
Tablet
Celular
```

## Requerimientos

1. Implementar constructores en todas las clases.
2. Implementar un método:

```cpp
mostrarInformacion()
```

3. Utilizar herencia jerárquica.
4. Mostrar los datos de varios dispositivos.

---

# Problema 7 — Clasificación Biológica

Diseñe la siguiente jerarquía:

```cpp
Animal
   ↓
Mamifero
   ↓
Perro
```

## Requerimientos

1. Implementar constructores en cada nivel.
2. Implementar destructores en cada nivel.
3. Mostrar el orden de construcción.
4. Mostrar el orden de destrucción.
5. Explicar el resultado obtenido.

---

# Problema 8 — Sistema de Nómina

Diseñe una clase base:

```cpp
Empleado
```

y dos clases derivadas:

```cpp
Profesor
Administrativo
```

## Requerimientos

1. Declarar:

```cpp
virtual double calcularSueldo() const;
```

2. Implementar diferentes fórmulas salariales.
3. Utilizar polimorfismo.
4. Mostrar el sueldo calculado para cada empleado.

---

# Problema 9 — Polimorfismo con Colecciones

Utilizando la jerarquía del problema anterior:

## Requerimientos

1. Crear un arreglo de punteros a `Empleado`.
2. Almacenar objetos de diferentes tipos.
3. Recorrer el arreglo.
4. Invocar:

```cpp
calcularSueldo()
```

sin conocer el tipo real del objeto.

---

# Problema 10 — Sistema de Pagos

Diseñe una clase base:

```cpp
Pago
```

## Clases derivadas

```cpp
PagoEfectivo
PagoTarjeta
PagoTransferencia
```

## Requerimientos

1. Implementar constructores parametrizados.
2. Implementar:

```cpp
virtual double calcularMontoFinal();
```

3. Aplicar diferentes cargos o descuentos.
4. Mostrar el monto final.

---

# Problema 11 — Clase Vector2D

Diseñe una clase matemática.

## Atributos

```cpp
double x;
double y;
```

## Requerimientos

Implementar:

```cpp
sumar()
escalar()
restar()
```

retornando:

```cpp
*this
```

para permitir:

```cpp
v.sumar(...)
 .escalar(...)
 .restar(...);
```

---

# Problema 12 — Sistema de Vehículos

Diseñe una clase base:

```cpp
Vehiculo
```

## Clases derivadas

```cpp
Auto
Moto
Camion
```

## Requerimientos

1. Implementar:

```cpp
virtual void mostrarInfo();
```

2. Crear un arreglo de punteros a vehículos.
3. Mostrar la información usando polimorfismo.

---

# Problema 13 — Ciclo de Vida de Objetos

Diseñe la jerarquía:

```cpp
A
 ↓
B
 ↓
C
```

## Requerimientos

1. Cada constructor debe imprimir un mensaje.
2. Cada destructor debe imprimir un mensaje.
3. Crear un objeto de tipo `C`.
4. Analizar el orden de ejecución.

---

# Problema 14 — Biblioteca de Figuras

Diseñe una clase abstracta:

```cpp
Figura
```

## Método puro virtual

```cpp
virtual double area() const = 0;
```

## Clases derivadas

```cpp
Circulo
Rectangulo
Triangulo
```

## Requerimientos

1. Implementar el método `area()`.
2. Utilizar `override`.
3. Almacenar las figuras en un arreglo de punteros.
4. Calcular el área total.

---

# Problema 15 — Sistema Integral Universitario

Diseñe una aplicación orientada a objetos que modele una universidad.

## Clases

```cpp
Persona
Profesor
Estudiante
Investigador
```

## Requerimientos

1. Utilizar herencia.
2. Utilizar polimorfismo.
3. Utilizar constructores parametrizados.
4. Utilizar destructores virtuales.
5. Implementar una clase abstracta para representar miembros de la universidad.
6. Mostrar información mediante punteros a la clase base.
7. Calcular estadísticas académicas.
8. Gestionar dinámicamente todos los objetos creados.

---

---

# Nivel C++20 — Programación moderna

Los problemas 1 al 15 se resuelven con C++11 o anterior. Los problemas 16 al 20 usan características de C++20 (y de C++14/17 que se consolidan en él). Compile con:

```bash
g++ -std=c++20 -Wall -Wextra solucionNN.cpp -o solucionNN
```

> `<format>` requiere GCC 13 o superior (o MSVC 19.29+). Verifique su compilador con `g++ --version`.

---

# Problema 16 — Polimorfismo estático con `concepts` (C++20)

## Requerimientos

- Definir `concept Figura` con una expresión `requires` que exija `area()`, `perimetro()` y `nombre()`.
- Implementar `Circulo` y `Rectangulo` **sin clase base ni `virtual`**.
- Escribir `template <Figura F> void describir(const F &)` y `masGrande`.
- Comprobar con `static_assert` que `Circulo` cumple el concepto y que `Triangulo` (sin `perimetro`) e `int` no lo cumplen.
- Guardar figuras de tipos distintos en un `vector<variant<Circulo, Rectangulo>>` y sumar sus áreas con `visit`.
- Comparar ventajas y desventajas con el polimorfismo dinámico (`virtual`).

---

# Problema 17 — Comparaciones automáticas con `<=>` (C++20)

## Requerimientos

- Clase `Version(mayor, menor, parche)` con `auto operator<=>(const Version &) const = default`; comprobar `<`, `==`, `>=`, `!=` y ordenar un vector con `ranges::sort`.
- Clase `Fraccion` que se mantenga simplificada y defina `strong_ordering operator<=>` propio (comparar `a*d` con `c*b`) y `operator==`.
- Ordenar un vector de fracciones (incluyendo negativas) y mostrar `x <=> z` como menor, mayor o equivalente.
- Explicar qué operadores genera el compilador a partir de `<=>` y `==`.

---

# Problema 18 — Prácticas modernas de diseño de clases

## Requerimientos

- Clase `Cuenta` con: inicializador de miembro, constructores delegados, constructor `explicit`, contador `inline static`, métodos `[[nodiscard]]` y `noexcept`, y `depositar` que devuelva `*this` para encadenar.
- Clases `Base`/`Derivada` donde `Base::usar()` sea `virtual ... final`, `Derivada` sea `final` y su método use `override`.
- Clase `NoCopiable` con copia eliminada (`= delete`).
- Dejar comentadas las líneas que **no** compilan y explicar cada error.

---

# Problema 19 — Regla de los cinco y semántica de movimiento

## Requerimientos

- Implementar `Buffer` con un arreglo dinámico propio: constructor, destructor, constructor de copia, asignación por copia, constructor de movimiento (`noexcept`) y asignación por movimiento. Cada uno debe imprimir un mensaje.
- Usar `std::exchange` en las operaciones de movimiento.
- Probar: construcción, copia, `move`, asignación por movimiento, retorno desde una función y `vector<Buffer>::push_back` con reubicación.
- Mostrar el estado de un objeto *movido-desde*.
- Implementar `BufferSimple` con `vector<int>` y demostrar la **regla del cero**.

---

# Problema 20 — Colección polimórfica moderna (C++20)

## Requerimientos

- Jerarquía `Empleado` (abstracta) → `Operario`, `Gerente`, `Practicante` con sueldo calculado de forma distinta; usar `using Empleado::Empleado;` para heredar constructores en la clase que no agrega atributos.
- Guardar los empleados en `vector<unique_ptr<Empleado>>` creados con `make_unique`.
- Mostrar la plantilla con `format`, ordenarla por sueldo descendente con `ranges::sort` y proyección, y mostrar solo los de sueldo mayor a 2000 con `views::filter`.
- Calcular el total y promedio de sueldos con `views::transform` y `accumulate`.
- Buscar con `ranges::find_if` y contar con `ranges::count_if`.

---

# Requisitos Generales

Todos los programas deben:

- Utilizar C++20.
- Aplicar encapsulamiento.
- Implementar constructores y destructores.
- Utilizar el puntero `this` cuando corresponda.
- Aplicar herencia correctamente.
- Aplicar polimorfismo mediante funciones virtuales.
- Liberar adecuadamente la memoria dinámica.
- Seguir buenas prácticas de programación orientada a objetos.

---

# Criterios de Evaluación

| Criterio | Peso |
|-----------|--------|
| Diseño de clases | 20% |
| Constructores y destructores | 15% |
| Uso de `this` | 10% |
| Herencia | 25% |
| Polimorfismo | 20% |
| Buenas prácticas | 10% |

**Nivel:** Avanzado  
**Lenguaje:** C++20  
**Duración sugerida:** 2–3 horas
