#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"


namespace Game 
{
	class Jogo
	{
	private:
		ListaEntidades entities;
		GerenciadorGrafico gg;
		GerenciadorEventos ge;
		GerenciadorColisoes gc;
		sf::Clock relogio;
	public:
		Jogo();
		~Jogo();
		void executar();

	};
}

