#include "Municion.h"
#include "glut.h"
#include <iostream>
using namespace std;


Municion::Municion(void)
{
	radio = 1.5f;
	rojo = 0;
	verde = 0;
	azul = 0;
	estado=INICIO;
	contador = 0.0f;
	heExplotado=true;
}

Municion::~Municion(void)
{
}

void Municion::Estallar( )
{
	if(estado==INICIO) 
	{ 
	contador += 0.1f;
		if (contador>5.0f)
		{
			estado = EXPLOSION;
			heExplotado=true;
		}
	}
	else if(estado == EXPLOSION)
	{
		contador += 0.1f;
		if (contador>6.5f)
		{
			estado = FIN;
		}
	}

}

void Municion::Muevete(int direccionMovimiento) //gestiona la patada que personaje da a su bomba
{
	switch (direccionMovimiento)
	{
		case 0://el personaje esta a la izquierda de la bomba => muevete a la derecha
			SetPosicion(p_x-1, p_z);

		break;
	case 1://el personaje esta a la derecha de la bomba => muevete a la izquierda
			SetPosicion(p_x+1, p_z);

		break;
	case 2://el personaje esta por encima de la bomba => muevete hacia abajo
			SetPosicion(p_x, p_z-1);

		break;
	case 3://el personaje esta por debajo de la bomba => muevete hacia arriba
			SetPosicion(p_x, p_z+1);

		break;
	}
}

bool Municion::compruebaPos(int i, int j)
{
	if(p_x == i && p_z == j){
			return true;
		}
	return false;
}

/// SETs y GETs ///

void Municion::SetContador(float c)
{
	contador=c;
}

float Municion::GetContador()
{
	return contador;
}

void Municion::SetPosicion(int p_x, int p_z)
{
	this-> p_x= p_x;
	this-> p_z = p_z;
}

int Municion::GetPos_x(){
	return p_x;
}

int Municion::GetPos_z(){
	return p_z;
}