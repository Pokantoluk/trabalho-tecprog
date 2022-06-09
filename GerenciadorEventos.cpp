#include "GerenciadorEventos.h"
#include "stdafx.h"

namespace Game
{
	namespace Gerenciadores 
	{
		bool GerenciadorEventos::escrevendo{ false };
		std::string GerenciadorEventos::nome{ "" };
		GerenciadorEventos::GerenciadorEventos() :
			janela()
		{
		}
		GerenciadorEventos::~GerenciadorEventos()
		{
			janela = nullptr;
		}
		void GerenciadorEventos::tratar_eventos()
		{
			sf::Event evento;
			while (janela->pollEvent(evento))
			{
				if (evento.type == sf::Event::Closed)
				{
					janela->close();
				}
				else if (evento.type == sf::Event::TextEntered)
				{
					if ((evento.text.unicode > 64 && evento.text.unicode < 128) && escrevendo)
						nome += evento.text.unicode;
					else if (evento.text.unicode == 8) {
						nome.pop_back();
					}
				}
			}

		}
		void GerenciadorEventos::set_janela(sf::RenderWindow* janela)
		{
			this->janela = janela;
		}
	}
}
