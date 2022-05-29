#pragma once
#include "Entidade.h"

namespace Game
{
	class Inimigo :
		public Entidade
	{
	private:

	public:
		Inimigo(bool vivo = true, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		~Inimigo();

	};

}
