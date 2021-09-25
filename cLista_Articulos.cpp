#include "cLista_Articulos.h"
#include "cArticulo.h"
#define NMAX 30

cArticulo** Lista_articulos = new cArticulo * [NMAX];

void Llenar_articulos()
{
	Lista_articulos[0]=new cArticulo("leche", "la serenisima", 80.0);
	Lista_articulos[2] = new cArticulo("leche", "sancor", 75.0);
	Lista_articulos[3] = new cArticulo("leche", "veronica", 80.0);
	Lista_articulos[4] = new cArticulo("galletitas", "chocolinas", 50.0);
	Lista_articulos[5] = new cArticulo("galletitas", "oreo", 50.0);
	Lista_articulos[6] = new cArticulo("galletitas", "criollitas", 50.0);
	Lista_articulos[7] = new cArticulo("manteca", "la serenisima", 50.0);
	Lista_articulos[8] = new cArticulo("manteca", "veronica", 50.0);
	Lista_articulos[9] = new cArticulo("coca cola", "coca cola", 50.0);
	Lista_articulos[10] = new cArticulo("agua", "villavicencio", 50.0);//10
	Lista_articulos[11] = new cArticulo("agua", "kin", 50.0);
	Lista_articulos[12] = new cArticulo("cerveza", "andes", 50.0);
	Lista_articulos[13] = new cArticulo("cerveza", "quilmes", 50.0);
	Lista_articulos[14] = new cArticulo("cerveza", "patagonia", 50.0);
	Lista_articulos[15] = new cArticulo("fideos", "matarazzo", 50.0);
	Lista_articulos[16] = new cArticulo("arroz", "gallo", 50.0);
	Lista_articulos[17] = new cArticulo("polenta", "polenta", 50.0);
	Lista_articulos[18] = new cArticulo("pan", "bimbo", 50.0);
	Lista_articulos[19] = new cArticulo("pan", "fargo", 50.0);
	Lista_articulos[20] = new cArticulo("yerba", "playadito", 50.0);
	Lista_articulos[21] = new cArticulo("yerba", "taragui", 50.0);//10
	Lista_articulos[22] = new cArticulo("cafe", "nescafe", 50.0);
	Lista_articulos[23] =new cArticulo("te", "taragui", 50.0);
	Lista_articulos[24] = new cArticulo("mate cocido", "taragui", 50.0);
	Lista_articulos[25] = new cArticulo("Lisoform", "Lisoform", 50.0);
	Lista_articulos[26] = new cArticulo("Lavandina", "querubin", 50.0);
	Lista_articulos[27] = new cArticulo("blem", "blem", 50.0);
	Lista_articulos[28] = new cArticulo("detergente", "magistral", 50.0);
	Lista_articulos[29] = new cArticulo("detergente", "cif", 50.0);

}


void Eliminar_Articulos()
{
	if (Lista_articulos != NULL)
	{
		for (int i = 0; i < 30; i++)
		{
			if (Lista_articulos[i] != NULL)
				delete Lista_articulos[i];
		}
		delete[] Lista_articulos;
	}
}

void imprimir()
{
	for (int i = 0; i < 30; i++)
	{
		Lista_articulos[i]->imprimir();
	}
}

