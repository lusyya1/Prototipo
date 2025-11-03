#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std; 

// El tablero se representa con un array de 9 caracteres.
char tablero[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char jugador_actual = 'X';

// Muestra el estado actual del tablero en la consola.
 
void dibujarTablero() {
    cout << "\n======================================" << endl;
    cout << "  Tic-Tac-Toe (El Gato) para 2 JUGADORES" << endl;
    cout << "======================================" << endl;

    cout << "\n  " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
    cout << "\n======================================" << endl;
}

/*  Verifica si un jugador ha ganado.
 @return true si hay un ganador, false en caso contrario. */
bool verificarGanador() {
    // Comprobar filas
    if ((tablero[0] == tablero[1] && tablero[1] == tablero[2]) ||
        (tablero[3] == tablero[4] && tablero[4] == tablero[5]) ||
        (tablero[6] == tablero[7] && tablero[7] == tablero[8])) {
        return true;
    }
    // Comprobar columnas
    if ((tablero[0] == tablero[3] && tablero[3] == tablero[6]) ||
        (tablero[1] == tablero[4] && tablero[4] == tablero[7]) ||
        (tablero[2] == tablero[5] && tablero[5] == tablero[8])) {
        return true;
    }
    // Comprobar diagonales
    if ((tablero[0] == tablero[4] && tablero[4] == tablero[8]) ||
        (tablero[2] == tablero[4] && tablero[4] == tablero[6])) {
        return true;
    }
    return false;
}

/* Si el tablero está lleno = Empate
 @return true si no quedan casillas disponibles, false si aún hay movimientos.  */

bool verificarEmpate() {
    for (int i = 0; i < 9; ++i) {
        // Si encontramos cualquier carácter que no sea 'X' u 'O', hay un espacio vacío.
        if (tablero[i] != 'X' && tablero[i] != 'O') {
            return false;
        }
    }
    return true; // El tablero está lleno
}

// Maneja el turno de un jugador.
void manejarTurno() {
    int eleccion;
    int indice;
    bool movimiento_valido = false;

    // Bucle para asegurar que el movimiento sea válido
    while (!movimiento_valido) {
        cout << "Jugador " << jugador_actual << ", ingresa un numero de casilla (1-9): ";

        // 1. Manejo de entrada no numérica
        if (!(cin >> eleccion)) {
            cout << " Entrada inválida. Por favor, ingresa un numero entre 1 y 9." << endl;
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada restante
            continue; // Vuelve al inicio del bucle
        }

        indice = eleccion - 1; // El array usa índices 0-8

        // 2. Comprobación de rango y disponibilidad
        if (indice >= 0 && indice < 9) {
            if (tablero[indice] != 'X' && tablero[indice] != 'O') {
                // Si la casilla no tiene 'X' u 'O', está libre.
                tablero[indice] = jugador_actual;
                movimiento_valido = true;
            } else {
                cout << "La casilla " << eleccion << " ya está ocupada. Intenta de nuevo." << endl;
            }
        } else {
            cout << "Número de casilla fuera de rango. Ingresa un número entre 1 y 9." << endl;
        }
    }
}

// Cambia el turno al otro jugador.
void cambiarJugador() {
    if (jugador_actual == 'X') {
        jugador_actual = 'O';
    } else {
        jugador_actual = 'X';
    }
}

// Función principal
int main() {
    // --- Presentación ---
    cout << "Hola, usuarios!, bienvenido al juego de Tic Tac Toe para 2 jugadores." << endl;
    cout << "Las instrucciones del juego son... escoge una casilla vacía según su número para colocar tu marca." << endl;
    cout << "El objetivo del juego es alinear tres marcas ('X' o 'O') en una fila, columna o diagonal." << endl;

    bool juego_terminado = false;

    // Bucle principal del juego
    while (!juego_terminado) {
        dibujarTablero(); // Dibuja el tablero al comienzo de cada turno
        manejarTurno();   // Procesa el movimiento del jugador actual
        
        // Comprobar si hay un ganador
        if (verificarGanador()) {
            dibujarTablero();
            cout << "\n ¡Felicidades! El Jugador " << jugador_actual << " ha ganado el juego." << endl;
            juego_terminado = true;
        }
        // Comprobar si hay un empate 
        else if (verificarEmpate()) {
            dibujarTablero();
            cout << "\n ¡Es un empate! No quedan movimientos posibles." << endl;
            juego_terminado = true;
        }
        // Si no hay ganador ni empate, cambia de turno
        else {
            cambiarJugador();
        }
    }

    return 0;
}