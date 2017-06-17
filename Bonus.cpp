#include "Bonus.h"
#include "glut.h"
#include <iostream>

using namespace std;


#include "Bonus.h"
#include "glut.h"

Bonus::Bonus()
{
	anguloCuboX = 0.0f;
	anguloCuboY = 0.0f;
	anguloEsfera = 0.0f;
}


Bonus::~Bonus()
{
}
 
bool Bonus::crearBonus()
{
	int numero = rand() % 6; //crea numeros aleatorios del 0 al 5 (son 6 numeros, un dado)
	if (numero>2){
		return true;
	}
	else
		return false;
}

void Bonus::Dibuja()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(2.5,2,2.5);

	glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
	
	glColor3ub(225,0,225); 
	glBegin(GL_QUADS);       //cara frontal
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f( 1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glEnd();

    glColor3ub(0,225,0);
    glBegin(GL_QUADS);       //cara trasera
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    glEnd();

    glColor3ub(0,0,225);
    glBegin(GL_QUADS);       //cara lateral izq
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glVertex3f(-1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3ub(225,225,0);
    glBegin(GL_QUADS);       //cara lateral dcha
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glEnd(); 
    
	glColor3ub(0,225,225);
    glBegin(GL_QUADS);       //cara arriba
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();
 
    glColor3ub(225,0,0);
    glBegin(GL_QUADS);       //cara abajo
    glVertex3f( 1.0f,-1.0f, -1.0f);
    glVertex3f( 1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f,-1.0f,  1.0f);
    glVertex3f(-1.0f,-1.0f, -1.0f);
    glEnd();

	glTranslatef(-2.5,-2,-2.5);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void Bonus::mueve()
{
	anguloCuboX+=1.0f;
	anguloCuboY+=1.0f;
	anguloEsfera+=2.0f;
}

//el Efecto del Bonus lo decidimos cuando personaje lo coge
int Bonus::Efecto()
{
		int numero = rand() % 6;
		switch (numero)
		{
			case 0:
			case 1:
				return 0;
				break;
			case 2:
			case 3:
				return 1;
				break;
			case 4:
			case 5:
				return 2;
				break;
		}
}