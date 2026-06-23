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

# Conclusión

Este conjunto evalúa:

* Programación orientada a objetos.
* Diseño de clases.
* Herencia (todas las formas).
* Polimorfismo dinámico.
* Uso de punteros a objetos.
* Buenas prácticas en C++20.
