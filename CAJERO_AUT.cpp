#include <iostream>
#include <string>
#include <limits> // Esta librería la necesito para limpiar el cin cuando falla

using namespace std;
/*------------------------------------------------------------------------------------------------------
                                        ESTRUCTURAS
    Aquí creo la "plantilla" de cómo se ve una cuenta.
    Es como crear mi propio tipo de dato que guarda varias cosas juntas.
------------------------------------------------------------------------------------------------------ */
struct Cuenta {
    int numeroCuenta;
    string nombreTitular;
    float saldo; // Uso float para que tenga decimales
};

/*------------------------------------------------------------------------------------------------------
                                 ARREGLOS Y VARIABLES GLOBALES 
------------------------------------------------------------------------------------------------------ */
// Aquí creo mis 3 cuentas. Es un arreglo de mi estructura Cuenta.
Cuenta listaCuentas[3] = {
    {111, "Juan Perez", 5000.50},
    {222, "Maria Lopez", 1500.00},
    {333, "Carlos Ruiz", 300.00}
};

/*------------------------------------------------------------------------------------------------------
                                    PUNTEROS 
    Guarda la dirección de memoria de la cuenta que inició sesión.
    Así no tengo que buscarla a cada rato, solo uso "miCuenta". */
Cuenta* miCuenta = nullptr;

// FUNCIONES DE AYUDA 
/* Esta función sirve para buscar una cuenta en el arreglo.
Devuelve un PUNTERO a la cuenta, si la encuentra, o queda nullptr (nulo) si no la encuentra. */
Cuenta* buscarCuenta(int numero) {
    // Uso un ciclo for para recorrer mi arreglo de 3 cuentas
    for(int i = 0; i < 3; i++) {
        // Si el número coincide, devuelvo la dirección de esa cuenta (&)
        if(listaCuentas[i].numeroCuenta == numero) {
            return &listaCuentas[i]; // Aquí uso return para "saltar" y devolver el valor
        }
    }
    return nullptr; // Si terminó el ciclo y no encontró nada, devuelvo nulo
}

// Esta función la hice para limpiar errores cuando el usuario escribe letras en lugar de números.
void limpiarError() {
    cin.clear(); // Resetea el error
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora lo que escribieron mal
}

// FUNCIONES DE OPERACIONES BANCARIAS 
void consultarSaldo() {
    cout << "\n----------------------------------\n";
    // Uso la flechita (->) porque miCuenta es un puntero.
    cout << "Hola " << miCuenta->nombreTitular << "\n";
    cout << "Tu saldo actual es: $" << miCuenta->saldo << "\n";
    cout << "----------------------------------\n";
}

void depositar() {
    float monto;
    cout << "\n¿Cuanto dinero quieres depositar? $";
    
    // MANEJO DE EXCEPCIONES
    // Uso try-catch por si escriben algo raro
    try {
        if (!(cin >> monto)) {
            throw "ERROR - no parece un numero valido."; // Lanzo un error personalizado
        }
        
        // Valido que no sea negativo
        if (monto <= 0) {
            cout << "ERROR - No puedes depositar cero o negativos.\n";
        } else {
            miCuenta->saldo += monto; // Sumo el dinero
            cout << "Deposito realizado.\n";
            consultarSaldo(); // Reutilizo mi función de ver saldo
        }
    }
    catch (const char* msg) {
        cout << "Error: " << msg << "\n";
        limpiarError(); // Limpio el buffer para que no se cicle
    }
}

void retirar() {
    float monto;
    cout << "\n¿Cuanto quieres retirar? $";
    
    try {
        if (!(cin >> monto)) {
            throw "Error al leer el monto.";
        }

        if (monto <= 0) {
            cout << "El monto debe ser mayor a cero.\n";
        }
        // Valido si tiene suficiente dinero (Saldo insuficiente)
        else if (monto > miCuenta->saldo) {
            cout << "ERROR - No tienes suficiente saldo para retirar.\n";
        }
        else {
            miCuenta->saldo -= monto; // Resto el dinero
            cout << "Retiro exitoso.\n";
            consultarSaldo();
        }
    }
    catch (...) { // Esto atrapa cualquier error
        cout << "Algo salio mal con el numero ingresado.\n";
        limpiarError();
    }
}

void transferir() {
    int cuentaDestinoID;
    float monto;

    cout << "\n--- Transferencia ---\n";
    cout << "Ingresa el numero de cuenta a quien le envias: ";
    
    try {
        if (!(cin >> cuentaDestinoID)) throw "Numero de cuenta invalido";

        // Aquí reutilizo mi función buscarCuenta
        Cuenta* cuentaAmigo = buscarCuenta(cuentaDestinoID);

        // Valido si la cuenta existe
        if (cuentaAmigo == nullptr) {
            cout << "Esa cuenta no existe en el sistema.\n";
        }
        // Valido que no se transfiera a sí mismo (comparo punteros)
        else if (cuentaAmigo == miCuenta) {
            cout << "No puedes transferirte a ti mismo.\n";
        }
        else {
            cout << "Cuenta encontrada: " << cuentaAmigo->nombreTitular << "\n";
            cout << "¿Cuanto quieres transferir? $";
            
            if (!(cin >> monto)) throw "Monto invalido";

            // Valido saldo otra vez
            if (monto > miCuenta->saldo) {
                cout << "No tienes fondos suficientes.\n";
            } else if (monto <= 0) {
                cout << "Monto invalido.\n";
            } else {
                // retiro dinero de mi cuenta y lo agrego a la del amigo
                miCuenta->saldo -= monto;
                cuentaAmigo->saldo += monto;
                cout << "Transferencia realizada con exito!\n";
                consultarSaldo();
            }
        }
    }
    catch (const char* e) {
        cout << "Error: " << e << "\n";
        limpiarError();
    }
}
/*------------------------------------------------------------------------------------------------------
                                             MAIN 
------------------------------------------------------------------------------------------------------*/
int main() {
    int numeroIngresado;
    bool sesionIniciada = false;

    // CONTROL DE FLUJO: Repetición (Ciclo para el Login)
    while (!sesionIniciada) {
        cout << "\n=== BIENVENIDO AL CAJERO AUTOMATICO ===\n";
        cout << "(Tips: Las cuentas son 111, 222, 333)\n";
        cout << "Por favor, ingresa tu numero de cuenta para entrar: ";
        
        if (cin >> numeroIngresado) {
            // Busco la cuenta
            miCuenta = buscarCuenta(numeroIngresado);

            // CONTROL DE FLUJO: Selección 
            if (miCuenta != nullptr) {
                sesionIniciada = true; // Romperé el ciclo
                cout << "Acceso concedido. Hola " << miCuenta->nombreTitular << "!\n";
            } else {
                cout << "Cuenta no encontrada. Intenta de nuevo.\n";
            }
        } else {
            cout << "Eso no fue un numero.\n";
            limpiarError();
        }
    }

    // Menú principal
    int opcion = 0;
    
    // CONTROL DE FLUJO: Repetición (Ciclo para el Menú)
    do {
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Consultar Saldo\n";
        cout << "2. Retirar Efectivo\n";
        cout << "3. Depositar Fondos\n";
        cout << "4. Transferir a otra cuenta\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";

        cin >> opcion;

        // CONTROL DE FLUJO: Selección múltiple 
        switch (opcion) {
            case 1:
                consultarSaldo();
                break; // El break es un salto para salir del switch
            case 2:
                retirar();
                break;
            case 3:
                depositar();
                break;
            case 4:
                transferir();
                break;
            case 5:
                cout << "Gracias por usar el cajero. Adios!\n";
                break;
            default:
                cout << "ERROR - Esa opcion no existe.\n";
                limpiarError(); // Por si escribieron letras en el menu
        }

    } while (opcion != 5);

    return 0;
}