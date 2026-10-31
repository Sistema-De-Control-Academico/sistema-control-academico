#include <iostream>
#include <iomanip>
#include <string>
#include "reportes.h"
#include "estructuras.h"
#include "procesamiento.h"

using namespace std;

// 1. Encabezado del sistema
void mostrarEncabezado() {
    cout << "\n==================================================\n";
    cout << "             REPORTE ACADEMICO                    \n";
    cout << "     Sistema de Control de Notas - UMG            \n";
    cout << "==================================================\n";
}

// 2. Reporte individual de un estudiante
void mostrarReporteEstudiante(string nombreCompleto, double promedio, string resultado) {
    cout << "--------------------------------------------------\n";
    cout << " Estudiante: " << nombreCompleto << "\n";
    cout << " Promedio:   " << fixed << setprecision(2) << promedio << "\n";
    cout << " Resultado:  " << resultado << "\n";
    cout << "--------------------------------------------------\n";
}

// 3. Reporte general del grupo
void mostrarReporteGeneral(int total, int aprobados, int reprobados, double promedioGeneral) {
    cout << "\n==================================================\n";
    cout << "             RESUMEN GENERAL                      \n";
    cout << "==================================================\n";
    cout << " Total estudiantes : " << total << "\n";
    cout << " Aprobados         : " << aprobados << "\n";
    cout << " Reprobados        : " << reprobados << "\n";
    cout << " Promedio general  : " << fixed << setprecision(2) << promedioGeneral << "\n";
    cout << "==================================================\n\n";
}

// 4. Función extra (Cadenas y Búsquedas)
// Muestra el expediente completo de un estudiante buscándolo por su nombre o carnet.
void mostrarExpedienteEstudiante(const Estudiante estudiantes[], int totalEst, 
                                  const RegistroNota notas[], int totalNotas,
                                  const Curso cursos[], int totalCursos, 
                                  string busqueda) {
    bool encontrado = false;
    
    for (int i = 0; i < totalEst; i++) {
        string nombreCompleto = estudiantes[i].nombre + " " + estudiantes[i].apellido;
        
        // Búsqueda por carnet exacto o por nombre parcial (usando find)
        if (estudiantes[i].carnet == busqueda || nombreCompleto.find(busqueda) != string::npos) {
            encontrado = true;
            cout << "\n==================================================\n";
            cout << " EXPEDIENTE DEL ESTUDIANTE                        \n";
            cout << "==================================================\n";
            cout << " Nombre: " << nombreCompleto << "\n";
            cout << " Carnet: " << estudiantes[i].carnet << "\n";
            cout << "--------------------------------------------------\n";
            cout << " Cursos y Notas:\n";
            
            for (int j = 0; j < totalNotas; j++) {
                if (notas[j].carnetEstudiante == estudiantes[i].carnet) {
                    string nombreCurso = notas[j].codigoCurso;
                    // Buscar el nombre real del curso
                    for (int k = 0; k < totalCursos; k++) {
                        if (cursos[k].codigo == notas[j].codigoCurso) {
                            nombreCurso = cursos[k].nombre;
                            break;
                        }
                    }
                    cout << "   - " << left << setw(20) << nombreCurso 
                         << " | Nota: " << notas[j].nota << "\n";
                }
            }
            cout << "==================================================\n";
        }
    }
    
    if (!encontrado) {
        cout << "\n[!] No se encontro ningun estudiante con: " << busqueda << "\n";
    }
}