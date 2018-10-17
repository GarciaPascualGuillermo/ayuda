#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include<graphics.h>

using namespace std;
//declaro variables x, radio, coorfdenada Y, la constante e
int x, r, y, e;
//vector que almacenara el resultado
//pinta los 8 puntos de simetria por una coordenada dada
void pinta(int x, int y){
	vector <vector <int > > res;
	vector<int> v;
		v.push_back(x);
	v.push_back(y);
	res.push_back(v);
	v.clear();
		v.push_back(y);
	v.push_back(x);
		res.push_back(v);
	v.clear();
		v.push_back(-x);
	v.push_back(y);
		res.push_back(v);
	v.clear();
		v.push_back(-y);
	v.push_back(x);
		res.push_back(v);
	v.clear();
		v.push_back(x);
	v.push_back(-y);
		res.push_back(v);
	v.clear();
		v.push_back(y);
	v.push_back(-x);
		res.push_back(v);
	v.clear();
		v.push_back(-x);
	v.push_back(-y);
		res.push_back(v);
	v.clear();
		v.push_back(-y);
	v.push_back(-x);
		res.push_back(v);
	v.clear();
}

int circulo(int r, int x, int y){	

//se hace el algoritmo del circulp
    pinta(x, y);
    putpixel(x,y,1);
    //pintamos puntos iniciales
	e=abs((x*x)+(y*y)-(r*r));
	//la condicion se detiene cuando y es mayor a x o Y es menor que 0, o x menor que 0
	if(y>x||y<0||x<0){
		
	}else{
		//se calcula es, y eso
		int es=abs(e+(2*y)+1);
		int eso=abs(es-(2*x)+1);
		//si es es mayor a eso se resta uno a x y suma uno a y, y se ejecuta recursividad
		if(es>eso){
			x=x-1;
			y=y+1;
			circulo(r, x,y);
		}else{
			//en caso contrario se suma uno a y, y se ejecuta recursividad
			y=y+1;
			circulo(r, x,y);
		}
	}
}


 

