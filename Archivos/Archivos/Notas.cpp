#include "Notas.h"

#include<fstream>


#include<iostream>
using namespace std;

void Notas::registrarAlumnos()
{

	ofstream archivoAlumnos("Alumnos.dat",ios::app);

	if (!archivoAlumnos) 
	{

		cout << "Error al intentar abrir archivo Alumnos.dat\n";

		return;
	
	}

	int cuenta, edad,cantidad;

	char nombre[50];

	cout << "\n\n *** I N G R E S O   D E   A L U M N O S *** \n\n";

	cout << "Cantidad de alumnos a ingresar: ";

	cin >> cantidad;

	for (int i = 0; i < cantidad; i++) 
	{
		
		cout << "Ingrese el numero de cuenta: ";
		
		cin >> cuenta;
		
		cout << "Ingrese nombre del alumno: ";
		
		cin >> nombre;
		
		cout<< "Ingrese edad: ";
		
		cin >> edad;

		archivoAlumnos << cuenta << ' ' << nombre << ' ' << edad << "\n";
	
	
	}
	archivoAlumnos.close();
}
void Notas::consultarAlumnos() {

	ifstream archivoAlumnoslm("Alumnos.dat",ios::app);
	if (!archivoAlumnoslm) {
	
		cout << "Error al intentar abrir archivo Alumnos.dat\n";

		return;

	
	
	}
	int cuenta, edad;
	char nombre[50];
	cout << "\n\n *** C O N S U L T A   D E   A L U M N O S ***\n\n";
	while (archivoAlumnoslm>>cuenta>>nombre>>edad) {
		cout << cuenta << ' ' << nombre << ' ' << edad << ' ' << "\n";

	
	}
	archivoAlumnoslm.close();

}
void Notas::consultarMateria() {

	ifstream archivoMateriasIn("materias.dat", ios::in);

	if (!archivoMateriasIn) {
		cout << "Error al intentar abrir el archivo materias.dat\n";
		return;
	}

	cout << "\n\n * C O N S U L T A  D E  M A T E R I A S *\n\n";

	archivoMateriasIn.seekg(0, ios::beg);

	int codigoM;
	char nombre[30];

	while (archivoMateriasIn >> codigoM >> nombre) {
		cout << codigoM << ' ' << nombre << "\n";
	}

	archivoMateriasIn.close();
}
void Notas::registrarMateria() {
	ofstream archivoMateriasOut("materias.dat", ios::app);

	if (!archivoMateriasOut) {
		cout << "Error al intentar abrir el archivo materias.dat\n";
		return;
	}

	int cantidad, codigoM;
	char nombre[30];

	cout << "\n\n * I N G R E S O  D E  M A T E R I A S *\n\n";

	cout << "Ingrese cantidad de materias: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++) {
		cout << "Ingrese codigo: ";
		cin >> codigoM;
		cout << "Ingrese materia: ";
		cin >> nombre;

		archivoMateriasOut << codigoM << ' ' << nombre << "\n";
	}
	archivoMateriasOut.close();

}

	void Notas::registrarNotas() {
		ofstream archivoNotasOut("notas.dat", ios::app);

		if (!archivoNotasOut) {
			cout << "Error al intentar abrir el archivo notas.dat\n";
			return;
		}

		int opcion = 0;

		cout << "\n\n * I N G R E S O  D E  N O T A S *\n\n";

		do {
			char nombreM[30];
			char nombreA[50];
			int codigoM, codigoA, nota;

			do {
				cout << "Ingrese Materia: ";
				cin >> nombreM;
				codigoM = ObtenerCodigoMateria(nombreM);
			} while (codigoM == -1);

			do {
				cout << "Ingrese Alumno: ";
				cin >> nombreA;
				codigoA = ObtenerCodigoAlumno(nombreA);
			} while (codigoA == -1);

			cout << "Ingrese Nota: ";
			cin >> nota;

			archivoNotasOut << codigoM << ' ' << codigoA << ' ' << nota << "\n";

			cout << "Desea ingresar una nueva nota? -1 para salir.";
			cin >> opcion;

		} while (opcion != -1);

		archivoNotasOut.close();


	}



int Notas::ObtenerCodigoMateria(char * nombreM) {


	ifstream archivoMateria("materias.dat", ios::in);
	if(!archivoMateria){

		cout << "Error";
			return -1;
	}

	archivoMateria.seekg(0,ios::beg);
	int codigo;
	char nombre[30];

	while (archivoMateria >> codigo >> nombre)
	{

		if (strcmp(nombre, nombreM) == 0)

			return codigo;
	}

	return -1;

}
int Notas::ObtenerCodigoAlumno(char *nombreA) {

	ifstream archivoAlumnos("alumnos.dat", ios::in);
	if (!archivoAlumnos) {

		cout << "Error";
		return -1;
	}

	archivoAlumnos.seekg(0, ios::beg);
	int codigo;
	char nombre[30];

	while (archivoAlumnos >> codigo >> nombre)
	{

		if (strcmp(nombre, nombreA) == 0)

			return codigo;
	}

	return -1;


}
char * Notas::ObtenerNombreAlumno(const int codigoAlumno) 
{

	ifstream archivoAlumnos("alumnos.dat", ios::in);

	if (!archivoAlumnos) 
	{
	
		cout << "Error";
		return NULL;//nullpr, 0
	}
	int codigo, edad;
	char nombre[30];
	archivoAlumnos.seekg(0, ios::beg);
	while (archivoAlumnos>>codigo>>nombre>>edad) 
	{
		if (codigoAlumno == codigo) 
		{
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';

			return retorno;
		
		
		
		}
	
	
	
	}
	archivoAlumnos.close();
	return NULL;

}
char *Notas::ObtenerNombreMateria(const int codigoMateria) {

	ifstream archivoMateria("materias.dat", ios::in);

	if (!archivoMateria)
	{

		cout << "Error, con el archivo materias";
		return NULL;//nullpr, 0
	}
	int codigo, edad;
	char nombre[50];

	archivoMateria.seekg(0,ios::beg);
	while (archivoMateria >> codigo >> nombre >> edad)
	{
		if (codigoMateria == codigo)
		{
			char *retorno = new char[strlen(nombre)];
			strcpy(retorno, nombre);
			retorno[strlen(nombre)] = '\0';

			return retorno;



		}



	}
	archivoMateria.close();
	return NULL;



}
//calcular el promedio de notas por alumno y calcular el promedio de notas por clase
void Notas::consultarNotas() {

	ifstream archivoNotas("notas.dat", ios::in);

	if (!archivoNotas) {
	
	
		cout << "Error con el arcivo notas";
		return;
	}

	cout << "\n\n *** C O N S U L T A  D E  N O T A S ***\n\n";

	int codigoM, codigoA, nota;
	archivoNotas.seekg(0, ios::beg);
	while (archivoNotas >> codigoM >> codigoA >> nota)
	{
		cout << ObtenerNombreMateria(codigoM) << ' ' << ObtenerNombreAlumno(codigoA) << ' ' << nota <<endl;
	
	
	
	}

	archivoNotas.close();

}
double Notas::promedioMateria() {

	ifstream archivoNotas("notas.dat", ios::app);
	if (!archivoNotas) {
	
	
		cout << "Error";
		return -1;
	}
	int codigoM = 0;
	int codigoA = 0;
	int nota = 0;
	int promedio = 0;
	int num_materias = 0;

	while (archivoNotas>>codigoM>>codigoA>>nota) {
	
		promedio = promedio + nota;
		num_materias++;
	
	
	}

	return promedio / num_materias;
}
double Notas::promedioAlumno(char *nombreAlumno) {
	ifstream archivoAlumno("Alumnos.dat", ios::app);
	if (!archivoAlumno) {
	
	
		cout << "Error";
		return -1;
	}
	int codigo;
	int edad;
	char nombre[50];

	archivoAlumno.seekg(0, ios::beg);
	while (archivoAlumno >> codigo >> nombre >> edad) {
		if (strcmp(nombre, nombreAlumno) == 0) {
			ifstream archivoNotas("notas.dat", ios::app);
			int codigoM = 0;
			int codigoA = 0;
			int nota = 0;
			double promedio = 0;
			int contador = 0;


			archivoNotas.seekg(0, ios::beg);

			while (archivoNotas >> codigoM >> codigoA >> nota) {
			
				if (codigoA == codigo) {
				
					promedio = promedio + nota;
					contador++;
				
				}
			
			}
		
			return promedio / contador;

		}
	
	
	}


	return -1;
}

