#include "jogador.h"
#include <iostream>

namespace Game
{
	Jogador::Jogador(Vector2F pos, Vector2F vel, const char* caminho_textura) :
		Entidade(IDsEntidades::Jogador, pos, vel, caminho_textura)
	{
	}

	Jogador::~Jogador()
	{
	}

	void Jogador::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
		gg.carregar_textura(caminho);
		dimensao = gg.get_tamanho(caminho);
	}

	void Jogador::atualizar(float t)
	{
		tratar_eventos();
		posicao += v*t;
	}

	void Jogador::desenhar(GerenciadorGrafico& gg)
	{
		gg.centralizar(posicao);
		gg.desenhar(caminho, posicao);
	}

	void Jogador::tratar_eventos()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			v.x += 1.f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			v.x -= 1.f;
		}
		else
		{
			v.x = 0;
		}
		if (v.x > 500.f) { v.x = 500.f; }
		if (v.x < -500.f) { v.x = -500.f; }
	}

	void Jogador::colidir(Entidade* ente, Vector2F intersse)
	{
		if (ente->get_id() == IDsEntidades::obstaculo)
		{
			v.y = 0.f;
			v.y -= 2.f;
		}
	}

}
