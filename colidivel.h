#pragma once
#include "Entidade.h"
#include "IDsEntidades.h"
#include "Vector2D.h"

namespace Game
{
	class colidivel:
		public Entidade
	{
	public:
		colidivel(IDsEntidades::IDsEntidades id = IDsEntidades::Inimigo, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr):
			Entidade(id, pos, vel, caminho_textura)
		{

		}
		~colidivel(){}
		virtual void colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro) = 0;
	};

}

