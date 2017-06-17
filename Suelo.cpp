#include "Suelo.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace std;

Suelo::Suelo()
{
	rojo = 255;
	verde = 255;
	azul = 255;
	sePuedePasar = true; //puede variar
	sePuedeRomper = false;
}

Suelo::~Suelo()
{
}

void Suelo::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Celda.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(rojo, verde, azul);
		glTexCoord2d(1,0); glVertex3d(0, 0, 0);
		glTexCoord2d(1,1); glVertex3d(0, 0, lado);
		glTexCoord2d(0,1); glVertex3d(lado, 0, lado);
		glTexCoord2d(0,0); glVertex3d(lado, 0, 0);
		glVertex3d(0, 0, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}