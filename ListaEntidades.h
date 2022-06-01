#pragma once
#include "Lista.h"


namespace Game
{
	class Entidade;
	class GerenciadorGrafico;
	class GerenciadorEventos;
	class GerenciadorColisoes;
	class ListaEntidades
	{
		
	private:
		Lista<Entidade> lista;
		unsigned int tam;
	public:
		ListaEntidades();
		~ListaEntidades();
		void inserir(Entidade* info);
		Entidade* operator[](int i);

		void inicializar_entidades(GerenciadorGrafico& gg, GerenciadorEventos& ge, GerenciadorColisoes& gc);
		void atualizar(float t);
		void percorrer_desenhar(GerenciadorGrafico& g);
		void destruir();
		unsigned int get_tam() { return tam; }

	};

}

