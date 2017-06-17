#include "Muro.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace std;

Muro::Muro()
{
	sePuedePasar = false;
	sePuedeRomper = false;
}

Muro::~Muro()
{
}

void Muro::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Muro.png").id);
	glDisable(GL_LIGHTING);
	glTranslatef(2.5,2.5,2.5);
	glColor3ub(rojo, verde, azul);
	glutSolidCube(lado);
	glTranslatef(-2.5, -2.5, -2.5);
	glBegin(GL_QUADS);

		//Frontal
		glTexCoord2f(1.0f, 0.0f); glVertex3f(lado, 0,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0, 0,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(lado,  lado,  lado);

		// Trasera
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0,  lado, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado, 0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);

		// Superior
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  lado, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0,  lado,  lado);

		// Inferior
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0, 0);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(lado, 0,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, lado,  lado);

		// Derecha
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	
	
		// Izquierda
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, lado,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  0,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  0, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, lado, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}