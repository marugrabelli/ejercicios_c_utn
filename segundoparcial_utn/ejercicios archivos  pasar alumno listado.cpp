

#include <iostream>
using namespace std;

void leerArchivo(FILE* archivo, Nodo*& listaDeAlumnos)
{
    Alumno alumnoActual;

    fread(&alumnoActual, sizeof(Alumno), 1, archivo);

    while(!feof(archivo))
    {
        insertarEnLista(listaDeAlumnos, alumnoActual);
        fread(&alumnoActual, sizeof(Alumno), 1, archivo);
    }
}
