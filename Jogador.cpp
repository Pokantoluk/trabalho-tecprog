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
		gc.add_Entidade(this);
	}

	void Jogador::atualizar(float t)
	{
		//gravidade();
		tratar_eventos();
		//std::cout << v.x <<v.y<< std::endl;
		//std::cout << posicao.x<<std::endl;
		posicao += v*t;
	}

	void Jogador::desenhar(GerenciadorGrafico& gg)
	{
		gg.centralizar(posicao);
		gg.desenhar(caminho, posicao);
	}

	void Jogador::tratar_eventos(/*const sf::Event& e*/)
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

	void Jogador::colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro)
	{
	}

	void Jogador::gravidade()
	{
		v.y += 0.0002f;
		if (v.y > 0.2f) { v.y = 0.2f; }
	}

}
