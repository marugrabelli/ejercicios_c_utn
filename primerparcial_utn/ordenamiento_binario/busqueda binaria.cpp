/******************************************************************************
diseñar un algoritmo recursivo, que permita invertir el contenido de un
vector. Como indica el ejemplo:
Vector original: 28 35 12 43 56 77
Vector invertido: 77 56 43 12 35 28
El algoritmo no podrá usar un vector auxiliar

*******************************************************************************/




#include <iostream>
#include <conio.h>
using namespace std;

void invertir(int tam, int n[], int i) {
    if (i < tam/2) {
        int aux = n[i];
        n[i] = n[tam-i-1];
        n[tam-i-1] = aux;
        invertir(tam, n, i+1);
    }
    return;
}

int main() {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    invertir(11, v, 0);

    cout << "Vector invertido: ";
    for (int i = 0; i < 11; i++) {
         cout << "v[" << i << "]= " << v[i] << endl;
    }
    cout << endl;

    getch();
    return 0;
}

