#include <iostream>
#include <string>
#include <limits> // sirve para limpiar cuando el cin se vuelve loco

using namespace std;

/* --------------------------------------------------------------------------------
   TIPO DE DATO (STRUCT)  
    definí una estructura llamada "Producto" para guardar los datos de cada uno de los producto.
   objetivo: agrupar varios datos en uno solo.
-----------------------------------------------------------------------------------*/ 
struct Producto { 
    int id;             
    string nombre;      
    float precio;       // Le puse float para los centavos
    int cantidad;       
};

/* --------------------------------------------------------------------------------
   INVENTARIO 
   declaré el arreglo de 10 posiciones con productos fijos como ejemplo.
-----------------------------------------------------------------------------------*/ 
const int TOTAL = 10;
Producto inventario[TOTAL] = {
    {101, "Sabritas", 15.50, 50},
    {102, "Coca Cola", 18.00, 30},
    {103, "Galletas", 12.00, 100},
    {104, "Agua", 10.00, 40},
    {105, "Chicle", 2.50, 200},
    {106, "Jugo", 22.00, 15},
    {107, "Leche", 28.50, 20},
    {108, "Pan", 35.00, 10},
    {109, "Yogurt", 8.50, 60},
    {110, "Chocolate", 14.00, 80}
};

/* --------------------------------------------------------------------------------
   FUNCIONES
-----------------------------------------------------------------------------------*/ 
void mostrarInventario() { // Esta función solo imprime la lista.
    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    cout << "ID\tNombre\t\tPrecio\tCantidad\n"; 
    cout << "------------------------------------------\n";
    
    // Recorro todo el arreglo uno por uno
    for(int i = 0; i < TOTAL; i++) {
        // Accedo a los datos usando el punto (.) porque aquí NO son punteros
            cout << inventario[i].id << "\t"  // Uso el \t (tabulador) para que se vea mas bonito
             << inventario[i].nombre << "\t\t$" 
             << inventario[i].precio << "\t" 
             << inventario[i].cantidad << "\n";
    }
    cout << "------------------------------------------\n";
}

// -- PUNTEROS --
// La función recibe un PUNTERO (*prod), osea, no recibe una copia del producto, 
// recibe la dirección de memoria original, esto hace que cualquier cambio que haga 
// se refleje en el arreglo original.
void modificarStock(Producto* prod) {
    int nuevaCantidad;
    
    // Como 'prod' es un puntero, tengo que usar la flechita (->) significa "ve a la dirección y saca el dato".
    cout << "Producto seleccionado: " << prod->nombre << "\n"; 
    cout << "Stock actual: " << prod->cantidad << "\n";
    cout << "Ingresa la nueva cantidad: ";
    cin >> nuevaCantidad;

    // Aquí actualizo el valor. Como es puntero, se guarda directo en el original.
    prod->cantidad = nuevaCantidad; 
    cout << "¡Stock actualizado!\n";
}

// -- MAIN --
int main() {
    int opcion = 0;
    int idBusqueda;

    // Puse todo en un do-while para que el menú no se cierre rapido.
    // Se repite hasta que elija la opción 5.
    do {
        cout << "\n=== MI TIENDITA ===\n";
        cout << "1. Ver inventario\n";
        cout << "2. Buscar por ID y editar Stock (Uso punteros y excepciones)\n";
        cout << "3. Ordenar por Precio (Burbuja)\n";
        cout << "4. Ordenar por Cantidad (Burbuja)\n";
        cout << "5. Salir\n";
        cout << "Que quieres hacer: ";
        cin >> opcion;

        // Por si el usuario escribe letras en vez de números
        if(cin.fail()) {
            cin.clear(); // Limpio el error 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoro lo que escribí
            cout << "Escribe un numero, por favor.\n";
            continue; // Vuelvo a empezar el ciclo
        }

        switch(opcion) {
            case 1:
                mostrarInventario();
                break;

            case 2:
                // -- MANEJO DE EXCEPCIONES --
                // Aquí uso el bloque try-catch para manejar errores.
                // La idea es: "intenta hacer esto (el try) y si algo sale mal (el throw), atrápalo".
                cout << "\nIngresa el ID a buscar: ";
                cin >> idBusqueda;

                try {
                    // Intento buscar. Si el ID no existe, la función 'buscarPorID' 
                    // lanza el error y saltamos directo al 'catch'.
                    Producto* prodEncontrado = buscarPorID(idBusqueda);
                    
                    cout << "¡Encontrado! Es: " << prodEncontrado->nombre << "\n";
                    
                    // Si llegué aquí es que sí existe. paso el puntero a la función de modificar.
                    modificarStock(prodEncontrado);

                } catch (const char* mensajeError) {
                    // Aquí caigo si el ID no existía. Imprimo el mensaje que puse en el throw.
                    cout << "\n*** OCURRIO UN ERROR ***\n";
                    cout << mensajeError << "\n";
                }
                break;

            case 3:
                ordenarPorPrecio();
                break;

            case 4:
                ordenarPorCantidad();
                break;

            case 5:
                cout << "Adios.\n";
                break;

            default:
                cout << "Esa opcion no existe.\n";
        }

    } while(opcion != 5);

    return 0;