#pragma once

class Enemigo
{
private:
	float lado;
	int VidaEnemigo;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	int ultimoMovimiento;
	int pos_x;
	int pos_z;
	int posSig_x;
	int posSig_z;

public:
	Enemigo();
	Enemigo(int i, int j){pos_x=i; pos_z=j;}
	~Enemigo();

	void Dibuja(bool eligeDibujoDistinto);
	bool Dispara(bool tieneDisparo, bool puedoDisparar, int direccionMovimiento);
	bool compruebaPos(int a, int b);
	void CalculaSiguiente();
	void ChequeaExplosion(int a,int b);

	void SetPosicion_x(int a);
	void SetPosicion_z(int b);
	int GetPosicion_x();
	int GetPosicion_z();
	int GetPosicionSiguiente_x();
	int GetPosicionSiguiente_z();
	void setUltimoMovimiento(int mov);
	int getUltimoMovimiento();
	void SetVidaEnemigo(int VidaEnemigo);
	int GetVidaEnemigo();
	int GetIndiceEnemigo(int i, int j);
};

