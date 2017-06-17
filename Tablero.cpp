#include "Tablero.h"
#include "ETSIDI.h"
#include "glut.h"
#include <iostream>
#include <fstream>
using namespace std;

Tablero::Tablero()
{
}

Tablero::~Tablero()
{
}

void Tablero::creaLaberinto()
{
	laberinto = new Celda**[numfilas];
	for (int i = 0; i < numfilas; i++)
		laberinto[i] = new Celda*[numcolumnas];
}

void Tablero::leerfichero(istream &is)
{
	is >> numfilas >> numcolumnas;
	creaLaberinto();

	int queEres;
	for (int i = 0;i < numfilas;i++){
		for (int j = 0; j< numcolumnas; j++) {
			is >> queEres;
			switch(queEres)
			{
				case 0:
					laberinto[i][j] = new Suelo;	
					break;
				case 6:
					laberinto[i][j] = new Bloque;	
					break;
				case 8:
					laberinto[i][j] = new Muro;		
					break;
				default:
					leerPersonajeYEnemigo(queEres, i, j);
			}
		}
	}
}

void Tablero::leerPersonajeYEnemigo(int queEres, int i, int j)
{
	switch(queEres)
	{
		case 1:
			laberinto[i][j] = new Suelo;
			personaje.SetPosicion_x(i);
			personaje.SetPosicion_z(j);
			break;
		case 7:
			laberinto[i][j] = new Suelo;
			Enemigo *e = new Enemigo;
			enemigos.Agregar(e,i,j);
			break;		
	}
}

void Tablero::Dibuja()
{
	int x = 0;
	int z = 0;

	for (int i = 0; i< numfilas; i++) {
		for (int j = 0; j< numcolumnas; j++) {

			glTranslated(x, 0, z);

			laberinto[i][j]->Dibuja();

			if(personaje.compruebaPos(i, j)){
				if(!personaje.SerInmune())
					personaje.Dibuja();
				else{
					int estado = personaje.Parpadeo();
					if(personaje.Parpadeo()==0)
						personaje.Dibuja();
				}
			}
			if(enemigos.compruebaPos(i, j)){
				enemigos.Dibuja(enemigos.GetIndiceEnemigo(i,j));
			}
			if(laberinto[i][j]->GetTieneBonus()){
				bonus.Dibuja();
			}
			if(bombas.compruebaPos(i, j)){
				int estado = bombas.Dibuja(bombas.GetIndiceBomba(i,j));
				int YaMeMataste=0;
				if(estado== 1) // estado es Explosion
				{
					//estallar bloques y pregunta por personaje o enemigos afectados
					int alcance = bombas.GetAlcance(); //como minimo siempre es 1
					DestruyeTablero(i,j, alcance, true);
					if (!personaje.SerInmune())
						personaje.ChequeaDaños(i,j); //nota: solo hacemos este chequea aqui.
													//es la poscion encima de la boba (i,j), las demas las puede leer en la funcion destruye tablero
				}
				if(estado== 2) // estado es FIN
				{
					bombas.Eliminar(bombas.GetIndiceBomba(i,j));
				}
			}
			if(tnt.compruebaPos(i, j)){
				int estado = tnt.Dibuja(tnt.GetIndiceBomba(i,j));
				int YaMeMataste=0;
				if(estado== 1) // estado es Explosion
				{
					//estallar bloques y pregunta por personaje o enemigos afectados
					int alcance = tnt.GetAlcance(); 
					DestruyeTablero(i,j,alcance,false);
				}
				if(estado== 2) // estado es FIN
				{
					tnt.Eliminar(tnt.GetIndiceBomba(i,j));
				}
			}
				
			glTranslated(0, 0, 0);

			x = 5;
			z = 0;
		}
		x = -5*(numcolumnas-1);
		z = 5;
	}
}

void Tablero::DestruyeTablero(int i, int j, int alcance, bool esBomba)
{
	int falloCasoIzq=0;
	int falloCasoDer=0;
	int falloCasoUp=0;
	int falloCasoDown=0;

	for (int x=1; x<=alcance; x++)
	{ 
	int mira=0;
	do{
		switch(mira)
		{
		case 0:
			if (falloCasoIzq==1 || !laberinto[i-x][j]->GetSePuedeRomper() && !laberinto[i-x][j]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
			{
				falloCasoIzq=1;

			}
			else if (laberinto[i-x][j]->GetSePuedeRomper() && falloCasoIzq==0)
			{
				delete laberinto[i-x][j];
				laberinto[i-x][j] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i-x][j]->SetTieneBonus(true);
			}
			else if (falloCasoIzq==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaDaños(i-x,j);
				//comprobacion que hace enemigo para saber si pisa explosion
				if (esBomba)
					enemigos.ChequeaExplosion(i-x,j);
			}
			mira=1;
			break;

		case 1:
			if (falloCasoDer==1 || !laberinto[i+x][j]->GetSePuedeRomper() && !laberinto[i+x][j]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
				{
					falloCasoDer=1;
				}
			else if (laberinto[i+x][j]->GetSePuedeRomper() && falloCasoDer==0)
			{
				delete laberinto[i+x][j];
				laberinto[i+x][j] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i+x][j]->SetTieneBonus(true);
			}
			else if(falloCasoDer==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaDaños(i+x,j);
				//comprobacion que hace enemigo para saber si pisa explosion
				if (esBomba)
					enemigos.ChequeaExplosion(i+x,j);
			}
			mira=2;
			break;

		case 2:
			if (falloCasoUp==1 || !laberinto[i][j-x]->GetSePuedeRomper() && !laberinto[i][j-x]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
			{
				falloCasoUp=1;
			}
			else if (laberinto[i][j-x]->GetSePuedeRomper() && falloCasoUp==0)
			{
				delete laberinto[i][j-x];
				laberinto[i][j-x] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i][j-x]->SetTieneBonus(true);
			}
			else if (falloCasoUp==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaDaños(i,j-x);
				//comprobacion que hace enemigo para saber si pisa explosion
				if (esBomba)
					enemigos.ChequeaExplosion(i,j-x);
			}
			mira=3;
			break;

		case 3:
			if (falloCasoDown==1 || !laberinto[i][j+x]->GetSePuedeRomper() && !laberinto[i][j+x]->GetSePuedePasar()) //si pasa una de las dos cosas estoy en muro
				{
					falloCasoDown=1;
				}
			else if (laberinto[i][j+x]->GetSePuedeRomper() && falloCasoDown==0)
			{
				delete laberinto[i][j+x];
				laberinto[i][j+x] = new Suelo;
				if (bonus.crearBonus())
					laberinto[i][j+x]->SetTieneBonus(true);
			}
			else if (falloCasoDown==0 && personaje.GetInmunidad()==0)
			{
				//comprobacion que hace personaje para saber si pisa explosion
				personaje.ChequeaDaños(i,j+x);
				//comprobacion que hace enemigo para saber si pisa explosion
				if (esBomba)
					enemigos.ChequeaExplosion(i,j+x);
			}
			mira=4;
			break;
		}
	}while(mira!=4);
	}
}

int Tablero::compruebaLab(int x, int z)
{
	/*Devuelve:
		0-> Si no hay nada, hay suelo
		1-> Hay muro, bloque o bomba
		2-> Hay bonus
	*/
	
	if(!laberinto[x][z]->GetSePuedePasar()){
		return 1;
	}
	else{
		if(bombas.compruebaPos(x,z) || tnt.compruebaPos(x,z)){
			return 3;
		}
		if(laberinto[x][z]->GetTieneBonus()){
			return 2;
		}
	return 0;
	}
}

void Tablero::Mueve()
{
	bonus.mueve();
	bool siTNT = false;

	//Enemigo mueve
	for(int i=0; i<enemigos.GetNumeroEnemigos();i++){
		int p1,p2;  //esta es la posicion a la que queremos movernos en cada caso, la devuelve el enemigo
		enemigos.CalculaSiguiente(i);
		p1 = enemigos.GetPosicionSiguiente_x(i);
		p2 = enemigos.GetPosicionSiguiente_z(i);
		
		int comprobacion = compruebaLab(p1,p2); //si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el enemigo se movera.
		switch(comprobacion)
		{
			case 0: //pasa el enemigo
				enemigos.SetPosicion(i,p1,p2);
				
				//En dispara estoy metiendo tres valores: que enmigo es (int indice), puede o no puede disparar(bool si_no_hay_nada_enetre_jugador_y_enemigo_dispara), hacia donde va el disparo (int direccion)
				siTNT = enemigos.Dispara(i,CeldasEntreEnemigoyPresonaje_ejeX(p1,p2),PosicionesRelativas(p1,p2));
				siTNT = siTNT || enemigos.Dispara(i,CeldasEntreEnemigoyPresonaje_ejeY(p1,p2),PosicionesRelativas(p1,p2));
				
				if(siTNT){
					PonerTnt();	
				}
				personaje.ChequeaDaños(p1,p2);
				
				break;	
			case 1://muro, bloque, bomba o bonus
				break;
		}
	}
}

//Para el movimiendo del personaje
void Tablero::TeclaEspecial(unsigned char key)	
{
	int p1,p2;  //esta es la posicion a la que queremos movernos en cada caso, la devuelve el personaje
	personaje.CalculaSiguiente(key);
	p1 = personaje.GetPosicionSiguiente_x();
	p2 = personaje.GetPosicionSiguiente_z();
	
	//si combrueba, mediante una lectura de laberinto, que podemos acceder a la casilla que pretendemos, el personaje se movera.
	int comprobacion = compruebaLab(p1,p2);
	switch(comprobacion)
	{
		case 0: //pasa el personaje
			personaje.direccionMovimiento(PosicionesRelativas(p1,p2));
			personaje.SetPosicion_x(p1);
			personaje.SetPosicion_z(p2);
			break;	
		case 1://muro o bloque
			break;

		case 2://bonus
			personaje.direccionMovimiento(PosicionesRelativas(p1,p2));
			personaje.SetPosicion_x(p1);
			personaje.SetPosicion_z(p2);
			EfectoBonus();
			laberinto[p1][p2]->SetTieneBonus(false);
			break;

		case 3://patada
			if (personaje.GetPatada()){
				int direccionMovimiento = PosicionesRelativas(p1,p2); //p1 y p2 son las posiciones de la bomba que impidio moverse al personaje
				int indiceBomba = bombas.GetIndiceBomba(p1,p2);
				
				bombas.Muevete(direccionMovimiento, indiceBomba);
			}
			break;
	}
}

void Tablero::PonerBomba()
{
	int i=personaje.GetPosicion_x();
	int j=personaje.GetPosicion_z();

	Bomba* bomba = new Bomba();
	bombas.Agregar(bomba,i,j);
}

void Tablero::PonerTnt()
{
	int aux = enemigos.EnemigoVerde();
	if(aux != -1){
		int i=enemigos.GetEnemPos_x(aux);
		int j=enemigos.GetEnemPos_z(aux);

		TNT* tntaux = new TNT();
		tnt.Agregar(tntaux,i,j);
	}
}

int Tablero::PosicionesRelativas(int p1, int p2) //me dice la posicion de personaje respecto a la bomba/ tamb respecto a la posicion anterior de personaje
{
	if(p1==(personaje.GetPosicion_x()-1) && p2==personaje.GetPosicion_z() )//el personaje esta a la izquierda de la bomba
		return 0;
	if(p1==(personaje.GetPosicion_x()+1) && p2==personaje.GetPosicion_z() )//el personaje esta a la derecha de la bomba
		return 1;
	if(p1==personaje.GetPosicion_x() && p2==(personaje.GetPosicion_z()-1) )//el personaje esta por encima de la bomba
		return 2;
	if(p1==personaje.GetPosicion_x() && p2==(personaje.GetPosicion_z()+1) )//el personaje esta por debajo de la bomba
		return 3;
}

int Tablero::PosicionesRelativasEnemigo(int p1, int p2) //para saber si enemigo y personaje estan en el mismo eje
{
	if(p1==personaje.GetPosicion_x())
	{ 
		if(p2<personaje.GetPosicion_z())
		{
			return 0;
		}
		else{
			return 1;
		}
	}
	else if(p2==personaje.GetPosicion_z())
	{
		if(p1<personaje.GetPosicion_x())
		{
			return 2;
		}
		else{
			return 3;
		}
	}
}

void Tablero::EfectoBonus()
{
	int efecto = bonus.Efecto();
	bool moneda= ETSIDI::lanzaMoneda();
	switch (efecto)
	{
		case 0:
			if(bombas.GetTopeBombas()<10)
				bombas.SetTopeBombas(bombas.GetTopeBombas() + 1);
			break;	
		case 1:
			if(personaje.GetMiVida()<5){
				personaje.SetMiVida(personaje.GetMiVida() + 1);
			}
			else 
				if(moneda=true)
				if(bombas.GetTopeBombas()<10){
					bombas.SetTopeBombas(bombas.GetTopeBombas() + 1);
				}	
				else 
				if(bombas.GetAlcance()<10){
					bombas.SetAlcance(bombas.GetAlcance() + 1);
				}
			break;
		case 2:
			if(bombas.GetAlcance()<10)
				bombas.SetAlcance(bombas.GetAlcance() + 1);
			break;
	}
}

bool Tablero::CeldasEntreEnemigoyPresonaje_ejeX(int i, int j)
{
	int desde = j;
	int hasta = personaje.GetPosicion_z();

	if(i == personaje.GetPosicion_x()) //puedo seguir un camino recto para ir desde enemigo hasta la posicion de personaje?
	{
		if(desde > hasta){
			int aux = desde;
			desde = hasta;
			hasta = aux;
		}
		for(int k=desde;k<hasta;k++)
		{
			if(!laberinto[i][k]->GetSePuedePasar()){ //obstaculo en el eje de las x //no hay linea directa con personaje => no disparo
				return false;
			}

		}
		return true;
	}
	else{
		return false;
	}
}

bool Tablero::CeldasEntreEnemigoyPresonaje_ejeY(int i, int j)
{
	int desde = i;
	int hasta = personaje.GetPosicion_x();

	if(j == personaje.GetPosicion_z()) //puedo seguir un camino recto para ir desde enemigo hasta la posicion de personaje?
	{
		if(desde > hasta){
			int aux = desde;
			desde = hasta;
			hasta = aux;
		}
		for(int k=desde;k<hasta;k++)
		{
			if(!laberinto[k][j]->GetSePuedePasar()){ //obstaculo en el eje de las x //no hay linea directa con personaje => no disparo
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}

/////////SETs y Gets//////////

int Tablero::GetMiVida(){
	return personaje.GetMiVida();
}

int Tablero::GetNumeroEnemigos(){
	return enemigos.GetNumeroEnemigos();
}

int Tablero::GetAlcance(){
	return bombas.GetAlcance();
}

int Tablero::GetMaxBomb(){
	return bombas.GetTopeBombas();
}
