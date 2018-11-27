//EDGARDO ERNESTO ESPADERO MIRANDA EM16006
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    /**
     Informacion que posee el nodo
     */
    int dato;
    /**
     Puntero de el nodo que apunta hacia la base de la pila
     */
    struct Nodo *direccion;
};
/**
 * Variable global apunta al primer nodo de la lista
 */
struct Nodo *puntero = NULL;

/**
 * Este Metodo agregara un nuevo elemento a la pila
 * Recibe como parametro un entero.
 */
void insertar(int num) {
    /**Se crea un nuevo puntero de tipo Nodo el cual servira para apuntar hacia abajo de la pila*/
    struct Nodo *nuevo;
    /**le asigna el numero especifico de bytes a nuevo*/
    nuevo = malloc(sizeof (struct Nodo));
    /**Ingresa el entero en el dato del nodo*/
    nuevo->dato = num;
    if (puntero == NULL) {
        puntero = nuevo;
        nuevo->direccion == NULL;
    } else {
        nuevo->direccion = puntero;
        puntero = nuevo;
    }
}

/**
 * Este metodo imprimira los valores dentro de la pila
 * No recibe parametros
 */
void imprimir() {
    /**Se crea un puntero de tipo Nodo el cual apunta hacia el puntero*/
    struct Nodo *imprimiendo = puntero;
    printf("Lista completa:\n");
    /**Mientras la condicion de este bucle la cual es que imprimiendo sea diferente de null ya que cuando el puntero apunte a NULL significara que esta en el ultimo dato de la pila por lo tanto es el ultimo valor a imprimir*/
    while (imprimiendo != NULL) {
        /**Imprimira el dato alojada en el nodo actual*/
        printf("%d ", imprimiendo->dato);
        /**El puntero ahora estara apuntando a el siguiente nodo todo esto hasta que el puntero apunte hacia NULL*/
        imprimiendo = imprimiendo->direccion;
    }
    printf("\n");
}

/**
 * Metodo encargado de extraer valores de la pila el cual comenzara con el ultimo nos en entrar hasta el primer nodo que entro
 *  
 */
int extraer() {
    if (puntero != NULL) {
        /**Entero que almacenara el valor del nodo con el que se este trabajando*/
        int miDato = puntero->dato;
        /**Puntero de tipo Nodo que apuntara hacia el valor de puntero que indica la posicion baja de la pila*/
        struct Nodo *extract = puntero;
        /**En este punto es que el puntero va bajando indicando que nodo se trabaja*/
        puntero = puntero->direccion;
        free(extract);
        return miDato;
    } else {
        return -1;
    }
}

/**
 * Metodo encargado de liberar la memoria
 */
void liberar() {
    struct Nodo *reco = puntero;
    struct Nodo *bor;
    while (reco != NULL) {
        bor = reco;
        reco = reco->direccion;
        free(bor);
    }
}

/**
 * Metodo encargado de verificar si una pila esta vacia o no
 */
void PilaVacia() {
    /**Evalua si el puntero apunta a NULL*/
    if (puntero == NULL) {
        printf("La pila está vacía\n");
    } else {
        printf("La pila no está vacía\n");
    }
}

/**
 * Metodo encargado de contar cuantos nodos hay en la pila
 */
int conteo() {
    /**Puntero de tipo nodo que indicara que nodo se utilizara*/
    struct Nodo *cont = puntero;
    int contador = 0;
    /**Mientras la condicion del bucle no se cumpla el contador acumulara el numero de nodos*/
    while (cont != NULL) {
        contador = contador + 1;
        cont = cont->direccion;
    }
    return contador;
}

int main() {
    insertar(10);
    insertar(40);
    insertar(3);
    PilaVacia();
    imprimir();
    printf("La pila contiene %d nodos\n", conteo());
    printf("Extraemos de la pila el numero: %i\n", extraer());
    PilaVacia();
    imprimir();
    liberar();
    printf("La pila contiene %d nodos\n", conteo());
    return 0;
}
