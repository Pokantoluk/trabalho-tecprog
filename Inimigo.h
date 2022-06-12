#pragma once
#include "Personagem.h"
#include "IDsEntidades.h"


namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Inimigo :
				public Personagem
			{
			protected:
				int pontos;
			public:
				Inimigo(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr, const int vidas = 1, const int pontuacao = 10);
				virtual ~Inimigo();
				virtual void executar(float t);
				void inicializar();
				virtual void atualizar(float t);
				virtual void colidir(Entidade* ente, Vector2F intersse) {}
				void bordas();
				bool ObjetoEmCima(Entidade* ente);
			
			};

		}
	}
}
