#include "Jogo.h"
#include <iostream>

namespace Game
{
	Jogo::Jogo() :
		ge(),
		gg(),
		fase(),
		jogador(new Entidades::Jogador(Vector2F(50.0f, 650.0f))),
		na_fase(false)
	{
	
		ge.set_janela(gg.get_janela());
		menu.iniciar();
		//fase.carregar_fundo(gg);
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
			if (!menu.get_fase())
				menu.executar(t.asSeconds(), gg);
			else
			{
				if (!na_fase)
				{
					fase.carregar_fundo(gg);
					na_fase = true;
				}
				if (fase.get_pausa() && menu.continuar())
				{
					menu.menu_pausa();
				}
				else
				{
					fase.executar(t.asSeconds(), gg);
				}
			}
			gg.mostrar();
		}
	}
}
