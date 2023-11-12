
#include <iostream>

using namespace std;

int main()
{
    int numeros [10][10], filas, columnas;
    //definir dimensiones de tabla por usuario
    cout<<"ingrese numero de columnas"<<endl;
    cin>>columnas;
    cout<<"ingrese numero de filas"<<endl;
    cin>>filas;

    //almacenar valores de la tabla por usuario
    for(int i=0;i<filas;i++) {
        for(int j=0;j <columnas;j++) {
            cout <<"ingrese numero ["<<i<<"]"<<"["<<j<<"]"<<endl;
            cin >>numeros[i][j];
        }
    }


   // mostrar la tabla por for
    for(int i=0; i<filas; i++) {
        for(int j=0; j<columnas; j++) {
            cout << numeros[i][j] << "\t";
    }
    cout << endl;
}


    return 0;
}
