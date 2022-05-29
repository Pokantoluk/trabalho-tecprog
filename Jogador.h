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
		unsigned int id;
	public:
		Jogador(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		~Jogador();
		void inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge);
		void atualizar(float t);
		void desenhar(GerenciadorGrafico& gg);
		void tratar_eventos();
	};

}
