
#include <iostream>
using namespace std;


struct Ataque
{
    int tipo; // 0 - Tanque, 1 - Tropas, 2 - Caza, 3 - Bombardero, 4 - Destructor, 5 - Acorazado, 6 - Submarino
    int intensidad;
    int resistencia;
    int IDAtacante;
    float minutoJuego;
};

struct ZonaTerreno
{
    int tipoTerreno; // 0 - Mara, 1 - Tierra
    int IDZona;
};

// a) Diseñe el struct NodoZonaTerreno e inicialice la lista vacia.
//    Declare, además todas las estructuras que considere necesarias para tal fin (particularmente de las sublitas)

struct NodoDeAtaque // Sublitas SE -> Simple enlazada
{
    Ataque info;
    NodoDeAtaque* siguiente;
};

struct NodoZonaTerreno // Lista DE -> Doblemente enlazada
{
    ZonaTerreno info;
    NodoZonaTerreno* anterior;
    NodoZonaTerreno* siguiente;
    NodoDeAtaque* listaDeAtaques = NULL;
};

NodoZonaTerreno* listaDeZonaTerreno = NULL; // Declaracion de la lista!

// b) Realice una funcion buscarZonaTerreno que reciba la lista principal,
//    un IDZona y devuelve un puntero a el nodo con el IDZona correspondiente o null en caso de no encontrarlo

NodoZonaTerreno* buscarZonaTerreno(NodoZonaTerreno* listaZonaTerreno, int IDZona)
{
    NodoZonaTerreno* aux = listaZonaTerreno;

    while(aux != NULL && aux->info.IDZona != IDZona)
        aux = aux->siguiente;

    if(aux != NULL)
        return aux;

    return NULL;
}

// c) Realice un subprograma que cargue de un archivo los ataques en una zona determinada por orden de minutojuego.
//    El subprograma debe recibir como parámetros la ruta y nombre de un archivo de ataques y un entero IDZona que indica la
//    zona en donde se quieren cargar los ataques. Se debe agregar todos los ataques que se encuentren en el archivo en
//    la sublista del nodo con IDzona correspondiente de manera ordenada por minuto ascendente.

void cargarArchivoDeAtaques(NodoZonaTerreno*& listaZonaTerreno, char ruta[], char nombre[], int IDZona)
{
    NodoZonaTerreno *aux;
    FILE* archivoDeAtaques;

    strcat(ruta, nombre);

    archivoDeAtaques = fopen(ruta, "rb");

    if(archivoDeAtaques == NULL)
        cout << "ERROR!" << endl;
    else
    {
        aux = buscarZonaTerreno(listaZonaTerreno, IDZona);

        if(aux != NULL)
        {
            Ataque registroActual;

            fread(&registroActual, sizeof(Ataque), 1, archivoDeAtaques);

            while(!feof(archivoDeAtaques))
            {
                insertarEnSublista(aux->listaDeAtaques, registroActual);
                fread(&registroActual, sizeof(Ataque), 1, archivoDeAtaques);
            }
        }
    }
}

void insertarEnSublista(NodoDeAtaque*& listaDeAtaques, Ataque dato)
{
    NodoDeAtaque *nuevo, *antecesor, *aux;
    nuevo = new NodoDeAtaque;
    nuevo->info = dato;
    aux = listaDeAtaques;

    while(aux != NULL && aux->info.minutoJuego < dato.minutoJuego)
    {
        antecesor = aux;
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux;

    if(aux != listaDeAtaques)
        antecesor->siguiente = nuevo;
    else
        listaDeAtaques = nuevo;
}

// d) Implemente una funcion "lanzarAtaque" que reciba la lista principal y un IDZona
//    y que quite de la sublista correspondiente el próximo ataque. El ataque lo debe
//    devolver a través del return. Si la sublista del nodoZonaTerreno en cuestión llegaraa estar vacia,
//    puede devolver un ataque con el tipo = -1. Debe cumplir: Ataque lanzarAtaque(nodoZonaTerreno*& p, int IDZona)

Ataque lanzarAtaque(NodoZonaTerreno*& p, int IDZona)
{
    Ataque ataqueAMandar;
    NodoZonaTerreno *aux = buscarZonaTerreno(p, IDZona);

    if(aux != NULL)
        desencolarAtaque(aux, ataqueAMandar);

    return ataqueAMandar;
}

void desencolarAtaque(NodoZonaTerreno*& zonaTerreno, Ataque& dato)
{
    if(aux.sublista == NULL)
        dato.tipo = -1;
    else
    {
        NodoDeAtaque *aux = zonaTerreno.sublista;
        dato = aux->info;
        zonaTerreno.sublista = aux->siguiente;

        delete aux;
    }
}
