#include <iostream>
#include "Punto.h" // importando la clase Punto para void claseSimplePunto()
#include "Estudiante.h" // solo hace falta importar la clase compuesta, no las clases que la componen (Curso en este caso)

using namespace std;

void claseSimplePunto();
void claseCompuestaEstudiante();

int main()
{
    claseSimplePunto();
    claseCompuestaEstudiante();

    return 0;
}

void claseSimplePunto(){
    Punto p1(1, 2); // objeto estático (se accede con el punto a sus métodos)
    cout << "X de p1: " << p1.getX() << endl;
    cout << "Y de p1: " << p1.getY() << endl;

    Punto* p2 = new Punto(); // objeto dinámico (se accede con la flecha a sus métodos), Punto() <- Constructor
    p2->setX(5);
    p2->setY(8);
    cout << "X de p2: " << p2->getX() << endl;
    cout << "Y de p2: " << p2->getY() << "\n\n";
    delete p2; // para eliminar el objeto dinámico, los estáticos los elimina el programa??

    /* ARREGLO DE OBJETOS ESTÁTICOS */
    /* Se accede a los objetos como un arreglo normal */
    // Punto puntos1[4];

    /* ARREGLO DE OBJETOS DINÁMICOS */
    /* Utiliza el constructor por defecto para los objetos */
    /* Punto() */
    Punto* puntos2 = new Punto[4];
    for(int i = 0; i < 4; i++){
        (puntos2 + i)->mostrarCoordenadas();
        cout<<"\n";
    }
    delete[] puntos2; // Destruyendo los objetos dinámicos guardados en el arreglo

    // Accediendo a variables static (globales para todos los objetos)
    cout << "Los objetos Punto que fueron creados con el constructor por default fueron: " << p1.getStaticContador() << "\n";
    cout << "(Esto debido a que es en este constructor en donde se modificó el contador)\n";

    // Accediendo a funciones static (que pertenecen a la clase)
    cout << "La suma de 5+5 es: " << Punto::sumaStatic(5, 5) << "\n\n";
}

void claseCompuestaEstudiante(){
    Estudiante e1("Elias Vasquez", 201900131, "Archivos", 5);
    e1.printDatos();
}
