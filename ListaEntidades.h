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

		void inicializar_entidades(GerenciadorGrafico& gg);
		void percorrer_executar(float t, GerenciadorGrafico& gg);
		void destruir();
		unsigned int get_tam() { return tam; }

	};

}

