#pragma once
#include "IDsEntidades.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"

namespace Game
{
	class Ente
	{
	protected:
		IDsEntidades::IDsEntidades id;
	public:
		Ente();
		~Ente();
		virtual void executar(float t) = 0;
		void imprimir(const char* caminho, Vector2F posicao);
	};

}

