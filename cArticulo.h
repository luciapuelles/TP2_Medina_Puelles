#pragma once
#include<iostream>
#include<string>

using namespace std;
class cArticulo
{
private:
	const string Codigo;
	static int counter;
	string marca;
	string nombre;
	float Precio_unitario;


public:
	cArticulo(string nombre, string marca, float precio);
	~cArticulo();
	float getPrecioUnitario() { return Precio_unitario; }
	const string getCodigo() { return Codigo; }
	string to_String();
	void imprimir();

};

