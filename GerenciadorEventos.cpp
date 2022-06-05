#include "GerenciadorEventos.h"
#include "stdafx.h"

namespace Game
{
	unsigned int GerenciadorEventos::proximoID{ 0 };

	GerenciadorEventos::GerenciadorEventos()
	{
	}

	GerenciadorEventos::~GerenciadorEventos()
	{
	}

	void GerenciadorEventos::tratar_eventos()
	{
		sf::Event evento;
		while (janela->pollEvent(evento))
		{

			if (evento.type == sf::Event::MouseButtonPressed ||
				evento.type == sf::Event::MouseButtonReleased ||
				evento.type == sf::Event::MouseMoved ||
				evento.type == sf::Event::MouseWheelScrolled)
			{
				for (auto& it : mouse)
				{
					it.second(evento);
				}
			}
			else if (evento.type == sf::Event::KeyPressed ||
				evento.type == sf::Event::KeyReleased)
			{
				for (auto& it : teclado)
				{
					it.second(evento);
				}
			}
			else
			{
				for (auto& it : outros)
				{
					it.second(evento);
				}
			}
		}
		if (evento.type == sf::Event::Closed)
		{
			janela->close();
		}
	}

	void GerenciadorEventos::set_janela(sf::RenderWindow* janela)
	{
		this->janela = janela;
	}

	unsigned int GerenciadorEventos::add_ouvinte_mouse(std::function<void(const sf::Event&)> chamada)
	{
		mouse.emplace(proximoID, chamada);
		return proximoID++;
	}

	unsigned int GerenciadorEventos::add_ouvinte_teclado(std::function<void(const sf::Event&)> chamada)
	{
		teclado.emplace(proximoID, chamada);
		return proximoID++;;
	}

	unsigned int GerenciadorEventos::add_ouvinte_outros(std::function<void(const sf::Event&)> chamada)
	{
		outros.emplace(proximoID, chamada);
		return proximoID++;
	}

	void GerenciadorEventos::rm_ouvinteMouse(int id)
	{
		mouse.erase(id);
	}

	void GerenciadorEventos::rm_ouvinte_teclado(int id)
	{
		teclado.erase(id);
	}

	void GerenciadorEventos::rm_ouvinte_outros(int id)
	{
		outros.erase(id);
	}
}
