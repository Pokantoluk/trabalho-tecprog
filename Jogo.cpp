#include "Jogo.h"
#include <iostream>

namespace Game 
{
	Jogo::Jogo():
		ge(),
		gg(),
		fase(),
		jogador(new Entidades::Jogador(Vector2F(50.0f, 650.0f)))
	{
		ge.set_janela(gg.get_janela());
		menu.iniciar(gg);
		//fase.carregar_fundo(gg);
		//fase.inserir_jogador(jogador);
		//fase.inicializar_entidades(gg);
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
			menu.executar(t.asSeconds(), gg);
			//fase.executar(t.asSeconds(), gg);
			gg.mostrar();
		}
	}
}
