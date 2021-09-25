#pragma once
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "cArticulo.h"

using namespace std;
class cItems
{
	cArticulo* articulo;
	int Cantidad;
	float Monto_total;
	string codigo;
	static int counter;
public:
	cItems();
	~cItems();

	cArticulo* getarticulo() { return articulo; };
	int getcantidad() { return Cantidad; };
	float getmontototal() { return Monto_total; };
	string getCodigo() { return codigo; };
	void imprimir();
	cItems& operator++();
	

};
//ostream& operator<<(ostream& out, cItems& I);
ostream& operator<<(ostream& out, cItems& I);
