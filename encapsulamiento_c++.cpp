#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    // Atributos privados: no se pueden tocar desde fuera de la clase
    string titular;
    double saldo;
    int numeroCuenta;

public:
    // Constructor: inicializa el objeto
    CuentaBancaria(string nombre, int numero, double saldoInicial) {
        titular = nombre;
        numeroCuenta = numero;
        saldo = (saldoInicial >= 0) ? saldoInicial : 0;
    }

    // --- GETTERS: permiten leer los atributos privados ---
    string getTitular() { return titular; }
    int    getNumeroCuenta() { return numeroCuenta; }
    double getSaldo() { return saldo; }

    // --- SETTERS: permiten modificar con validación ---
    void setTitular(string nuevoNombre) {
        if (!nuevoNombre.empty()) {
            titular = nuevoNombre;
        }
        else {
            cout << "Error: el nombre no puede estar vacío.\n";
        }
    }

    // --- MÉTODOS DE NEGOCIO ---
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Depósito exitoso. Nuevo saldo: $" << saldo << "\n";
        }
        else {
            cout << "Error: la cantidad debe ser positiva.\n";
        }
    }

    void retirar(double cantidad) {
        if (cantidad <= 0) {
            cout << "Error: la cantidad debe ser positiva.\n";
        }
        else if (cantidad > saldo) {
            cout << "Error: saldo insuficiente.\n";
        }
        else {
            saldo -= cantidad;
            cout << "Retiro exitoso. Nuevo saldo: $" << saldo << "\n";
        }
    }

    void mostrarInfo() {
        cout << "================================\n";
        cout << "Titular:  " << titular << "\n";
        cout << "Cuenta #: " << numeroCuenta << "\n";
        cout << "Saldo:    $" << saldo << "\n";
        cout << "================================\n";
    }
};

int main() {
    // Creamos un objeto de la clase
    CuentaBancaria cuenta("Ana García", 1001, 500.0);

    cout << "\n--- Información inicial ---\n";
    cuenta.mostrarInfo();

    cout << "\n--- Operaciones ---\n";
    cuenta.depositar(200.0);
    cuenta.retirar(100.0);
    cuenta.retirar(1000.0); // Intento fallido

    cout << "\n--- Intento de acceso inválido ---\n";
    cuenta.setTitular("");  // Será rechazado por el setter

    cout << "\n--- Información final ---\n";
    cuenta.mostrarInfo();

    // Esto causaría un ERROR de compilación (¡eso es el encapsulamiento!):
    // cuenta.saldo = 999999;  ← NO permitido, es private

    return 0;
}