#include "Jogo.h"
#include <iostream>

namespace Game
{
	bool Jogo::na_fase{ false };

	Jogo::Jogo() :
		ge(),
		gg(),
		fase(),
		jogador(new Entidades::Jogador(Vector2F(50.0f, 650.0f)))
	{
		ge.set_janela(gg.get_janela());
		inicializar();
		executar();
	}

	Jogo::~Jogo()
	{
	}
	void Jogo::inicializar()
	{
		menu.iniciar();
		fase.inserir_jogador(jogador);
		fase.inicializar_entidades();
	}
	void Jogo::reiniciar_fase()
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
			if (!menu.get_fase())
				menu.executar(t.asSeconds());
			else
			{
				if (!na_fase)
				{
					fase.carregar_fundo();
					na_fase = true;
				}
				if (fase.get_pausa())
				{
					menu.menu_pausa();
				}
				else
				{
					fase.executar(t.asSeconds());
				}
			}
			gg.mostrar();
		}
	}
}
