/******************************************************************************
: Escribe un programa que pida cinco enteros al usuario y los almacene en una matriz. Calcula si la suma de los números almacenados es par o impar.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
    int m[5];
    int i, suma=0;

    for(int i=0; i<5; i++) {
        cout << "Escribe numeros " << i+1 << endl;
        cin >>  m[i];
    }

    for(int i=0; i<5; i++) {
        suma += m[i];
    }

    if (suma % 2 == 0) {
        cout << "La suma es par" << endl;
    }
    else {
        cout << "La suma es impar" << endl;
    }

    return 0;
}
