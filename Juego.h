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
	
	//m�todo que maximiza la ventana de la consola. 
	//El tama�o de la consola para el que est� optimizado el dise�o es 168 de ancho x 50 de alto
	void Maximizar();
	
	bool CheckColision(ObjetoGrafico *obj1, ObjetoGrafico *obj2);
	void ResetObj();
	void MostrarPuntos();
	void MostrarColisiones();
	void ActualizarNivel();
private:
	// arreglo que contiene todos los objetos gr�ficos del juego:
	ObjetoGrafico *arrayObjetos[4];
	// Posici�n [0] = auto del jugador (color magenta)
	// Posici�n [1] = auto enemigo de recorrido fijo (color amarillo)
	// Posici�n [0] = auto enemigo de recorrido variable (color rojo)
	// Posici�n [0] = objeto tipo mancha de aceite en la ruta de recorrido fijo (color marron)
	
	int x, x1, x2;
	int y, y1, y2;
	int alto, ancho;
	int puntaje=0;
	int colisiones=0;
	int nivel=1;
	
};

#endif

