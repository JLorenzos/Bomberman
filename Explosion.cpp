#include "Explosion.h"
#include "Glut.h"
#include <iostream>
#include "ETSIDI.h"

using namespace std;

Explosion::Explosion(void)
{
	primeraVez=true;
	lado = 5;
	rojo = 243;
	verde = 144;
	azul = 52;
}

Explosion::~Explosion(void)
{
}

void Explosion::Dibuja(int alcance, int i, int j)
{
	
	if(primeraVez){
		ETSIDI::play("Audio/bomba.wav");
		primeraVez=false;
	}
	glColor3ub(rojo, verde, azul);
	glDisable(GL_LIGHTING);
		
	//centro
	glTranslatef(2.5,0,2.5);
	glutSolidCube(lado);
	glTranslatef(-2.5,0,-2.5);

	for (int x=0; x<alcance; x++)
	{ 
	//derecha
	if(j-x>0 && j-x<14)
		{
		glTranslatef(-(2.5+x*5), 0, 2.5);
		glutSolidCube(lado);
		glTranslatef(2.5+x*5, 0, -2.5);
		}
	//izquierda
	if(j+x>0 && j+x<14)
		{
		glTranslatef(7.5+x*5, 0, 2.5);
		glutSolidCube(lado);
		glTranslatef(-(7.5+x*5), 0, -2.5);
		}
	//arriba
	if(i-x>0 && i-x<12)
		{
		glTranslatef(2.5, 0, -(2.5+x*5));
		glutSolidCube(lado);
		glTranslatef(-2.5, 0, 2.5+x*5);
		}
	//abajo
	if(i+x>0 && i+x<12)
		{
		glTranslatef(2.5, 0, 7.5+x*5);
		glutSolidCube(lado);
		glTranslatef(-2.5, 0, -(7.5+x*5));	
		}
	}
	
	glEnable(GL_LIGHTING); 
}