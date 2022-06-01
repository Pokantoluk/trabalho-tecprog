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



	void ListaEntidades::inicializar_entidades(GerenciadorGrafico& gg, GerenciadorEventos& gf, GerenciadorColisoes& gc)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->inicializar(gg, gc);
			p = lista.proximo();
		}
	}

	void ListaEntidades::atualizar(float t)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->atualizar(t);
			p = lista.proximo();
		}
	}

	void ListaEntidades::percorrer_desenhar(GerenciadorGrafico& gg)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->desenhar(gg);
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
