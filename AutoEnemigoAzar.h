#ifndef AUTOENEMIGOAZAR_H
#define AUTOENEMIGOAZAR_H
#include "ObjetoGrafico.h"

class AutoEnemigoAzar : public ObjetoGrafico {
public:
	AutoEnemigoAzar(int x0,int y0,int vel);
	bool update(int direccion);
private:
	
};


#endif

