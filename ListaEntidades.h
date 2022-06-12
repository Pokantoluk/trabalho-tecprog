#pragma once
#include "Lista.h"


namespace Jogo
{
	class Entidade;
	class GerenciadorGrafico;
	class GerenciadorEventos;
	class GerenciadorColisoes;
	namespace Listas
	{

		class ListaEntidades
		{

		private:
			Lista<Entidade> lista;
		    int tam;
		public:
			ListaEntidades();
			~ListaEntidades();
			void inserir(Entidade* info);
			Entidade* operator[](int i);
			void inicializar_entidades();
			void percorrer_executar(float t);
			void remover(int i);
			void destruir();
			int get_tam() { return tam; }
			

		};
	}
}

