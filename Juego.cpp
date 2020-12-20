#include "Juego.h"

Juego::Juego() {
	// se construyen los objetos en el arreglo de objetos gráficos
	arrayObjetos[0] = new AutoJugador(4, 16, 39);
	arrayObjetos[0]->setLimit(1,78,40,40);
	
	arrayObjetos[1]= new AutoEnemigo(5, 51, 0);
	arrayObjetos[1]->setLimit(1,78,1,40);
	
	srand (time(NULL));
	int xAzar = rand() % 52 + 16;
	
	arrayObjetos[2] = new AutoEnemigoAzar(5, xAzar, 0);
	arrayObjetos[2]->setLimit(1,78,1,40);
	
	arrayObjetos[3] = new ObstaculoFijo(5, xAzar, 0);
	arrayObjetos[3]->setLimit(1,78,1,40);
	
}

void Juego::ResetObj(){
	//pausa de 1 segundo luego de una colisión
	Sleep(1000);
	for (int i=1; i<4; i++){
		arrayObjetos[i]->reset(rand() % 52 + 16,0);
	}
}

void Juego::DibujarPista(){
	textcolor(2);
	for (x= 1; x<16; x++){
		for (y= 1; y<50; y++){
			gotoxy(x,y);
			if (x==15){
				textcolor(15);
				cout<<(char) 219;
				textcolor(2);
			}else{
				cout<<(char) 219;
			}
		}
	}
	for (x= 83; x<98; x++){
		for (y= 1; y<50; y++){
			gotoxy(x,y);
			if (x==83){
				textcolor(15);
				cout<<(char) 219;
				textcolor(2);
			}else{
				cout<<(char) 219;
			}
		}
	}
	for (x= 98; x<=168; x++){
		for (y= 1; y<51; y+=23){
			if (y==47){
				y = 48;
			}
			gotoxy(x,y);
			cout<<(char) 219;
		}
	}
	textcolor(15);
	gotoxy(100,2);
	cout<<"PUNTAJE: 0"<<endl;
	gotoxy(100,4);
	cout<<"COLISIONES: 0";
	gotoxy(100,6);
	cout<<"NIVEL: 1";
	gotoxy(100,25);
	cout<<"INSTRUCCIONES: ";
	gotoxy(100,27);
	cout<<"(*) Utilizar las teclas de direccion para mover el auto.";
	gotoxy(100,28);
	cout<<"    Tecla <- : el auto se mueve a la izquierda.";
	gotoxy(100,29);
	cout<<"    Tecla -> : el auto se mueve a la derecha.";
	gotoxy(100,31);
	cout<<"(*) Para pausar el juego realizar un clic izquierdo con el mouse en";
	gotoxy(100,32);
	cout<<"    cualquier lugar de la pantalla.";
	gotoxy(100,34);
	cout<<"(*) Para continuar con el juego presionar cualquier tecla.";
	gotoxy(100,36);
	cout<<"(*) Para salir del juego presionar la tecla 'q'.";
	gotoxy(100,38);
	textcolor(2);
	cout<<"(*) Reglamento: cada 20 obstaculos superados se sube de nivel.";
}

void Juego::Maximizar(){
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
	return;
}

bool Juego::CheckColision(ObjetoGrafico *obj1, ObjetoGrafico *obj2){
	x1 = obj1->getX();
	y1 = obj1->getY();
	
	x2 = obj2->getX();
	y2 = obj2->getY();
	
	ancho=16;
	alto= 9;
	
	if(x1 > (x2 - ancho) && x1 < (x2 + ancho) && y1 > (y2 - alto) && y1 < (y2 + alto)){
		return true;
	}
	return false;
}

void Juego::MostrarPuntos(){
	gotoxy(109,2);
	textcolor(15);
	puntaje++;
	cout<<puntaje;
}

void Juego::MostrarColisiones(){
	gotoxy(112,4);
	textcolor(15);
	colisiones++;
	cout<<colisiones;
}

void Juego::ActualizarNivel(){
	
	for (int i=1; i<4; i++){
		arrayObjetos[i]->setVel();
	}
	
	gotoxy(107,6);
	textcolor(15);
	nivel++;
	cout<<nivel;
	gotoxy(40,20);
	textcolor(2);
	cout<<"ALCANZASTE EL NIVEL: "<<nivel;
	Sleep(1000);
	for (int i=40; i<63; i++){
		gotoxy(i,20);
		cout<<" ";
	}
}

void Juego::Jugar(){
	
	bool flag = true;
	//el primer elemento en aparecer se elige al azar
	int azar = rand() % 3+1;
	arrayObjetos[azar]->dibujar();
	
	//bucle principal del juego
	while(flag) {
		if (! arrayObjetos[azar]->update(arrayObjetos[0]->getX())){
			azar = rand() % 3+1;
			MostrarPuntos();
			if (puntaje/5 == nivel*4 && puntaje%5 == 0){
				ActualizarNivel();
			}
		}
		//condicional que lee dirección del auto del jugador o tecla de salida del juego
		if(kbhit()) { 
			int tecla=getch();
			
			switch(tecla)
			{
			case 75: //izquierda
				flag = arrayObjetos[0]->update(1);
				break;
			case 77: //derecha
				flag = arrayObjetos[0]->update(2);
				break;
			case 81: case 113: //salir - tecla "q" o "Q"
				flag = false;
				break;
			}
		}
		//condicional que verifica colisión de objetos con el auto del jugador
		if (CheckColision(arrayObjetos[azar],arrayObjetos[0])){
			MostrarColisiones();
			ResetObj();
			azar = rand() % 3+1;
			arrayObjetos[0]->dibujar();
		}
		
	}

	
}
