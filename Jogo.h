#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Fase.h"
#include "Jogador.h"


namespace Game 
{
	class Jogo
	{
	private:
		Entidades::Jogador* jogador;
		Fases::Fase fase;
		GerenciadorGrafico gg;
		GerenciadorEventos ge;
		sf::Clock relogio;
	public:
		Jogo();
		~Jogo();
		void executar();
	};
}

