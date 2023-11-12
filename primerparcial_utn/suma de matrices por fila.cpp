
#include <iostream>

using namespace std;

int main()
{
    int m[3][3];
    int i, c, sumafila=0;
    int mayorfila=0, nfila=0;

    for (i=0; i<3; i++) {
        for (c=0; c<3; c++) {
            cout << "Escribe numeros aleatorios: [" << i << "][" << c << "]" << endl;
            cin >> m[i][c];
        }
        cout <<"fila completada "<<i+1<<endl;
    }

    for (i=0; i<3; i++) {
        sumafila=0;
        for (c=0; c<3; c++) {
            sumafila += m[i][c];
        }

        if (sumafila > mayorfila) {
            mayorfila = sumafila;
            nfila = i+1;
        }
    }

    printf ("\n-----------\n");
    printf ("La fila con suma mayor es: %i con resultado %i\n", nfila, mayorfila);
    return 0;
}
