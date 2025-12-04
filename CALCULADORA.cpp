#include <iostream>
#include <cmath> // Necesito esta libreria para usar sqrt (la raiz cuadrada) y pow

using namespace std;

/* --------------------------------------------------------------------------------
   PROTOTIPOS DE FUNCIONES
-----------------------------------------------------------------------------------*/

// -- SOBRECARGA DE FUNCIONES --
// aplicacion de la "sobrecarga".
// Uso el mismo nombre "sumar" pero con diferentes argumentos.
double sumar(double a, double b);                // Suma normal de 2 numeros
double sumar(double a, double b, double c);      // Suma de 3 numeros

double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);

// -- PARAMETROS POR OMISION --
// Aquí uso el parametro por defecto, si el usuario no me dice a qué potencia elevar, asumo que es al cuadrado.
double potencia(double base, int exponente = 2);

double raizCuadrada(double numero);

// -- RECURSIVIDAD --
// Esta funcion se va a llamar a si misma. 
long long factorial(int n);


/* --------------------------------------------------------------------------------
   MAIN 
-----------------------------------------------------------------------------------*/
int main() {
    int opcion;
    double n1, n2, n3;
    
    do {
        cout << "\n=== MI CALCULADORA ===\n";
        cout << "1. Sumar 2 numeros\n";
        cout << "2. Sumar 3 numeros (Probando Sobrecarga)\n";
        cout << "3. Restar\n";
        cout << "4. Multiplicar\n";
        cout << "5. Dividir (Con manejo de error)\n";
        cout << "6. Potencia (Con parametro por omision)\n";
        cout << "7. Raiz Cuadrada (Con manejo de error)\n";
        cout << "8. Factorial (Recursivo)\n";
        cout << "9. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
    }
    