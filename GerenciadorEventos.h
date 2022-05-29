#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <functional>

namespace Game
{
	class GerenciadorEventos
	{
	private:
		static unsigned int proximoID;
		sf::RenderWindow* janela;
		std::map<unsigned int, std::function<void(const sf::Event&)>> mouse;
		std::map<unsigned int, std::function<void(const sf::Event&)>> teclado;
		std::map<unsigned int, std::function<void(const sf::Event&)>> outros;

	public:
		GerenciadorEventos();
		~GerenciadorEventos();

		void tratar_eventos();
		void set_janela(sf::RenderWindow* janela);

		/**/
		unsigned int add_ouvinte_mouse(std::function<void(const sf::Event&)> chamada);
		unsigned int add_ouvinte_teclado(std::function<void(const sf::Event&)> chamada);
		unsigned int add_ouvinte_outros(std::function<void(const sf::Event&)> chamada);
		/**/
		void rm_ouvinteMouse(int id);
		void rm_ouvinte_teclado(int id);
		void rm_ouvinte_outros(int id);

	};

}

