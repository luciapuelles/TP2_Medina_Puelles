#pragma once
#include<iostream>
#include<time.h>
#include <sstream>
#include"cTickets.h"
using namespace std;
#define NMAX 5//max tickets(puse 5 para probar si funciona)

 
class cCajas
{
	friend class cTickets;
private:
	cTickets** Lista_tickets;
	int CA, TAM;
	const string Codigo;
	float Dinero_caja;
	float Dinero_total_recaudado;
	bool Estado_caja; //si esta abierta o cerrada
	bool EliminarObjetos;

public:
	
	cCajas(string code, float dinero_caja);
	~cCajas();

	void Agregar(cTickets* objeto);
	cTickets* Buscar(string clave);
	int BuscarPos(string clave);
	void Eliminar(string clave);
	cTickets* Quitar(string clave);
	cTickets* operator[](string clave);
	cTickets* operator[](int pos);
	void operator+(cTickets* objeto);
	void Listar();

	cTickets* CrearTicket();
	void EmitirTicket();


	bool getestado() { return Estado_caja; };
	const string getCodigo() { return Codigo; };
	void setMonto_total(int num) { num; }
	int getDinero_caja() { return Dinero_caja; };
	void setDinero_caja(int num) { Dinero_caja = Dinero_caja+num; }
	void setDineroTotalRecaudado(int num) { Dinero_total_recaudado = num; }
	void setEstado(bool est) { Estado_caja = est; }
	float getDineroTotalRecaudado() { return Dinero_total_recaudado; }
	void setDineroTotalRecaudado(float aux) { Dinero_total_recaudado=aux; }
	int getCA() { return CA; }
	cTickets* getTicket(int pos) { return Lista_tickets[pos]; }
	string to_String();
	void imprimir();
	//void imprimirListaTickets(); //verificar
};

