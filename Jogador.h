#pragma once
#include "Personagem.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"

namespace Game
{
	namespace Entidades
	{
		class Jogador :
			public Personagem
		{
		private:
			static int pontos;
			bool andando;
			bool pode_pular;
			bool olhando_esquerda;
			const char* caminho_e;
			bool morto;
		public:
			static unsigned int get_pontuacao();

			Jogador(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f));
			~Jogador();
			void executar(float t);
			void inicializar();
			void set_posicao(Vector2F pos) { posicao = pos; }
			void atualizar(float t);
			void tratar_eventos();
			void colidir(Entidade* ente, Vector2F intersse);
			void pular();
			void andar(bool esquerda);
			void bordas();
			void set_pode_pular(bool pode) { pode_pular = pode; }

		};
	}
}
