#include "Bomba.h"
#include "glut.h"


Bomba::Bomba(void)
{
}

Bomba::~Bomba(void)
{
}

int Bomba::Dibuja(int alcance)
{
	Estallar();
	
	if(estado == INICIO)
	{ 
		glColor3ub(rojo, verde, azul);
		glDisable(GL_LIGHTING);
		glTranslatef(2.5, 1.5, 2.5);
		glutSolidSphere(radio, 20, 20);
		glTranslatef(-2.5, -1.5, -2.5);
		glEnable(GL_LIGHTING);
		
		return 0;
	}

	else if(estado == EXPLOSION) 
	{
		explosion.Dibuja(alcance,p_x,p_z);
		return 1;
	}
	else if (estado == FIN)
	{
		return 2;
	}

}