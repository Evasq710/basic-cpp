#include "Estudiante.h"

#include <iostream>
using namespace std;

// ctr
Estudiante::Estudiante(){}

/* Se llama al constructor de Curso con : objeto(parametros del constructor) */
/* Si posee varios objetos, se separan con comas en el constructor */
Estudiante::Estudiante(string nombre, int carnet, string nombreCurso, int creditos) : cursoAsignado(nombreCurso, creditos)
{
    this->nombre = nombre;
    this->carnet = carnet;
    // El constructor del objeto cursoAsignado ya se ha llamado arriba
}

// dtr
Estudiante::~Estudiante(){}

void Estudiante::printDatos()
{
    cout << "Mostrando datos del estudiante (clase compuesta):\n";
    cout << "Nombre: " << this->nombre << "\n";
    cout << "Carnet: " << this->carnet << "\n";
    cout << "Nombre curso asignado: " << this->cursoAsignado.getNombre() << "\n";
    cout << "Creditos curso asignado: " << this->cursoAsignado.getCreditos() << "\n";
}
