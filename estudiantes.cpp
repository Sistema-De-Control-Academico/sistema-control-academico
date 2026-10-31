#include "estudiantes.h"
#include <iostream>
#include <cctype>

std::string normalizarTexto(const std::string &texto)
{
    std::string resultado;
    // Quitar espacios al inicio y al final
    int inicio = 0;
    int fin = (int)texto.size() - 1;
    while (inicio <= fin && std::isspace((unsigned char)texto[inicio])) inicio++;
    while (fin >= inicio && std::isspace((unsigned char)texto[fin])) fin--;

    for (int i = inicio; i <= fin; i++)
    {
        resultado += (char)std::toupper((unsigned char)texto[i]);
    }
    return resultado;
}

int buscarEstudiantePorCarnet(const Estudiante lista[], int total, const std::string &carnet)
{
    std::string objetivo = normalizarTexto(carnet);
    for (int i = 0; i < total; i++)
    {
        if (normalizarTexto(lista[i].carnet) == objetivo)
            return i;
    }
    return -1;
}

int buscarEstudiantesPorNombre(const Estudiante lista[], int total, const std::string &texto, int resultados[])
{
    std::string buscado = normalizarTexto(texto);
    int encontrados = 0;
    for (int i = 0; i < total; i++)
    {
        std::string nombreCompleto = normalizarTexto(lista[i].nombre + " " + lista[i].apellido);
        if (nombreCompleto.find(buscado) != std::string::npos)
        {
            resultados[encontrados] = i;
            encontrados++;
        }
    }
    return encontrados;
}

bool registrarEstudiante(Estudiante lista[], int &total, int capacidad,
                          const std::string &carnet, const std::string &nombre, const std::string &apellido)
{
    if (total >= capacidad) return false;
    if (buscarEstudiantePorCarnet(lista, total, carnet) != -1) return false; // carnet duplicado
    if (carnet.empty() || nombre.empty() || apellido.empty()) return false;

    lista[total].carnet = carnet;
    lista[total].nombre = nombre;
    lista[total].apellido = apellido;
    total++;
    return true;
}

bool editarEstudiante(Estudiante lista[], int total, const std::string &carnet,
                       const std::string &nuevoNombre, const std::string &nuevoApellido)
{
    int idx = buscarEstudiantePorCarnet(lista, total, carnet);
    if (idx == -1) return false;
    if (nuevoNombre.empty() || nuevoApellido.empty()) return false;

    lista[idx].nombre = nuevoNombre;
    lista[idx].apellido = nuevoApellido;
    return true;
}

void mostrarEstudiante(const Estudiante &est)
{
    std::cout << "Carnet: " << est.carnet
               << " | Nombre: " << est.nombre << " " << est.apellido << std::endl;
}

void listarEstudiantes(const Estudiante lista[], int total)
{
    if (total == 0)
    {
        std::cout << "No hay estudiantes registrados.\n";
        return;
    }
    for (int i = 0; i < total; i++)
        mostrarEstudiante(lista[i]);
}

int contarEstudiantesRecursivo(const Estudiante lista[], int total)
{
    if (total == 0) return 0; // caso base
    return 1 + contarEstudiantesRecursivo(lista, total - 1); // caso recursivo
}

void menuEstudiantes(Estudiante estudiantes[], int &totalEstudiantes, int capacidad)
{
    int opcion = -1;
    do
    {
        std::cout << "\n--- MODULO ESTUDIANTES ---\n";
        std::cout << "1. Registrar estudiante\n";
        std::cout << "2. Editar estudiante\n";
        std::cout << "3. Buscar por carnet\n";
        std::cout << "4. Buscar por nombre/apellido\n";
        std::cout << "5. Listar todos\n";
        std::cout << "6. Contar estudiantes (recursivo)\n";
        std::cout << "0. Volver al menu principal\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        if (opcion == 1)
        {
            std::string carnet, nombre, apellido;
            std::cout << "Carnet: "; std::getline(std::cin, carnet);
            std::cout << "Nombre: "; std::getline(std::cin, nombre);
            std::cout << "Apellido: "; std::getline(std::cin, apellido);
            if (registrarEstudiante(estudiantes, totalEstudiantes, capacidad, carnet, nombre, apellido))
                std::cout << "Estudiante registrado correctamente.\n";
            else
                std::cout << "No se pudo registrar (carnet duplicado, datos vacios o sin espacio).\n";
        }
        else if (opcion == 2)
        {
            std::string carnet, nombre, apellido;
            std::cout << "Carnet del estudiante a editar: "; std::getline(std::cin, carnet);
            std::cout << "Nuevo nombre: "; std::getline(std::cin, nombre);
            std::cout << "Nuevo apellido: "; std::getline(std::cin, apellido);
            if (editarEstudiante(estudiantes, totalEstudiantes, carnet, nombre, apellido))
                std::cout << "Estudiante actualizado.\n";
            else
                std::cout << "No se encontro el estudiante.\n";
        }
        else if (opcion == 3)
        {
            std::string carnet;
            std::cout << "Carnet a buscar: "; std::getline(std::cin, carnet);
            int idx = buscarEstudiantePorCarnet(estudiantes, totalEstudiantes, carnet);
            if (idx != -1) mostrarEstudiante(estudiantes[idx]);
            else std::cout << "No encontrado.\n";
        }
        else if (opcion == 4)
        {
            std::string texto;
            std::cout << "Texto a buscar: "; std::getline(std::cin, texto);
            int resultados[MAX_ESTUDIANTES];
            int encontrados = buscarEstudiantesPorNombre(estudiantes, totalEstudiantes, texto, resultados);
            if (encontrados == 0) std::cout << "Sin coincidencias.\n";
            for (int i = 0; i < encontrados; i++)
                mostrarEstudiante(estudiantes[resultados[i]]);
        }
        else if (opcion == 5)
        {
            listarEstudiantes(estudiantes, totalEstudiantes);
        }
        else if (opcion == 6)
        {
            std::cout << "Total de estudiantes (recursivo): "
                       << contarEstudiantesRecursivo(estudiantes, totalEstudiantes) << std::endl;
        }
        else if (opcion != 0)
        {
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}
