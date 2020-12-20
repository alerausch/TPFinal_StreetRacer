#include<iostream>
#include "Juego.h"

using namespace std;

int main (int argc, char *argv[]) {
	
	Juego *juego = new(Juego);
	juego->Maximizar();
	juego->DibujarPista();
	juego->Jugar();
	
	return 0;
}

