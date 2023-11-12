
#include <iostream>
#include <iostream>

using namespace std;

struct Nodo {
    int info; Nodo*sgte;
};

int main()
{
    Nodo *p=NULL; Nodo*aux;
    p= new Nodo;
    p -> info=1; p->sgte=new Nodo;
    p -> sgte ->info=2; p ->sgte->sgte= new Nodo;
    p->sgte ->sgte->info=3; p->sgte ->sgte ->sgte =NULL;
    aux=p;
    p= p->sgte;
    p->sgte->sgte=aux;
    aux ->sgte=NULL;
    aux =p;

    while (aux)  {
        cout <<aux->info<<";";
        aux = aux ->sgte;
    }

    return 0;
}
