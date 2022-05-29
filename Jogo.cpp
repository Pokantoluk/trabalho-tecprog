#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo()
	{
		entities.inserir(new Jogador(Vector2F(50.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/mario.png"));
		entities.inserir(new Inimigo(Vector2F(50.0f, 50.0f), Vector2F(0.1f, 0.1f), "assets/goomba.png"));
		entities.inicializar_entidades(gg, ge);
		ge.set_janela(gg.get_janela());
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
			ge.tratar_eventos();
			gg.limpar();
			entities.update(t.asSeconds());
			entities.draw(gg);
			gg.get_janela()->display();
		}
	}
}
