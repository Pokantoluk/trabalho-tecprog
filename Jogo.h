#pragma once
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"


namespace Game 
{
	class Jogo
	{
	private:
		ListaEntidades entidades;
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

