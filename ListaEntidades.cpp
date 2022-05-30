#include "ListaEntidades.h"

namespace Game
{
	ListaEntidades::ListaEntidades()
	{

	}

	ListaEntidades::~ListaEntidades()
	{
		destruir();
	}

	void ListaEntidades::inserir(Entidade* info)
	{
		lista.inserir(info);
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

	void ListaEntidades::update(float t)
	{
		Entidade* p = lista.voltar_inicio();
		while (p)
		{
			p->atualizar(t);
			p = lista.proximo();
		}
	}

	void ListaEntidades::draw(GerenciadorGrafico& gg)
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
