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
	public:
		Jogador(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f));
		~Jogador();
		void inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc);
		void atualizar(float t);
		void desenhar(GerenciadorGrafico& gg);
		void tratar_eventos();
		void colidir(Entidade* ente, Vector2F intersse);
		void pular();
		void andar(bool esquerda);
		void bordas();
	};

}
