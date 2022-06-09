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
				Mario(Vector2F pos = Vector2F(0.0f, 0.0f));
				~Mario();
				void tratar_eventos();
			};
		}
	}
}