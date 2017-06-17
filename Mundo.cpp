#include "Mundo.h"
#include "glut.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define MAXSIZE 100

Mundo::Mundo()
{
}

Mundo::~Mundo()
{
}

//mundo abre fichero, y tablero lo lee, asignando asi un objeto a cada posicion
void Mundo::leerfichero(char*filename)
{
	ifstream laberinto(filename);
	if (laberinto.is_open())
	{
		tablero.leerfichero(laberinto);
	}
	else
		cout << "ERROR" << endl;
}

void Mundo::Inicializa()
{
	//cambiar la camara para que se ajuste a las dimensiones del tablero
	cam_x = 37.5f;
	cam_y = 100.0f;
	cam_z = 65.0f; 

	ojo_x = 37.5f; 
	ojo_z = 32.5f;
}

//mundo solo gestiona el dibuja de la camara, y del tablero
void Mundo::Dibuja()
{
	gluLookAt(cam_x, cam_y, cam_z,	// posicion del ojo
		ojo_x, 7, ojo_z,	 // hacia que punto mira (0,0,0)
		0.0, 1.0, 0.0);		// definimos hacia arriba (eje Y)
						
	tablero.Dibuja();
}

void Mundo::TeclaEspecial(unsigned char key)	//Para el movimiendo del personaje
{
	tablero.TeclaEspecial(key);
}

//comando para poner bombas
void Mundo::Tecla(unsigned char clave)
{ 
	int p1, p2;
	if(clave==' '){
		tablero.PonerBomba();
	}
}

void Mundo::Mueve()
{
	tablero.Mueve();
}


/////////SETs y Gets//////////
int Mundo::GetMiVida()
{
	return tablero.GetMiVida();
}

int Mundo::GetNumeroEnemigos()
{
	return tablero.GetNumeroEnemigos();
}

int Mundo::GetAlcance()
{
	return tablero.GetAlcance();
}

int Mundo::GetNumBombas()
{
	return tablero.GetMaxBomb();
}