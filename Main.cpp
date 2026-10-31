#include <iostream>
#include "estructuras.h"
#include "estudiantes.h"
// (Incluir los demás headers de cursos, notas, persistencia, etc.)

using namespace std;

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int totalEstudiantes = 0;
    
    // Opcional: inicializar desde persistencia si ya está integrado
    // inicializarDatos(estudiantes, totalEstudiantes, ...);

    int opcionPrincipal = -1;
    do {
        cout << "\n========================================\n";
        cout << "   SISTEMA DE CONTROL ACADEMICO - UMG   \n";
        cout << "========================================\n";
        cout << "1. Modulo de Estudiantes\n";
        cout << "2. Modulo de Cursos y Notas\n";
        cout << "3. Modulo de Procesamiento y Reportes\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcionPrincipal;
        cin.ignore();

        switch (opcionPrincipal) {
            case 1:
                menuEstudiantes(estudiantes, totalEstudiantes, MAX_ESTUDIANTES);
                break;
            case 2:
                // menuCursosNotas(...);
                break;
            case 3:
                // menuReportes(...);
                break;
            case 0:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcionPrincipal != 0);

    return 0;
}