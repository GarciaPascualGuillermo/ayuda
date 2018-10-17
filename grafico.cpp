#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "Graficador.h"
#include "Pila.h"

using namespace std;

void nave(){
	punto p1, p2;
	p1.x=100;  p1.y=100;  
    p2.x=120;    p2.y=100;
	for(int i=0; i<19; i++){
	linea(p1, p2,2);
	p1.y--;
	p2.y--;
}
punto m1, m2, m3, m4;
m1.x=100; m1.y=101;
m2.x=105; m2.y=101;
m3.x=115; m3.y=101;
m4.x=120; m4.y=101;

for(int j=0; j<10; j++){
	linea(m1, m2,4);
	linea(m3, m4,4);
	m1.y++;
	m2.y++;
	m3.y++;
	m4.y++;
}

}

void bala(){
	punto p1, p2;
	p1.x=109;
	p1.y=112;
	p2.x=112;
	p2.y=112;
	for(int h=0; h<5; h++){
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

void alien(punto p1, punto p2){
	for(int i=0; i<=10; i++){
		linea(p1, p2, 12);
		p1.x--;
		p1.y++;
		p2.x++;
		p2.y++;
	}	
}

int random(){
	int random = rand() % 4 + 1;
	return random;
}

void generap(int x){
	punto p1, p2;
	if(x==1){
		p1.x=50;
		p1.y=385;
		p2.x=50;
		p2.y=385;
	}else 
	if(x==2){
		p1.x=200;
		p1.y=385;
		p2.x=200;
		p2.y=385;		
	}else
	if(x==3){
		p1.x=350;
		p1.y=385;
		p2.x=350;
		p2.y=385;		
	}else
	if(x==4){
		p1.x=500;
		p1.y=385;
		p2.x=500;
		p2.y=385;		
	}	
	alien(p1, p2);
}


