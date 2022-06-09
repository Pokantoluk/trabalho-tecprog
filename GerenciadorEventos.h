#pragma once
#include "SFML/Graphics.hpp"
#include "stdafx.h"

namespace Jogo
{
	namespace Gerenciadores
	{

	class GerenciadorEventos
	{
	private:
		sf::RenderWindow* janela;
		static std::string nome;
		static bool escrevendo;

	public:
		GerenciadorEventos();
		~GerenciadorEventos();

		void tratar_eventos();
		void set_janela(sf::RenderWindow* janela);
		static void escrever_nome(const bool e) { escrevendo = e; }
		static std::string get_nome() { return nome; }
	};
	}
}

