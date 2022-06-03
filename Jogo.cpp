#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo():
		jogador(),
		ge(),
		gg(),
		fase(&ge)
	{
		jogador = new Jogador(Vector2F(50.0f, 650.0f));
		fase.inserir_jogador(jogador);
		fase.inicializar_entidades(gg);
		executar();
	}

	Jogo::~Jogo()
	{

	}
	void Jogo::executar()
	{
		relogio.restart();
		while (gg.get_janela()->isOpen())
		{
			sf::Time t = relogio.getElapsedTime();
			relogio.restart();
			gg.limpar();
			ge.tratar_eventos();
			fase.executar(t.asSeconds(), gg);
			gg.mostrar();
		}
	}
}
