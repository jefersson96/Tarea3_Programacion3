#include <conio.h>
#include<iostream>
#include"Notas.h"
using namespace std;
int main() {

	//Notas::registrarAlumnos();
	//Notas::consultarAlumnos();

	//Notas::registrarMateria();
	//Notas::consultarMateria();
	//Notas::registrarNotas();
	//Notas::registrarNotas();
	//Notas::consultarNotas();

	//Notas::promedioMateria();

	int opcion;
	do {
		cout << "\n\n *** M E N U ** \n\n";
		cout << "\n1-Ingresar Materia\n2-Ingresar Alumno\n3-Ingresar Nota\n4-Mostrar Materias\n5-Mostrar Alumnos\n6-Mostrar Notas\n7-Consultar Promedio Alumno\n8-Consultar promedio clase\n9-Salir" << endl;
		cout << "Ingrese una opcion: " << endl;
		cin >> opcion;


		switch (opcion)
		{

		case 1:
			system("cls");
			Notas::registrarMateria();
			break;
		case 2:
			system("cls");
			Notas::registrarAlumnos();

			break;
		case 3:
			system("cls");
			Notas::registrarNotas();
			break;
		case 4:
			Notas::consultarMateria();
			break;

		case 5:
			system("cls");
			Notas::consultarAlumnos();

			break;
		case 6:
			system("cls");
			Notas::consultarNotas();

			break;

		case 7:
			//	Notas::promedioAlumno();
			break;
		case 8:
			system("cls");
			Notas::promedioMateria();
			break;
		case 9:

			exit(0);
			break;
		}


		system("cls");
	} while (opcion != 9);




	_getch();
}