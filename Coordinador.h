#pragma once
#include "Mundo.h" 

class Coordinador
{
private:
	Mundo mundo;

	enum Estado {INICIO, JUEGO, GAMEOVER, FIN}; 
	Estado estado;

public:
	Coordinador();
	~Coordinador();

	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
};

