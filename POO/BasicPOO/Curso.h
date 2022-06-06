#ifndef CURSO_H
#define CURSO_H

#include <iostream>
using namespace std;

class Curso
{
    private:
        string nombre;
        int creditos;

    public:
        Curso(); // ctr por defecto
        Curso(string nombre, int creditos); // ctr definido
        ~Curso(); // dtr

        string getNombre();
        int getCreditos();

};

#endif // CURSO_H
