#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo()
		//janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo", sf::Style::Default))
	{
		entities.inserir(new Entidade(Vector2F(50.0f, 50.0f), Vector2F(0.1f, 0.2f), "assets/mario.png"));
		//jogadores.inserir(new Personagem(Vector2F(50.0f, 50.0f), Vector2F(0.2f, 0.1f), "assets/mario.png"));
		entities.inicializar_entidades(gg, ge);
		executar();
		
	}

	Jogo::~Jogo()
	{
		entities.destruir();
	}

	void Jogo::executar()
	{
		relogio.restart();
		while (gg.get_janela()->isOpen())
		{
			sf::Time t = relogio.getElapsedTime();
			relogio.restart();
			sf::Event evento;
			while (gg.get_janela()->pollEvent(evento))
			{
				
				switch (evento.type)
				{
				case sf::Event::Closed:
					gg.get_janela()->close();
					break;
				case sf::Event::TextEntered:
					if (evento.text.unicode < 128)
						printf("%c", evento.text.unicode);
				}
			}
			gg.limpar();
			entities.update(t.asSeconds());
			entities.draw(gg);
			gg.get_janela()->display();
		}
	}
}
