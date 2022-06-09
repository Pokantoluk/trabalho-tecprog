#include "Jogo.h"
#include "stdafx.h"
using namespace std;

namespace Jogo
{
	bool Jogo::na_fase{ false };

	Jogo::Jogo() :
		ge(),
		gg(),
		fase_1(),
		fase_2(),
		jogador_1(),
		jogador_2(),
		dois_jogadores(false)
	{
		jogador_1 = new Entidades::Personagens::Mario(Vector2F(50.0f, 650.0f));
		jogador_2 = new Entidades::Personagens::Luigi(Vector2F(20.0f, 650.0f));
		ge.set_janela(gg.get_janela());
		menu.iniciar();
		executar();
	}

	Jogo::~Jogo()
	{
	}
	void Jogo::inicializar_fase_1()
	{
		fase_1.inserir_jogador(jogador_1);
		
		if (dois_jogadores)
		{
			fase_1.inserir_jogador(jogador_2);
		}
		fase_1.inicializar_entidades();
	}
	void Jogo::inicializar_fase_2()
	{
		fase_2.inserir_jogador(jogador_1);
		fase_2.inicializar_entidades();
		if (dois_jogadores)
		{
			fase_1.inserir_jogador(jogador_2);
		}
	}
	void Jogo::reiniciar_fase()
	{
		fase_1.reiniciar_entidades(Vector2F(50.0f, 650.0f));
	}
	void Jogo::reiniciar_fase_2()
	{
		fase_2.reiniciar_entidades(Vector2F(50.0f, 650.0f));
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
			if (menu.get_jogadores() == 2)
			{
				dois_jogadores = true;
			}
			else
			{
				dois_jogadores = false;
			}
			if (menu.get_fase() == 0)
				menu.executar(t.asSeconds());
			else if (menu.get_fase() == 1)
			{
				if (!na_fase)
				{
					inicializar_fase_1();
					fase_1.carregar_fundo();
					na_fase = true;
				}
				if (fase_1.get_pausa())
				{
					menu.menu_pausa();
				}
				else
				{
					if (jogador_1->get_morto() && jogador_2->get_morto())
					{
						menu.menu_JogoOver();
					}
					else
						fase_1.executar(t.asSeconds());
				}
			}
			else if (menu.get_fase() == 2)
			{
				if (!na_fase)
				{
					inicializar_fase_2();
					fase_2.carregar_fundo();
					na_fase = true;
				}
				if (fase_2.get_pausa())
				{
					menu.menu_pausa();
				}
				else
				{
					if (jogador_1->get_morto() && jogador_2->get_morto())
					{
						menu.menu_JogoOver();
					}
					else
						fase_2.executar(t.asSeconds());
				}
			}
			if (dois_jogadores)
				gg.centralizar(jogador_1->get_pos(), jogador_2->get_pos());
			else
				gg.centralizar(jogador_1->get_pos(), jogador_1->get_pos());
			gg.mostrar();
		}
	}
}
