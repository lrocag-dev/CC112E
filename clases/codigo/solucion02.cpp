#include <iostream>
#include <iomanip>
#include <string>

class CuentaBancaria
{
private:
    int numeroCuenta;
    std::string titular;
    double saldo;

public:
    // Constructor por defecto
    CuentaBancaria()
        : numeroCuenta(0),
          titular("Sin titular"),
          saldo(0.0)
    {
        std::cout << "Cuenta creada (constructor por defecto)\n";
    }

    // Constructor parametrizado
    CuentaBancaria(
        int numeroCuenta,
        const std::string& titular,
        double saldoInicial)
        : numeroCuenta(numeroCuenta),
          titular(titular),
          saldo(saldoInicial)
    {
        std::cout << "Cuenta creada para "
                  << titular << '\n';
    }

    // Destructor
    ~CuentaBancaria()
    {
        std::cout
            << "Eliminando cuenta "
            << numeroCuenta
            << " de "
            << titular
            << '\n';
    }

    // Depositar dinero
    void depositar(double monto)
    {
        if (monto <= 0)
        {
            std::cout
                << "Error: monto invalido.\n";
            return;
        }

        saldo += monto;

        std::cout
            << "Deposito realizado: S/. "
            << monto
            << '\n';
    }

    // Retirar dinero
    bool retirar(double monto)
    {
        if (monto <= 0)
        {
            std::cout
                << "Error: monto invalido.\n";
            return false;
        }

        if (monto > saldo)
        {
            std::cout
                << "Fondos insuficientes.\n";
            return false;
        }

        saldo -= monto;

        std::cout
            << "Retiro realizado: S/. "
            << monto
            << '\n';

        return true;
    }

    // Mostrar información de la cuenta
    void mostrarCuenta() const
    {
        std::cout << "\n===== DATOS DE LA CUENTA =====\n";

        std::cout
            << "Numero : "
            << numeroCuenta
            << '\n';

        std::cout
            << "Titular: "
            << titular
            << '\n';

        std::cout
            << std::fixed
            << std::setprecision(2);

        std::cout
            << "Saldo  : S/. "
            << saldo
            << "\n\n";
    }
};

int main()
{
    CuentaBancaria cuenta(
        1001,
        "Luis Roca",
        1500.00);

    cuenta.mostrarCuenta();

    cuenta.depositar(500);

    cuenta.mostrarCuenta();

    cuenta.retirar(700);

    cuenta.mostrarCuenta();

    cuenta.retirar(2000);

    cuenta.mostrarCuenta();

    return 0;
}
