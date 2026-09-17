#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
struct Estudiante {
    std::string nombre;
    double calificacion;
};
struct Clase {
    std::string codigo;
    std::string nMateria;
    std::vector<Estudiante> estudiantes;
};
void guardarEnArchivo(const std::vector<Clase>& listaClases) {
    std::ofstream archivo("registro_calificaciones.txt");
    if (archivo.is_open()) {
        for (const auto& clase : listaClases) {
            archivo << "CLASE|" << clase.codigo << "|" << clase.nMateria << "\n";
            for (const auto& estudiante : clase.estudiantes) {
                archivo << "ESTUDIANTE|" << estudiante.nombre << "|" << estudiante.calificacion << "\n";
            }
        }
        archivo.close();
        std::cout << "\n[!] Datos guardados temporalmente en 'registro_calificaciones.txt'.\n";
    } else {
        std::cout << "\n[Error] No se pudo crear el archivo de texto.\n";
    }
}
int main() {
    std::vector<Clase> Clases;
    int cantidadClases;
    std::cout << "--- REGISTRO DE CLASES ---\n";
    std::cout << "¿Cuantas clases se desean registrar?: ";
    std::cin >> cantidadClases;
    
    for (int e = 0; e < cantidadEstudiantes; ++e) {
    Estudiante nuevoEstudiante;
    std::cin.ignore();
    std::cout << "  Nombre del estudiante " << (e + 1) << ": ";
    std::getline(std::cin, nuevoEstudiante.nombre);
    
    
    std::cout << "  Calificacion: ";
    std::cin >> nuevoEstudiante.calificacion;

    
    while (nuevoEstudiante.calificacion < 0 || nuevoEstudiante.calificacion > 100) {
        std::cout << "  [!] Nota invalida. Ingresa una nota valida: ";
        std::cin >> nuevoEstudiante.calificacion;
    }

    nuevaClase.estudiantes.push_back(nuevoEstudiante);
}
        Clases.push_back(nuevaClase);
    }
    guardarEnArchivo(Clases);
    return 0;