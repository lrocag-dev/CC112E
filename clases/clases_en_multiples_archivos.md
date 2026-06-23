# Guía de Trabajo con Clases en Múltiples Archivos en C++20

## Introducción

En proyectos pequeños es común escribir todo el código en un único archivo `.cpp`. Sin embargo, en aplicaciones reales es una buena práctica separar:

- Declaración de clases.
- Implementación de métodos.
- Programa principal.

Esta organización mejora:

- La mantenibilidad.
- La reutilización del código.
- La compilación incremental.
- El trabajo colaborativo.

---

# Estructura Recomendada

Supongamos una clase `Estudiante`.

```text
Proyecto/
│
├── Estudiante.h
├── Estudiante.cpp
├── main.cpp
└── Makefile
```

---

# Archivo de Cabecera (.h)

Contiene únicamente la declaración de la clase.

## Estudiante.h

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante
{
private:
    int codigo;
    std::string nombre;
    double promedio;

public:
    Estudiante();

    Estudiante(
        int codigo,
        const std::string& nombre,
        double promedio);

    void mostrar() const;
};

#endif
```

---

# Archivo de Implementación (.cpp)

Contiene la definición de los métodos.

## Estudiante.cpp

```cpp
#include "Estudiante.h"

#include <iostream>

Estudiante::Estudiante()
{
    codigo = 0;
    nombre = "";
    promedio = 0.0;
}

Estudiante::Estudiante(
    int codigo,
    const std::string& nombre,
    double promedio)
{
    this->codigo = codigo;
    this->nombre = nombre;
    this->promedio = promedio;
}

void Estudiante::mostrar() const
{
    std::cout
        << codigo << " "
        << nombre << " "
        << promedio << '\n';
}
```

---

# Programa Principal

## main.cpp

```cpp
#include "Estudiante.h"

int main()
{
    Estudiante e(
        1001,
        "Luis",
        18.5);

    e.mostrar();

    return 0;
}
```

---

# Compilación Manual

Cuando existen varios archivos fuente, NO debe compilarse únicamente `main.cpp`.

Incorrecto:

```bash
g++ main.cpp -o programa
```

Generará errores porque el compilador no encuentra las implementaciones de los métodos.

---

## Forma Correcta

```bash
g++ main.cpp Estudiante.cpp -o programa
```

---

# Compilación Separada

En proyectos medianos y grandes es recomendable compilar cada archivo por separado.

## Paso 1

Compilar la clase.

```bash
g++ -std=c++20 -c Estudiante.cpp
```

Genera:

```text
Estudiante.o
```

---

## Paso 2

Compilar el programa principal.

```bash
g++ -std=c++20 -c main.cpp
```

Genera:

```text
main.o
```

---

## Paso 3

Enlazar los archivos objeto.

```bash
g++ main.o Estudiante.o -o programa
```

---

# Estructura Profesional

```text
Proyecto/
│
├── include/
│   └── Estudiante.h
│
├── src/
│   ├── Estudiante.cpp
│   └── main.cpp
│
├── build/
│
└── Makefile
```

---

# Compilación con Directorios

```bash
g++ -std=c++20 \
-Iinclude \
src/main.cpp \
src/Estudiante.cpp \
-o programa
```

---

# Proyecto con Varias Clases

Supongamos:

```text
Proyecto/
│
├── Persona.h
├── Persona.cpp
│
├── Estudiante.h
├── Estudiante.cpp
│
├── Profesor.h
├── Profesor.cpp
│
└── main.cpp
```

---

## Compilación

```bash
g++ \
main.cpp \
Persona.cpp \
Estudiante.cpp \
Profesor.cpp \
-o programa
```

---

# Dependencias entre Clases

## Persona.h

```cpp
#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona
{
protected:
    std::string nombre;

public:
    Persona(
        const std::string& nombre);
};

#endif
```

---

## Estudiante.h

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "Persona.h"

class Estudiante
    : public Persona
{
private:
    double promedio;

public:
    Estudiante(
        const std::string& nombre,
        double promedio);
};

#endif
```

---

# Uso de #ifndef

Evita que un mismo archivo de cabecera se incluya varias veces.

```cpp
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

// contenido

#endif
```

---

# Alternativa Moderna

C++ admite:

```cpp
#pragma once
```

Ejemplo:

```cpp
#pragma once

class Estudiante
{
};
```

---

# Uso de Makefile

## Makefile

```make
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra

programa: main.o Estudiante.o
	$(CXX) main.o Estudiante.o -o programa

main.o: main.cpp Estudiante.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Estudiante.o: Estudiante.cpp Estudiante.h
	$(CXX) $(CXXFLAGS) -c Estudiante.cpp

clean:
	rm -f *.o programa
```

---

# Compilar con Make

```bash
make
```

---

# Limpiar Objetos

```bash
make clean
```

---

# Compilación Recomendada para C++20

```bash
g++ \
-std=c++20 \
-Wall \
-Wextra \
-Wpedantic \
-O2 \
main.cpp \
Estudiante.cpp \
-o programa
```

---

# Errores Comunes

## Error 1

```text
undefined reference to ...
```

### Causa

No se compiló alguno de los archivos `.cpp`.

---

## Error 2

```text
multiple definition of ...
```

### Causa

Implementar funciones dentro del `.h` sin usar `inline`.

---

## Error 3

```text
redefinition of class ...
```

### Causa

No usar:

```cpp
#ifndef
#define
#endif
```

o

```cpp
#pragma once
```

---

# Recomendación para Proyectos Académicos

Para cada clase utilizar:

```text
NombreClase.h
NombreClase.cpp
```

Ejemplo:

```text
Alumno.h
Alumno.cpp

Curso.h
Curso.cpp

Profesor.h
Profesor.cpp
```

y mantener un único:

```text
main.cpp
```

que coordine la ejecución del programa.

---

# Resumen

| Archivo | Contenido |
|----------|------------|
| `.h` | Declaración de clases |
| `.cpp` | Implementación de métodos |
| `main.cpp` | Programa principal |
| `.o` | Código objeto generado por el compilador |
| Ejecutable | Programa final enlazado |

## Flujo de compilación

```text
Estudiante.h
       ↓
Estudiante.cpp ──→ Estudiante.o
                              ↓
main.cpp ─────────→ main.o ───┘
                              ↓
                         programa.exe
```

Esta organización es el estándar utilizado en proyectos profesionales de C++ y constituye la base para trabajar posteriormente con bibliotecas estáticas, bibliotecas dinámicas, CMake y proyectos de gran escala.
