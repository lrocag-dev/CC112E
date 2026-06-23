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
