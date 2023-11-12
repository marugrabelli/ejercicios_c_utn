
#include <stdio.h>
#include <iostream>
using namespace std;


 void unsubp(int x[], int tam){
     int i;
      for(int i=0;i<tam; i++){
     if ((x[i] >0 && i%2) || !x[i]){
     x[i]=1;
     }
      }
      return;
 }

int main()
{
   int u[6]={0,5,3};
    unsubp(u,6);
    for (int i=0;i<6;i++)
    cout <<u[i]<<";";


    return 0;
}







