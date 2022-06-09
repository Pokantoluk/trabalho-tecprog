#pragma once
#include "Personagem.h"
#include "IDsEntidades.h"


namespace Game
{
	namespace Entidades
	{
		class Inimigo :
			public Personagem
		{
		public:
			Inimigo(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr, int vidas =1);
			virtual ~Inimigo();
			void executar(float t);
			void inicializar();
			void atualizar(float t);
			virtual void colidir(Entidade* ente, Vector2F intersse){}
			void bordas();
			bool ObjetoEmCima(Entidade* ente);
		};
	}
}
