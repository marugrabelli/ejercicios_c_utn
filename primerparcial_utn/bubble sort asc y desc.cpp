#include <iostream>
using namespace std;

void ordernarVectorDesc(int tam, int vec[]){
    for(int i=0;i<tam-1;i++) {
        for (int j=0;j<tam-i-1;j++)  {
            if(vec[j]<vec[j+1]){
                int aux= vec[j];
                vec[j]=vec[j+1];
                vec[j+1]=aux;
            }
        }
    }
    cout << "Vector ordenado de forma descendente: ";
    for(int i=0;i<tam;i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void ordernarVectorAsc(int tam, int vec[]){
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vec[j] > vec[j+1]) {
                int aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
            }
        }
    }
    cout << "Vector ordenado de forma ascendente: ";
    for(int i=0;i<tam;i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

bool funcion_uno(int v1[],int v2[], int i, int tam){
    if(i<tam && (i%2|| v2[i]<v1[i])){
        v2[i]=v1[i];
        return true;
    }
    return false;
}

int main(){
    int tam=5;
    int vec[tam] = {5,8,7,9,3 };

    cout << "Vector original: ";
    for(int i = 0; i < tam; i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    ordernarVectorDesc(tam, vec);
    ordernarVectorAsc(tam, vec);

    int vec1[10]={32,41,50,42,33,87,91,64,39,11};
    int vec2[10]= {9,8,7,6,5,4,3,2,1,0};

    if (!funcion_uno(vec1, vec2, 3, 45)){
        cout <<"No hubo cambio"<<endl;
    }
    else {
        cout <<"Hubo cambio"<<endl;
    }

    return 0;
}

