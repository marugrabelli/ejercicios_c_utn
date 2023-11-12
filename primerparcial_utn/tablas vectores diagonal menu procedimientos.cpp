/******************************************************************************
 *
*******************************************************************************/

using namespace std;

void cargarTablaAleatoriamente(int t[][TAM])
{
    srand(time(NULL));
    for (int i=0;i < TAM;i++)
        for (int j=0; j < TAM; j++)
            t[i][j] = rand() % 1000 + 1;
    return;
}

/* Ponemos const para indicar que no se debe modificar
la tabla dentro del procedimiento*/
void mostrarTabla(const int t[][TAM])
{
    for (int i=0;i < TAM;i++)
    {
        for (int j=0; j < TAM; j++)
            cout << t[i][j] << "\t\t";
        cout << endl << endl;
    }
    return;
}

void mostrarDiagonal(const int t[][TAM])
{
    for (int i=0; i < TAM; i++)
    {
        for(int canttab=0; canttab < i; canttab++)
            cout << "\t\t";
        cout << t[i][i] << endl;
    }
    return;
}

char opcionElegida()
{
    char opcion;
    cout << "a - Cargar nuevos valores en la tabla." << endl;
    cout << "b - Mostrar toda la tabla." << endl;
    cout << "c - Mostrar la digonal" << endl;
    cout << "Esc - Salir." << endl;
    do
    {
        cin >> opcion;
        opcion = tolower(opcion);
    }
    while (opcion!='a' && opcion!='b' && opcion!='c' && opcion!=27);
    return opcion;
}

int main()
{
    int tabla[TAM][TAM];
    char caracter;
    do
    {
        caracter = opcionElegida();
        switch(caracter)
        {
            case 'a':
                cargarTablaAleatoriamente(tabla);
            break;
            case 'b':
                mostrarTabla(tabla);
            break;
            case 'c':
                mostrarDiagonal(tabla);
            break;
        }
    }
    while (caracter != 27);


    return 0;
}
