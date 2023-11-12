/******************************************************************************
Funciones recursivas

*******************************************************************************/
#include <iostream>

using namespace std;

int fib(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int contarDigitos(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return 1 + contarDigitos(num / 10);
    }
}

int main()
{
    //opcion 1
    int n, t1 = 0, t2 = 1, siguiente;

    cout << "Ingrese el número de términos que desea en la sucesión de Fibonacci: ";
    cin >> n;

    cout << "Sucesión de Fibonacci: ";

    for (int i = 1; i <= n; ++i)
    {
        cout << t1 << ", ";

        siguiente = t1 + t2;
        t1 = t2;
        t2 = siguiente;
    }

    //opcion 2
    int fibNumber = 9;
    cout << "El número en la posición 9 de la sucesión de Fibonacci es: " << fib(fibNumber) << endl;

    //opcion 3
    int numero = 12345;
    int cantidadDigitos = contarDigitos(numero);
    cout << "El número " << numero << " tiene " << cantidadDigitos << " dígitos." << endl;

    return 0;
}


