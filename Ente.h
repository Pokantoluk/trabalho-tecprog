#pragma once
#include "IDsEntidades.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"

namespace Jogo
{
	class Ente
	{
	protected:
		IDsEntidades::IDsEntidades id;
		const char* caminho;
		Vector2F posicao;
	public:
		Ente(Vector2F posicao = (0.0f, 0.0f), const char* caminho = nullptr, IDsEntidades::IDsEntidades id = IDsEntidades::IDsEntidades::Inimigo);
		~Ente();
		virtual void executar(float t) = 0;
		virtual void imprimir_se();
	};
}

