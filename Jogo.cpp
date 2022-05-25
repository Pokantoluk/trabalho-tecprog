#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo()
		//janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo", sf::Style::Default))
	{
		jogadores.inserir(new Personagem(Vector2F(50.0f, 50.0f), Vector2F(1.f, 2.f), "mario.png"));
		jogadores.inserir(new Personagem(Vector2F(50.0f, 50.0f), Vector2F(2.f, 1.f), "mario.png"));
		executar();
		
	}

	Jogo::~Jogo()
	{
		jogadores.destruir();
	}

	void Jogo::executar()
	{
		relogio.restart();
		while (gerenciador_grafico.get_janela()->isOpen())
		{
			sf::Time t = relogio.getElapsedTime();
			relogio.restart();
			sf::Event evento;
			while (gerenciador_grafico.get_janela()->pollEvent(evento))
			{
				
				switch (evento.type)
				{
				case sf::Event::Closed:
					gerenciador_grafico.get_janela()->close();
					break;
				case sf::Event::TextEntered:
					if (evento.text.unicode < 128)
						printf("%c", evento.text.unicode);
				}
			}
			gerenciador_grafico.limpar();
			jogadores.update(t.asSeconds());
			jogadores.draw(gerenciador_grafico.get_janela());
		}
	}
}
