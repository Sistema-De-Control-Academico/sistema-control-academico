#include "procesamiento.h"
#include "estudiantes.h" // normalizarTexto

double sumarNotasRecursivo(const RegistroNota notas[], int totalNotas, const std::string &carnet, int indice)
{
    if (indice == totalNotas) return 0.0; // caso base: se recorrieron todos los registros

    double resto = sumarNotasRecursivo(notas, totalNotas, carnet, indice + 1); // caso recursivo

    if (normalizarTexto(notas[indice].carnetEstudiante) == normalizarTexto(carnet))
        return notas[indice].nota + resto;

    return resto;
}

int contarNotasEstudianteRecursivo(const RegistroNota notas[], int totalNotas, const std::string &carnet, int indice)
{
    if (indice == totalNotas) return 0; // caso base

    int resto = contarNotasEstudianteRecursivo(notas, totalNotas, carnet, indice + 1); // caso recursivo

    if (normalizarTexto(notas[indice].carnetEstudiante) == normalizarTexto(carnet))
        return 1 + resto;

    return resto;
}

double calcularPromedioEstudiante(const std::string &carnet, const RegistroNota notas[], int totalNotas)
{
    int cantidad = contarNotasEstudianteRecursivo(notas, totalNotas, carnet, 0);
    if (cantidad == 0) return 0.0;
    double suma = sumarNotasRecursivo(notas, totalNotas, carnet, 0);
    return suma / cantidad;
}

double calcularPromedioEstudianteEnCurso(const std::string &carnet, const std::string &codigoCurso,
                                          const RegistroNota notas[], int totalNotas)
{
    for (int i = 0; i < totalNotas; i++)
    {
        if (normalizarTexto(notas[i].carnetEstudiante) == normalizarTexto(carnet) &&
            normalizarTexto(notas[i].codigoCurso) == normalizarTexto(codigoCurso))
        {
            return notas[i].nota; // una sola nota por estudiante-curso en este diseno
        }
    }
    return 0.0;
}

std::string determinarResultado(double promedio, double notaMinimaAprobacion)
{
    if (promedio >= notaMinimaAprobacion)
        return "APROBADO";
    return "REPROBADO";
}

// Umbral general del grupo: promedio de las notas minimas de todos los cursos registrados.
// Sirve para las estadisticas generales cuando un estudiante puede tener notas en varios cursos.
static double calcularUmbralGeneral(const Curso cursos[], int totalCursos)
{
    if (totalCursos == 0) return 61.0; // valor de respaldo si aun no hay cursos cargados
    double suma = 0;
    for (int i = 0; i < totalCursos; i++)
        suma += cursos[i].notaMinimaAprobacion;
    return suma / totalCursos;
}

int contarAprobadosRecursivo(const Estudiante estudiantes[], int totalEstudiantes,
                              const RegistroNota notas[], int totalNotas,
                              const Curso cursos[], int totalCursos, int indice)
{
    if (indice == totalEstudiantes) return 0; // caso base

    int resto = contarAprobadosRecursivo(estudiantes, totalEstudiantes, notas, totalNotas,
                                          cursos, totalCursos, indice + 1); // caso recursivo

    double promedio = calcularPromedioEstudiante(estudiantes[indice].carnet, notas, totalNotas);
    double umbral = calcularUmbralGeneral(cursos, totalCursos);

    if (promedio >= umbral)
        return 1 + resto;

    return resto;
}

double calcularPromedioGeneral(const Estudiante estudiantes[], int totalEstudiantes,
                                const RegistroNota notas[], int totalNotas)
{
    if (totalEstudiantes == 0) return 0.0;
    double suma = 0;
    for (int i = 0; i < totalEstudiantes; i++)
        suma += calcularPromedioEstudiante(estudiantes[i].carnet, notas, totalNotas);
    return suma / totalEstudiantes;
}

void construirMatrizCalificaciones(const Estudiante estudiantes[], int totalEstudiantes,
                                    const Curso cursos[], int totalCursos,
                                    const RegistroNota notas[], int totalNotas,
                                    double matriz[][MAX_CURSOS])
{
    for (int i = 0; i < totalEstudiantes; i++)
    {
        for (int j = 0; j < totalCursos; j++)
        {
            matriz[i][j] = calcularPromedioEstudianteEnCurso(estudiantes[i].carnet, cursos[j].codigo, notas, totalNotas);
        }
    }
}

int indiceEstudianteConMayorPromedio(const Estudiante estudiantes[], int totalEstudiantes,
                                      const RegistroNota notas[], int totalNotas)
{
    if (totalEstudiantes == 0) return -1;

    int mejorIndice = 0;
    double mejorPromedio = calcularPromedioEstudiante(estudiantes[0].carnet, notas, totalNotas);

    for (int i = 1; i < totalEstudiantes; i++)
    {
        double promedio = calcularPromedioEstudiante(estudiantes[i].carnet, notas, totalNotas);
        if (promedio > mejorPromedio)
        {
            mejorPromedio = promedio;
            mejorIndice = i;
        }
    }
    return mejorIndice;
}
