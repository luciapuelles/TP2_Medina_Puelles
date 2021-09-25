#include "cItems.h"
#include "cLista_Articulos.h"
int cItems::counter = 0;
cItems::cItems():codigo(to_string(counter))
{
	srand(time(NULL));
	int num = rand() % (30-1);
	this->articulo = Lista_articulos[num];
	Cantidad = rand()%9;//se puede llevar hasta 10 del mismo articulo
	Monto_total = Lista_articulos[num]->getPrecioUnitario() * Cantidad;
	counter++;
}

cItems::~cItems()
{
	//delete articulo;
}

void cItems::imprimir()
{	
	cout << "Cantidad: " << to_string(Cantidad) << endl;
	this->articulo->imprimir();
	cout << "valor total: " << to_string(Monto_total) << endl;
	
}

ostream& operator<<(ostream& out, cItems& I)
{
	for (int i = 0; i < 30; i++)
	{
		out << "Cantidad: " << I.getcantidad() << endl;
		out << I.getarticulo()->to_String() << endl;
		out << "Monto Total: " << I.getmontototal() << endl;
		return out;
	}

}

cItems& cItems::operator++()
{
	Cantidad++;
	return *this;
}
