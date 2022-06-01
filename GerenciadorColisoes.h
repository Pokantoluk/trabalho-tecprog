#pragma once
#include <set>
#include <vector>
#include <list>
#include <math.h>
#include "ListaEntidades.h"

namespace Game
{
	class Inimigo;
	class Entidade;
	class Obstaculo;
	class Jogador;
	class GerenciadorColisoes
	{
	private:


		ListaEntidades* moveis;
		ListaEntidades* estaticos;
	public:
		GerenciadorColisoes(ListaEntidades* m = nullptr, ListaEntidades* e = nullptr);
		~GerenciadorColisoes();

		void verificar_colisoes();
	};

}

