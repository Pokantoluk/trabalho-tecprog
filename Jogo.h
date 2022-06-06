#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Fase.h"
#include "Jogador.h"
#include "Menu.h"


namespace Game 
{
	class Jogo
	{
	private:
		Menu menu;
		Entidades::Jogador* jogador;
		Fases::Fase fase;
		GerenciadorGrafico gg;
		GerenciadorEventos ge;
		sf::Clock relogio;

	public:
		static bool na_fase;
		Jogo();
		~Jogo();
		void inicializar();
		void reiniciar_fase();
		void executar();
	};
}

