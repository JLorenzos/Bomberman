#pragma once
#include "Enemigo.h"
#define MAX_ENEMIGOS 3

class ListaEnemigos
{
private:
	Enemigo * lista[MAX_ENEMIGOS];
	int numero;
	bool tieneDisparo;
	bool eligeDibujoDistinto;
public:
	ListaEnemigos(void);
	~ListaEnemigos(void);

	bool Agregar(Enemigo *e, int i, int j);
	void Eliminar(int indice);
	void Dibuja(int indiceEnemigo);
	bool Dispara(int indiceEnemigo, bool puedoDisparar, int direccionMovimiento);
	void Mueve();
	void CalculaSiguiente(int indice);
	bool compruebaPos(int a, int b);
	void ChequeaExplosion(int a, int b);
	bool EspecificacionDeEnemigo(int indice);
	int EnemigoVerde();
	
	int GetNumeroEnemigos();
	int GetPosicionSiguiente_x(int indice);
	int GetPosicionSiguiente_z(int indice);
	void SetPosicion(int indice,int p1,int p2);
	int GetEnemPos_x(int indice);
	int GetEnemPos_z(int indice);
	int GetIndiceEnemigo(int i, int j);
};