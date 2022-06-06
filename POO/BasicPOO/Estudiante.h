#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include "Curso.h" // Incluyendo la clase Curso que forma parte de la clase Estudiante
using namespace std;

class Estudiante
{
    private:
        string nombre;
        int carnet;
        Curso cursoAsignado;

    public:
        Estudiante(); // Constructor por defecto
        /* CLASE COMPUESTA */
        /* "Estudiante" es una clase compuesta, ya que posee otra clase (Curso) */
        /* Para acceder al constructor de Curso, se reciben los parámetros necesarios en el constructor Estudiante */
        /* Ver Estudiante.cpp */
        Estudiante(string nombre, int carnet, string nombreCurso, int creditos);
        ~Estudiante(); // Destructor

        void printDatos();
};

#endif // ESTUDIANTE_H
