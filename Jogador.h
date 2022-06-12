#pragma once
#include "Personagem.h"

#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#define VIDA_MAX  5

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{

			class Jogador :
				public Personagem
			{
			protected:
				
				bool andando;
				bool pode_pular;
				bool olhando_esquerda;
				const char* caminho_e;
				const char* caminho_cinza;
				const char* caminho_cinza_e;
				bool morto;
				static int pontuacao;
				bool terminou_fase;

			public:
				

				Jogador(Vector2F pos = Vector2F(0.0f, 0.0f), const char* caminho = nullptr, const char* caminho_e = nullptr, const char* caminho_cinza = nullptr, const char* caminho_cinza_e = nullptr, unsigned int vidas = VIDA_MAX);
				~Jogador();
				void executar(float t);
				void inicializar();
				void set_posicao(Vector2F pos) { posicao = pos; }
				void atualizar(float t);
				void imprimir_se();
				void colidir(Entidade* ente, Vector2F intersse);
				void pular();
				void andar(bool esquerda);
				void bordas();
				void set_pode_pular(bool pode) { pode_pular = pode; }
				virtual void tratar_eventos();
				static void incrementar_pontuacao(int pontos) { pontuacao += pontos; std::cout << "\t" << pontuacao << std::endl; }
				static int get_pontuacao() { return pontuacao; }
				const unsigned int get_vida() const { return vidas; }
				
			};
		}
	}
}
