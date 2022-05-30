#pragma once
#include "Entidade.h"

namespace Game
{
	class Inimigo :
		public Entidade
	{
	private:

	public:
		Inimigo(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		~Inimigo();
		void inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc);
		void atualizar(float t);
		void desenhar(GerenciadorGrafico& gg);
		void colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro);

	};

}
