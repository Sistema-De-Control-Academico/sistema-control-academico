#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <string>

const int MAX_ESTUDIANTES = 100;
const int MAX_CURSOS = 50;
const int MAX_NOTAS = 500;

struct Estudiante
{
    std::string carnet;
    std::string nombre;
    std::string apellido;
};

struct Curso
{
    std::string codigo;
    std::string nombre;
    double notaMinimaAprobacion;
};

struct RegistroNota
{
    std::string carnetEstudiante;
    std::string codigoCurso;
    double nota;
};

#endif
