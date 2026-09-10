#include <iostream>
#include <string>
#include <iomanip>
#include "reportes.h"
using namespace std;

// ==Los codigos dE colores ==
const string RESET     = "\033[0m";
const string NEGRITA   = "\033[1m";
const string GRIS      = "\033[100;97m";
const string CIAN      = "\033[96m";
const string AMARILLO  = "\033[93m";
const string VERDE     = "\033[92m";
const string ROJO      = "\033[91m";
const string BLANCO    = "\033[97m";

// ==El  ENCABEZADO ==
void mostrarEncabezado() {
    cout << GRIS;
    cout << "================================================" << RESET << endl;
    cout << GRIS << "|" << RESET;
    cout << CIAN << NEGRITA
         << "           REPORTE ACADEMICO                  "
         << RESET << GRIS << "|" << RESET << endl;
    cout << GRIS << "|" << RESET;
    cout << BLANCO
         << "           Sistema de Control de Notas        "
         << RESET << GRIS << "|" << RESET << endl;
    cout << GRIS;
    cout << "================================================" << RESET << endl;
    cout << endl;
}

// == Determinar resultado ==
string determinarResultado(double promedio) {
    if (promedio >= 61) {
        return "APROBADO";
    } else {
        return "REPROBADO";
    }
}

// == Reporte individual ==
void mostrarReporteEstudiante(string nombre, double nota1, double nota2, double nota3) {
    double promedio = (nota1 + nota2 + nota3) / 3;
    string resultado = determinarResultado(promedio);

    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;
    cout << GRIS << "|" << RESET;
    cout << AMARILLO << NEGRITA
         << "           REPORTE DEL ESTUDIANTE               "
         << RESET << GRIS << "|" << RESET << endl;
    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Nombre:    "
         << CIAN << left << setw(30) << nombre
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Nota 1:    "
         << AMARILLO << left << setw(30) << nota1
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Nota 2:    "
         << AMARILLO << left << setw(30) << nota2
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Nota 3:    "
         << AMARILLO << left << setw(30) << nota3
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Promedio:  "
         << CIAN << NEGRITA << left << setw(30) << promedio
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Resultado: ";
    if (resultado == "APROBADO") {
        cout << VERDE << NEGRITA << left << setw(30) << resultado;
    } else {
        cout << ROJO << NEGRITA << left << setw(30) << resultado;
    }
    cout << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;
    cout << endl;
}

// == Reporte asi  general ==
void mostrarReporteGeneral(int total, int aprobados, int reprobados, double promedioGeneral) {
    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;
    cout << GRIS << "|" << RESET;
    cout << AMARILLO << NEGRITA
         << "          REPORTE GENERAL DEL GRUPO             "
         << RESET << GRIS << "|" << RESET << endl;
    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Total estudiantes:  "
         << CIAN << left << setw(24) << total
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Aprobados:          "
         << VERDE << left << setw(24) << aprobados
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Reprobados:         "
         << ROJO << left << setw(24) << reprobados
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS << "|" << RESET << BLANCO << "  Promedio general:   "
         << AMARILLO << left << setw(24) << promedioGeneral
         << RESET << GRIS << "|" << RESET << endl;

    cout << GRIS;
    cout << "+------------------------------------------------+" << RESET << endl;
    cout << endl;
}
