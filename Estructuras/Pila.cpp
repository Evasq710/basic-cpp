#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

// (pasamos la PILA, que es un puntero -se lo pasamos por referencia-, int dato)
void push(Nodo *&, int);

void pop(Nodo *&);

void mostrarPila(Nodo *);

int main(){
    Nodo *pila = NULL;
    int nElementos;

    cout<<"Ingrese la cantidad de elementos que desea en la pila: ";
    cin>>nElementos;

    int dato;
    for(int i = 0; i < nElementos; i++){
        cout<<"\nDato "<<i+1<<" a ingresar en la pila: ";
        cin>>dato;
        push(pila, dato);
        mostrarPila(pila);
    }

    // Eliminando todos los elementos de la pila
    while(pila != NULL){
        pop(pila);
        mostrarPila(pila);
    }

    return 0;
}

void push(Nodo *&pila, int nuevoDato){
    Nodo *nuevoNodo = new Nodo(); // creando el espacio en memoria para el nuevo nodo
    nuevoNodo->dato = nuevoDato; // colocando el dato en el nodo
    nuevoNodo->siguiente = pila; // PRIMER DATO: siguiente=NULL, DEMÁS: siguiente=cima (puntero pila)
    pila = nuevoNodo; // El puntero pila (cima) es el nuevo nodo ingresado
}

void pop(Nodo *&pila){
    // El control de que pila no sea NULL se llevó en el main
    Nodo *aux = pila;
    cout<<"\nEliminando " << aux->dato <<"..."<<endl;
    pila = aux->siguiente;
    delete aux;
}

void mostrarPila(Nodo *pila){
    cout<<"Mostrando Pila:"<<endl;

    Nodo *actual = pila;
    while(actual != NULL){
        cout<< actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout<<"NULL"<<endl;
}

