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