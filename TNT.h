#pragma once
#include "municion.h"

class TNT :
	public Municion
{
public:
	TNT(void);
	~TNT(void);

	int Dibuja(int alcance);
};

