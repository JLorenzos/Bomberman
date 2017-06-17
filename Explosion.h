#pragma once

class Explosion
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	int lado;
	bool primeraVez;

public:
	Explosion(void);
	~Explosion(void);

	void Dibuja(int alcance, int i, int j);
};

