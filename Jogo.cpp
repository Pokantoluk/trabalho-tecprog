#include "Jogo.h"
#include "stdafx.h"
using namespace std;

namespace Jogo
{

	Jogo::Jogo() :
		gg(),
		ge(),
		gm(),
		fase_1(nullptr),
		fase_2(nullptr),
		jogador_1(nullptr),
		jogador_2(nullptr),
		dois_jogadores(false),
		num_fase(0),
		na_fase(false),
		m_vidas(VIDAS),
		l_vidas(VIDAS)
	{
		ge.set_janela(gg.get_janela());
		executar();
	}

	Jogo::~Jogo()
	{
	}
	void Jogo::inicializar_fase_1()
	{
		jogador_1 = new Entidades::Personagens::Mario(Vector2F(50.0f, 650.0f), m_vidas);
		jogador_2 = new Entidades::Personagens::Luigi(Vector2F(20.0f, 650.0f), l_vidas);
		fase_1 = new Fases::Fase_1();
		fase_1->inserir_jogador(jogador_1);
		
		if (dois_jogadores)
		{
			fase_1->inserir_jogador(jogador_2);
		}
		fase_1->inicializar_entidades();
	}
	void Jogo::inicializar_fase_2()
	{
		jogador_1 = new Entidades::Personagens::Mario(Vector2F(50.0f, 650.0f), m_vidas);
		jogador_2 = new Entidades::Personagens::Luigi(Vector2F(20.0f, 650.0f), l_vidas);
		fase_2 = new Fases::Fase_2();
		fase_2->inserir_jogador(jogador_1);
		if (dois_jogadores)
		{
			fase_2->inserir_jogador(jogador_2);
		}
		fase_2->inicializar_entidades();
	}
	void Jogo::terminar_fase_1()
	{
		if (fase_1) 
		{
			fase_1->destruir_fase();
			delete fase_1;
			fase_1 = nullptr;
			jogador_1 = nullptr;
		}
	}
	void Jogo::terminar_fase_2()
	{
		if (fase_2)
		{
			fase_2->destruir_fase();
			delete fase_2;
			fase_2 = nullptr;
		}
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
			num_fase = gm.get_fase();
			if (gm.get_num_jogadores() == 2)
			{
				dois_jogadores = true;
			}
			else
			{
				dois_jogadores = false;
			}
			if (num_fase == 0) 
			{
				terminar_fase_1();
				terminar_fase_2();
				na_fase = false;
				gm.executar();
			}
			else if (num_fase == 1)
			{
				if (!na_fase)
				{
					inicializar_fase_1();
					na_fase = true;
				}
				else
				{
					if (!jogador_1->get_vida() && !jogador_2->get_vida() && dois_jogadores)
					{
						gm.set_gameover();
					}
					else if (!jogador_1->get_vida() && !dois_jogadores)
					{						
						gm.set_gameover();
					}
					else if (fase_1->get_pausa())
					{
						gm.set_pausa();
					}
					else {
						fase_1->executar(t.asSeconds());
						if (dois_jogadores)
						{
							if (!jogador_1->get_vida())
							{
								gg.centralizar(jogador_2->get_pos(), jogador_2->get_pos());
							}
							else if (!jogador_2->get_vida())
							{
								gg.centralizar(jogador_1->get_pos(), jogador_1->get_pos());
							}
							else
							{
								gg.centralizar(jogador_1->get_pos(), jogador_2->get_pos());
							}
						}
						else
							gg.centralizar(jogador_1->get_pos(), jogador_1->get_pos());
						if (fase_1->get_fim())
						{
							m_vidas = jogador_1->get_vida();
							l_vidas = jogador_2->get_vida();
							gm.set_fase(2);
							na_fase = false;
						}
					}
				}
			}
			else if (num_fase == 2)
			{
				if (!na_fase)
				{
					inicializar_fase_2();
					na_fase = true;
				}
				else
				{
					
					if (!jogador_1->get_vida() && !jogador_2->get_vida() && dois_jogadores)
					{
						gm.set_gameover();
							
					}
					else if (!jogador_1->get_vida())
					{			
						gm.set_gameover();
					}
					else if (fase_2->get_pausa())
					{
						gm.set_pausa();
					}
					else 
					{
						fase_2->executar(t.asSeconds());
						if (dois_jogadores)
						{
							if (!jogador_1->get_vida())
							{
								gg.centralizar(jogador_2->get_pos(), jogador_2->get_pos());
							}
							else if (!jogador_2->get_vida())
							{
								gg.centralizar(jogador_1->get_pos(), jogador_1->get_pos());
							}
							else
							{
								gg.centralizar(jogador_1->get_pos(), jogador_2->get_pos());
							}
						}
						else
							gg.centralizar(jogador_1->get_pos(), jogador_1->get_pos());
						if (fase_2->get_fim())
						{
							gm.set_fase(3);
						}
					}
				}
			}
			else
			{
				gm.set_gameover();
			}
			gg.mostrar();
		}
	}
}
