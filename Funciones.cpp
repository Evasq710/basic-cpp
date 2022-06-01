#include <iostream>
//#include <conio.h>
#include <string>

using namespace std;

// PROTOTIPO DE FUNCIÓN (VER DEFINICION ABAJO)
int encontrarMax(int, int);

// PLANTILLAS DE FUNCIÓN (VER DEFINICION ABAJO)
template <typename TIPOD> // Prefijo de la plantilla, Esto engloba a distintos tipos de datos (int, double, etc), Se puede usar class en vez de typename
void mostrarValorAb(TIPOD);

// PASO DE PARÁMETROS POR REFERENCIA (VER DEFINICION ABAJO)
void valNuevo(int&, int&);

// PASO DE PARÁMETROS TIPO VECTOR (VER DEFINICION ABAJO)
void mostrarArray(int vector[], int);

// PASO DE PARÁMETROS TIPO STRUCT
struct Persona{
	string nombre;
	int edad;
}persona1;
void mostrarStruct(Persona);

int main(){
	int n1, n2;
	cout<<"Digite dos numeros: ";
	cin>>n1>>n2;
	int max = encontrarMax(n1, n2);
	cout << "El numero mayor es " << max << endl;
	
	// Plantillas de función
	int num1 = -4;
	float num2 = 23.4;
	double num3 = -234.5423;
	mostrarValorAb(num1);
	mostrarValorAb(num2);
	mostrarValorAb(num3);
	
	// Parametros por referencia
	valNuevo(n1, n2);
	cout<<"El nuevo valor de n1 es: "<<n1<<endl;
	cout<<"El nuevo valor de n2 es: "<<n2<<endl;
	
	// Parametros por referencia (array)
	cout<<"\nPasando vectores a funciones:"<<endl;
	int array[5] = {1, 2, 3, 4, 5};
	int  size = sizeof array / sizeof array[0];
	mostrarArray(array, size);
	
	// Parametros struct
	persona1.edad = 21;
	persona1.nombre = "Elias Vasquez";
	mostrarStruct(persona1);
	
	//getch();
	return 0;
}

// DEFINICIÓN DE FUNCIÓN
int encontrarMax(int x, int y){
	int max;
	
	if(x > y){
		max = x;
	} else {
		max = y;
	}
	
	return max;
}

// DEFINICIÓN DE FUNCIÓN USANDO PLANTILLAS
template <typename TIPOD>
void mostrarValorAb(TIPOD numero){
	if(numero < 0){
		numero *= -1;
	}
	
	cout<<"El valor absoluto del numero es "<<numero<<endl;
}

// DEFINICIÓN DE FUNCIÓN, PARAM POR REFERENCIA
void valNuevo(int& xnum, int& ynum){
	cout<<"\nEl valor del primer numero es: "<<xnum<<endl;
	cout<<"El valor del segundo numero es: "<<ynum<<endl;
	xnum = 89;
	ynum = 90;
}

void mostrarArray(int vector[], int sizeArray){
	for(int i = 0; i < sizeArray; i++){
		cout << vector[i] << " ";
	}
}

// DEFINICIÓN DE FUNCIÓN, STRUCTS EN PARAMETROS

void mostrarStruct(Persona p){
	cout << "\n\nNombre de struct: " << p.nombre << endl;
	cout << "Edad de struct: " << p.edad << endl;
}

