#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
#include <iostream>
#include "grafico.h"
#include "Graficador.h"
#include <vector>
using namespace std;
punto pnave1, pnave2;
vector <vector <punto> > Valien;
vector <vector <punto> > Vbala;
boolean estado= false;

int random(){
	int random = rand() % 8 + 1;
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
	}else	
	if(x==5){
		p1.x=100;
		p1.y=385;
		p2.x=100;
		p2.y=385;
	}else 
	if(x==6){
		p1.x=150;
		p1.y=385;
		p2.x=150;
		p2.y=385;
	}else 
	if(x==7){
		p1.x=250;
		p1.y=385;
		p2.x=250;
		p2.y=385;
	}else 
	if(x==8){
		p1.x=400;
		p1.y=385;
		p2.x=400;
		p2.y=385;
	}
	alien(p1, p2, 12);
	vector <punto> ali;
	ali.push_back(p1);
	ali.push_back(p2);
	Valien.push_back(ali);
}


void movealien(punto p1, punto p2){
	alien(p1, p2, 0);
	punto pA1, pA2;
	 if(p1.y>90){
	 
	pA1.x=p1.x;
	pA1.y=p1.y-10;
	pA2.x=p2.x;
	pA2.y=p2.y-10;
	
	vector <punto> aux;
	aux.push_back(pA1);
	aux.push_back(pA2);
	Valien.push_back(aux);
	

	alien(pA1, pA2, 12);
}else{
	generap(random());
}

}

void start(){
    generap(random());
    generap(random());
    generap(random());
    generap(random());

    marco();    

}
int main(){
	_init();
	
	char tecla;
	while(!kbhit()){
	//	while(estado==false){
		
		tecla=getch();
		
		if(tecla=='t'){
		punto p1, p2;
	  p1.x=100;  p1.y=90;  
    p2.x=120;  p2.y=90;
    pnave1=p1;
		pnave2=p2;
    nave(p1, p2, 1);
		start();	
		}
		if(tecla=='a'){
			nave(pnave1, pnave2,0);
			if(pnave1.x>=20){
			
			pnave1.x=pnave1.x-20;
			pnave2.x=pnave2.x-20;
		}
			nave(pnave1, pnave2,2);
			
		}
		if(tecla=='d'){
			nave(pnave1, pnave2,0);
			if(pnave2.x<=600){
			
			pnave1.x=pnave1.x+20;
			pnave2.x=pnave2.x+20;
		}
			nave(pnave1, pnave2,2);	
		}
		if(tecla=='w'){
			punto p1, p2;
			p1.x=pnave1.x+8;
			p1.y=pnave1.y+15;
			p2.x=pnave2.x-5;
			p2.y=pnave2.y+15;
			vector <punto> balas;
			balas.push_back(p1);
			balas.push_back(p2);
			Vbala.push_back(balas);
			bala(p1, p2);
		}
	//acciones que hara cada milisegundo
	for(int k=0; k<Valien.size(); k+2){
		movealien(Valien[k][0],Valien[k][1]);

		Valien.erase(Valien.begin()+0);
	}
	//finalizan acciones de comprobacion y avance
	
}
	finalizar();
	return 0;
}
