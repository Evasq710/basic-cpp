#include <iostream>
#include <string>
using namespace std;

// TRANSMISIÓN DE DIRECCIONES DE MEMORIA MEDIANTE PUNTEROS
void intercambio(float *, float *);

// TRANSMISIÓN DE ARRAYS MEDIANTE PUNTEROS
int hallarMaximo(int *, int);

// PUNTEROS A STRUCTS
struct Persona{
	string nombre;
	int edad;
}persona1, *punteroPersona = &persona1;
//struct Persona{
//	string nombre;
//	int edad;
//}personas[3], *punteroPersona = personas; // almacenando la dirección de memoria del primer elemento al puntero


int main(){
	int num, *puntero_dir_num;

	num = 20;
	puntero_dir_num = &num;

//	cout << "Numero: " << num << endl;
//	cout << "Direccion de memoria: " << &num << endl;
	cout << "Numero: " << *puntero_dir_num << endl;
	cout << "Direccion de memoria: " << puntero_dir_num << endl;


	// === CORRESPONDENCIA ENTRE ARRAYS Y PUNTEROS ===

	int numeros[] = {2, 4, 6, 8, 10};
//	int *dir_numeros = &numeros[0]; // Dir de memoria del primer elemento, ya que se almacenan de manera contigua
	int *dir_numeros = numeros; // Esto es lo mismo que lo anterior, la dir del primer elemento

	for(int i = 0; i < 5; i++){
		cout << "Posicion de memoria del elemento del vector[" << i << "]: " << dir_numeros;
		cout << ", elemento guardado: " << *dir_numeros << endl;
		dir_numeros++; // Aumenta el puntero 4 bytes más
		/*
		Un problema con esto es que se modifica el puntero, por lo que al final del for, el puntero estará apuntando
		4 bytes después del último elemento del array.
		SOLUCIÓN: *(dir_numeros + i)
		*/
	}


	/*
		=== ASIGNACIÓN DINAMICA DE ARREGLOS ===
		new: reserva el número de bytes solicitados por la declaración
		delete: libera un bloque de bytes reservado con anterioridad
	*/
	int numCalificaciones, *calificaciones;
	cout << "\nIngrese el numero de calificaciones que desee: "; cin >> numCalificaciones;
	calificaciones = new int[numCalificaciones]; // Creando el arreglo, y guardandolo en el puntero
	for(int i = 0; i < numCalificaciones; i++){
		calificaciones[i] = i*10; // también -> *(calificaciones + i) = i*10;
	}
	cout << "Mostrando las calificaciones guardadas en un puntero con NEW: " << endl;
	for(int i = 0; i < numCalificaciones; i++){
		cout << calificaciones[i] << " ";
	}
	delete[] calificaciones; // Liberando el espacio de memoria


	// === TRANSMISIÓN DE DIRECCIONES DE MEMORIA MEDIANTE PUNTEROS ===
	float num1 = 234.4, num2 = 34.2;
	cout << "\n\nPrimer numero: " << num1 << endl;
	cout << "Segundo numero: " << num2 << endl;
	intercambio(&num1, &num2); // Enviando las direcciones para que se guarden en los punteros de la funcion
	cout << "Nuevo valor de Primer numero: " << num1 << endl;
	cout << "Nuevo valor de Segundo numero: " << num2 << endl;


	// === TRANSMISIÓN DE ARRAYS MEDIANTE PUNTEROS ===
	int numbers[] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
	int sizeArr = 10;
	int maximo = hallarMaximo(numbers, sizeArr);
	cout << "\nPasando un array como puntero, el mayor elemento es el " << maximo << endl;


	// === MATRIZ DINÁMICA (PUNTERO DE PUNTEROS) ===
	int **punteroMatriz, filas = 3, columnas = 4;
	punteroMatriz = new int*[filas]; // Reservando espacio para un array de punteros
	for(int i = 0; i < filas; i++){
		*(punteroMatriz + i) = new int[columnas]; // Reservando memoria para las columnas (declaramos arrays en cada puntero)
	}
	cout<<"\nDigite elementos para matriz dinámica de 3*4: "<<endl;
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
			cin >> *(*(punteroMatriz + i)+j); // punteroMatriz[i][j]
		}
	}
	// Mostrando matriz
	for(int i = 0; i < filas; i++){
		for(int j = 0; j < columnas; j++){
			cout<<*(*(punteroMatriz + i)+j)<<" ";
		}
		cout<<endl;
	}
	// Liberando la memoria
	for(int i = 0; i < filas; i++){
		delete[] *(punteroMatriz + i);
	}
	delete[] punteroMatriz;


	// === PUNTEROS A STRUCTS ===
	punteroPersona->nombre = "Elias";
	punteroPersona->edad = 20;
	cout<<"\nDatos de un struct guardados con un puntero: "<<endl;
	cout << punteroPersona->nombre << endl;
	cout << punteroPersona->edad << endl;

	return 0;
}

void intercambio(float *dir_num1, float *dir_num2){
	float aux;

	aux = *dir_num1;
	*dir_num1 = *dir_num2;
	*dir_num2 = aux;
}

int hallarMaximo(int *dir_vector, int sizeArray){
	int max = 0;

	cout << "\nVector numbers:" << endl;
	for(int i = 0; i < sizeArray; i++){
		cout << *(dir_vector + i) << " ";
		// Se accede a la posicion de memoria, aumentando el puntero, ya que el array usa posiciones de memoria contiguas

		if(*(dir_vector + i) > max){
			max = *(dir_vector + i);
		}
	}

	return max;
}

