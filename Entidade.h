#pragma once
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"
#include "IDsEntidades.h"
#include "GerenciadorColisoes.h"


namespace Game 
{
	class Entidade :
		public Ente
	{
	protected:
		Vector2F position;
		Vector2F v;
		Vector2F dimension;
		const char* caminho;
		IDsEntidades::IDsEntidades id;
	public:
		Entidade(IDsEntidades::IDsEntidades id, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		virtual ~Entidade();
		virtual void inicializar(GerenciadorGrafico& g, GerenciadorColisoes& gc);
		virtual void atualizar(float t);
		virtual void desenhar(GerenciadorGrafico &g);
		const Vector2F get_dimentions() const;
		const Vector2F get_pos() const { return position; }
		const IDsEntidades::IDsEntidades get_id() const;

	};
}

