#pragma once
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"


namespace Game 
{
	class Entidade :
		public Ente
	{
	protected:
		Vector2F position;
		Vector2F v;
		const char* caminho;
	public:
		Entidade(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		virtual ~Entidade();
		virtual void inicializar(GerenciadorGrafico& g);
		virtual void atualizar(float t);
		virtual void desenhar(GerenciadorGrafico &g);
		void gravidade();

	};
}

