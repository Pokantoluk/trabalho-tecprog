#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo()
	{
		entities.inserir(new Jogador(Vector2F(50.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/mario.png"));
		entities.inserir(new Inimigo(Vector2F(300.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entities.inserir(new Inimigo(Vector2F(600.0f, 500.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entities.inserir(new Inimigo(Vector2F(600.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entities.inicializar_entidades(gg, ge, gc);
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
			gc.verificar_colisoes();
			entities.draw(gg);
			gg.get_janela()->display();
		}
	}
}
