// Métodos de ordenamiento

#include <iostream>
//#include <conio.h>

using namespace std;

// ORDENAMIENTOS DIRECTOS

void bubblesort(){
	int numeros[] = {4, 5, 2, 1, 3};
	int sizeArray = sizeof numeros / sizeof numeros[0];
	int aux, iteraciones = 0;
	bool cambios;
	
	cout<<"==== BURBUJA ===="<<endl;
	cout<<"DESORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	
	//METODO DE ORDENAMIENTO
	do{
		cambios = false;
		for(int i = 0; i < sizeArray - 1; i++){
			if(numeros[i] > numeros[i+1]){
				// si el actual es > al siguiente, cambio, flota hacia adelante, hasta terminar de verificar en el final del array
				aux = numeros[i];
				numeros[i] = numeros[i+1];
				numeros[i+1] = aux;
				cambios = true;
			}
		}
		iteraciones++;
	}while(cambios);
	
	cout<<"\nORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\nITERACIONES: "<<iteraciones<<"\n"<<endl;
}

void insercion(){
	int numeros[] = {4, 5, 2, 1, 3};
	int sizeArray = sizeof numeros / sizeof numeros[0];
	int aux, pos;
	
	cout<<"==== INSERCION ===="<<endl;
	cout<<"DESORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	
	//METODO DE ORDENAMIENTO
	for(int i = 1; i < sizeArray; i++){
		pos = i;
		
		while(pos > 0 && numeros[pos-1] > numeros[pos]){
			// si el de la izquierda es > al actual, cambio, y continuar evaluando hasta llegar al principio del array
			aux = numeros[pos];
			numeros[pos] = numeros[pos-1];
			numeros[pos-1] = aux;
			pos--;
		}
		
		// I: 4 5 2 1 3
		// II: 2 4 5 1 3
		// III: 1 2 4 5 3
		// IV: 1 2 3 4 5
	}
	
	cout<<"\nORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\n"<<endl;
}

void seleccion(){
	int numeros[] = {4, 5, 2, 1, 3};
	int sizeArray = sizeof numeros / sizeof numeros[0];
	int aux, min;
	
	cout<<"==== SELECCION ===="<<endl;
	cout<<"DESORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	
	//METODO DE ORDENAMIENTO
	for(int i = 0; i < sizeArray; i++){
		min = i;
		
		for(int j = i + 1; j < sizeArray; j++){
			if(numeros[j] < numeros[min]){
				// Verificando desde la posición actual+1 (i+1) hasta el final, cuál es el menor, el pos se guarda en min
				min = j;
			}
		}
		
		// Haciendo el cambio siempre, ya que en min siempre estará el pos del menor valor
		aux = numeros[i];
		numeros[i] = numeros[min];
		numeros[min] = aux;
	}
	
	cout<<"\nORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\n"<<endl;	
}

// ORDENAMIENTOS INDIRECTOS

void ordenacionShell(){
	int numeros[] = {4, 6, 5, 0, 2, 1, 3};
	int sizeArray = sizeof numeros / sizeof numeros[0], iteraciones = 0;
	
	cout<<"==== ORDENACION SHELL ===="<<endl;
	cout<<"DESORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	
	//METODO DE ORDENAMIENTO
	int aux, j, salto = sizeArray/2;
	bool cambios;
	
	while(salto > 0){ 
		cambios = false;
		
		for(int i = 0; i < sizeArray - salto; i++){
			j = i + salto;
			if(numeros[i] > numeros[j]){
				// Par desordenado, se hace el intercambio
				aux = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = aux;
				cambios = true;
			}
		}
		
		if(!cambios){
			// Si no hay cambios, los pares están ordenados en su salto correspondiente, se pasa a reducir el salto
			salto = salto / 2;
		}
		iteraciones++;	
	}
	
	cout<<"\nORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\nITERACIONES: "<<iteraciones<<"\n"<<endl;
}

// Metodos para quicksort

void intercambio(int &x, int &y){
	int aux = x;
	x = y;
	y = aux;
}

void quicksortRecursivo(int arreglo[], int primero, int ultimo, int &llamadas){
	int size = ultimo - primero + 1, iteraciones = 0;
	cout<<"\nOrdenando la lista con "<<size<<" elementos...";
	cout<<"\nDesordenada: ";
	for(int k = primero; k <= ultimo; k++){
		cout<<arreglo[k]<<" ";
	}
	
	int i, j, posCentral, pivote;
	llamadas++;
	
	posCentral = (primero + ultimo)/2;
	pivote = arreglo[posCentral];
	i = primero;
	j = ultimo;
	cout<<"- Pivote: "<<pivote;
	
	do{
		// los whiles se detienen en la pos del desordenado, o bien, en el pivote, cuando todo está ordenado
		while(arreglo[i] < pivote) i++; // los de la izquierda del pivote deben ser menor al pivote
		while(arreglo[j] > pivote) j--; // los de la derecha deben ser mayores al pivote
		
		if(i <= j){
			// Con el if, se controla que no se hayan cruzado los indices, si esto pasa, es porque están ordenados los lados
			intercambio(arreglo[i], arreglo[j]);
			i++;
			j--;
		}
		iteraciones++;
	}while(i<=j);
	
	cout<<" - Ordenada: ";
	for(int k = primero; k <= ultimo; k++){
		cout<<arreglo[k]<<" ";
	}
	cout<<"- i: "<<i<<" - j: "<<j<<" - Iteraciones: "<<iteraciones;
	
	if(primero < j){
		int size = j - primero + 1;
		cout<<"\nMandando la sublista izquierda con "<<size<<" elementos...";
		quicksortRecursivo(arreglo, primero, j, llamadas);
	}
	if(ultimo > i){
		int size = ultimo - i + 1;
		cout<<"\nMandando la sublista derecha con "<<size<<" elementos...";
		quicksortRecursivo(arreglo, i, ultimo, llamadas);
	}
}

void quicksort(){
	int numeros[] = {4, 6, 5, 0, 2, 1, 3, 6, 2};
	int sizeArray = sizeof numeros / sizeof numeros[0];
	
	cout<<"==== ORDENACION RAPIDA (QUICKSORT) ===="<<endl;
	cout<<"DESORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\n";
	
	//METODO DE ORDENAMIENTO
	int llamadas = 0;
	quicksortRecursivo(numeros, 0, sizeArray - 1, llamadas);
	
	cout<<"\n\nORDENADO:"<<endl;
	for(int i = 0; i < sizeArray; i++){
		cout<<numeros[i]<<" ";
	}
	cout<<"\nLLAMADAS AL METODO RECURSIVO: "<<llamadas<<endl;	
}


int main(){
	cout<<"METODOS DIRECTOS:\n"<<endl;
	bubblesort();
	insercion();
	seleccion();
	
	cout<<"METODOS INDIRECTOS:\n"<<endl;
	ordenacionShell();
	quicksort();
	
	//getch();
	return 0;
}
