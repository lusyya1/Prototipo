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

