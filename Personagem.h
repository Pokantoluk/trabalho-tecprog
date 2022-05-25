#pragma once
#include "Entidade.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"


namespace Game 
{
	class Personagem :
		public Entidade
	{
	private:
		Vector2F position;
		Vector2F v;
		const char* caminho;
	public:
		Personagem(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		~Personagem();
		void atualizar(float t);
		void desenhar(GerenciadorGrafico &g);

	};
}

