
#include <iostream>



using namespace std;
void func ( int v[], int tam) {
    *v=10;
}
//Se asigna el valor de la suma del segundo elemento del arreglo "p" y "x" al tercer elemento del arreglo "p"
int main()
{
    int *p=NULL;
    int x=30;
    p =new int[3];
    p[1]=x;

    func(p,3);
    p[2]=*(p+1)+x;

    for(int i=0;i<3;i++)
    cout <<*(p+1)<<"";
    delete []p;
    return 0;
}

