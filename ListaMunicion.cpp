#include "ListaMunicion.h"
#include <iostream>

using namespace std;

ListaMunicion::ListaMunicion(void)
{
	alcance = 1;
	topeBombas = 1;
	totalBombas = 0;
	for(int i=0;i<MAX_BOMBAS;i++)
		lista[i]=0;
}

ListaMunicion::~ListaMunicion(void)
{
}

bool ListaMunicion::Agregar(Municion *m, int i, int j)
{
	if(totalBombas<topeBombas){
	   lista[totalBombas]=m;
	   lista[totalBombas]->SetPosicion(i,j);
	   totalBombas = totalBombas +1;   
	 }
	else 
		return false;
	return true;
}

void ListaMunicion::Eliminar(int indice)
{
	for(int i=indice;i<totalBombas;i++){
		lista[i]=lista[i+1];
	}
	totalBombas--;
}

int ListaMunicion::Dibuja(int indiceBomba)
{
	return lista[indiceBomba]->Dibuja(GetAlcance());
	
}

void ListaMunicion::Muevete(int direccionMovimiento, int indiceBomba)
{
	if(indiceBomba != -1)
		lista[indiceBomba]->Muevete(direccionMovimiento);
}

bool ListaMunicion::compruebaPos(int x, int y)
{
	for(int i=0;i<totalBombas;i++){
		Municion *m = lista[i];
		if((m->GetPos_x() == x) && (m->GetPos_z() == y)){
			m->compruebaPos(x,y);
			return true;
		}
	}
	return false;
}

/////////SETs y Gets//////////

void ListaMunicion::SetPosicion(int indice,int i,int j)
{
	lista[indice]->SetPosicion(i,j);
}

int ListaMunicion:: GetBombaPos_x(int indice)
{
	return lista[indice]->GetPos_x();
}

int ListaMunicion:: GetBombaPos_z(int indice)
{
	return lista[indice]->GetPos_z();
}

void ListaMunicion:: SetTopeBombas(int tope)
{
	topeBombas = tope;
}

int ListaMunicion:: GetTopeBombas()
{ 
	return topeBombas;
}

void ListaMunicion::SetAlcance(int a)
{
	alcance=a;
}

int ListaMunicion::GetAlcance()
{
	return 	alcance;
}

int ListaMunicion::GetIndiceBomba(int i, int j)
{
	for(int k=0;k<totalBombas;k++){
		Municion *m = lista[k]; 
		if((m->GetPos_x() == i) && (m->GetPos_z() == j)){
			return k;
		}
	}
	return -1;
}