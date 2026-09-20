#ifndef REPORTES_H
#define REPORTES_H

#include <string>
using namespace std;

// Procedimiento: muestra el encabezado del sistema
void mostrarEncabezado();

// Funcion: recibe promedio y nota minima del curso, devuelve "APROBADO" o "REPROBADO"
string determinarResultado(double promedio, double notaMinima);

// Procedimiento: recibe nombre, promedio y resultado del estudiante
void mostrarReporteEstudiante(string nombre, double promedio, string resultado);

// Procedimiento: recibe los datos del grupo y muestra el reporte general
void mostrarReporteGeneral(int total, int aprobados, int reprobados, double promedioGeneral);

#end
