#include "AutoEnemigo.h"

AutoEnemigo::AutoEnemigo(int vel, int x0, int y0):ObjetoGrafico(vel){
	
	matriz[0][0]=0;    matriz[0][1]=0;    matriz[0][2]=0;    matriz[0][3]=0;   matriz[0][4]=0;   matriz[0][5]=0;   matriz[0][6]=219;   matriz[0][7]=219;  matriz[0][8]=219; 
	matriz[1][0]=220;  matriz[1][1]=219;  matriz[1][2]=223;  matriz[1][3]=0;   matriz[1][4]=0;   matriz[1][5]=0;   matriz[1][6]=219;   matriz[1][7]=219;  matriz[1][8]=219;
	matriz[2][0]=220;  matriz[2][1]=219;  matriz[2][2]=223;  matriz[2][3]=0;   matriz[2][4]=0;   matriz[2][5]=0;   matriz[2][6]=219;   matriz[2][7]=219;  matriz[2][8]=219;
	matriz[3][0]=0;    matriz[3][1]=219;  matriz[3][2]=0;    matriz[3][3]=0;   matriz[3][4]=0;   matriz[3][5]=0;   matriz[3][6]=0;     matriz[3][7]=219;  matriz[3][8]=0;
	matriz[4][0]=0;    matriz[4][1]=219;  matriz[4][2]=0;    matriz[4][3]=0;   matriz[4][4]=0;   matriz[4][5]=0;   matriz[4][6]=0;     matriz[4][7]=219;  matriz[4][8]=201;
	matriz[5][0]=0;    matriz[5][1]=219;  matriz[5][2]=0;    matriz[5][3]=0;   matriz[5][4]=0;   matriz[5][5]=0;   matriz[5][6]=0;     matriz[5][7]=219;  matriz[5][8]=205;
	matriz[6][0]=219;  matriz[6][1]=219;  matriz[6][2]=219;  matriz[6][3]=219; matriz[6][4]=219; matriz[6][5]=219; matriz[6][6]=219;   matriz[6][7]=219;  matriz[6][8]=205;
	matriz[7][0]=219;  matriz[7][1]=219;  matriz[7][2]=219;  matriz[7][3]=219; matriz[7][4]=219; matriz[7][5]=219; matriz[7][6]=219;   matriz[7][7]=219;  matriz[7][8]=202;
	matriz[8][0]=219;  matriz[8][1]=219;  matriz[8][2]=219;  matriz[8][3]=219; matriz[8][4]=219; matriz[8][5]=219; matriz[8][6]=219;   matriz[8][7]=219;  matriz[8][8]=202;
	matriz[9][0]=219;  matriz[9][1]=219;  matriz[9][2]=219;  matriz[9][3]=219; matriz[9][4]=219; matriz[9][5]=219; matriz[9][6]=219;   matriz[9][7]=219;  matriz[9][8]=205;
	matriz[10][0]=0;   matriz[10][1]=219; matriz[10][2]=0;   matriz[10][3]=0;  matriz[10][4]=0;  matriz[10][5]=0;  matriz[10][6]=0;    matriz[10][7]=219; matriz[10][8]=205;
	matriz[11][0]=0;   matriz[11][1]=219; matriz[11][2]=0;   matriz[11][3]=0;  matriz[11][4]=0;  matriz[11][5]=0;  matriz[11][6]=0;    matriz[11][7]=219; matriz[11][8]=187;
	matriz[12][0]=0;   matriz[12][1]=219; matriz[12][2]=0;   matriz[12][3]=0;  matriz[12][4]=0;  matriz[12][5]=0;  matriz[12][6]=0;    matriz[12][7]=219; matriz[12][8]=0;
	matriz[13][0]=220; matriz[13][1]=219; matriz[13][2]=223; matriz[13][3]=0;  matriz[13][4]=0;  matriz[13][5]=0;  matriz[13][6]=219;  matriz[13][7]=219; matriz[13][8]=219;
	matriz[14][0]=220; matriz[14][1]=219; matriz[14][2]=223; matriz[14][3]=0;  matriz[14][4]=0;  matriz[14][5]=0;  matriz[14][6]=219;  matriz[14][7]=219; matriz[14][8]=219;
	matriz[15][0]=0;   matriz[15][1]=0;   matriz[15][2]=0;   matriz[15][3]=0;  matriz[15][4]=0;  matriz[15][5]=0;  matriz[15][6]=219;  matriz[15][7]=219; matriz[15][8]=219;
	
	ancho = 16;
	alto = 9;
	color = 14;	
	pasoY = 2;
	x = x0;
	y = y0;
	xnueva = x0;
	ynueva = y0;
	
}

bool AutoEnemigo::update(int direccion){

	if (y<39){
		if(tempo+paso<clock()){
			borrar();
			y += pasoY;
			if (y>39){
				y=40;
			}
			dibujar();
			tempo=clock(); 
		}
		return true;
	}else{
		reset(rand() % 52 + 16,0);
		return false;
	};
}

		

