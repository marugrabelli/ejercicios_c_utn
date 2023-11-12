
#include <iostream>
#include <conio.h>

using namespace std;
//. sando un puntero, escriba un programa que encuentre el máximo de un conjunto de
//enteros que ingresa el usuario. El usuario ingresa al principio el tamaño de la muestra.


int *findMax(int data[], int n) {

    int *max = data;
    int i;

    for (i=1;i <n;i++) {
        if (*max < *(max+i)) {
            *max= *(max+i);
        }
      return max;
    }
}


int main()
{
 int n, i, *u;

 int *p= new int [n];

 cout <<"ingrese largo del array"<<endl;
 cin >>n;

 for (i =0;i <n;i++) {
    cout <<p[i]<<endl;
}


u= findMax(p,n);

 cout <<"resultado"<<*u<<endl;

getch();
    return 0;
}
