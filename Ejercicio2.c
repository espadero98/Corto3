#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Nodo {
    int numero;
    struct Nodo *apuntador;
};

struct Nodo *puntero = NULL;

void imprimir() {
    struct Nodo *imprimiendo = puntero;
    printf("El numero invertido es: \n");
    while (imprimiendo != NULL) {
        printf("%i", imprimiendo->numero);
        imprimiendo = imprimiendo->apuntador;
    }
    printf("\n");
}

void insertar(int num) {
    struct Nodo *nuevo;
    nuevo = malloc(sizeof (struct Nodo));
    nuevo->numero = num;
    if (puntero!=NULL) {
        nuevo->apuntador = puntero;
        puntero = nuevo;
    }else{
       puntero = nuevo;
        nuevo->apuntador == NULL; 
    }
}

void main() {
    int numero;
    char * cadena = malloc(12 * sizeof (char));
    printf("Ingrese un número:\n");
    scanf("%d", &numero);
    sprintf(cadena, "%i", numero);
    for (int i = 0; cadena[i] != '\0'; i++) {
        int n = (cadena[i] - '0');
        insertar(n);
    }
    imprimir();
}
