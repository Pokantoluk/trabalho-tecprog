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
		bool encostou;
		Vector2F posicao;
		Vector2F v;
		Vector2F dimensao;
		const char* caminho;
		IDsEntidades::IDsEntidades id;
	public:
		Entidade(IDsEntidades::IDsEntidades id, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		virtual ~Entidade();
		virtual void colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro) = 0;
		virtual void inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc);
		virtual void atualizar(float t);
		virtual void desenhar(GerenciadorGrafico &gg);
		const Vector2F get_dim() const { return dimensao; }
		const Vector2F get_pos() const { return posicao; }
		const IDsEntidades::IDsEntidades get_id() const { return id; }

	};
}

