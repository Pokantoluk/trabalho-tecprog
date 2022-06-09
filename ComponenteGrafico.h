#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Game
{

	class ComponenteGrafico
	{
	protected:
		
 
	public:
		ComponenteGrafico();
		~ComponenteGrafico();
		virtual void executar() = 0;
		virtual void atualizar(Entidades::Jogador* jogador) {};

	};
}