//EDGARDO ERNESTO ESPADERO MIRANDA EM16006
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    int info;
    struct nodo *sig;
};
//Variable global apunta al primer nodo de la lista
struct nodo *raiz = NULL;

void insertar(int x) {
    struct nodo *nuevo;
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    if (raiz == NULL) {
        raiz = nuevo;
        nuevo->sig == NULL;
    } else {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

void imprimir() {
    struct nodo *reco = raiz;
    printf("Lista completa:\n");
    while (reco != NULL) {
        printf("%i ", reco->info);
        reco = reco->sig;
    }
    printf("\n");
}

int extraer() {
    if (raiz != NULL) {
        int informacion = raiz->info;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return informacion;
    } else {
        return -1;
    }
}

void liberar() {
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL) {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

void PilaVacia() {
    if (raiz == NULL) {
        printf("La pila está vacía\n");
    } else {
        printf("La pila no está vacía\n");
    }
}

int conteo(){
        struct nodo *reco=raiz;
        int contador=0;
        while (reco!=NULL) {
            contador=contador+1;
            reco=reco->sig;
        }
        return contador;
}

int main() {
    insertar(10);
    insertar(40);
    insertar(3);
    PilaVacia();
    imprimir();
    printf("La pila contiene %d nodos\n",conteo());
    printf("Extraemos de la pila el numero: %i\n", extraer());
    PilaVacia();
    imprimir();
    liberar();
    printf("La pila contiene %d nodos\n",conteo());
    return 0;
}