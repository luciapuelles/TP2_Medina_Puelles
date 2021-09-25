#pragma once
#include <iostream>
#include <string>
#include "cCajas.h"
#include "cLista_Articulos.h"
#include <ctime>
using namespace std;

#define NMAX 5//max de cajas
class cSupermercado
{
private:
	float cant_dinero_banco;
	float dinero_caja_fuerte;
	int TAM;
	int CA;
	cCajas** Lista_cajas;

public:
	cSupermercado(float cant_dinero_banco, float dinero_caja_fuerte);
	~cSupermercado();
	void Agregar(cCajas*);
	cCajas* Quitar(string clave);
	int BuscarPos(string clave);
	cCajas* Buscar(string clave);
	void Eliminar(string clave);
	int getCA() { return CA; }
	int getTAM() { return TAM; }
	void MayorRecaudacion();
	void MayorTransaccion();
	void RecolectarRecaudacion();
	void AbrirSupermercado();
	void CerrarSupermercado();
	void imprimir();
	void Final_supermercado();
};

