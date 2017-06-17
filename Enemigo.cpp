#include "Enemigo.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>

using namespace std;

Enemigo::Enemigo(void)
{
	pos_x=0;
	pos_z=0;
	lado = 4.0f;
	rojo = 255;
	verde = 255;
	azul = 0;
	VidaEnemigo=1;
	ultimoMovimiento=0;
}


Enemigo::~Enemigo(void)
{
}

void Enemigo::Dibuja(bool eligeDibujoDistinto)
{
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	if(eligeDibujoDistinto)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Verde.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Mounstruito.png").id);

	glBegin(GL_QUADS);
		// Superior
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0,  lado, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  lado,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado, lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado,  lado, 0);

	glEnd();

	if(eligeDibujoDistinto)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/C_Verde2.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Cuerpo.png").id);
	glBegin(GL_QUADS);

		// Inferior
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0, 0, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);

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
	
		// Derecha 
		glTexCoord2f(1.0f, 0.0f); glVertex3f( lado, 0, 0);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( lado,  lado, 0);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( lado,  lado,  lado);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( lado, 0,  lado);	

		// Izquierda 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0, 0,  lado);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0,  lado,  lado);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0,  lado, 0);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 0, 0);	
		
		glEnd();
	glDisable(GL_TEXTURE_2D);	
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

bool Enemigo::Dispara(bool tieneDisparo, bool puedoDisparar, int direccionMovimiento)
{
	if(tieneDisparo)//solo si este enemigo SI tiene disparo
	{
		//EfectuaDisparo
		if(puedoDisparar) //funcion bool que te dice si tengo via libre para disparar y acertar
		{
			return true;
		}
	}
	return false;
}

bool Enemigo::compruebaPos(int a, int b)
{
	if(pos_x == a && pos_z == b){
			return true;
		}
	return false;
}

void Enemigo::CalculaSiguiente()//Para el movimiendo del enemigo
{
	int movimiento = rand() % 13;// va de 0 a 12	
	if (movimiento > 3 && movimiento < 8)
	{
		movimiento = ultimoMovimiento;
	}
	ultimoMovimiento = movimiento;

	switch (movimiento)
	{
	case 0://arriba
		posSig_x=pos_x-1;
		posSig_z=pos_z;
		break;

	case 1://derecha
		posSig_x=pos_x;
		posSig_z=pos_z+1;
		break;

	case 2://abajo
		posSig_x=pos_x+1;
		posSig_z=pos_z;
		break;

	case 3://izquierda
		posSig_x=pos_x;
		posSig_z=pos_z-1;
		break;

	default:
		//no hagas nada.
		break;

	}
}

void Enemigo::ChequeaExplosion(int a,int b)
{
	if(pos_x==a && pos_z==b){
		VidaEnemigo=VidaEnemigo-1;
	}
}

/////////SETs y Gets//////////

void Enemigo::SetPosicion_x(int a)
{
	pos_x=a;
}

void Enemigo::SetPosicion_z(int b)
{
	pos_z=b;
}

int Enemigo::GetPosicion_x(){
	return pos_x;
}

int Enemigo::GetPosicion_z(){
	return pos_z;
}

int Enemigo::GetPosicionSiguiente_x(){
	return posSig_x;
}

int Enemigo::GetPosicionSiguiente_z(){
	return posSig_z;
}

void Enemigo::setUltimoMovimiento(int mov)
{
	ultimoMovimiento=mov;
}

int Enemigo::getUltimoMovimiento(){
	return ultimoMovimiento;
}

int Enemigo::GetVidaEnemigo()
{
	return VidaEnemigo;
}
