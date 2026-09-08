#include "persistencia.h"
#include <fstream>
#include <sstream>
#include <iostream>

// En estudiantes.txt  va carnet|nombre|apellido
// En cursos.txt va codigo|nombre|notaMinimaAprobacion
// En notas.txt va carnetEstudiante|codigoCurso|nota

static bool separarLinea(const std::string &linea, std::string partes[], int cantidadPartes)
{
    std::stringstream ss(linea);
    std::string campo;
    int i = 0;
    while (std::getline(ss, campo, '|') && i < cantidadPartes)
    {
        partes[i] = campo;
        i++;
    }
    return i == cantidadPartes;
}

int cargarEstudiantes(Estudiante lista[], int capacidad, const std::string &archivo)
{
    std::ifstream entrada(archivo);
    if (!entrada.is_open())
        return 0;

    int cantidad = 0;
    std::string linea;
    while (std::getline(entrada, linea) && cantidad < capacidad)
    {
        if (linea.empty())
            continue;
        std::string partes[3];
        if (separarLinea(linea, partes, 3))
        {
            lista[cantidad].carnet = partes[0];
            lista[cantidad].nombre = partes[1];
            lista[cantidad].apellido = partes[2];
            cantidad++;
        }
    }
    entrada.close();
    return cantidad;
}

bool guardarEstudiantes(const Estudiante lista[], int cantidad, const std::string &archivo)
{
    std::ofstream salida(archivo);
    if (!salida.is_open())
        return false;
    for (int i = 0; i < cantidad; i++)
    {
        salida << lista[i].carnet << "|" << lista[i].nombre << "|" << lista[i].apellido << "\n";
    }
    salida.close();
    return true;
}

int cargarCursos(Curso lista[], int capacidad, const std::string &archivo)
{
    std::ifstream entrada(archivo);
    if (!entrada.is_open())
        return 0;

    int cantidad = 0;
    std::string linea;
    while (std::getline(entrada, linea) && cantidad < capacidad)
    {
        if (linea.empty())
            continue;
        std::string partes[3];
        if (separarLinea(linea, partes, 3))
        {
            lista[cantidad].codigo = partes[0];
            lista[cantidad].nombre = partes[1];
            lista[cantidad].notaMinimaAprobacion = std::stod(partes[2]);
            cantidad++;
        }
    }
    entrada.close();
    return cantidad;
}

bool guardarCursos(const Curso lista[], int cantidad, const std::string &archivo)
{
    std::ofstream salida(archivo);
    if (!salida.is_open())
        return false;
    for (int i = 0; i < cantidad; i++)
    {
        salida << lista[i].codigo << "|" << lista[i].nombre << "|"
               << lista[i].notaMinimaAprobacion << "\n";
    }
    salida.close();
    return true;
}

int cargarNotas(RegistroNota lista[], int capacidad, const std::string &archivo)
{
    std::ifstream entrada(archivo);
    if (!entrada.is_open())
        return 0;

    int cantidad = 0;
    std::string linea;
    while (std::getline(entrada, linea) && cantidad < capacidad)
    {
        if (linea.empty())
            continue;
        std::string partes[3];
        if (separarLinea(linea, partes, 3))
        {
            lista[cantidad].carnetEstudiante = partes[0];
            lista[cantidad].codigoCurso = partes[1];
            lista[cantidad].nota = std::stod(partes[2]);
            cantidad++;
        }
    }
    entrada.close();
    return cantidad;
}

bool guardarNotas(const RegistroNota lista[], int cantidad, const std::string &archivo)
{
    std::ofstream salida(archivo);
    if (!salida.is_open())
        return false;
    for (int i = 0; i < cantidad; i++)
    {
        salida << lista[i].carnetEstudiante << "|" << lista[i].codigoCurso << "|"
               << lista[i].nota << "\n";
    }
    salida.close();
    return true;
}

void inicializarDatos(Estudiante estudiantes[], int &totalEstudiantes,
                      Curso cursos[], int &totalCursos,
                      RegistroNota notas[], int &totalNotas)
{
    totalEstudiantes = cargarEstudiantes(estudiantes, MAX_ESTUDIANTES);
    totalCursos = cargarCursos(cursos, MAX_CURSOS);
    totalNotas = cargarNotas(notas, MAX_NOTAS);

    std::cout << "Datos cargados: " << totalEstudiantes << " estudiantes, "
              << totalCursos << " cursos, " << totalNotas << " notas.\n";
}

bool guardarProgreso(const Estudiante estudiantes[], int totalEstudiantes,
                     const Curso cursos[], int totalCursos,
                     const RegistroNota notas[], int totalNotas)
{
    bool ok1 = guardarEstudiantes(estudiantes, totalEstudiantes);
    bool ok2 = guardarCursos(cursos, totalCursos);
    bool ok3 = guardarNotas(notas, totalNotas);
    return ok1 && ok2 && ok3;
}