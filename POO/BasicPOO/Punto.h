#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
    private:
        int x, y;
        /* VARIABLES STATIC */
        /* Pertenecen a la clase, por lo que su valor es "global", para todos los objetos que se creen */
        /* Se deben inicializar en el archivo implementación (Punto.cpp) */
        static int contadorPuntos;

    // PROTECTED: acceso por la clase, y por las clases hijas

    public:
        /* SOBRECARGA DE FUNCIONES MIEMBRO */
        // Varias funciones con el mismo nombre, pero distintos parámetros
        Punto(){
            /* CONSTRUCTOR POR DEFECTO (Sin parámetros) */
            /* - Necesario si se desea trabajar con arreglos dinámicos de objetos (Punto* puntos = new Punto[5];) */
            /* - Puede ir vacío o inicializando atributos */
            /* - Debe incluirse si ya existe otro constructor en la clase y se quieren usar arreglos dinámicos */

            contadorPuntos++; // Al ser STATIC, aumentará cada vez que se cree un nuevo objeto Punto
        }
        Punto(int x, int y){
            this->x = x;
            this->y = y;
        }

        ~Punto(){
            /* DESTRUCTOR */
        }

        // La definición de métodos se realiza en el archivo Punto.cpp

        void setX(int valorX);

        void setY(int valorY);

        int getX();

        int getY();

        void mostrarCoordenadas();

        int getStaticContador();

        /* FUNCIONES STATIC */
        /* Son funciones propias de la clase, por lo que no hace falta instanciar algún objeto para acceder a ellas */
        static int sumaStatic(int n1, int n2);
};

#endif // PUNTO_H
