#include "ObjetoGrafico.h"

ObjetoGrafico::ObjetoGrafico(int vel){

	velocidad = vel;
	paso=CLOCKS_PER_SEC/velocidad; 
	tempo=clock(); 
	
}

void ObjetoGrafico::reset(int x0, int y0){
	
	borrar();
	y = y0;
	x = x0;
}

void ObjetoGrafico::setVel(){
	
	velocidad+=4;
	paso=CLOCKS_PER_SEC/velocidad; 
}

void ObjetoGrafico::dibujar(){
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			textcolor(color);	
			gotoxy(x+i,y+k);
			cout<<(char) matriz[i][k]; 
		}
	}
}

void ObjetoGrafico::borrar(){
	
	for (int i= 0; i<ancho; i++){
		for (int k= 0; k<alto; k++){
			gotoxy(x+i,y+k);
			cout<<" ";
		}
	}
	
}


void ObjetoGrafico::setLimit(int x0, int x1,int y0, int y1){
	maxLimitX = x1;
	maxLimitY = y1;
	minLimitX = x0;
	minLimitY = y0;
	
}
