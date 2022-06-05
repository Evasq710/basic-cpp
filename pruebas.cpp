#include <iostream>
#include <fstream> // para manipular archivos
#include <string.h>

using namespace std;

// se guardará en un archivo binario
struct Persona{
    char nombre[10];
    int edad;
};

void creatingFile();
void modifyFileWithoutChangingSize();
void creatingEmptyBinaryFile();
void readingBinaryFile();
void modifyBinaryFileWithoutChangingSize(Persona);

int main(){
    //creatingFile();
    //modifyFileWithoutChangingSize();
    creatingEmptyBinaryFile();
    readingBinaryFile();

    Persona p1;
    strcpy(p1.nombre, "p1");
    p1.edad = 10;
    modifyBinaryFileWithoutChangingSize(p1);
    readingBinaryFile();

    Persona p2;
    strcpy(p2.nombre, "p2");
    p2.edad = 20;
    modifyBinaryFileWithoutChangingSize(p2);
    readingBinaryFile();

    Persona p3;
    strcpy(p3.nombre, "p3");
    p3.edad = 30;
    modifyBinaryFileWithoutChangingSize(p3);
    readingBinaryFile();

    return 0;
}

void creatingFile(){
    ofstream archivo; // escritura

    archivo.open("pruebas.txt", ios::out);

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo que se intento modificar."<<endl;
        exit(1);
    }

    archivo << "alo! que tal como estas"<<endl;

    archivo.close();
}

void modifyFileWithoutChangingSize()
{
    fstream archivo; // lectura y escritura

    archivo.open("pruebas.txt"); // el archivo debe existir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo que se intento modificar."<<endl;
        exit(1);
    }

    cout << "Pos puntero tellp: " << archivo.tellp() << endl;
    cout << "Pos puntero tellg: " << archivo.tellg() << endl;
    archivo.seekp(3);
    cout << "Pos puntero tellp luego de seekp(0): " << archivo.tellp() << endl;
    cout << "Pos puntero tellg luego de seekp(0): " << archivo.tellg() << endl;

    archivo << ",";
    cout << "Pos puntero tellp luego de escribir , en vez de !: " << archivo.tellp() << endl;
    cout << "Pos puntero tellg luego de escribir , en vez de !: " << archivo.tellg() << endl;

    archivo.close();
}

void creatingEmptyBinaryFile(){
    // creating 1MB Empty Binary File
    string command = "dd if=/dev/zero of=/home/abrava/Escritorio/Cursos\\ Progra/basic-cpp/pruebas.dat bs=1024 count=1k";
    system(command.c_str());
    //ofstream archivo;
    //archivo.open("pruebas.dat", ios::out | ios::binary);
    //if(archivo.fail()){
    //    cout<<"No se pudo abrir el archivo para creacion."<<endl;
    //    exit(1);
    //}

    //int oneMB = 1024*1024;
    //char nulo = '\0';
    //for(int i = 0; i < oneMB; i++){
    //    archivo.write((char *)&nulo, sizeof(char));
    //}

    //archivo.close();

    cout << "Archivo binario pruebas.dat creado exitosamente." << endl;
}

void readingBinaryFile(){
    ifstream archivo; // lectura

    archivo.open("pruebas.dat", ios::in | ios::binary); // el archivo debe existir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo para lectura."<<endl;
        exit(1);
    }

    char flag;
    Persona p;
    int iteraciones = 0;

    cout << "\nLEYENDO EL BINARIO:\n\n";
    while(!archivo.eof()){
        //cout << "posicion lectura antes del char: "<<archivo.tellg()<<endl;
        flag = archivo.get();

        if(!archivo.eof() && flag != '\0'){
            cout << "Flag: " << flag << endl;

            //cout << "posicion lectura antes del struct: "<<archivo.tellg()<<endl;
            archivo.read((char *) &p, sizeof(p));
            //cout << "posicion lectura despues del struct: "<<archivo.tellg()<<endl;
            cout << "Persona guardada: "<< endl;
            cout << p.edad << endl;
            cout << p.nombre << endl << endl;
        }
        else break;

        iteraciones++;
    }
    cout << "iteraciones: "<<iteraciones<<endl<< endl;
    //cout << "posicion actual en lectura: "<<archivo.tellg()<<endl<<endl;

    archivo.close();
}

void modifyBinaryFileWithoutChangingSize(Persona p)
{
    fstream archivo; // lectura y escritura

    archivo.open("pruebas.dat", ios::in|ios::out|ios::binary); // el archivo debe existir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo binario que se intento modificar."<<endl;
        exit(1);
    }

    char c;
    Persona pAux;
    int iteraciones = 0;

    cout << "\MODIFICANDO EL BINARIO:\n";
    //cout << "\nposicion actual en lectura: "<<archivo.tellg()<<endl;
    while(!archivo.eof()){

        c = archivo.get();

        if(!archivo.eof() && c != '\0'){
            cout << "Flag: " << c << endl;
            archivo.read((char *) &pAux, sizeof(pAux));
        }
        else break;

        iteraciones++;
    }
    cout << "iteraciones: "<<iteraciones<<endl<< endl;
    archivo.seekp(archivo.tellp()-1); // posicionando el puntero antes del caracter nulo encontrado
    //cout << "posicion actual en escritura: "<<archivo.tellp()<<endl;
    char flag = '0'; // para indicar que el siguiente es struct
    archivo.write((char *)&flag, sizeof(flag));
    //cout << "posicion en escritura luego de ingresar el int (flag): "<<archivo.tellp()<<endl;
    archivo.write((char *)&p, sizeof(p));
    //cout << "posicion en escritura luego de ingresar el struct: "<<archivo.tellp()<<endl;

    archivo.close();
}
