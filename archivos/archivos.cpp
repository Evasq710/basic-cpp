#include <iostream>
#include <string>
#include <stdlib.h> // para el exit(1)
#include <fstream> // para manipular archivos

using namespace std;

void escritura();
void lectura();
void addContent();

void escribirBinarios();
void leerBinarios();

// se guardará en un archivo binario
struct Persona{
    string nombre;
    int edad;
};


int main(){

    escritura();
    lectura();
    addContent();
    cout<<"\nLeyendo el archivo luego de añadir una linea:"<<endl;
    lectura();

    escribirBinarios();
    leerBinarios();

    return 0;
}

void escritura(){
    ofstream nuevoArchivo;
    string nombre, contenido;

    /* PIDIENDO LOS DATOS */
    //cout<<"Digite el nombre del archivo: ";
    //getline(cin, nombre); // el nombre debe contener la extensión del archivo (.txt, .json, etc)
    //nuevoArchivo.open(nombre.c_str(), ios::out);
    nuevoArchivo.open("prueba.txt", ios::out); // Abriendo el archivo, si no existe, lo crea, si existe, lo reemplaza

    if(nuevoArchivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    nuevoArchivo<<"Esta es una primera línea ingresada al nuevo archivo.\n";
    nuevoArchivo<<"Esta es una segunda línea ingresada al nuevo archivo.\n";
    nuevoArchivo<<"Esta es una tercera línea ingresada al nuevo archivo.\n";

    /* PIDIENDO LOS DATOS */
    //cout<<"Digite el texto del archivo: ";
    //getline(cin, contenido);
    //nuevoArchivo<<contenido;

    nuevoArchivo.close();
}

void lectura(){
    ifstream archivoLeido;
    string contenido;

    archivoLeido.open("prueba.txt", ios::in); // Abriendo el archivo en modo LECTURA

    if(archivoLeido.fail()){
        cout<<"No se pudo abrir el archivo para su lectura."<<endl;
        exit(1);
    }

    while(!archivoLeido.eof()){ // mientras no se el final del archivo, lee LINEA POR LINEA
        getline(archivoLeido, contenido);
        cout<<contenido<<endl;
    }

    archivoLeido.close();
}

void addContent(){
    ofstream archivo;

    archivo.open("prueba.txt", ios::app); // Abriendolo en modo AÑADIR CONTENIDO (si no existe, lo crea)

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo que se intento modificar."<<endl;
        exit(1);
    }

    archivo<<"Esta es una linea agregada al archivo prueba.txt"<<endl;

    archivo.close();
}

void escribirBinarios(){
    ofstream archivoBinario;

    archivoBinario.open("pruebaBinario.dat", ios::out | ios::binary);

    if(archivoBinario.fail()){
        cout<<"No se pudo abrir el archivo binario"<<endl;
        exit(1);
    }

    Persona persona1;
    persona1.nombre = "Elías Vásquez";
    persona1.edad = 24;

    // Escribiendo el struct en un archivo binario
    archivoBinario.write((char *)&persona1, sizeof(Persona));

    archivoBinario.close();
}

void leerBinarios(){
    ifstream archivoBinario;

    archivoBinario.open("pruebaBinario.dat", ios::in | ios::binary);

    if(archivoBinario.fail()){
        cout<<"No se pudo abrir el archivo binario para su lectura."<<endl;
        exit(1);
    }

    Persona persona1;
    archivoBinario.read((char *)&persona1, sizeof(Persona)); // igual que en la escritura

    cout<<"\nMostrando los datos de un STRUCT, leidos de un archivo binario:"<<endl;
    cout<<persona1.nombre<<endl;
    cout<<persona1.edad<<endl;

    archivoBinario.close();
}
