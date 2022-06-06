#include "Punto.h" // incluyendo la clase declarada
#include<iostream>

using namespace std;

/* Inicializando el valor de los atributos static (Ver Punto.h para más explicación) */
int Punto::contadorPuntos = 0;

void Punto::setX(int valorX){
    this->x = valorX;
}

void Punto::setY(int valorY){
    this->y = valorY;
}

int Punto::getX(){
    return this->x;
}

int Punto::getY(){
    return this->y;
}

void Punto::mostrarCoordenadas(){
    cout << "Mostrando coordenadas:\n";
    cout << "X: " << this->x << "\n";
    cout << "Y: " << this->y << "\n";
}

int Punto::getStaticContador(){
    return this->contadorPuntos;
}

int Punto::sumaStatic(int n1, int n2){
    return n1 + n2;
}
