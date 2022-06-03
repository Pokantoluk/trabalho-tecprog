#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo():
		gc(&entidades_moveis, &entidades_estaticas)
	{
		entidades_moveis.inserir(new Jogador(Vector2F(50.0f, 650.0f)));
		entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(300.0f, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(600.0f, 650.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(1000.0f, 650.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		entidades_moveis.inicializar_entidades(gg);
		entidades_estaticas.inicializar_entidades(gg);
		ge.set_janela(gg.get_janela());
		executar();
	}

	Jogo::~Jogo()
	{
		entidades_moveis.destruir();
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
			entidades_moveis.percorrer_executar(t.asSeconds(), gg);
			gc.verificar_colisoes();
			gg.mostrar();
		}
	}
}
