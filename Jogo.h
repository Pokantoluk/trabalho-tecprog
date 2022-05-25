#pragma once
#include "ListaPersonagens.h"
#include "GerenciadorGrafico.h"


namespace Game 
{
	class Jogo
	{
	private:
		ListaPersonagens jogadores;
		GerenciadorGrafico gerenciador_grafico;
		sf::Clock relogio;
	public:
		Jogo();
		~Jogo();
		void executar();
	};
}

