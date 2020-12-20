#ifndef OBSTACULOFIJO_H
#define OBSTACULOFIJO_H
#include "ObjetoGrafico.h"

class ObstaculoFijo : public ObjetoGrafico {
public:
	ObstaculoFijo(int x0,int y0,int vel);
	bool update(int direccion);
private:
	
};

#endif

