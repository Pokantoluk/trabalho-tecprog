#pragma once
#include "Entidade.h"
#include "GerenciadorEventos.h"
#include "SFML/Graphics.hpp"




namespace Game
{
	class Jogador :
		public Entidade
		
	{
	private:
		bool andando;
		bool pode_pular;
		bool olhando_esquerda;
		const char* caminho_e;
		unsigned int vidas;
		bool morto;
	public:
		Jogador(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f));
		~Jogador();
		void executar(float t, GerenciadorGrafico& gg);
		void inicializar(GerenciadorGrafico& gg);
		void atualizar(float t);
		void tratar_eventos();
		void colidir(Entidade* ente, Vector2F intersse);
		void pular();
		void andar(bool esquerda);
		void bordas();
	};

}
