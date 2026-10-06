# Soluciones Conceptuales — C++20 (Clases, Herencia y Polimorfismo)

## Problemas Avanzados — Ideas de Solución y Algoritmos

---

# Problema 1 — Sistema de Empleados

## Idea de solución

Se define una clase `Empleado` con atributos privados y métodos públicos. Se crean objetos dinámicos usando `new`.

## Algoritmo

1. Definir clase `Empleado`.
2. Implementar métodos de entrada y salida.
3. Crear arreglo dinámico de objetos.
4. Llenar datos desde teclado.
5. Mostrar información.
6. Liberar memoria.

---

# Problema 2 — Cuenta Bancaria

## Idea de solución

Uso de constructores sobrecargados y destructor para rastrear ciclo de vida del objeto.

## Algoritmo

1. Definir clase `Cuenta`.
2. Crear constructor por defecto y parametrizado.
3. Implementar destructor con mensaje.
4. Implementar métodos `depositar` y `retirar`.
5. Probar creación y destrucción de objetos.

---

# Problema 3 — Uso de `this`

## Idea de solución

Usar `this` para diferenciar atributos y retornar referencia al objeto actual.

## Algoritmo

1. Crear clase `Producto`.
2. Usar `this->atributo = atributo`.
3. Retornar `*this` en métodos.
4. Permitir encadenamiento de llamadas.
5. Probar asignaciones encadenadas.

---

# Problema 4 — Herencia básica (Figura)

## Idea de solución

Clase base abstracta `Figura` con método virtual `calcularArea()`.

## Algoritmo

1. Crear clase base.
2. Definir método virtual.
3. Crear clases derivadas.
4. Sobrescribir método.
5. Usar punteros a clase base.

---

# Problema 5 — Herencia múltiple

## Idea de solución

Clase `Becario` hereda de `Empleado` y `Estudiante`.

## Algoritmo

1. Crear clases base.
2. Definir atributos independientes.
3. Crear clase derivada múltiple.
4. Resolver ambigüedad con scope.
5. Mostrar datos combinados.

---

# Problema 6 — Herencia jerárquica

## Idea de solución

Una clase base `Dispositivo` y múltiples derivadas.

## Algoritmo

1. Definir clase base.
2. Crear clases hijas.
3. Sobrescribir métodos.
4. Usar arreglo de punteros base.
5. Mostrar comportamiento.

---

# Problema 7 — Herencia multinivel

## Idea de solución

Encadenamiento de herencia en tres niveles.

## Algoritmo

1. Crear `Animal`.
2. Crear `Mamifero`.
3. Crear `Perro`.
4. Llamar constructores en cadena.
5. Mostrar ejecución.

---

# Problema 8 — Polimorfismo básico

## Idea de solución

Método virtual `calcularSueldo()` redefinido en clases hijas.

## Algoritmo

1. Definir clase base.
2. Crear clases derivadas.
3. Sobrescribir método virtual.
4. Usar punteros base.
5. Ejecutar polimorfismo dinámico.

---

# Problema 9 — Polimorfismo con punteros

## Idea de solución

Uso de array de punteros a clase base.

## Algoritmo

1. Crear clase base.
2. Crear derivadas.
3. Crear arreglo de punteros.
4. Asignar objetos dinámicos.
5. Ejecutar métodos virtuales.

---

# Problema 10 — Sistema de Pagos

## Idea de solución

Herencia con constructores propios en cada tipo de pago.

## Algoritmo

1. Crear clase base `Pago`.
2. Crear derivadas.
3. Sobrescribir métodos.
4. Instanciar objetos.
5. Ejecutar cálculo de pago.

---

# Problema 11 — Uso avanzado de `this`

## Idea de solución

Encadenamiento de operaciones en clase `Vector2D`.

## Algoritmo

1. Crear clase.
2. Implementar métodos que retornan `*this`.
3. Encadenar operaciones.
4. Probar suma y escalado.

---

# Problema 12 — Sistema de Vehículos

## Idea de solución

Polimorfismo con método `mostrarInfo()`.

## Algoritmo

1. Crear clase base.
2. Crear derivadas.
3. Sobrescribir método.
4. Usar arreglo polimórfico.
5. Mostrar información.

---

# Problema 13 — Constructores y destructores

## Idea de solución

Observar orden de construcción/destrucción.

## Algoritmo

1. Crear jerarquía.
2. Agregar mensajes en constructores.
3. Agregar destructor.
4. Instanciar objetos.
5. Observar orden.

---

# Problema 14 — override

## Idea de solución

Uso de `override` para asegurar sobreescritura correcta.

## Algoritmo

1. Crear clase base con método virtual.
2. Crear derivadas.
3. Usar `override`.
4. Ejecutar polimorfismo.
5. Validar comportamiento.

---

# Problema 15 — Sistema Integral OO

## Idea de solución

Combinar herencia múltiple, polimorfismo y clases abstractas.

## Algoritmo

1. Definir clases abstractas.
2. Crear jerarquías.
3. Implementar polimorfismo.
4. Usar punteros base.
5. Integrar sistema completo.
6. Mostrar resultados globales.

---

---

# Nivel C++20 — Programación moderna

Programas completos en [`codigo/`](codigo/) (`solucion16.cpp` … `solucion20.cpp`). Compilar con `g++ -std=c++20 -Wall -Wextra`.

---

# Problema 16 — Polimorfismo estático

## Idea de solución

Un `concept` define una interfaz **implícita** verificada en compilación. No hay tabla virtual ni indirección, pero todos los elementos de una colección deben ser del mismo tipo (o usar `variant`).

## Algoritmo

1. `concept Figura = requires(const T &f){ { f.area() } -> convertible_to<double>; ... }`.
2. `Circulo` y `Rectangulo` implementan los tres métodos; no heredan de nada.
3. `describir<Figura F>` y `masGrande<Figura F>(F, F)` solo aceptan tipos que cumplan el concepto.
4. `static_assert(Figura<Circulo>)`, `static_assert(!Figura<Triangulo>)`.
5. `visit([](const auto &x){ return x.area(); }, f)` sobre `variant` suma áreas de tipos distintos.

| Dinámico (`virtual`) | Estático (`concept`) |
|---|---|
| Decide en ejecución | Decide en compilación |
| Colección heterogénea simple | Colección homogénea o `variant` |
| Costo de indirección | Sin costo adicional |
| Requiere herencia | No requiere herencia |

---

# Problema 17 — `<=>`

## Idea de solución

`a <=> b` devuelve un resultado de ordenamiento (`strong_ordering`, `weak_ordering` o `partial_ordering`). A partir de `<=>` el compilador sintetiza `<`, `<=`, `>`, `>=`; `==` y `!=` provienen de `operator==`. Con `= default` en `<=>`, también se genera `==`.

## Algoritmo

1. `Version`: el `<=>` por defecto compara `mayor`, `menor`, `parche` en ese orden.
2. `Fraccion`: normalizar en el constructor (signo en el numerador, dividir por el MCD).
3. `operator<=>`: `num * o.den <=> o.num * den` (válido porque los denominadores son positivos).
4. Como `<=>` es personalizado, definir `operator==` aparte.
5. `ranges::sort` usa `<`; `r < 0`, `r > 0`, `r == 0` interpretan el resultado.

---

# Problema 18 — Prácticas modernas

## Idea de solución

Cada palabra clave moderna traslada un error de ejecución a un error de compilación.

| Elemento | Qué evita |
|---|---|
| `explicit` | conversiones implícitas inesperadas |
| `[[nodiscard]]` | ignorar un resultado importante (p. ej. si el retiro falló) |
| `override` | método que no sobrescribe nada por error de firma |
| `final` | redefinir o heredar donde no se debe |
| `= delete` | copias indeseadas |
| constructor delegado | duplicar código de inicialización |
| `inline static` | definir miembros estáticos fuera de la clase |

## Algoritmo

1. Implementar el constructor completo y hacer que los demás deleguen: `Cuenta(string t) : Cuenta(move(t), 0.0)`.
2. Incrementar el contador estático en el constructor principal.
3. `retirar` devuelve `bool`; el llamador debe usarlo.
4. `Base::usar` es `virtual final`: llama a `tipo()`, que sí puede sobrescribirse.
5. Comentar las líneas inválidas y razonar cada error.

---

# Problema 19 — Regla de los cinco

## Idea de solución

Si la clase administra un recurso crudo, hay que definir destructor, copia, asignación por copia, movimiento y asignación por movimiento. Si no, delegue en `vector`/`unique_ptr` y no defina ninguno (regla del cero).

## Algoritmo

1. Copia: reservar nuevo arreglo y copiar elementos (copia profunda).
2. Asignación por copia: copiar primero a un arreglo nuevo, luego liberar el anterior (seguro ante autoasignación).
3. Movimiento: `n(exchange(o.n, 0)), datos(exchange(o.datos, nullptr))`: roba el recurso y deja el origen vacío pero destruible.
4. Marcar el movimiento `noexcept`: `vector` solo mueve al reubicar si es `noexcept`; si no, copia.
5. El objeto movido-desde queda válido pero sin recursos (`tamano() == 0`).
6. `BufferSimple` con `vector<int>` obtiene copia y movimiento correctos sin escribir nada.

---

# Problema 20 — Colección polimórfica moderna

## Idea de solución

`unique_ptr<Base>` da propiedad exclusiva y destrucción correcta (la base tiene destructor virtual). Los rangos permiten consultas declarativas sobre la colección.

## Algoritmo

1. `plantilla.push_back(make_unique<Operario>("Luis", 1500, 10))`.
2. Lambda genérica `auto mostrar = [](auto &&rango){ ... }` acepta vector y vistas filtradas.
3. `ranges::sort(plantilla, ranges::greater{}, [](const auto &e){ return e->sueldo(); })`: la proyección invoca el método virtual.
4. `views::filter` crea una vista perezosa sin copiar los `unique_ptr`.
5. `views::transform` + `accumulate` calcula el total sin vector intermedio.
6. `ranges::find_if` y `ranges::count_if` consultan por `cargo()`.

---

# Conclusión

Este conjunto evalúa:

* Programación orientada a objetos.
* Diseño de clases.
* Herencia (todas las formas).
* Polimorfismo dinámico.
* Uso de punteros a objetos.
* Buenas prácticas en C++20.
