#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "Graficador.h"
#include "Pila.h"

using namespace std;


void nave(punto p1,punto p2, int color){

	for(int i=0; i<11; i++){
	linea(p1, p2,color);
	p1.x++;
	p1.y++;
	p2.x--;
	p2.y++;
	}
}

void bala(punto p1, punto p2){
	
	for(int h=0; h<8; h++){
		linea(p1, p2, 4);
		p2.y++;
		p1.y++;
	}
}
// Abre la carpeta del proyecto
void marco(){
	punto p1, p2, p3, p4;
	
	p1.x=0;   p1.y=0;
	p2.x=630; p2.y=0;
	
	p3.x=0;   p3.y=400;
	p4.x=630; p4.y=400; 
	for(int i=0; i<80; i++){
		linea(p1, p2,14);
		linea(p3, p4,14);
		p1.y++; p2.y++;
		p3.y++; p4.y++;		
	}
}

void alien(punto p1, punto p2,int color){
	for(int i=0; i<=10; i++){
		linea(p1, p2, color);
		p1.x--;
		p1.y++;
		p2.x++;
		p2.y++;
	}	
}





