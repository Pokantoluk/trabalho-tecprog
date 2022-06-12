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
			public:

				Luigi(Vector2F pos = Vector2F(0.0f, 0.0f), unsigned int vidas = 5);
				~Luigi();
				void tratar_eventos();
			};
		}
	}
}

