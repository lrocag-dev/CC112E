#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

struct Estudiante {
    int codigo;
    char nombre[50];
    double promedio;
};

/*
 * Lee los datos de un estudiante.
 */
void leerEstudiante(Estudiante& e)
{
    cout << "\nCodigo   : ";
    cin >> e.codigo;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre   : ";
    cin.getline(e.nombre, 50);

    cout << "Promedio : ";
    cin >> e.promedio;
}

/*
 * Imprime un estudiante.
 */
void imprimirEstudiante(const Estudiante& e)
{
    cout << left
         << setw(10) << e.codigo
         << setw(30) << e.nombre
         << fixed << setprecision(2)
         << e.promedio
         << '\n';
}

/*
 * Guarda un arreglo de estudiantes
 * en un archivo de texto.
 */
bool guardarArchivoTexto(
    const Estudiante* estudiantes,
    int n,
    const string& nombreArchivo)
{
    ofstream archivo(nombreArchivo);

    if (!archivo)
        return false;

    for (int i = 0; i < n; i++)
    {
        archivo << estudiantes[i].codigo << '\n'
                << estudiantes[i].nombre << '\n'
                << estudiantes[i].promedio << '\n';
    }

    archivo.close();

    return true;
}

/*
 * Lee e imprime el contenido
 * del archivo de texto.
 */
bool mostrarArchivoTexto(
    const string& nombreArchivo)
{
    ifstream archivo(nombreArchivo);

    if (!archivo)
        return false;

    Estudiante e;

    cout << "\n=========================================\n";
    cout << "CONTENIDO DEL ARCHIVO estudiantes.txt\n";
    cout << "=========================================\n\n";

    cout << left
         << setw(10) << "Codigo"
         << setw(30) << "Nombre"
         << "Promedio\n";

    cout << string(50, '-') << '\n';

    while (archivo >> e.codigo)
    {
        archivo.ignore();

        archivo.getline(e.nombre, 50);

        archivo >> e.promedio;
        archivo.ignore();

        imprimirEstudiante(e);
    }

    archivo.close();

    return true;
}

/*
 * Retorna un puntero al estudiante
 * con mayor promedio.
 */
const Estudiante* estudianteMayorPromedio(
    const Estudiante* estudiantes,
    int n)
{
    if (n <= 0)
        return nullptr;

    const Estudiante* mejor = &estudiantes[0];

    for (int i = 1; i < n; i++)
    {
        if (estudiantes[i].promedio >
            mejor->promedio)
        {
            mejor = &estudiantes[i];
        }
    }

    return mejor;
}

int main()
{
    cout << "=====================================\n";
    cout << "REGISTRO DE ESTUDIANTES UNIVERSITARIOS\n";
    cout << "=====================================\n\n";

    int n;

    cout << "Ingrese cantidad de estudiantes: ";
    cin >> n;

    while (n <= 0)
    {
        cout << "Cantidad invalida. Intente nuevamente: ";
        cin >> n;
    }

    Estudiante* estudiantes =
        new Estudiante[n];

    cout << "\n=== INGRESO DE DATOS ===\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nEstudiante #" << i + 1 << '\n';
        leerEstudiante(estudiantes[i]);
    }

    const string archivo = "estudiantes.txt";

    if (guardarArchivoTexto(
            estudiantes,
            n,
            archivo))
    {
        cout << "\nDatos guardados correctamente en "
             << archivo << '\n';
    }
    else
    {
        cerr << "\nError al guardar el archivo.\n";
    }

    if (!mostrarArchivoTexto(archivo))
    {
        cerr << "\nError al leer el archivo.\n";
    }

    const Estudiante* mejor =
        estudianteMayorPromedio(
            estudiantes,
            n);

    if (mejor != nullptr)
    {
        cout << "\n=====================================\n";
        cout << "ESTUDIANTE CON MAYOR PROMEDIO\n";
        cout << "=====================================\n\n";

        cout << left
             << setw(10) << "Codigo"
             << setw(30) << "Nombre"
             << "Promedio\n";

        cout << string(50, '-') << '\n';

        imprimirEstudiante(*mejor);
    }

    delete[] estudiantes;

    return 0;
}

