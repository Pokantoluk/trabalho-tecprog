#pragma once
#include <set>
#include <math.h>


namespace Game
{
	class colidivel;
	class GerenciadorColisoes
	{
	private:
		std::set<colidivel*> colisions;
		bool colidiu(colidivel* p1, colidivel* p2);
	public:
		GerenciadorColisoes();
		~GerenciadorColisoes();

		void add_colidivel(colidivel* p);
		void rm_colidivel(colidivel* p);
		void rm_todos();
		void verificar_colisoes();

	};

}

