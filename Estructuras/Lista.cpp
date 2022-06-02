#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertar(Nodo *&, int);

void mostrarLista(Nodo *);

int main(){
    Nodo *lista = NULL;
    int nElementos;

    cout<<"Ingrese la cantidad de elementos que desea en la lista enlazada simple: ";
    cin>>nElementos;

    int dato;
    for(int i = 0; i < nElementos; i++){
        cout<<"\nDato "<<i+1<<" a ingresar en la lista: ";
        cin>>dato;
        insertar(lista, dato);
        mostrarLista(lista);
    }

    return 0;
}

void insertar(Nodo *& lista, int nuevoDato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->dato = nuevoDato;

    if(lista == NULL){
        // primer elemento
        lista = nuevoNodo;
    }else{
        Nodo *actual = lista;
        while(actual->siguiente != NULL){
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarLista(Nodo *primero){
    cout<<"Mostrando Lista simple:"<<endl;

    Nodo *actual = primero;
    while(actual != NULL){
        cout<< actual->dato << " -> ";
        actual = actual->siguiente;
    }

    cout<<"NULL"<<endl;
}
