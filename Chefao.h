#pragma once
#include"Inimigo.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Chefao :
				public	Inimigo
			{
			private:
			public:
				Chefao(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
				~Chefao();
				void colidir(Entidade* ente, Vector2F intersse);
			};
		}
	}
}