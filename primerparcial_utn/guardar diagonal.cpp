/******************************************************************************
 *
 * Escriba en C++ un procedimiento que reciba:
- Un vector.
- Una matriz cuadrada donde cada dimensión tiene el mismo
tamaño del vector.
- El tamaño del vector.
El procedimiento debe guardar en el vector los valores de la
diagonal de la matriz. Puede utilizar constantes predefinidas
fuera del subprograma

*******************************************************************************/
#include <iostream>
using namespace std;

const int MAX = 100; // Constante para el tamaño máximo del vector y la matriz

void guardar_diagonal(int vector[], int matriz[][MAX], int tam)
{
    for(int i = 0; i < tam; i++) { // Recorre cada elemento de la diagonal de la matriz
        vector[i] = matriz[i][i]; // Copia el valor del elemento en la diagonal al vector
    }
}

