#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// === FORMAS DE DECLARAR VARIABLES DE STRUCTS ===

// FORMA 1
struct PersonaForma1{
    string nombre;
    int edad;
}
persona1f1 = {"Alejandro", 20},
persona2f1 = {"Ruperto", 15};

// FORMA 2
struct PersonaForma2{
    string nombre;
    int edad;
} persona1f2;

// === STRUCTS ANIDADOS ===

struct infoDireccion{
    char direccion[30];
    char ciudad[20];
    char provincia[20];
};
struct empleado{
    char nombre[20];
    struct infoDireccion dirEmpleado;
    double salario;
};

int main(){
    cout<<"FORMA 1"<<endl;
	cout<<"Nombre1: "<<persona1f1.nombre<<endl;
	cout<<"Edad1: "<<persona1f1.edad<<endl;
	cout<<"Nombre2: "<<persona2f1.nombre<<endl;
	cout<<"Edad2: "<<persona2f1.edad<<endl;

	cout<<"\nFORMA 2"<<endl;
	cout<<"Ingrese Nombre1: ";
	getline(cin, persona1f2.nombre);
	cout<<"Ingrese Edad1: ";
	cin >> persona1f2.edad;
	cout<<"Nombre1: "<<persona1f2.nombre<<endl;
	cout<<"Edad1: "<<persona1f2.edad<<endl;

	cout<<"\nFORMA 3"<<endl;
	struct PersonaForma1 persona;
	persona.edad = 20;
	persona.nombre = "Abraham";
	cout<<"Nombre: "<<persona.nombre<<endl;
	cout<<"Edad: "<<persona.edad<<endl<<endl;

	// array del struct empleado
	struct empleado empleados[2];
	int sizeArray = sizeof empleados / sizeof empleados[0];
	for(int i = 0; i < sizeArray; i++){
        fflush(stdin); // Limpiando el buffer de basura
        cout<<"Digite su nombre: ";
        cin.getline(empleados[i].nombre, 20, '\n');
        cout<<"Digite su direccion: ";
        cin.getline(empleados[i].dirEmpleado.direccion, 30, '\n');
        cout<<"Digite su ciudad: ";
        cin.getline(empleados[i].dirEmpleado.ciudad, 20, '\n');
        cout<<"Digite su provincia: ";
        cin.getline(empleados[i].dirEmpleado.provincia, 20, '\n');
        cout<<"Digite su salario: ";
        cin>>empleados[i].salario;
        cout<<"\n";
	}
	cout<<"\nSTRUCTS ANIDADOS:"<<endl;
	for(int i = 0; i < sizeArray; i++){
        cout<<empleados[i].nombre<<endl;
        cout<<empleados[i].dirEmpleado.direccion<<endl;
        cout<<empleados[i].dirEmpleado.ciudad<<endl;
        cout<<empleados[i].dirEmpleado.provincia<<endl;
        cout<<empleados[i].salario<<endl;
	}

	system("PAUSE");
	return 0;
}
