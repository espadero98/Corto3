//EDGARDO ERNESTO ESPADERO MIRANDA EM16006
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int datos;
    struct nodo *apuntador;
};

struct nodo *puntero = NULL;

void insertar(int num) {
    struct nodo *insert;
    insert = malloc(sizeof (struct nodo));
    insert->datos = num;  
    if (puntero!=NULL) {
        insert->apuntador = puntero;
        puntero = insert;
    }
    else{
        puntero = insert;
        insert->apuntador == NULL;
    }
}

void imprimir() {
    struct nodo *print = puntero;
    printf("Pila:\n");
    while (print != NULL) {
        printf("%i ", print->datos);
        print = print->apuntador;
    }
    printf("\n");
}

void cambiar(struct nodo *Mipila, int nuevo, int anterior) {
    if (Mipila != NULL) {
        if (Mipila->datos == anterior) {
            Mipila->datos = nuevo;
        } else {
            cambiar(Mipila->datos, nuevo, anterior);
        }
    } else {
        printf("No se encontro nada\n");
    }
}

int main() {
    insertar(10);
    insertar(38);
    insertar(21);
    imprimir();
    printf("Reemplazando elemento de la pila.\n");
    cambiar(puntero, 20, 10);
    imprimir();
    printf("Reemplazando elemento de la pila.\n");
    cambiar(puntero, 15, 30);
    imprimir();
    return 0;
}