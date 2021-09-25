#define _CRT_SECURE_NO_WARNINGS
#include "cTickets.h"

int cTickets::counter = 0;
cTickets::cTickets():Codigo("#"+to_string(counter))
{ 
	counter++;	
	Hora_emision = DiaActual();
	TAM = NMAX;
	CA = 0; 
	Lista_items = new cItems*[TAM];
	for (int i = 0; i < TAM; i++)
	{
		Lista_items[i] = NULL;
	}
	Abonado = false; 
	Total_final = 0;
	eliminar = false; 
	Modo_pago = rand() % (1 - 0 + 1);//0 o 1 random de si abona con tarjeta o efectivo
}

cTickets::~cTickets()
{
	if (Lista_items != NULL && eliminar == true)
	{
		for (int i = 0; i < CA; i++)
		{
			if (Lista_items[i] != NULL)
			{
				Lista_items[i]->~cItems();
				delete Lista_items[i];
			}
		}
		delete[] Lista_items;
	}
}

void cTickets::Agregar(cItems* objeto)
{
	
	if (CA < TAM)
	{
		Lista_items[CA] = objeto;
		CA++;

	}
	else
	{
		throw new exception("No se pueden agregar mas elementos a la lista");
	}
}

cItems* cTickets::Buscar(string clave)
{
	unsigned int pos = BuscarPos(clave);
	if (pos < CA)
		return Lista_items[pos];
	return NULL;
}

int cTickets::BuscarPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista_items[i]->getCodigo() == clave)
			return i;
	}
	return CA;
}

void cTickets::Eliminar(string clave)
{
	cItems* aux = Quitar(clave);
	if (aux != NULL)
	{
		delete aux;
	}

}

cItems* cTickets::Quitar(string clave)
{
	cItems* aux = Buscar(clave);
	int i = BuscarPos(clave);
	for (int k = i; k < CA - 1; k++)
	{
		Lista_items[k] = Lista_items[k + 1];

	}
	Lista_items[CA] = NULL;
	CA--;
	return aux;
}

tm* cTickets::DiaActual()
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	return timeinfo;
}

void cTickets::ProcesarProductos()
{
	srand(time(NULL));
	int num = rand() % (30-1);//se pueden procesar hasta 30 productos 
	for (int i = 0; i < num; i++)
	{
		try 
		{
			Agregar(new cItems());
		}
		catch (exception* ex) {
			cout << ex->what() << endl;
		}
		
		Total_final = Total_final + Lista_items[i]->getmontototal();
	}

	for (int i = 0; i < CA-1; i++)
	{
		if (Lista_items[i]->getarticulo()->getCodigo() == Lista_items[i+1]->getarticulo()->getCodigo())
		{
			Eliminar(Lista_items[i]->getCodigo());
		}
	
	}

}

//void cTickets::imprimirListaItems()
//{
//	for (int i = 0; i < CA; i++)
//	{
//		//cout << **Lista_items;
//	}
//}

string cTickets::to_String()
{
	stringstream ss;
	ss << "Codigo: " << Codigo << endl;
	ss << "Hora - Fecha de emision: " << DiaActual()->tm_mday<<"/"<<DiaActual()->tm_mon<<"/"<<DiaActual()->tm_year+1900<<" "<<DiaActual()->tm_hour<<":"<<DiaActual()->tm_min << endl;
	ss << "Monto Total: " << Total_final << endl;
	return ss.str();
}

void cTickets::imprimir()
{
	string imprimir2 = to_String();
	cout << imprimir2;
	cout << **Lista_items;
	//for (int i = 0; i < CA-1; i++)
	//{
	//	
	//}
}


