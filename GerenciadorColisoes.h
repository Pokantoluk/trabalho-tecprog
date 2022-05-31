#pragma once
#include <set>
#include <math.h>


namespace Game
{
	class Entidade;
	class GerenciadorColisoes
	{
	private:
		std::set<Entidade*> colisoes;
		bool colidiu(Entidade* p1, Entidade* p2);
	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();

		void add_Entidade(Entidade* p);
		void rm_Entidade(Entidade* p);
		void rm_todos();
		void verificar_colisoes();

	};

}

