#pragma once
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Fase_1.h"
#include "Fase_2.h"
#include "Mario.h"
#include "Luigi.h"
#include "GerenciadorMenu.h"
#define VIDAS 5

namespace Jogo 
{
	class Jogo
	{
	private:
		Entidades::Personagens::Mario* jogador_1;
		Entidades::Personagens::Luigi* jogador_2;
		Fases::Fase_1* fase_1;
		Fases::Fase_2* fase_2;
		Gerenciadores::GerenciadorGrafico gg;
		Gerenciadores::GerenciadorEventos ge;
		Gerenciadores::GerenciadorMenu gm;
		sf::Clock relogio;
		unsigned int m_vidas;
		unsigned int l_vidas;
		bool dois_jogadores;
		int num_fase;
		bool na_fase;

	public:
		Jogo();
		~Jogo();

		void inicializar_fase_1();
		void inicializar_fase_2();
		void terminar_fase_1();
		void terminar_fase_2();
		

		void executar();
	};
}

