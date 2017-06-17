#pragma once
#include "Explosion.h"

class Municion
{
protected:
	Explosion explosion;
	enum Estado {INICIO, EXPLOSION, FIN}; 
	Estado estado;
	bool heExplotado;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	float radio;
	float contador;
	int estallar;

	int p_x;
	int p_z;

public:
	Municion(void);
	~Municion(void);
	bool haExplotado(){return heExplotado;}
	void resetExplosion(){heExplotado=false;}
	virtual int Dibuja(int alcance)=0;
	void Estallar();
	void Muevete(int direccionMovimiento);
	bool compruebaPos(int x, int y);

	void DestruyeDisparo(int x, int y);

	void SetContador(float c);
	float GetContador();

	void SetPosicion(int p_x, int p_z);
	int GetPos_x();
	int GetPos_z();
};