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
			public:

				Luigi(Vector2F pos = Vector2F(0.0f, 0.0f));
				~Luigi();
				void tratar_eventos();

			};
		}
	}
}

