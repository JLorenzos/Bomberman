#pragma once

class Bonus
{
private:
	float anguloCuboX;
	float anguloCuboY;
	float anguloEsfera;

public:
	Bonus(void);
	~Bonus(void);

	bool crearBonus();
	void Dibuja();
	void mueve();
	int Efecto();
};

