#pragma once
#include "Municion.h"
#define MAX_BOMBAS 10

class ListaMunicion
{
protected:
	Municion * lista[MAX_BOMBAS];
	int alcance;
	int topeBombas;
	int totalBombas;
	int pos_x;
	int pos_z;

public:
	ListaMunicion(void);
	~ListaMunicion(void);

	bool Agregar(Municion *m, int i, int j);
	void Eliminar(int indice);
	int Dibuja(int indiceBomba);
	void Estallar();
	void Muevete(int direccionMovimiento, int indiceBomba);
	bool compruebaPos(int x, int y);

	void SetPosicion(int indice,int i,int j);
	int GetBombaPos_x(int indice);
	int GetBombaPos_z(int indice);
	void SetTopeBombas(int tope);
	int GetTopeBombas();
	void SetAlcance(int a);
	int GetAlcance();
	int GetIndiceBomba(int i, int j);
};


