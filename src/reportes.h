#ifndef REPORTES_H
#define REPORTES_H

#include <string>
using namespace std;

// Procedimiento: muestra el encabezado del sistema
void mostrarEncabezado();

// Funcion: recibe promedio y devuelve "APROBADO" o "REPROBADO"
string determinarResultado(double promedio);

// Procedimiento: recibe los datos del estudiante y muestra su reporte
void mostrarReporteEstudiante(string nombre, double nota1, double nota2, double nota3);

// Procedimiento: recibe los datos del grupo y muestra el reporte general
void mostrarReporteGeneral(int total, int aprobados, int reprobados, double promedioGeneral);

#endif
