# Framework de Solución para Problemas con Archivos en C++20

## Objetivo

Estas plantillas proporcionan una estructura base que puede reutilizarse en ejercicios de:

* Gestión dinámica de memoria.
* Estructuras (`struct`).
* Archivos de texto.
* Archivos binarios.
* Archivos de acceso aleatorio.

---

# Plantilla 1 — Archivo de Texto

## Estructura Base

```cpp
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Registro {
    int codigo;
    string nombre;
    double valor;
};
```

## Escritura en Archivo de Texto

```cpp
void guardarTexto(Registro* datos, int n,
                  const string& nombreArchivo)
{
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir archivo.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        archivo << datos[i].codigo << " "
                << datos[i].nombre << " "
                << datos[i].valor << "\n";
    }

    archivo.close();
}
```

## Lectura desde Archivo de Texto

```cpp
void leerTexto(const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "Error al abrir archivo.\n";
        return;
    }

    Registro r;

    while (archivo >> r.codigo
                   >> r.nombre
                   >> r.valor)
    {
        cout << r.codigo << " "
             << r.nombre << " "
             << r.valor << endl;
    }

    archivo.close();
}
```

## Programa Principal

```cpp
int main()
{
    int n;

    cout << "Cantidad de registros: ";
    cin >> n;

    Registro* datos = new Registro[n];

    for (int i = 0; i < n; i++) {
        cin >> datos[i].codigo;
        cin >> datos[i].nombre;
        cin >> datos[i].valor;
    }

    guardarTexto(datos, n, "datos.txt");

    leerTexto("datos.txt");

    delete[] datos;

    return 0;
}
```

---

# Plantilla 2 — Archivo Binario

## Estructura Base

```cpp
struct Registro {
    int codigo;
    char nombre[50];
    double valor;
};
```

## Escritura Binaria

```cpp
void guardarBinario(Registro* datos,
                    int n,
                    const char* archivoNombre)
{
    ofstream archivo(
        archivoNombre,
        ios::binary
    );

    if (!archivo)
        return;

    archivo.write(
        reinterpret_cast<char*>(datos),
        n * sizeof(Registro)
    );

    archivo.close();
}
```

## Lectura Binaria

```cpp
void leerBinario(
    const char* archivoNombre)
{
    ifstream archivo(
        archivoNombre,
        ios::binary
    );

    if (!archivo)
        return;

    Registro r;

    while (
        archivo.read(
            reinterpret_cast<char*>(&r),
            sizeof(Registro)
        )
    )
    {
        cout << r.codigo << " "
             << r.nombre << " "
             << r.valor << endl;
    }

    archivo.close();
}
```

## Programa Principal

```cpp
int main()
{
    int n;

    cin >> n;

    Registro* datos =
        new Registro[n];

    for (int i = 0; i < n; i++) {
        cin >> datos[i].codigo;
        cin >> datos[i].nombre;
        cin >> datos[i].valor;
    }

    guardarBinario(
        datos,
        n,
        "datos.dat"
    );

    leerBinario(
        "datos.dat"
    );

    delete[] datos;
}
```

---

# Plantilla 3 — Archivo de Acceso Aleatorio

## Estructura Base

```cpp
struct Registro {
    int codigo;
    char nombre[50];
    double valor;
};
```

---

## Crear Archivo

```cpp
void crearArchivo(
    Registro* datos,
    int n)
{
    fstream archivo(
        "datos.dat",
        ios::binary | ios::out
    );

    for (int i = 0; i < n; i++) {
        archivo.write(
            reinterpret_cast<char*>(&datos[i]),
            sizeof(Registro)
        );
    }

    archivo.close();
}
```

---

## Buscar Registro por Posición

```cpp
void mostrarRegistro(
    int posicion)
{
    fstream archivo(
        "datos.dat",
        ios::binary | ios::in
    );

    Registro r;

    archivo.seekg(
        posicion * sizeof(Registro)
    );

    archivo.read(
        reinterpret_cast<char*>(&r),
        sizeof(Registro)
    );

    cout << r.codigo << " "
         << r.nombre << " "
         << r.valor << endl;

    archivo.close();
}
```

---

## Modificar Registro

```cpp
void modificarRegistro(
    int posicion,
    double nuevoValor)
{
    fstream archivo(
        "datos.dat",
        ios::binary
        | ios::in
        | ios::out
    );

    Registro r;

    archivo.seekg(
        posicion * sizeof(Registro)
    );

    archivo.read(
        reinterpret_cast<char*>(&r),
        sizeof(Registro)
    );

    r.valor = nuevoValor;

    archivo.seekp(
        posicion * sizeof(Registro)
    );

    archivo.write(
        reinterpret_cast<char*>(&r),
        sizeof(Registro)
    );

    archivo.close();
}
```

---

## Mostrar Todo el Archivo

```cpp
void mostrarTodo()
{
    fstream archivo(
        "datos.dat",
        ios::binary | ios::in
    );

    Registro r;

    while (
        archivo.read(
            reinterpret_cast<char*>(&r),
            sizeof(Registro)
        )
    )
    {
        cout << r.codigo << " "
             << r.nombre << " "
             << r.valor << endl;
    }

    archivo.close();
}
```

---

# Plantilla 4 — Búsqueda por Código

## Función Genérica

```cpp
int buscarCodigo(
    const char* archivoNombre,
    int codigoBuscado)
{
    fstream archivo(
        archivoNombre,
        ios::binary | ios::in
    );

    Registro r;

    int posicion = 0;

    while (
        archivo.read(
            reinterpret_cast<char*>(&r),
            sizeof(Registro)
        )
    )
    {
        if (r.codigo ==
            codigoBuscado)
        {
            archivo.close();
            return posicion;
        }

        posicion++;
    }

    archivo.close();

    return -1;
}
```

Uso:

```cpp
int pos =
    buscarCodigo(
        "datos.dat",
        1005
    );

if (pos != -1)
    mostrarRegistro(pos);
else
    cout << "No encontrado\n";
```

---

# Plantilla 5 — Menú General Reutilizable

```cpp
int opcion;

do {
    cout << "\nMENU\n";
    cout << "1. Registrar\n";
    cout << "2. Mostrar\n";
    cout << "3. Buscar\n";
    cout << "4. Modificar\n";
    cout << "5. Salir\n";

    cin >> opcion;

    switch(opcion)
    {
        case 1:
            // Registrar
            break;

        case 2:
            // Mostrar
            break;

        case 3:
            // Buscar
            break;

        case 4:
            // Modificar
            break;
    }

} while(opcion != 5);
```

---

# Patrón General para Resolver los 15 Problemas

1. Definir estructuras.
2. Reservar memoria dinámica.
3. Leer datos.
4. Guardar archivo.
5. Leer archivo.
6. Implementar búsquedas.
7. Implementar actualizaciones.
8. Generar reportes.
9. Liberar memoria.
10. Validar apertura de archivos.

Este framework cubre aproximadamente el 90% de los ejercicios universitarios sobre estructuras, archivos de texto, archivos binarios y acceso aleatorio en C++20.

# Código del problema 1

## Compilación

```bash
g++ -std=c++20 -Wall -Wextra -pedantic solucion01.cpp -o solucion01
```

## Ejemplo de ejecución

```text
Ingrese cantidad de estudiantes: 3

Estudiante #1
Codigo   : 1001
Nombre   : Ana Torres
Promedio : 16.8

Estudiante #2
Codigo   : 1002
Nombre   : Luis Rojas
Promedio : 18.4

Estudiante #3
Codigo   : 1003
Nombre   : Carla Perez
Promedio : 15.7
```

Salida:

```text
Codigo    Nombre                        Promedio
--------------------------------------------------
1001      Ana Torres                    16.80
1002      Luis Rojas                    18.40
1003      Carla Perez                   15.70

ESTUDIANTE CON MAYOR PROMEDIO

1002      Luis Rojas                    18.40
```
