#include <stdio.h>
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* sgte;
};

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

void IntercambiarNodos(Nodo*& lista) {
    if (lista == NULL || lista->sgte == NULL) {
        // No hay suficientes nodos para intercambiar
        return;
    }

    Nodo* aux = lista;
    lista = lista->sgte;
    aux->sgte = lista->sgte;
    lista->sgte = aux;

    cout << "Intercambio de nodos realizado" << endl;
}





void RecorrerLista(Nodo* inicio) {
    Nodo* aux = inicio;
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->sgte;
    }
    cout << "recorre" << endl;
}

void RecorrerListaYordenar(Nodo* inicio) {
    Nodo* aux = inicio;
    IntercambiarNodos(aux);
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->sgte;
    }
    cout << "recorre y ordena:" << endl;
}



void MostrarLista(Nodo* lista) {
    Nodo* aux = lista;
    while (aux != NULL) {
        //IntercambiarNodos(lista);
        cout << aux->dato << " | ";
        aux = aux->sgte;
    }
    cout << endl;
    cout << "muestra lsta:" << endl;
}

int main() {
    Nodo* lista = NULL;

    InsertarNodo(lista, 37);
    InsertarNodo(lista, 52);
    InsertarNodo(lista, 42);
    InsertarNodo(lista, 61);

    cout << "Lista desordenada:" << endl;
    MostrarLista(lista);

    cout << "Lista ordenada:" << endl;
    //RecorrerListaYordenar(lista);
    MostrarLista(lista);

    return 0;
}

