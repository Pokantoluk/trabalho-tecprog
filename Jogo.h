#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"


namespace Game 
{
	class Jogo
	{
	private:
		ListaEntidades entities;
		GerenciadorGrafico gg;
		GerenciadorEventos ge;
		sf::Clock relogio;
	public:
		Jogo();
		~Jogo();
		void executar();
	};
}

