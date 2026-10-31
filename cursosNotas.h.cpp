#ifndef CURSOS_NOTAS_H
#define CURSOS_NOTAS_H

#include <string>
#include "estructuras.h"

// --- CURSOS ---

// Busca un curso por codigo. Devuelve el indice o -1 si no existe.
int buscarCursoPorCodigo(const Curso lista[], int total, const std::string &codigo);

// Registra un curso nuevo. Devuelve false si el codigo ya existe, hay datos invalidos o no hay espacio.
bool registrarCurso(Curso lista[], int &total, int capacidad,
                     const std::string &codigo, const std::string &nombre, double notaMinima);

// Lista todos los cursos registrados.
void listarCursos(const Curso lista[], int total);

// --- NOTAS ---

// Valida que una nota este en el rango permitido (0 a 100 inclusive).
bool validarRangoNota(double nota);

// Busca el indice de un registro de nota para un estudiante+curso especifico. -1 si no existe.
int buscarNota(const RegistroNota notas[], int totalNotas, const std::string &carnet, const std::string &codigoCurso);

// Registra una nota nueva. Valida que el estudiante y el curso existan, que la nota este en rango,
// y que no exista ya una nota para ese mismo estudiante+curso (para eso se usa modificarNota).
bool registrarNota(RegistroNota notas[], int &totalNotas, int capacidad,
                    const Estudiante estudiantes[], int totalEstudiantes,
                    const Curso cursos[], int totalCursos,
                    const std::string &carnet, const std::string &codigoCurso, double nota);

// Modifica una nota ya existente. Devuelve false si no se encontro o la nota no es valida.
bool modificarNota(RegistroNota notas[], int totalNotas,
                    const std::string &carnet, const std::string &codigoCurso, double nuevaNota);

// Menu interactivo por consola del modulo Cursos/Notas. Se llama desde main().
void menuCursosNotas(Curso cursos[], int &totalCursos, int capacidadCursos,
                      RegistroNota notas[], int &totalNotas, int capacidadNotas,
                      const Estudiante estudiantes[], int totalEstudiantes);

#endif
