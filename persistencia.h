#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "estructuras.h"

const std::string ARCHIVO_ESTUDIANTES = "estudiantes.txt";
const std::string ARCHIVO_CURSOS = "cursos.txt";
const std::string ARCHIVO_NOTAS = "notas.txt";

int cargarEstudiantes(Estudiante lista[], int capacidad, const std::string &archivo = ARCHIVO_ESTUDIANTES);
int cargarCursos(Curso lista[], int capacidad, const std::string &archivo = ARCHIVO_CURSOS);
int cargarNotas(RegistroNota lista[], int capacidad, const std::string &archivo = ARCHIVO_NOTAS);

bool guardarEstudiantes(const Estudiante lista[], int cantidad, const std::string &archivo = ARCHIVO_ESTUDIANTES);
bool guardarCursos(const Curso lista[], int cantidad, const std::string &archivo = ARCHIVO_CURSOS);
bool guardarNotas(const RegistroNota lista[], int cantidad, const std::string &archivo = ARCHIVO_NOTAS);

void inicializarDatos(Estudiante estudiantes[], int &totalEstudiantes,
                      Curso cursos[], int &totalCursos,
                      RegistroNota notas[], int &totalNotas);

bool guardarProgreso(const Estudiante estudiantes[], int totalEstudiantes,
                     const Curso cursos[], int totalCursos,
                     const RegistroNota notas[], int totalNotas);

#endif
