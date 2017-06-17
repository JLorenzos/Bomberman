#pragma once
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Personaje
{
private:
	SpriteSequence sprite;
	float lado;
	int MiVida;
	bool Inmunidad;
	int contar;
	int cuentaParpadeos;
	enum Estado{ON,OFF};
	Estado estado;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	int pos_x;
	int pos_z;

	int posSig_x;
	int posSig_z;

	int Pos_Relativa;

public:
	Personaje();
	~Personaje();

	void Dibuja();
	bool compruebaPos(int a, int b);
	void CalculaSiguiente(unsigned char key);
	void ChequeaDaños(int a,int b);
	int Parpadeo();
	bool SerInmune();

	void SetPosicion_x(int a);
	void SetPosicion_z(int b);
	int GetPosicion_x();
	int GetPosicion_z();
	int GetPosicionSiguiente_x();
	int GetPosicionSiguiente_z();
	void SetMiVida(int MiVida);
	int GetMiVida();
	void SetInmunidad(bool Inmunidad);
	bool GetInmunidad();
	bool GetPatada();
	void direccionMovimiento(int n);
};


