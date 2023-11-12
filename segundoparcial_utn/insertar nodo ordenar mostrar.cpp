

#include <stdio.h>
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sgte;
};

void OrdenarLista(Nodo* lista); // Declaration of OrdenarLista function

void RecorrerListaYordenar(Nodo* inicio) {
    Nodo* aux = inicio;
    OrdenarLista(aux);
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->sgte;
    }
}

void RecorrerLista(Nodo* inicio) {
    Nodo* aux = inicio;
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->sgte;
    }
}

void InsertarNodo(Nodo*& lista, int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->sgte = NULL;

    if (lista == NULL) {
        lista = nuevo_nodo;
    }
    else {
        Nodo* aux = lista;
        while (aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo_nodo;
    }

}

void OrdenarLista(Nodo* lista) {
    Nodo* aux;
    Nodo* siguiente;
    int t;

    aux = lista;
    while (aux->sgte != NULL) {
        siguiente = aux->sgte;
        while (siguiente != NULL) {
            if (aux->dato > siguiente->dato) {
                t = aux->dato;
                aux->dato = siguiente->dato;
                siguiente->dato = t;
            }
            siguiente = siguiente->sgte;
        }
        aux = aux->sgte;
    }
    //cout << "\n\n\tLista ordenada..." << endl;
}

void MostrarLista(Nodo* lista) {
    Nodo* aux = lista;
    while (aux != NULL) {
        cout << aux->dato << " | ";
        aux = aux->sgte;
    }
    cout << endl;

}

int main() {
    Nodo* lista = NULL;

    InsertarNodo(lista, 37);
    InsertarNodo(lista, 52);
    InsertarNodo(lista, 42);
    InsertarNodo(lista, 61);

    cout << "Lista desordenada:" << endl;
    MostrarLista(lista);

    RecorrerListaYordenar(lista);

    cout << "Lista ordenada:" << endl;
    MostrarLista(lista);

    return 0;
}
