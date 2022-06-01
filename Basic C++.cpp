//Fundamentos de C++


#include <iostream> //>>>Librería input output stream
#include <math.h> //>>>Librería matemática y trigonométrica
#include <string.h> //>>>Librería para trabajar con cadenas de caracteres
//#include <conio.h> //>>>Librería para evitar que se cierre el ejecutable (getch();)
#include <stdlib.h> //>>>pause, atoi y atof
//#include <time.h> //>>>Librería para generar números aleatorios
//srand(time(NULL));
//variable = limite_inferior + rand() % (limite_superior + 1 - limite_inferior);

using namespace std;

int main(){	
	
	int entero = 15;
	float flotante = 10.45;
	double mayor = 16.3456;
	char letra = 'a';
	
	//===Cadenas de caracteres===
	char palabra[] = "abcdef";
	int longitud = strlen(palabra);
	cout<<palabra<<" tiene "<<longitud<<" caracteres."<<endl;
	
	char palabra2[] = {'g', 'h', 'i', 'j', 'k'};
	cout<<palabra2<<endl;
	
	char palabraCopiada[10];
	strcpy(palabraCopiada, palabra2);
	cout<<palabraCopiada<<endl;
	
	if(strcmp(palabra, palabra2)==0){
		cout<<"Ambas cadenas son iguales"<<endl;
	} else {
		cout<<"Las cadenas comparadas son distintas"<<endl;
	}
	
	char cadenaConcatenada[20];
	strcpy(cadenaConcatenada, palabra);
	strcat(cadenaConcatenada, palabra2);
	cout<<"Concatenacion: "<<cadenaConcatenada<<endl;
	strrev(cadenaConcatenada);
	cout<<"Invertida: "<<cadenaConcatenada<<endl;
	strupr(cadenaConcatenada);
	cout<<"Mayusculas: "<<cadenaConcatenada<<endl;
	strlwr(cadenaConcatenada);
	cout<<"Minusculas: "<<cadenaConcatenada<<endl;
	
	char cadInt[] = "123";
	int charToInt = atoi(cadInt); // 0 si la cadena no es un número
	cout<<"Cadena a int: "<<charToInt<<endl;
	char cadFloat[] = "123.4";
	float charToFloat = atof(cadFloat); // 0 si la cadena no es un número
	cout<<"Cadena a float: "<<charToFloat<<endl;
	
	char nombre[20];
	cout<<"Ingrese su nombre: ";
	//cin>>nombre; //No toma la cadena luego de detectado un espacio
	//gets(nombre); //Guarda toda la cadena, sin importar el tamaño definido al arreglo
	//cin.getline(nombre, 20, '\n'); //ERROR: ¿Buffer lleno? 
	cout<<nombre<<endl;
	
	//===Arreglos unidimensionales===
	int enteros[5], enteros2[2];
	cout<<"enteros[1] = "<<enteros[1]<<endl;
	float flotantes[] = {1, 2.2, 3, 4.4, 5};
	cout<<"flotantes[3] = "<<flotantes[3]<<endl;
	//===Arreglos bidimensionales===
	char caracteres[2][3];
	cout<<"caracteres[0][0] = "<<caracteres[0][0]<<endl;
	int matriznum[2][3] = {1,2,3 , 4,5,6};
	cout<<"matriznum[1][0] = "<<matriznum[1][0]<<endl;
	int matriznum2[2][3] = {{1,2,3} , {4,5,6}};
	cout<<"matriznum2[1][0] = "<<matriznum2[1][0]<<endl;
	
	//===Ingreso y salida de datos===
	//===Operaciones aritméticas===
	//Declaración de multiples variables:
	int n1, n2, suma = 0, resta = 0, producto = 0, division = 0;
	cout << "Digite un número: ";
	cin >> n1; //Guardandolo en una variable
	cout << "Digite otro número: ";
	cin >> n2;
	
	suma = n1 + n2;
	resta = n1 - n2;
	producto = n1 * n2;
	division = n1 / n2;
	
	cout << "\nSuma: " <<suma<<endl;
	cout << "Resta: " <<resta<<endl; 
	cout << "Multiplicacion: " <<producto<<endl;
	cout << "Division: " <<division<<endl;
	
	//Raíces cuadradas y potencias (librería math.h)
	float cateto1, cateto2, hipotenusa;
	cateto1 = 3;
	cateto2 = 4;
	hipotenusa = sqrt(pow(cateto1, 2) + pow(cateto2, 2));
	cout<<"\nCateto 1: "<<cateto1<<endl;
	cout<<"Cateto 2: "<<cateto2<<endl;
	cout<<"Hipotenusa: "<<hipotenusa<<endl;
	
	/*
	if(condicion){
		instruccion;
	} else {
		instruccion;
	}
	
	switch(variable){
		case literal1:
			instruccion;
			break;
		case literal2:
			instruccion;
			break;
		default:
			instruccion;
			break;
	}
	
	while(expresion logica) {
		instruccion;
	}
	
	do {
		instrucciones;
	} while(expresion logica);
	
	
	for(int i = 0; i < 10; i++){
		cout<<(i + 1)<<endl;
	}
	
	*/
		
	//Finaliza el programa cuando se presiona una tecla #include <conio.h>
	//getch();	
	//Finaliza el programa cuando se presiona una tecla #include <stdlib.h>
	system("pause");
	
	return 0;
}
