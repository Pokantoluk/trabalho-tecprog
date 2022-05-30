#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Game
{
	class GerenciadorGrafico;
	class GerenciadorEventos;
	class GerenciadorColisoes;
	class ListaEntidades
	{
		
	private:
		Lista<Entidade> lista;
	public:
		ListaEntidades();
		~ListaEntidades();
		void inserir(Entidade* info);

		void inicializar_entidades(GerenciadorGrafico& gg, GerenciadorEventos& ge, GerenciadorColisoes& gc);
		void update(float t);
		void draw(GerenciadorGrafico& g);
		void destruir();
		

	};

}

