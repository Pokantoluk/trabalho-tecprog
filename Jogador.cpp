#include "jogador.h"
#include <iostream>

namespace Game
{
	Jogador::Jogador(Vector2F pos, Vector2F vel) :
		Entidade(IDsEntidades::Jogador, pos, vel, "assets/mario.png"),
		andando(false),
		olhando_esquerda(false),
		pode_pular(false),
		caminho_e("assets/mario_e.png")
	{
	}

	Jogador::~Jogador()
	{
	}

	void Jogador::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
		gg.carregar_textura(caminho_e);
		gg.carregar_textura(caminho);
		dimensao = gg.get_tamanho(caminho);
	}

	void Jogador::atualizar(float t)
	{
		tratar_eventos();
		bordas();
		if (andando) 
		{
			v.x = VEL_JOGADOR;
			if (olhando_esquerda) 
			{
				v.x *= -1;

			}
		}
		else { v.x *= 0.5; }
		if (!pode_pular)
		{
			v.y += GRAVIDADE * t;
		}
		posicao += v * t;
	}

	void Jogador::desenhar(GerenciadorGrafico& gg)
	{
		gg.centralizar(posicao);
		if (olhando_esquerda)
		{
			gg.desenhar(caminho_e, posicao);
		}
		else
		{
			gg.desenhar(caminho, posicao);
		}
	}

	void Jogador::tratar_eventos()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			andar(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			andar(true);
		}
		else
		{
			andando = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			pular();
		}
	}

	void Jogador::colidir(Entidade* ente, Vector2F intersse)
	{
		if (ente->get_id() == IDsEntidades::obstaculo)
		{
		}
	}

	void Jogador::pular()
	{
		if (pode_pular)
		{
			v.y = -sqrtf(2.0f * GRAVIDADE * PULO);
		}
	}

	void Jogador::andar(bool esquerda)
	{
		andando = true;
		olhando_esquerda = esquerda;
	}

	void Jogador::bordas()
	{
		if (posicao.x < 0) { posicao.x = 0; }
		if (posicao.y + dimensao.y >= 800)
		{
			posicao.y = 800 - dimensao.y;
			pode_pular = true;
		}
		else
		{
			pode_pular = false;
		}
	}

}
