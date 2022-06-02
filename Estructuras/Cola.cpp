#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

// encolar
void enQueue(Nodo *&, Nodo *&, int);

// desencolar
void deQueue(Nodo *&, Nodo *&);

bool colaVacia(Nodo *);

void mostrarCola(Nodo *);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int nElementos;

    cout<<"Ingrese la cantidad de elementos que desea en la cola: ";
    cin>>nElementos;

    int dato;
    for(int i = 0; i < nElementos; i++){
        cout<<"\nDato "<<i+1<<" a ingresar en la cola: ";
        cin>>dato;
        enQueue(frente, fin, dato);
        mostrarCola(frente);
    }

    // Eliminando todos los elementos de la cola
    while(frente != NULL){
        deQueue(frente, fin);
        mostrarCola(frente);
    }

    return 0;
}

void enQueue(Nodo *&frente, Nodo *&fin, int nuevoDato){
    Nodo *nuevoNodo = new Nodo();

    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;
    if(colaVacia(frente)){
        frente = nuevoNodo;
        fin = nuevoNodo;
    }else{
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
}

void deQueue(Nodo *&frente, Nodo *&fin){
    // El control de que frente no sea NULL se llevó en el main
    Nodo *aux = frente;
    cout<<"\nEliminando " << aux->dato <<"..."<<endl;
    if(frente == fin){
        // solo hay un elemento en la cola
        frente = NULL;
        fin = NULL;
        delete aux;
    }else{
        // hay más de un elemento en la cola
        frente = frente->siguiente;
        delete aux;
    }
}

bool colaVacia(Nodo *frente){
    return (frente == NULL)? true : false;
    //return frente==NULL;
}

void mostrarCola(Nodo *frente){
    cout<<"Mostrando Cola:"<<endl;

    Nodo *actual = frente;
    while(actual != NULL){
        cout<< actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout<<"NULL"<<endl;
}

