#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Fase_1.h"
#include "Fase_2.h"
#include "Jogador.h"
#include "Menu.h"


namespace Game 
{
	class Jogo
	{
	private:
		Menu menu;
		Entidades::Jogador* jogador;
		Fases::Fase_1 fase_1;
		Fases::Fase_2 fase_2;
		GerenciadorGrafico gg;
		GerenciadorEventos ge;
		sf::Clock relogio;

	public:
		static bool na_fase;
		Jogo();
		~Jogo();
		void inicializar_fase_1();
		void inicializar_fase_2();
		void reiniciar_fase();
		void reiniciar_fase_2();
		void executar();
	};
}

