#include <iostream>
#include <string>
#include <limits> // sirve para limpiar cuando el cin se vuelve loco
#include <iomanip> // AGREGUÉ ESTA: Sirve para usar setw y acomodar la tabla bonita

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
void mostrarInventario() { 
    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    
    // Aquí uso 'left' para alinear a la izquierda y 'setw' para dar un ancho fijo a cada columna.
    // Es como dibujar casillas invisibles.
    cout << left; // Todo lo que imprima a partir de aqui se alinea a la izquierda
    cout << setw(10) << "ID" 
         << setw(20) << "Nombre" 
         << setw(15) << "Precio" 
         << setw(10) << "Cantidad" << endl;
         
    cout << "--------------------------------------------------------\n";
    
    // Recorro todo el arreglo uno por uno
    for(int i = 0; i < TOTAL; i++) {
        cout << left; // Aseguro que se mantenga la alineación
        
        cout << setw(10) << inventario[i].id 
             << setw(20) << inventario[i].nombre;
             
        // Para el precio le agrego el signo de pesos manual antes del numero
        cout << "$" << setw(14) << inventario[i].precio 
             << setw(10) << inventario[i].cantidad << "\n";
    }
    cout << "--------------------------------------------------------\n";
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

/* --------------------------------------------------------------------------------
   BÚSQUEDA Y ORDENAMIENTO
-----------------------------------------------------------------------------------*/ 

// -- BÚSQUEDA --
// Esta función busca un ID. 
// Devuelve un PUNTERO (Producto*) para saber dónde está en memoria.
Producto* buscarPorID(int idBuscado) {
    for(int i = 0; i < TOTAL; i++) {
        // Comparo si el ID actual es el que busco
        if(inventario[i].id == idBuscado) {
            // Si lo encuentro, uso '&' para devolver su DIRECCIÓN de memoria
            return &inventario[i];
        }
    }
    
    // Si llegué aquí es que recorrí todo y no lo encontré.
    // Lanzo un error manual con 'throw'.
    throw "Error 404: Ese ID no existe, checalo bien.";
}

// -- ORDENAMIENTO POR PRECIO (BURBUJA) --
// Método de la Burbuja: compara parejitas y si están mal, las cambia.
void ordenarPorPrecio() {
    cout << "\nOrdenando por precio (del mas barato al mas caro)...\n";
    
    Producto temporal; 

    for(int i = 0; i < TOTAL - 1; i++) {
        for(int j = 0; j < TOTAL - 1; j++) {
            // Si el precio de hoy es mayor al de mañana... los cambio
            if(inventario[j].precio > inventario[j+1].precio) {
                // Intercambio (Swap)
                temporal = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = temporal;
            }
        }
    }
    cout << "Ya quedo ordenado por precio.\n";
    mostrarInventario(); 
}

// -- ORDENAMIENTO POR CANTIDAD --
void ordenarPorCantidad() {
    cout << "\nOrdenando por cantidad (de menor a mayor stock)...\n";
    Producto temporal;

    for(int i = 0; i < TOTAL - 1; i++) {
        for(int j = 0; j < TOTAL - 1; j++) {
            // Aquí la condición es sobre stock (cantidad)
            if(inventario[j].cantidad > inventario[j+1].cantidad) {
                temporal = inventario[j];
                inventario[j] = inventario[j+1];
                inventario[j+1] = temporal;
            }
        }
    }
    cout << "Ya quedo ordenado por stock.\n";
    mostrarInventario();
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
}