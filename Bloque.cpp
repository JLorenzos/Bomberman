#include "Bloque.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
using namespace std;

Bloque::Bloque()
{
	lado = 5;
	sePuedePasar = false;
	sePuedeRomper = true;
}

Bloque::~Bloque()
{
}

void Bloque::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); 
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Bloque.png").id);

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
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	
	
		// Derecha face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	

		// Izquierda Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  lado,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  lado, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);	
		
	glEnd();
	glDisable(GL_TEXTURE_2D);	
	glEnable(GL_LIGHTING);
}