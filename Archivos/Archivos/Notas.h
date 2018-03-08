#pragma once
#ifndef NOTA_H
#define NOTA_H
class Notas {

public:
	static void registrarAlumnos();
	static void consultarAlumnos();
	static void registrarMateria();
	static void consultarMateria();
	static void registrarNotas();

	static void consultarNotas();
	static int ObtenerCodigoAlumno(char *);
	static int ObtenerCodigoMateria(char *);
	static char * ObtenerNombreAlumno(const int);
	static char * ObtenerNombreMateria(const int);
	static double promedioMateria();
	static double promedioAlumno(char *);
};



#endif // !NOTA_H

