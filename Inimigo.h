#pragma once
#include "Entidade.h"


namespace Game
{
	namespace Entidades
	{
		class Inimigo :
			public Entidade
		{
		private:
			bool no_chao;
		public:
			Inimigo(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
			~Inimigo();
			void executar(float t, GerenciadorGrafico& gg);
			void inicializar(GerenciadorGrafico& gg);
			void atualizar(float t);
			void colidir(Entidade* ente, Vector2F intersse);
			void bordas();
		};
	}
}
