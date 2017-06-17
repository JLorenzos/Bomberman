#include "Personaje.h"
#include "glut.h"
#include "ETSIDI.h"
#include <iostream>
#include <fstream>
using namespace std;

Personaje::Personaje():sprite("Images/pangPlayer.png",5)
{
	lado = 4.0f;
	sprite.setCenter(2.5,2.5);
	sprite.setSize(8,8);
	rojo = 255;
	verde = 0;
	azul = 0;
	MiVida=2;
	Inmunidad=false;
	contar=0;
	cuentaParpadeos=0;
	estado=ON;
}

Personaje::~Personaje()
{
}

void Personaje::Dibuja()
{
	glPushMatrix();
	glTranslatef(2.5,2.5,2.5);
   	glColor3ub(rojo,verde,azul);

	//gestion de direccion y animacion
	if(Pos_Relativa==3)sprite.flip(false,false);
	if(Pos_Relativa==2)sprite.flip(true,false);
	if(Pos_Relativa==0 || Pos_Relativa==1)
		sprite.setState(0);
	else if (sprite.getState()==0)
		sprite.setState(1,false);
	sprite.draw();

	glTranslatef(-2.5,-2.5,-2.5);

	glPopMatrix();
}

bool Personaje::compruebaPos(int a, int b)
{
	if(pos_x == a && pos_z == b)
			return true;

	return false;
}

void Personaje::CalculaSiguiente(unsigned char key)//Para el movimiendo del personaje
{
	//esta es la posicion a la que queremos movernos en cada caso
	//si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el personaje se movera.
	switch (key)
	{
	case GLUT_KEY_LEFT:
		posSig_x=pos_x;
		posSig_z=pos_z-1;
		break;

	case GLUT_KEY_RIGHT:
		posSig_x=pos_x;
		posSig_z=pos_z+1;
		break;

	case GLUT_KEY_UP:
		posSig_x=pos_x-1;
		posSig_z=pos_z;
		break;

	case GLUT_KEY_DOWN:
		posSig_x=pos_x+1;
		posSig_z=pos_z;
		break;
	default:
		break;
	}

}

void Personaje::ChequeaDaños(int a,int b)  //Expresion comun a verse afectado por explosion y enemigo
{
	if(pos_x==a && pos_z==b){
		if(!SerInmune()){
			MiVida=MiVida-1;
			Inmunidad=true;
		}
	}
}

bool Personaje::SerInmune()
{
	if (Inmunidad==true){
		Parpadeo();
		return true;
	}
	else 
		return false;
}

int Personaje::Parpadeo()
{
	if (estado==ON)
	{
		contar+=1;
		if(contar>10){
			estado=OFF;
			return 0;
		}
		return 1;
	}
	if (estado==OFF)
	{
		contar+=1;
		if(contar>20){
			estado=ON;
			contar=0;
			cuentaParpadeos=cuentaParpadeos+1;
			
			if (cuentaParpadeos>20){
				cuentaParpadeos=0;
				Inmunidad=false; //cuando espera los suficientes tiempos como para que hullas, entonces pongo inmunidad a false
			}
			return 1;
		}
		return 0;
	}
}

/////////SETs y Gets//////////

void Personaje::SetPosicion_x(int a)
{
	pos_x=a;
}

void Personaje::SetPosicion_z(int b)
{
	pos_z=b;
}

int Personaje::GetPosicion_x(){
	return pos_x;
}

int Personaje::GetPosicion_z(){
	return pos_z;
}

int Personaje::GetPosicionSiguiente_x(){
	return posSig_x;
}

int Personaje::GetPosicionSiguiente_z(){
	return posSig_z;
}

void Personaje::SetMiVida(int MiVida)
{
	this-> MiVida = MiVida;
}

int Personaje::GetMiVida()
{
	return MiVida;
}

void Personaje::SetInmunidad(bool Inmunidad)
{
	this-> Inmunidad = Inmunidad;
}

bool Personaje::GetInmunidad()
{
	return Inmunidad;
}

bool Personaje::GetPatada()
{
	if(MiVida>2)
		return true;
	return false;
}

void Personaje::direccionMovimiento(int n)
{
	Pos_Relativa = n;
}