#pragma once
#include "Tablero.h"
#include "Celda.h"

class Mundo
{
	private:
		float cam_x;
		float cam_y;
		float cam_z;
		float ojo_x;
		float ojo_z;

		Tablero tablero;

	public:
		Mundo();
		~Mundo();

		void leerfichero(char*filename);
		void Inicializa();
		void Dibuja();
		void TeclaEspecial(unsigned char key);
		void Tecla(unsigned char key);
		void Mueve();

		int GetMiVida();
		int GetAlcance();
		int GetNumBombas();
		int GetNumeroEnemigos();
};
