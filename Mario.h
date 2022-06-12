#pragma once
#include "Jogador.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Mario :
				public Jogador
			{
			private:
				static int pontos;
			public:
				Mario(Vector2F pos = Vector2F(0.0f, 0.0f));
				~Mario();
				void tratar_eventos();
				static unsigned int get_pontuacao() { return pontos; }
				void reiniciar();
			};
		}
	}
}