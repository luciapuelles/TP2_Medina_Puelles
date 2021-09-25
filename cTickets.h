#pragma once
#include<iostream>
#include <string> 
#include <ctime>
#include <sstream>
#include "cItems.h"
#include "cLista_Articulos.h"
using namespace std;
#define NMAX 30//cantidad maxima de articulos que puede llevar(solo hay 30 productos)

class cTickets
{
private:
	bool Abonado;//pago o no pago
	const string Codigo;
	static int counter;
	tm* Hora_emision;
	cItems** Lista_items;
	bool Modo_pago; // true: efectivo y flase: tarjeta
	float Total_final;
	int CA;
	int TAM;
	bool eliminar;
public:
	cTickets();
	~cTickets();

	void Agregar(cItems* objeto);
	cItems* Buscar(string clave);
    int BuscarPos(string clave);
	void Eliminar(string clave);
	cItems* Quitar(string clave);
	tm* DiaActual();

	void ProcesarProductos();
	const string getCode() { return Codigo; };
	bool getabono() { return Abonado; };
	void setabono(bool aux) { Abonado = aux; }
	bool getModoPago() { return Modo_pago; };
	float getMonto_total() { return Total_final; }
	void setMonto_total(int num) { Total_final = num; }
	//void imprimirListaItems();
	string to_String();
	void imprimir();
};

