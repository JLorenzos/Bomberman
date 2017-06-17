#include "ListaEnemigos.h"
#include <iostream>

using namespace std;


ListaEnemigos::ListaEnemigos(void)
{
	tieneDisparo=false;
	eligeDibujoDistinto=false;
	numero=0;
	for(int i=0;i<MAX_ENEMIGOS;i++)
		lista[i]=0;
}


ListaEnemigos::~ListaEnemigos(void)
{
}

bool ListaEnemigos::Agregar(Enemigo *e, int i, int j)
{
	if(numero<MAX_ENEMIGOS){
	   lista[numero]=e;
		e->SetPosicion_x(i);
		e->SetPosicion_z(j);
	   numero = numero +1;
	 }
	else 
		return false;
	return true;
}

void ListaEnemigos::Eliminar(int indice)
{
	for(int i=indice;i<numero;i++){
		lista[i]=lista[i+1];
	}
	numero--; //por este modo de eliminar, y la manera que tenemos de crear enemigos, si hay mas de dos enemigos el juego garantiza que uno es verde y otro azul
}

void ListaEnemigos::Dibuja(int indiceEnemigo)
{
		lista[indiceEnemigo]->Dibuja(EspecificacionDeEnemigo(indiceEnemigo));
}

bool ListaEnemigos::Dispara(int indiceEnemigo, bool puedoDisparar, int direccionMovimiento)
{
		return lista[indiceEnemigo]->Dispara(EspecificacionDeEnemigo(indiceEnemigo), puedoDisparar, direccionMovimiento);
}

void ListaEnemigos::Mueve()
{
	for(int i=0;i<numero;i++)
		lista[i]->CalculaSiguiente();
}

void ListaEnemigos::CalculaSiguiente(int indice)
{
	lista[indice]->CalculaSiguiente();
}

bool ListaEnemigos::compruebaPos(int a, int b)
{
	for(int i=0;i<numero;i++){
		Enemigo *e = lista[i];
		
		if((e->GetPosicion_x() == a)&&(e->GetPosicion_z() == b)){
			e->compruebaPos(a,b);
			return true;
		}
	}
	return false;
}

void ListaEnemigos::ChequeaExplosion(int a, int b)
{
	for(int i=0;i<numero;i++){
		lista[i]->ChequeaExplosion(a,b);
		if(lista[i]->GetVidaEnemigo() == 0){
			Eliminar(i);
		}
	}
}

bool ListaEnemigos::EspecificacionDeEnemigo(int indice)
{
	for(int i=indice;i<numero;i++){
		int resto=i%2;
	   if(resto==0){ //numero par
		  return false;
	   }
	   else if(resto!=0){ //numero impar
		  return true;//enemigo verde y con disparos
	   }
	}
}

int ListaEnemigos::EnemigoVerde()
{
	for(int i=0;i<numero;i++){
		if(EspecificacionDeEnemigo(i)){
			return i;
		}
	}
	return -1;
}

/////////SETs y Gets//////////

int ListaEnemigos::GetNumeroEnemigos()
{
	return numero;
}

int ListaEnemigos::GetPosicionSiguiente_x(int indice)
{
	return lista[indice]->GetPosicionSiguiente_x();
}

int ListaEnemigos::GetPosicionSiguiente_z(int indice)
{
	return lista[indice]->GetPosicionSiguiente_z();
}

void ListaEnemigos::SetPosicion(int indice,int p1,int p2)
{
	lista[indice]->SetPosicion_x(p1);
	lista[indice]->SetPosicion_z(p2);
}

int ListaEnemigos:: GetEnemPos_x(int indice)
{
	return lista[indice]->GetPosicion_x();
}

int ListaEnemigos:: GetEnemPos_z(int indice)
{
	return lista[indice]->GetPosicion_z();
}

int ListaEnemigos::GetIndiceEnemigo(int i, int j)
{
	for(int k=0;k<numero;k++){
		Enemigo *e = lista[k]; 
		if((e->GetPosicion_x() == i) && (e->GetPosicion_z() == j)){
			return k;
		}
	}
	return -1;
}