#pragma once
#include "Lista.h"


namespace Game
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
			unsigned int tam;
		public:
			ListaEntidades();
			~ListaEntidades();
			void inserir(Entidade* info);
			Entidade* operator[](int i);
			void remover(int i);
			void inicializar_entidades();
			void percorrer_executar(float t);
			void destruir();
			unsigned int get_tam() { return tam; }

		};
	}
}

