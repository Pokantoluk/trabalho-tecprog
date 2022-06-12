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
			public:
				Mario(Vector2F pos = Vector2F(0.0f, 0.0f), unsigned int vidas = 5);
				~Mario();
				void tratar_eventos();
				
				void reiniciar();
			};
		}
	}
}