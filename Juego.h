#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <ctime>
#include <conio2.h>
#include <windows.h>
#include "AutoJugador.h"
#include "AutoEnemigo.h"
#include "AutoEnemigoAzar.h"
#include "ObstaculoFijo.h"

using namespace std;
class Juego {
public:
	Juego();
	void Jugar();
	void DibujarPista();
	
	//método que maximiza la ventana de la consola. 
	//El tamaño de la consola para el que está optimizado el diseño es 168 de ancho x 50 de alto
	void Maximizar();
	
	bool CheckColision(ObjetoGrafico *obj1, ObjetoGrafico *obj2);
	void ResetObj();
	void MostrarPuntos();
	void MostrarColisiones();
	void ActualizarNivel();
private:
	// arreglo que contiene todos los objetos gráficos del juego:
	ObjetoGrafico *arrayObjetos[4];
	// Posición [0] = auto del jugador (color magenta)
	// Posición [1] = auto enemigo de recorrido fijo (color amarillo)
	// Posición [0] = auto enemigo de recorrido variable (color rojo)
	// Posición [0] = objeto tipo mancha de aceite en la ruta de recorrido fijo (color marron)
	
	int x, x1, x2;
	int y, y1, y2;
	int alto, ancho;
	int puntaje=0;
	int colisiones=0;
	int nivel=1;
	
};

#endif

