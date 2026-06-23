#include <iostream>
#include <iomanip>
#include <string>

class Producto
{
private:
    int codigo;
    std::string nombre;
    double precio;

public:
    // Constructor por defecto
    Producto()
        : codigo(0),
          nombre("Sin nombre"),
          precio(0.0)
    {
    }

    // Constructor parametrizado usando this
    Producto(
        int codigo,
        const std::string& nombre,
        double precio)
    {
        this->codigo = codigo;
        this->nombre = nombre;
        this->precio = precio;
    }

    // Setter encadenable
    Producto& setCodigo(int codigo)
    {
        this->codigo = codigo;
        return *this;
    }

    // Setter encadenable
    Producto& setNombre(const std::string& nombre)
    {
        this->nombre = nombre;
        return *this;
    }

    // Setter encadenable
    Producto& setPrecio(double precio)
    {
        if (precio >= 0)
        {
            this->precio = precio;
        }

        return *this;
    }

    // Getters
    int getCodigo() const
    {
        return codigo;
    }

    const std::string& getNombre() const
    {
        return nombre;
    }

    double getPrecio() const
    {
        return precio;
    }

    // Mostrar información
    void mostrar() const
    {
        std::cout << "\n===== PRODUCTO =====\n";

        std::cout
            << "Codigo : "
            << codigo
            << '\n';

        std::cout
            << "Nombre : "
            << nombre
            << '\n';

        std::cout
            << std::fixed
            << std::setprecision(2);

        std::cout
            << "Precio : S/. "
            << precio
            << '\n';
    }
};

int main()
{
    Producto p;

    // Encadenamiento de métodos
    p.setCodigo(1001)
     .setNombre("Laptop Lenovo")
     .setPrecio(3499.90);

    p.mostrar();

    Producto q(
        2001,
        "Monitor LG",
        899.50);

    q.mostrar();

    return 0;
}
