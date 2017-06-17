#pragma once

#include "Muro.h"
#include "Bloque.h"
#include "Suelo.h"
#include "Personaje.h"
#include "ListaEnemigos.h"
#include "ListaMunicion.h"
#include "Bonus.h"
#include "Bomba.h"
#include "TNT.h"

class Tablero
{
private:
	int numfilas;
	int numcolumnas;
	Celda*** laberinto;
	Personaje personaje;
	ListaEnemigos enemigos;
	ListaMunicion bombas;
	ListaMunicion tnt;
	Bonus bonus;

public:
	Tablero();
	~Tablero();

	void creaLaberinto();
	void leerfichero(istream &is);
	void leerPersonajeYEnemigo(int queEres, int i, int j);
	void Dibuja();
	void DestruyeTablero(int i, int j, int alcance, bool esBomba);
	int compruebaLab(int x, int z);
	void Mueve();
	void TeclaEspecial(unsigned char key);
	void PonerBomba();
	void PonerTnt();
	int PosicionesRelativas(int p1, int p2);
	int PosicionesRelativasEnemigo(int p1, int p2);
	void EfectoBonus();
	bool CeldasEntreEnemigoyPresonaje_ejeX(int i, int j);
	bool CeldasEntreEnemigoyPresonaje_ejeY(int i, int j);

	int GetMiVida();
	int GetNumeroEnemigos();
	int GetAlcance();
	int GetMaxBomb();
};
