
#include <iostream>
#include <math.h>

using namespace std;


struct Alumno
{
    char legajo[10]; //xxx.xxx-x\0
    char apellidos[100];
    char nombres[100];
    unsigned int fechaNacimiento;
};

void cargarAlumno(Alumno &x)
{
    cout << "Ingrese el legajo del alumno:";
    cin >> x.legajo;
    cout << "Ingrese apellidos:";
    cin >> x.apellidos;
    cout << "Ingrese nombres:";
    cin >> x.nombres;
    cout << "Ingrese fecha de nacimiento AAAAMMDD:";
    cin >> x.fechaNacimiento;
    return;
}

void mostrarAlumno(Alumno x)
{
    cout << "******** Alumno " << x.legajo << " *******" << endl;
    cout << "Nombres: " << x.nombres << endl;
    cout << "Apellidos: " << x.apellidos << endl;
    cout << "Fecha de nacimiento: " << x.fechaNacimiento << endl;
    return;
}

void mostrarLegajos(Alumno va[], int tam)
{
    for (int i=0;i< tam;i++)
        cout << "Alumno: " << va[i].legajo  << endl;
    return;
}

int main()
{
    Alumno a;
    cargarAlumno(a);
    mostrarAlumno(a);
    Alumno vAlumnos[3];
    for(int i=0;i<3;i++)
        cargarAlumno(vAlumnos[i]);
    for (int i=0; i<3; i++)
        mostrarAlumno(vAlumnos[i]);
    mostrarLegajos(vAlumnos,3);
    return 0;
}
