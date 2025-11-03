#include <iostream>
#include <string>
using namespace std;
struct Alumno {
    string nombre;
    int edad;
    float promedio;
};

int main() {
    const int TAM = 5;
    Alumno grupo[TAM]; // Arreglo de una estructura definida por el usuario
    cout << "Ingrese los datos del alumno" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\nAlumno " << i + 1 << ":" << endl;
        getline(cin >> ws, grupo[i].nombre);
        cout << "Promedio: ";
        cin >> grupo[i].promedio;
        cout << "Edad: ";
        cin >> grupo[i].edad;
    }
    cout << "=== Listado de Alumnos ===" << endl;
    for (int i = 0; i < TAM; i++) {
        cout << "\nAlumno " << i + 1 << ":" << endl;
        cout << "\nNombre: " << grupo[i].nombre << endl;
        cout << "\nEdad: " << grupo[i].edad << endl;
        cout << "\nPromedio: " << grupo[i].promedio << endl;
    }

    cout << "\nPresione Enter para salir...";
    cin.ignore();
    cin.get();
    return 0;
}