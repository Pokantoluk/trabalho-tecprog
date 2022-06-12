#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Fase_1.h"
#include "Fase_2.h"
#include "Mario.h"
#include "Luigi.h"
#include "GerenciadorMenu.h"


namespace Jogo 
{
	class Jogo
	{
	private:
		Entidades::Personagens::Mario* jogador_1;
		Entidades::Personagens::Luigi* jogador_2;
		Fases::Fase_1 fase_1;
		Fases::Fase_2 fase_2;
		Gerenciadores::GerenciadorGrafico gg;
		Gerenciadores::GerenciadorEventos ge;
		Gerenciadores::GerenciadorMenu gm;
		sf::Clock relogio;
		bool dois_jogadores;
		bool acabou_fase;

	public:
		static bool na_fase;
		Jogo();
		~Jogo();
		void inicializar_fase_1();
		void inicializar_fase_2();
		void executar();
	};
}

