#ifndef OBJETOGRAFICO_H
#define OBJETOGRAFICO_H
#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>

using namespace std;
class ObjetoGrafico {
protected:
	//coordenadas del objeto
	int x; 
	int y;
	
	char matriz[16][9]; //matriz del elemento gráfico
	int color; // color del objeto
	int ancho;
	int alto;
	
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
	ObjetoGrafico(int v);
	void setLimit(int, int,int, int);
	void dibujar();
	void borrar();
	
	//metodo que resetea la posición del objeto gráfico al llegar a la base de la pantalla
	void reset(int x0, int y0);
	
	int getX(){return x;}
	int getY(){return y;}
	int getVel(){return velocidad;};
	
	//metodo para aumentar la velocidad en cada actualización de nivel
	void setVel();
	
	//metodo virtual para aplicar polimorfismo en el arreglo de objetos gráficos de la clase Juego
	virtual bool update(int direccion) {};
};

#endif

