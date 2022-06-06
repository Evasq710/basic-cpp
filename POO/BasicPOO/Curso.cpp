#include "Curso.h"

#include <iostream>
using namespace std;

Curso::Curso()
{
    //ctor
}

Curso::Curso(string nombre, int creditos)
{
    this->nombre = nombre;
    this->creditos = creditos;
}

Curso::~Curso()
{
    //dtor
}

string Curso::getNombre(){
    return this->nombre;
}

int Curso::getCreditos(){
    return this->creditos;
}
