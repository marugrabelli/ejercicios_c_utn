#include <iostream>
#include <stdio.h>

using namespace std;

void apareoinvertido(char namefile1[], char namefile2[], char namefileout[])
{
    FILE *f1,*f2,*output;
    int cant_elementos_1;
    int cant_elementos_2;
    f1 = fopen(namefile1,"rb");
    f2 = fopen(namefile2,"rb");
    output = fopen(namefileout,"wb");
    int x1,x2;
    fseek(f1, 0, SEEK_END);
    fseek(f2, 0, SEEK_END);
    cant_elementos_1 = ftell(f1)/sizeof(int);
    cant_elementos_2 = ftell(f2)/sizeof(int);
    fseek(f1, (-1) * sizeof(int), SEEK_END);
    fseek(f2, (-1) * sizeof(int), SEEK_END);
    while(cant_elementos_1 && cant_elementos_2)
    {

        fread(&x1,sizeof(int),1,f1);
        fread(&x2,sizeof(int),1,f2);
        if (x1 > x2)
        {
            fwrite(&x1,sizeof(int),1,output);
            fseek(f2,(-1)*sizeof(int),SEEK_CUR);
            fseek(f1,(-2)*sizeof(int),SEEK_CUR);
            cant_elementos_1--;
        }
        else
        {
            fwrite(&x2,sizeof(int),1,output);
            fseek(f1,(-1)*sizeof(int),SEEK_CUR);
            fseek(f2,(-2)*sizeof(int),SEEK_CUR);
            cant_elementos_2--;
        }
    }
    if (cant_elementos_1)
    {
        fwrite(&x1,sizeof(int),1,output);
        cant_elementos_1--;
        fseek(f1,(-1)*sizeof(int),SEEK_CUR);
        while (cant_elementos_1)
        {
            fread(&x1,sizeof(int),1,f1);
            fwrite(&x1,sizeof(int),1,output);
            cant_elementos_1--;
            fseek(f1,(-2)*sizeof(int),SEEK_CUR);
        }
    }
    if (cant_elementos_2)
    {
        fwrite(&x2,sizeof(int),1,output);
        cant_elementos_2--;
        fseek(f2,(-1)*sizeof(int),SEEK_CUR);
        while (cant_elementos_2)
        {
            fread(&x2,sizeof(int),1,f2);
            fwrite(&x2,sizeof(int),1,output);
            cant_elementos_2--;
            fseek(f2,(-2)*sizeof(int),SEEK_CUR);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(output);
    return;
}

int main()
{
    FILE *f1;
    FILE *f2;
    int x1,x2;
    /* Creamos datros de prueba en el archivo */
    f1 = fopen("arch1.data","wb");
    int v[] = {-5, -3,1,2,4,5,20,31};
    fwrite(v, sizeof(int),8,f1);
    fclose(f1);
    f2 = fopen("arch2.data","wb");
    int w[] = {3,7,12};
    fwrite(w, sizeof(int),3,f2);
    fclose(f2);
    /* Comienza el algoritmo */
    FILE *output;
    apareoinvertido("arch1.data","arch2.data","output.data");
    /*corroboramos */
    f1= fopen("output.data","rb");
    while (fread(&x1,sizeof(int),1,f1))
    {
        cout << x1 << endl;
    }
    return 0;
}
