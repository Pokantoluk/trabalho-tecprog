#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"


namespace Game
{
	class ComponenteGrafico
	{
	protected:

		Entidades::Jogador* jogador;
 
	public:
		ComponenteGrafico(Entidades::Jogador* jog = nullptr):
			jogador(jog)
		{
		}

		~ComponenteGrafico(){}
		virtual void executar() = 0;
	
	};
}