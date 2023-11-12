
#include <stdio.h>
#include <iostream>
using namespace std;

void carga ( int v[], int tam) {
    for (int i =0; i <tam; i++) {
        if (!v[i]&& i <=7) {
            v[i]+=5;
        }
    }
}

int main()
{
   int v1[10]={21,22,23,24,25};
   carga(v1,10);
    for (int i=0;i <10;i++){
        cout <<"el vector tiene los numeros: " <<i <<endl;
    }



    return 0;
}







