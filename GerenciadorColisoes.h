#pragma once
#include "stdafx.h"
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
		std::list<Obstaculo*> LOs;
		std::vector<Inimigo*> LIs;

		ListaEntidades* moveis;
		ListaEntidades* estaticos;
	public:
		GerenciadorColisoes(ListaEntidades* m = nullptr, ListaEntidades* e = nullptr);
		~GerenciadorColisoes();

		void verificar_colisoes();
	};

}

