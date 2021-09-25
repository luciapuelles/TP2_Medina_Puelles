#include "cSupermercado.h"


cSupermercado::cSupermercado(float cant_dinero_banco, float dinero_caja_fuerte)
{
	this->cant_dinero_banco = cant_dinero_banco;
	this->dinero_caja_fuerte = dinero_caja_fuerte;
	TAM = NMAX;
	CA = 0;
	Lista_cajas = new cCajas * [TAM];
	for (int i = 0; i < TAM; i++)
	{
		Lista_cajas[i] = NULL;
	}

}

cSupermercado::~cSupermercado()
{
	if (Lista_cajas != NULL ) {
		for (unsigned int i = 0; i < CA; i++)
		{
			if (Lista_cajas[i] != NULL)
				Lista_cajas[i]->~cCajas();
				delete Lista_cajas[i];
		}
		delete[]Lista_cajas;
	}
}

void cSupermercado::Agregar(cCajas* c)
{
	if (CA >= TAM) throw exception("no hay lugar");
	Lista_cajas[CA] = c;
	CA++;
	return;
}

cCajas* cSupermercado::Quitar(string clave)
{
	cCajas* aux = Buscar(clave);
	int i = BuscarPos(clave);
	for (int k = i; k < CA - 1; k++)
	{
		Lista_cajas[k] = Lista_cajas[k + 1];

	}
	Lista_cajas[CA] = NULL;
	return aux;
}

int cSupermercado::BuscarPos(string clave)
{
	for (unsigned int i = 0; i < CA; i++)
	{
		if (Lista_cajas[i]->getCodigo() == clave)
			return i;
	}
	return CA;
}

cCajas* cSupermercado::Buscar(string clave)
{
	unsigned int pos = BuscarPos(clave);
	if (pos < CA)
		return Lista_cajas[pos];
	return NULL;
}

void cSupermercado::Eliminar(string clave)
{
	cCajas* aux = Quitar(clave);
	delete aux;
	CA--;
}

void cSupermercado::MayorRecaudacion()
{
	int pos=0;
	float max = 0;
	for (int i = 0; i < TAM; i++)
	{
		if (Lista_cajas[i] != NULL)
		{
			if (Lista_cajas[i]->getDineroTotalRecaudado() > max)
			{
				max = Lista_cajas[i]->getDineroTotalRecaudado();
				pos = i;
			}
		}
	}
	cout << "La caja" << Lista_cajas[pos]->getCodigo() << "tuvo la mayor recaudacion" << endl;

}

void cSupermercado::MayorTransaccion()
{
	int max = 0;
	int pos = 0;
	for (int i = 0; i < CA; i++)
	{
		for (int j = 0; j < Lista_cajas[i]->getCA(); j++)
		{
			if (Lista_cajas[i]->getTicket(j)->getModoPago() == false)
			{
				if (Lista_cajas[i]->getTicket(j)->getMonto_total() > max)
				{
					max = Lista_cajas[i]->getTicket(j)->getMonto_total();
					pos = i;
				}
			}
		}
	}
	cout << "La mayor transaccion la tuvo la caja: " << Lista_cajas[pos]->getCodigo() << endl;
}

void cSupermercado::RecolectarRecaudacion()
{
	float cuenta_bancaria = 0;
	float efectivo = 0;
	for (int i = 0; i < CA; i++)
	{
		for (int j = 0; j < Lista_cajas[i]->getCA(); j++)
		{
			if (Lista_cajas[i]->getTicket(j)->getModoPago() == true)//true=eff
			{
				efectivo = Lista_cajas[i]->getTicket(j)->getMonto_total();
				Lista_cajas[i]->setDineroTotalRecaudado(Lista_cajas[i]->getTicket(j)->getMonto_total()+Lista_cajas[i]->getDineroTotalRecaudado());
			}
			else
			{
				cuenta_bancaria = Lista_cajas[i]->getTicket(j)->getMonto_total();
				Lista_cajas[i]->setDineroTotalRecaudado(Lista_cajas[i]->getTicket(j)->getMonto_total() + Lista_cajas[i]->getDineroTotalRecaudado());
			}
		}
		Lista_cajas[i]->setDinero_caja(0);
		Lista_cajas[i]->setDineroTotalRecaudado(0);
	}
	dinero_caja_fuerte = dinero_caja_fuerte + efectivo;
	cant_dinero_banco = cant_dinero_banco + cuenta_bancaria;
}

void cSupermercado::AbrirSupermercado()
{
	Llenar_articulos();
	
	//abrir las cajas
	Agregar(new cCajas("01", 2000.0));
	Agregar(new cCajas("02", 2000.0));
	Agregar(new cCajas("03", 2000.0));
	Agregar(new cCajas("04", 2000.0));
	Agregar(new cCajas("05", 2000.0));

	for (int i = 0; i < CA; i++)
	{
		if (Lista_cajas[i] != NULL)
		{
			Lista_cajas[i]->EmitirTicket();
		}
	}
}

void cSupermercado::CerrarSupermercado()
{

	for (int i = 0; i < CA; i++)
	{
		Lista_cajas[i]->setEstado(false);
	}
}

void cSupermercado::imprimir()
{
	for (int i = 0; i < CA; i++)
	{
		Lista_cajas[i]->imprimir();
	}
}

void cSupermercado::Final_supermercado()
{
	MayorRecaudacion();
	MayorTransaccion();
	RecolectarRecaudacion();
}

