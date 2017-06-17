#include "Coordinador.h"
#include "ETSIDI.h"
#include "glut.h"

Coordinador::Coordinador()
{
	estado=INICIO;  
}

Coordinador::~Coordinador()
{
}

void Coordinador::Dibuja()
{
	if(estado==INICIO)
	{
		gluLookAt(0, 7.5, 30,  
				0.0, 7.5, 0.0,      
				0.0, 1.0, 0.0);      

	ETSIDI::setTextColor(1,1,0);
	ETSIDI::setFont("fuentes/MAIN.otf",34); //tamaño de letra
	ETSIDI::printxy("Bomberman", -5,12); //posicion donde lo escribe
	
	ETSIDI::setTextColor(1,1,1);
	ETSIDI::setFont("fuentes/MAIN.otf",16); //tamaño de letra
	ETSIDI::printxy("ELIJA EL NIVEL", -5,8); 
		
	ETSIDI::setFont("fuentes/MAIN.otf",12);
	ETSIDI::printxy("PULSE LA TECLA -F- PARA FACIL", -5,6);
	ETSIDI::printxy("PULSE LA TECLA -M- PARA MEDIO", -5,5);
	ETSIDI::printxy("PULSE LA TECLA -D- PARA DIFICIL", -5,4);

	ETSIDI::printxy("Lucia Estrada y Alvaro Gonzalez",1,1);
	}

	else if(estado==JUEGO)
	{
		mundo.Dibuja();

		gluLookAt(0, 7.5, 30,  
				0.0, 7.5, 0.0,   
				0.0, 1.0, 0.0); 

		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/MAIN.otf",11);
		ETSIDI::printxy("VIDA:",-51,61);
		
		int l =mundo.GetMiVida();
		switch(l)
		{
		case 1:
			ETSIDI::printxy("1",-48,61);
			break;
		case 2:
			ETSIDI::printxy("2",-48,61);
			break;
		case 3:
			ETSIDI::printxy("3",-48,61);
			break;
		case 4:
			ETSIDI::printxy("4",-48,61);
			break;
		case 5:
			ETSIDI::printxy("5",-48,61);
			break;
		}

		if (l>2){
			ETSIDI::printxy("BONUS",-56,61);
			ETSIDI::printxy("PATADA",-57,59);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("Images/Zapas.png").id);
			glDisable(GL_LIGHTING);
			glTranslatef(-10,0,0);
			glBegin(GL_QUADS);
	
			glTexCoord2f(1.0f, 0.0f); glVertex3f(3, 0,  3);	
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 0, 0,  3);	
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0,  3,  3);	
			glTexCoord2f(0.0f, 0.0f); glVertex3f(3,  3,  3);

			glEnd();
			glTranslatef(10,0,0);
			glDisable(GL_TEXTURE_2D);
			glEnable(GL_LIGHTING);
		}
		
		ETSIDI::printxy("Nº DE BOMBAS:",-41,61);

		int b= mundo.GetNumBombas();
		switch(b)
		{
		case 1:
			ETSIDI::printxy("1",-33,61);
			break;
		case 2:
			ETSIDI::printxy("2",-33,61);
			break;
		case 3:
			ETSIDI::printxy("3",-33,61);
			break;
		case 4:
			ETSIDI::printxy("4",-33,61);
			break;
		case 5:
			ETSIDI::printxy("5",-33,61);
			break;
		case 6:
			ETSIDI::printxy("6",-33,61);
			break;
		case 7:
			ETSIDI::printxy("7",-33,61);
			break;
		case 8:
			ETSIDI::printxy("8",-33,61);
			break;
		case 9:
			ETSIDI::printxy("9",-33,61);
			break;
		case 10:
			ETSIDI::printxy("MAX",-33,61);
			break;
		}

		ETSIDI::printxy("ALCANCE:",-26,61);

		int a= mundo.GetAlcance();
		switch(a)
		{
		case 1:
			ETSIDI::printxy("1",-20,61);
			break;
		case 2:
			ETSIDI::printxy("2",-20,61);
			break;
		case 3:
			ETSIDI::printxy("3",-20,61);
			break;
		case 4:
			ETSIDI::printxy("4",-20,61);
			break;
		case 5:
			ETSIDI::printxy("5",-20,61);
			break;
		case 6:
			ETSIDI::printxy("6",-20,61);
			break;
		case 7:
			ETSIDI::printxy("7",-20,61);
			break;
		case 8:
			ETSIDI::printxy("8",-20,61);
			break;
		case 9:
			ETSIDI::printxy("9",-20,61);
			break;
		case 10:
			ETSIDI::printxy("MAX",-20,61);
			break;

		}

	}


	else if(estado==GAMEOVER)
	{
		gluLookAt(0, 7.5, 30,  
				0.0, 7.5, 0.0,   
				0.0, 1.0, 0.0); 

		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/MAIN.otf",16);
		ETSIDI::printxy("GAMEOVER: Has perdido",-5,10);
		ETSIDI::printxy("Pulsa -C- para cerrar",-5,5);
	}
	else if(estado==FIN)
	{
		gluLookAt(0, 7.5, 30, 
				0.0, 7.5, 0.0,  
				0.0, 1.0, 0.0); 

		ETSIDI::setFont("fuentes/MAIN.otf",16);
		ETSIDI::printxy("ENHORABUENA",-5,10); 
		ETSIDI::printxy("¡Cumpliste tu objetivo!",-5,9);
		ETSIDI::printxy("Pulsa -C- para cerrar",-5,7);
	}
}	

 void Coordinador::Tecla(unsigned char key)
 {  
	 if(estado==INICIO) 
	 {   
		 //NivelDificultad
		 switch (key)  //simbolo      
		{
			case 'f': {   //case 'FACIL': 
				mundo.Inicializa();
				mundo.leerfichero("Level/Facil.txt");
				estado=JUEGO;
				break;
			}
			
			case 'm': {	  //case 'MEDIO': 
				mundo.Inicializa();
				mundo.leerfichero("Level/Medio.txt");
				estado=JUEGO;
				break;
			}
		
			case 'd': {	  //case 'DIFICIL': 
				mundo.Inicializa();
				mundo.leerfichero("Level/Dificil.txt");
				estado=JUEGO;
				break;

			default:
				exit(0);
			}
		}
	}

	 else if(estado==JUEGO)
	 {
		 mundo.Tecla(key);
	 }

	else if(estado==GAMEOVER)
	 {  
		 if(key=='c')
			 exit(0);
	 }  
	 
	 else if(estado==FIN)
	 {  
		 if(key=='c') 
			 exit(0);
	 }
 }

 void Coordinador::TeclaEspecial(unsigned char key)
 {  
	 if(estado==JUEGO)
		 mundo.TeclaEspecial(key);
 }

 void Coordinador::Mueve()
 {
	 if(estado==JUEGO)
		 mundo.Mueve();
		if(mundo.GetMiVida()==0)
		{
			estado=GAMEOVER;
		}
		if(estado!=INICIO && mundo.GetNumeroEnemigos()==0)
		{
			estado=FIN;
		}

}
