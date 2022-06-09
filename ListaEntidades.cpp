#include "ListaEntidades.h"
#include "Entidade.h"

namespace Game
{
	ListaEntidades::ListaEntidades():
		tam(0)
	{

	}

	ListaEntidades::~ListaEntidades()
	{
		destruir();
	}

	void ListaEntidades::inserir(Entidade* info)
	{
		lista.inserir(info);
		tam++;
	}

	Entidade* ListaEntidades::operator[](int i)
	{
		return lista[i];
	}



	void ListaEntidades::inicializar_entidades()
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->inicializar();
			p = lista.proximo();
		}
	}

	void ListaEntidades::percorrer_executar(float t)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->executar(t);
			p = lista.proximo();
		}
	}

	void ListaEntidades::destruir()
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			delete p;
			p = lista.proximo();
		}
		lista.esvaziar();
		tam = 0;
	}

	void ListaEntidades::remover(int i)
	{
		lista.remover(i);
		tam--;
	}
}
