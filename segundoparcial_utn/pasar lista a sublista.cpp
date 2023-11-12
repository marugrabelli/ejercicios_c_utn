/* EJERCICIO 5 */
#include <stdio.h> //Se agrega para poder usar archivos
#include <iostream>
#include <conio.h>
#include <cstring>
using namespace std;



#include <iostream>

using namespace std;

struct Materia
{
    int folio;
    int libro;
    int nota;
    int nroDeLegajo;
    char nombreDeLaMateria[50];
    char fechaDeAprobacion[11];
};

struct Nodo
{
    int info;
    Nodo *ant;
    Nodo *siguiente;
};

struct NodoSub
{
    Materia info;
    NodoSub* siguiente;
};

struct Alumno
{
    int nroDeLegajo;
    int codigoCarrera;
    char documento[10];
    char nombre[50];
    char apellido[50];
    NodoSub* listaDeMaterias;
};

struct Nodo
{
    Alumno info;
    Nodo* siguiente;
};

void leerArchivoDeAlumnos(Nodo*& listaDeAlumnos, FILE* archivoDeAlumnos);
void leerArchivoDeMaterias(Nodo*& listaDeAlumnos, FILE* archivoDeMaterias);
void insertarEnLista(Nodo*& listaDeAlumnos, Alumno dato);
void insertarAlPrincipio(Nodo*& listaDeAlumnos, Alumno dato);
void mostrarLista(Nodo* listaDeAlumnos);
void insertarMateriaEnLista(NodoSub*& listaDeMaterias, MateriaActual dato);
void mostrarListaConSubLista(Nodo* listaDeAlumnos);
Nodo* buscarAlumnoPorNroDeLegajo(Nodo* listaDeAlumnos, int nroDeLegajo);

int main()
{
    FILE* archivoDeAlumnos = fopen("Alumnos.dat", "rb");
    FILE* archivoDeMaterias = fopen("Materias.dat", "rb");

    if(archivoDeAlumnos == NULL)
    {
        cout << "ERROR!";

        return 1;
    }
else
    {
        Nodo* listaDeAlumnos = NULL;

        leerArchivoDeAlumnos(archivoDeAlumnos, listaDeAlumnos);
        leerArchivoDeMaterias(archivoDeMaterias, listaDeAlumnos);
        mostrarLista(listaDeAlumnos);
        mostrarListaConSubLista(listaDeAlumnos);
    }

    return 0;
}

void leerArchivoDeAlumnos(Nodo*& listaDeAlumnos, FILE* archivoDeAlumnos)
{
    Alumno alumnoActual;

    fread(&alumnoActual, sizeof(Alumno), 1, archivoDeAlumnos);

    while(!feof(archivoDeAlumnos))
    {
        insertarEnLista(listaDeAlumnos, alumnoActual);
        fread(&alumnoActual, sizeof(Alumno), 1, archivoDeAlumnos);
    }
}

void leerArchivoDeMaterias(Nodo*& listaDeAlumnos, FILE* archivoDeMaterias)
{
    Nodo *aux;
    Materia materiaActual;

    fread(&materiaActual, sizeof(Materia), 1, archivoDeMaterias);

    while(!feof(archivoDeMaterias))
    {
        aux = buscarAlumnoPorNroDeLegajo(listaDeAlumnos, materiaActual.nroDeLegajo);

        if(aux != NULL)
            insertarMateriaEnLista(aux->info.listaDeMaterias, materiaActual);

        fread(&materiaActual, sizeof(Materia), 1, archivoDeMaterias);
    }
}

void insertarEnLista(Nodo*& listaDeAlumnos, Alumno dato)
{
    Nodo *nuevo, *antecesor, *aux;
    nuevo = new Nodo;
    nuevo->info = dato;
    aux = listaDeAlumnos;

    while(aux != NULL && aux->info.nroDeLegajo < dato.nroDeLegajo)
    {
        antecesor = aux;
        aux = aux->siguiente;
    }

    nuevo->siguiente = aux;

    if(aux != listaDeAlumnos)
        antecesor->siguiente = nuevo;
    else
        lista = nuevo;
}

void insertarAlPrincipio(Nodo*& listaDeAlumnos, Alumno dato)
{

Nodo *nuevo = new Nodo;
    nuevo->info = dato;
    nuevo->siguiente = listaDeAlumnos;
    listaDeAlumnos = nuevo;
}

void mostrarLista(Nodo* listaDeAlumnos)
{
    Nodo *aux = listaDeAlumnos;

    while(aux != NULL)
    {
        cout << "Nro de legajo: " << aux->info.nroDeLegajo << endl;
        cout << "Documento: " << aux->info.documento << endl;
        cout << "-----------------------------------" << endl;

        aux = aux->siguiente;
    }
}

void insertarMateriaEnLista(NodoSub*& listaDeMaterias, MateriaActual dato)
{
    NodoSub *nuevo = new NodoSub;
    nuevo->info = dato;
    nuevo->siguiente = listaDeMaterias;
    listaDeMaterias = nuevo;
}

void mostrarListaConSubLista(Nodo* listaDeAlumnos)
{
    Nodo *aux = listaDeAlumnos;
    NodoSub *auxSub;

    while(aux != NULL)

{
        cout << "Nro de legajo: " << aux->info.nroDeLegajo << endl;
        cout << "Documento: " << aux->info.documento << endl;
        cout << "-----------------------------------" << endl;

        auxSub = aux->info.listaDeMaterias;

        cout << "Listado de materias aprobada por el alumno: " << endl;

        while(auxSub != NULL)
        {
            cout << "Nombre de materia: " << auxSub->info.nombreDeLaMateria << endl;
            cout << "Nota de la materia: " << auxSub->info.nota << endl;

            auxSub = auxSub->siguiente;
        }

        cout << "-------------------------------" << endl;

        aux = aux->siguiente;
    }
}

Nodo* buscarAlumnoPorNroDeLegajo(Nodo* listaDeAlumnos, int nroDeLegajo)
{
    Nodo *aux = listaDeAlumnos;

    while(aux != NULL && aux->info.nroDeLegajo < nroDeLegajo)
        aux = aux->siguiente;

    if(aux->info.nroDeLegajo == nroDeLegajo)
        return aux;

    return NULL;
}
