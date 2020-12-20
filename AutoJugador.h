#ifndef AUTO_H
#define AUTO_H
#include <ctime>
#include "ObjetoGrafico.h"

class AutoJugador: public ObjetoGrafico {
protected:
	int pasoX;
	int pasoY;
	int xnueva;
	int ynueva;
	int maxLimitX;
	int maxLimitY;
	int minLimitX;
	int minLimitY;
	clock_t tempo; 
	clock_t paso; 
	int velocidad;
	
public:
	AutoJugador(int vel, int x0,int y0);
	bool update(int direccion);
	void setLimit(int, int, int, int);
};

#endif

