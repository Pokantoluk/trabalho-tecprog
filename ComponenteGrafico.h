#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"


namespace Jogo
{
	class ComponenteGrafico
	{
	protected:

		Entidades::Personagens::Jogador* jogador;
 
	public:
		ComponenteGrafico(Entidades::Personagens::Jogador* jog = nullptr):
			jogador(jog)
		{
		}

		~ComponenteGrafico(){}
		virtual void executar() = 0;
	
	};
}