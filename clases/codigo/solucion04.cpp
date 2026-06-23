#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

using namespace std;

//=====================================================
// Clase base
//=====================================================

class Figura
{
public:
    virtual double calcularArea() const = 0;

    virtual void mostrar() const = 0;

    virtual ~Figura() = default;
};

//=====================================================
// Triángulo
//=====================================================

class Triangulo : public Figura
{
private:
    double base;
    double altura;

public:
    Triangulo(
        double base,
        double altura)
        : base(base),
          altura(altura)
    {
    }

    double calcularArea() const override
    {
        return base * altura / 2.0;
    }

    void mostrar() const override
    {
        cout << "Triangulo\n";
        cout << "Base   : " << base << '\n';
        cout << "Altura : " << altura << '\n';
        cout << "Area   : "
             << calcularArea()
             << "\n\n";
    }
};

//=====================================================
// Rectángulo
//=====================================================

class Rectangulo : public Figura
{
private:
    double base;
    double altura;

public:
    Rectangulo(
        double base,
        double altura)
        : base(base),
          altura(altura)
    {
    }

    double calcularArea() const override
    {
        return base * altura;
    }

    void mostrar() const override
    {
        cout << "Rectangulo\n";
        cout << "Base   : " << base << '\n';
        cout << "Altura : " << altura << '\n';
        cout << "Area   : "
             << calcularArea()
             << "\n\n";
    }
};

//=====================================================
// Programa principal
//=====================================================

int main()
{
    cout << fixed << setprecision(2);

    vector<unique_ptr<Figura>> figuras;

    figuras.push_back(
        make_unique<Triangulo>(10.0, 5.0));

    figuras.push_back(
        make_unique<Rectangulo>(8.0, 4.0));

    figuras.push_back(
        make_unique<Triangulo>(12.0, 6.0));

    cout << "===== SISTEMA DE FIGURAS =====\n\n";

    for (const auto& figura : figuras)
    {
        figura->mostrar();
    }

    return 0;
}
