#pragma once
#include "stdafx.h"
#include <math.h>
#include "ListaEntidades.h"

namespace Jogo
{
	class Inimigo;
	class Entidade;
	class Obstaculo;
	class Jogador;
	namespace Gerenciadores
	{

		class GerenciadorColisoes
		{
		private:
			std::list<Obstaculo*> LOs;
			std::vector<Inimigo*> LIs;

			Listas::ListaEntidades* moveis;
			Listas::ListaEntidades* estaticos;
		public:
			GerenciadorColisoes(Listas::ListaEntidades* m = nullptr, Listas::ListaEntidades* e = nullptr);
			~GerenciadorColisoes();

			void verificar_colisoes();
		};
	}

}

