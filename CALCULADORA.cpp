#include <iostream>
#include <cmath> // Necesito esta libreria para usar sqrt (la raiz cuadrada) y pow
#include <limits> // Para limpiar errores si escriben letras

using namespace std;

/* --------------------------------------------------------------------------------
   PROTOTIPOS DE FUNCIONES
-----------------------------------------------------------------------------------*/

// -- FUNCIONES --
//Aquí aviso qué funciones voy a usar abajo.

double sumar(double a, double b);                // Suma normal de 2 numeros
double sumar(double a, double b, double c);      // Suma de 3 numeros

double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);
// -- PARAMETROS POR OMISION --
// Si el usuario no me dice a qué potencia elevar, asumo que es al cuadrado (2).
double potencia(double base, int exponente = 2);
double raizCuadrada(double numero);
long long factorial(int n); // RECURSIVIDAD 



/* --------------------------------------------------------------------------------
   MAIN 
-----------------------------------------------------------------------------------*/
int main() {
    int opcion;
    double n1, n2, n3;
    char respuesta; //sirve para guardar s/n 

//CICLO PRINCIPAL
    do {
        cout << "\n=== MI CALCULADORA ===\n";
        cout << "1. Sumar 2 numeros\n";
        cout << "2. Sumar 3 numeros\n";
        cout << "3. Restar\n";
        cout << "4. Multiplicar\n";
        cout << "5. Dividir\n";
        cout << "6. Potencia \n";
        cout << "7. Raiz Cuadrada\n";
        cout << "8. Factorial\n";
        cout << "9. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

         // Si escriben letras en el menu, limpio el error para que no se cicle 
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        switch(opcion) {
            case 1:
                // SUB-CICLO: Se repiten las sumas hasta que el usuario diga que no
                do {
                    cout << "\n--- SUMA DE 2 NUMEROS ---\n";
                    cout << "Dame el primer numero: ";
                    cin >> n1;
                    cout << "Dame el segundo numero: ";
                    cin >> n2;
                    
                    cout << ">> El resultado es: " << sumar(n1, n2) << "\n";

                    cout << "\n¿Quieres hacer otra suma? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S'); 
                break;

            case 2:
                do {
                    cout << "\n--- SUMA DE 3 NUMEROS ---\n";
                    cout << "Dame el primer numero: ";
                    cin >> n1;
                    cout << "Dame el segundo numero: ";
                    cin >> n2;
                    cout << "Dame el tercer numero: ";
                    cin >> n3;
                    
                    cout << ">> El resultado es: " << sumar(n1, n2, n3) << "\n";

                    cout << "\n¿Quieres hacer otra suma de 3? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 3:
                do {
                    cout << "\n--- RESTA ---\n";
                    cout << "Dame el primer numero: "
                    cin >> n1;
                    cout << "Dame el segundo numero: ";
                    cin >> n2;
                    
                    cout << ">> El resultado es: " << restar(n1, n2) << "\n";

                    cout << "\n¿Quieres hacer otra resta? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 4:
                do {
                    cout << "\n--- MULTIPLICACION ---\n";
                    cout << "Dame el primer numero: ";
                    cin >> n1;
                    cout << "Dame el segundo numero: ";
                    cin >> n2;
                    
                    cout << ">> El resultado es: " << multiplicar(n1, n2) << "\n";

                    cout << "\n¿Otra multiplicacion? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 5:
                do {
                    cout << "\n--- DIVISION ---\n";
                    cout << "Dame el numerador (el de arriba): ";
                    cin >> n1;
                    cout << "Dame el denominador (el de abajo): ";
                    cin >> n2;

                    // MANEJO DE EXCEPCIONES
                    try {
                        cout << ">> El resultado es: " << dividir(n1, n2) << "\n";
                    } catch (const char* error) {
                        cout << "¡ERROR!: " << error << "\n";
                    }

                    cout << "\n¿Otra division? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 6:
                do {
                    cout << "\n--- POTENCIA ---\n";
                    cout << "Dame el numero base: ";
                    cin >> n1;
                    cout << "¿Quieres poner exponente manual? (1=Si, 0=No, usara exponente al cuadrado): ";
                    int quiere;
                    cin >> quiere;

                    if(quiere == 1) {
                        int exp;
                        cout << "¿Cuál es el exponente?: ";
                        cin >> exp;
                        cout << ">> Resultado: " << potencia(n1, exp) << "\n";
                    } else {
                        // Aquí uso el parametro por omision (no brindo el segundo dato)
                        cout << ">> Resultado (al cuadrado): " << potencia(n1) << "\n";
                    }

                    cout << "\n¿Te gustaria realizar otra potencia? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 7:
                do {
                    cout << "\n--- RAIZ CUADRADA ---\n";
                    cout << "Dame el numero: ";
                    cin >> n1;

                    try {
                        cout << ">> La raiz es: " << raizCuadrada(n1) << "\n";
                    } catch (const char* error) {
                        cout << "¡ERROR!: " << error << "\n";
                    }

                    cout << "\n¿Te gustaria realizar otra raiz? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 8:
                do {
                    int numFact;
                    cout << "\n--- FACTORIAL ---\n";
                    cout << "Dame un numero entero positivo: ";
                    cin >> numFact;

                    if(numFact < 0) {
                        cout << "No existen factoriales de negativos.\n";
                    } else {
                        cout << ">> El factorial de " << numFact << " es: " << factorial(numFact) << "\n";
                    }

                    cout << "\n¿Te gustaria realizar otro factorial? (s/n): ";
                    cin >> respuesta;
                } while(respuesta == 's' || respuesta == 'S');
                break;

            case 9:
                cout << "¡Adios!.\n";
                break;

            default:
                cout << "Esa opcion no existe en el menu.\n";
        }

    } while(opcion != 9); // Si eligen 9, se rompe el ciclo principal y se acaba

    return 0;