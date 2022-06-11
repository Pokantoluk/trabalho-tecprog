#pragma once
#include "Jogador.h"
namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Luigi :
				public Jogador
			{
			private:
				static int pontos;
			public:

				Luigi(Vector2F pos = Vector2F(0.0f, 0.0f));
				~Luigi();
				void tratar_eventos();
				static unsigned int get_pontuacao() { return pontos; }
				void reiniciar();
			};
		}
	}
}

