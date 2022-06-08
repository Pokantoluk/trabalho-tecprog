#pragma once
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"
#include "IDsEntidades.h"
#include "GerenciadorColisoes.h"

#define GRAVIDADE 1500.f
#define VEL_INIMIGO 100.f
#define VEL_JOGADOR 300.f
#define PULO 150.0f

namespace Game
{
	class Fase;
	class Entidade :
		public Ente
	{
	protected:
		Vector2F posicao;
		Vector2F v;
		Vector2F dimensao;
		bool gosma;
		const char* caminho;
		IDsEntidades::IDsEntidades id;
	public:
		Entidade(IDsEntidades::IDsEntidades id, Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
		virtual ~Entidade();
		virtual void executar(float t) = 0;
		virtual void colidir(Entidade* ente, Vector2F interssec) = 0;
		virtual void inicializar();
		virtual void atualizar(float t);
		virtual void machucar(int dano) {};

		void set_gosma(bool g) { gosma = g; }
		void set_vel(Vector2F vel);
		const Vector2F get_vel() const { return v; }
		void set_lista(ListaEntidades& l);
		const Vector2F get_dim() const { return dimensao; }
		const Vector2F get_pos() const { return posicao; }
		const IDsEntidades::IDsEntidades get_id() const { return id; }

	};
}

