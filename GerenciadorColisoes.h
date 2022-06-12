#pragma once
#include "stdafx.h"
#include <math.h>
#include "ListaEntidades.h"

namespace Jogo
{   
	class Entidade;
	namespace Entidades
	{
		namespace Personagens
		{
			class Inimigo;
		    class Jogador;
		}
		namespace Obstaculos
		{
			class Obstaculo;
		}
		
	}
	
	namespace Gerenciadores
	{

		class GerenciadorColisoes
		{
		private:

			Listas::ListaEntidades* moveis;
			Listas::ListaEntidades* estaticos;
		public:
			GerenciadorColisoes(Listas::ListaEntidades* m = nullptr, Listas::ListaEntidades* e = nullptr);
			~GerenciadorColisoes();
			const bool tentar_destruir(Entidade* ente, int index, bool estatico);
			void verificar_colisoes();
		};
	}

}

