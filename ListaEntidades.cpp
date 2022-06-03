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



	void ListaEntidades::inicializar_entidades(GerenciadorGrafico& gg)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->inicializar(gg);
			p = lista.proximo();
		}
	}

	void ListaEntidades::percorrer_executar(float t, GerenciadorGrafico& gg)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->executar(t, gg);
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
	}


}
