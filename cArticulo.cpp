#include "cArticulo.h"
#include<sstream>
#define NMAX 30

int cArticulo::counter = 0;

cArticulo::cArticulo(string nombre, string marca, float precio) : Codigo(to_string(counter + 1000))
{
	this->marca = marca;
	this->nombre = nombre;
	this->Precio_unitario = precio;
	counter++;
	
}

cArticulo::~cArticulo()
{
	
}


string cArticulo::to_String()
{
	stringstream ss;

	ss << "Codigo de producto: " << Codigo << endl;
	ss << "Nombre: " << nombre;
	ss << "		Marca: " << marca;
	ss << "		Precio Unitario: " << Precio_unitario;
	return ss.str();
}

void cArticulo::imprimir()
{
	string imprimir2 = to_String();
	cout << imprimir2;
}

