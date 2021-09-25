#include "cCajas.h"


cCajas::cCajas(string code, float dinero_caja):Codigo(code)
{
	TAM = NMAX;
	CA = 0;
	Lista_tickets = new cTickets* [TAM];
	for (unsigned int i = 0; i < TAM; i++)
	{
		Lista_tickets[i] = NULL;
	}
	EliminarObjetos = false;
	this->Dinero_caja = dinero_caja;
	this->Dinero_total_recaudado = 0;
	this->Estado_caja = true;
}

cCajas::~cCajas()
{
	if (Lista_tickets != NULL && EliminarObjetos == true) {
		for (unsigned int i = 0; i < CA; i++)
		{
			if (Lista_tickets[i] != NULL)
				Lista_tickets[i]->~cTickets();
				delete Lista_tickets[i];
		}
		delete[]Lista_tickets;
	}
}

void cCajas::Agregar(cTickets* objeto)
{
	if (CA < TAM)
	{
		Lista_tickets[CA] = objeto;
		CA++;
		return;
	}
	else
	{
		throw new exception("No se pueden agregar mas elementos a la lista");
	}
}

cTickets* cCajas::Buscar(string clave)
{
	unsigned int pos = BuscarPos(clave);
	if (pos < CA)
		return Lista_tickets[pos];
	return NULL;
}

int cCajas::BuscarPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista_tickets[i]->getCode() == clave)
			return i;
	}
	return CA;
}

void cCajas::Eliminar(string clave)
{
	cTickets* aux = Quitar(clave);
	delete aux;
	CA--;
}

cTickets* cCajas::Quitar(string clave)
{
	cTickets* aux = Buscar(clave);
	int i = BuscarPos(clave);
	for (int k = i; k < CA - 1; k++)
	{
		Lista_tickets[k] = Lista_tickets[k + 1];

	}
	Lista_tickets[CA] = NULL;
	return aux;
}

cTickets* cCajas::operator[](string clave)
{
	return Buscar(clave);
}

cTickets* cCajas::operator[](int pos)
{
	if (pos < CA) return Lista_tickets[pos];
}

void cCajas::operator+(cTickets* objeto)
{
	try {
		Agregar(objeto);
	}
	catch (exception* e) {//Si no hay mas lugar en la lista, lo imprimimos
		cout << e->what() << endl;
		delete e;
		
	}
}

void cCajas::Listar()
{
	for (int i = 0; i < CA; i++)
	{
		cout << Lista_tickets[i];
	}
}

cTickets* cCajas::CrearTicket()
{
	cTickets* aux = new cTickets();
	if (aux != NULL)
	{
		try 
		{
			Agregar(aux);
		}
		catch (exception* ex)
		{
			cout << ex->what() << endl;
		}
		return aux;
	}
	else
	{			
		delete aux;
		return NULL;
	}	

	
	
}

void cCajas::EmitirTicket()
{
	srand(time(NULL));
	int num = 1+rand() % (NMAX+1-1);//rand de cantidad de tickets+
	for (int j = 0; j < TAM; j++)//TODOS LOS TICKETS DEL DIA
	{
		float aux = 0.0;
		
		Lista_tickets[j] = CrearTicket();
		if (Lista_tickets[j] != NULL)
		{
			if (Estado_caja == true)
			{
				Lista_tickets[j]->ProcesarProductos();
				for (int i = 0; i < CA; i++) 
				{
					if (Lista_tickets[i]->getModoPago() == true)//paga en efectivo
					{
						aux = getDinero_caja() + Lista_tickets[i]->getMonto_total();
						setDinero_caja(aux);
						Lista_tickets[i]->setabono(true);
						Dinero_total_recaudado = Dinero_total_recaudado + Lista_tickets[i]->getMonto_total();
					}
					else if (Lista_tickets[i]->getModoPago() == false)//paga con tarjeta
					{
						Lista_tickets[i]->setabono(true);
						Dinero_total_recaudado = Dinero_total_recaudado + Lista_tickets[i]->getMonto_total();
					}
				}
			}
		}
		
	}
	
}

//void cCajas::imprimirListaTickets()
//{
//	//cout << "tickets emitidos en la caja:" << endl;
//	for (int i = 0; i < CA; i++)
//	{
//		//Lista_tickets[i]->imprimir();
//		//Lista_tickets[i]->imprimirListaItems();
//	}
//}

string cCajas::to_String()
{
	stringstream ss;
	ss << "Codigo: " << Codigo << endl;
	ss << "Dinero en la caja: " << Dinero_caja << endl;
	ss << "Dinero Total Recaudado: " << Dinero_total_recaudado << endl;

	return ss.str();
}

void cCajas::imprimir()
{
	string imprimir1 = to_String();
	cout << imprimir1;
	//imprimirListaTickets();
}





