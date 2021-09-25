#include "cSupermercado.h"
#include "cLista_Articulos.h"

int main()
{
	cSupermercado* supermercado = new cSupermercado(100000.0, 50000.0);
	supermercado->AbrirSupermercado();
	supermercado->CerrarSupermercado();
	supermercado->Final_supermercado();
	supermercado->~cSupermercado();
}