#pragma once
#include "Personagem.h"

#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"


namespace Game
{
	class ComponenteGrafico;
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
			std::vector<ComponenteGrafico*> componentes;

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

			
			bool get_morto();
			const unsigned int get_vida() const { return vidas; }
		};
	}
}
