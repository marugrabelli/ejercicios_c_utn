
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

int *OrdenarAscendentemente(int *p, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(p + j) < *(p + i)) {
                int aux = *(p + j);
                *(p + j) = *(p + i);
                *(p + i) = aux;
            }
        }
    }
    return p;
}

int main() {
    int largo, i, p;

    cout << "Ingrese el tamaño del vector:" << endl;
    cin >> largo;
    int *n = new int[largo];

    for (int i = 0; i < largo; i++) {
        cout << "Ingrese el número " << i << ":" << endl;
        cin >> *(n + i);
    }

    OrdenarAscendentemente(n, largo);
    for (int i = 0; i < largo; i++) {
        cout << "Números ordenados: " << *(n + i) << endl;
    }

    delete[] n;

    return 0;
}
