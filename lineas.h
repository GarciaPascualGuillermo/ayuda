
#include <iostream>
#include<graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
using namespace std;


vector<vector<int> > res; // el vector va a almacenar las coordenadas de cada iteracion

int deltax, deltay, ini=0;// son las deltas de las coordenadas




 int f1(int pk){
	int p=pk +(2*deltay);
	return p;
	//es la primer forma que se pueden tornar las ecuaciones 
}
 int f2(int pk){
 	int p=pk +(2*deltax);
 	return p;
 	//segunda forma que se pueden tornar las ecuaciones
 }

 int f3(int pk){
 	int p=pk +(2*deltax)-(2*deltay);
 	return p;
 	//tercera forma que se pueden tornar las iteraciones.
 }
 
 int f4(int pk){
 	int p=pk +(2*deltay)-(2*deltax);	
 	return p;
 	//cuarta forma de las ecuaciones
 }
 
 void caso1(int p0,int x0, int y0, int x1, int y1){
 	vector<int > v;
 	
	 //mientras las coordenadas de inicio sean mayores a las de inicio se seguira iterando
 	//esta forma es cuando las linea avanza por X
	 if(x1>x0 && y1>y0){
 		if (p0<0){
 		x0++;
 		v.push_back(x0);
 		v.push_back(y0);
 		res.push_back(v);
 		putpixel(x0, y0, 1);

 		//se calcula la primer coordenada y se guarda en el vector
		 caso1(f1(p0), x0,y0,x1, y1);	
		 }else{
		 	x0++;
		 	y0++;
		v.push_back(x0);
 		v.push_back(y0);
 		res.push_back(v);
 			putpixel(x0, y0, 1);
		 	caso1(f4(p0), x0,y0,x1, y1);
		 	
		 }
	 }
 }
 
  void caso2(int p0, int x0, int y0, int x1, int y1){ 
  //esta forma es cuando la linea avanza por Y
  	vector<int > v;
 	if(x1>x0 && y1>y0){
 		if (p0<0){
 		y0++;
 		v.push_back(x0);
 		v.push_back(y0);
 			putpixel(x0, y0, 1);

 	 	res.push_back(v);

		 caso2(f2(p0), x0,y0,x1, y1);	
		 }else{
		 	x0++;
		 	y0++;
		 	v.push_back(x0);
 		    v.push_back(y0);
 		    putpixel(x0, y0, 1);
 	 		res.push_back(v);
		 	caso2(f3(p0), x0,y0,x1, y1);
		 }
	 }
 }
 
   void caso3(int p0, int x0, int y0, int x1, int y1){
   	//esta forma es para cuando la linea avanza por x pero decrementando y aumenta Y
   	 	vector<int > v;
 	if(x1>x0 && y1>y0){
 		if (p0<0){
 		y0++;
 		v.push_back(x0);
 		v.push_back(y0); 
		res.push_back(v);
    	putpixel(x0, y0, 1);
		 caso3(f2(p0), x0,y0,x1, y1);	
		 }else{
		 	x0--;
		 	y0++;
		v.push_back(x0);
 		v.push_back(y0);
 		res.push_back(v);
			putpixel(x0, y0, 1);	
		 	caso3(f3(p0), x0,y0,x1, y1);
		 }
	 }
 }
 
  void caso4(int p0, int x0, int y0, int x1, int y1){
  	
  	//esta forma es para cuando la linea avanza por Y decrementaando y aumentando por x
  	 	vector<int > v;
 	if(x1>x0 && y1>y0){
 		if (p0<0){
 		x0++;
 		v.push_back(x0);
 		v.push_back(y0);
 		res.push_back(v);
 		putpixel(x0, y0, 1);
		 caso4(f1(p0), x0,y0,x1, y1);	
		 }else{
		 	x0--;
		 	y0++;
		v.push_back(x0);
 		v.push_back(y0);
 		res.push_back(v);
 		putpixel(x0, y0, 1);
		 	caso4(f4(p0), x0,y0,x1, y1);
		 }
	 }
 }
 
void compara(int x0, int y0, int x1, int y1){
	//aqui se realiza la primer comparacion y decide que caso usara en base a las deltas
if(deltax>deltay){
	ini=(2*deltay-(deltax));
	caso1(ini, x0,y0,x1, y1);
}else
if(deltay>deltax){
	ini=(2*deltax-(deltay));
	caso2(ini,x0,y0,x1, y1);
}else 
if(deltax<0){
	ini=(2*deltay-(deltax));
    caso3(ini, x0,y0,x1, y1);
}else
if(deltay<0){
	ini=(2*deltax-(deltay));
	caso4(ini, x0,y0,x1, y1);
}
} 
 void imprime(vector<vector<int> > v){
 	//imprime el vector
 	for(int i=0; i<v.size(); i++){
 		for(int j=0; j<2; j++){
 			printf("%d", v[i][j]);
 			printf("\t");
		 } 
		 printf("\n");
	 }
 }


void linea(int x0, int y0, int x1, int y1){

//se piden los datos y se guardan en las variables	
	if(x0>x1 && y0>y1){
		int aux=x0;
		int aux2=y0;	
		x0=x1;
		y0=y1;
		y1= aux2;
		x1= aux;				
	}	
	//este if sirve para que si las coordenadas de inicio son mayores a las de final se intercambien los puntos
	
	deltax= x1-x0;
	deltay= y1-y0;
	//se calculan las deltas
	vector <int> v;
	v.push_back(x0);
	v.push_back(y0);
	res.push_back(v);
	//guardo la primero coordenada en mi vector
	compara(x0,y0,x1, y1);
	
}
