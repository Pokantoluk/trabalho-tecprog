#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

namespace Game
{
	class ListaEntidades
	{
	private:
		Lista<Entidade> lista;
	public:
		ListaEntidades();
		~ListaEntidades();
		void inserir(Entidade* info);

		void inicializar_entidades(GerenciadorGrafico& gg, GerenciadorEventos& ge);
		void update(float t);
		void draw(GerenciadorGrafico& g);
		void destruir();
		

	};

}

