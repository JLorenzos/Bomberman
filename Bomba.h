#pragma once
#include "municion.h"

class Bomba :
	public Municion
{
public:
	Bomba(void);
	~Bomba(void);

	int Dibuja(int alcance);
};

