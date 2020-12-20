#ifndef AUTOENEMIGO_H
#define AUTOENEMIGO_H
#include "AutoJugador.h"

class AutoEnemigo : public ObjetoGrafico {
public:
	AutoEnemigo(int x0,int y0,int vel);
	bool update(int direccion);
private:
	
};

#endif

