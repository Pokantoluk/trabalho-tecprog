#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo()
	{
		entidades.inserir(new Jogador(Vector2F(50.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/mario.png"));
		entidades.inserir(new Inimigo(Vector2F(300.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades.inserir(new Inimigo(Vector2F(600.0f, 500.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades.inserir(new Inimigo(Vector2F(600.0f, 50.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades.inicializar_entidades(gg, ge, gc);
		ge.set_janela(gg.get_janela());
		executar();
	}

	Jogo::~Jogo()
	{
		entidades.destruir();
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
			entidades.atualizar(t.asSeconds());
			gc.verificar_colisoes();//retirar o Entidade
			entidades.percorrer_desenhar(gg);
			gg.get_janela()->display();
		}
	}
}
