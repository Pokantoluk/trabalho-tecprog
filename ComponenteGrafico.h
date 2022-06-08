#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"

namespace Game
{

	class ComponenteGrafico
	{
	protected:
		static GerenciadorGrafico* gg;
 
	public:
		ComponenteGrafico();
		~ComponenteGrafico();
		virtual void executar() = 0;
		virtual void atualizar(Entidades::Jogador* jogador) {};

	};

	GerenciadorGrafico* ComponenteGrafico::gg = GerenciadorGrafico::get_gerenciador();

}