#pragma once
#include "GerenciadorGrafico.h"



namespace Game
{
	namespace Entidades 
	{
		class Jogador;
	}
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