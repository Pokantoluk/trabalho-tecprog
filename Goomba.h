#pragma once
#include"Inimigo.h"

namespace Game 
{
	namespace Entidades
	{
		namespace Personagens
		{

			class Goomba :
				public	Inimigo
			{
			public:
				Goomba(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
				~Goomba();
				void colidir(Entidade* ente, Vector2F intersse);

			};

		}
	}
}