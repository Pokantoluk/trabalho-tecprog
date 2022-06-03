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

	void Jogador::executar(float t, GerenciadorGrafico& gg)
	{
		atualizar(t);
		gg.centralizar(posicao);
		if (olhando_esquerda)
		{
			imprimir(gg, caminho_e, posicao);
		}
		else
		{
			imprimir(gg, caminho, posicao);
		}
	}

	void Jogador::inicializar(GerenciadorGrafico& gg)
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
			v.x = VEL_JOGADOR;//coloca a velocidade do jogador
			if (olhando_esquerda) 
			{
				v.x *= -1;//anda para o outro lado

			}
		}
		else 
		{ 
			v.x *= 0.5; 
		}
		if (!pode_pular)
		{
			v.y += GRAVIDADE * t;
		}
		posicao += v * t;
	}


	void Jogador::tratar_eventos()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			andar(false);//anda com falso para esquerda
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

	void Jogador::pular() //para fazer o personagem pular
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

	void Jogador::bordas()//para não sair da tela
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
