#include "jogador.h"
#include <iostream>

namespace Game
{
	Jogador::Jogador(Vector2F pos, Vector2F vel, const char* caminho_textura) :
		Entidade(vivo, pos, vel, caminho_textura)
	{
	}

	Jogador::~Jogador()
	{
	}

	void Jogador::inicializar(GerenciadorGrafico& gg, GerenciadorEventos& ge)
	{
		gg.carregar_textura(caminho);
		//id = ge.add_ouvinte_teclado([this](const sf::Event& e) {tratar_eventos(e); });
	}

	void Jogador::atualizar(float t)
	{
		gravidade();
		tratar_eventos();
		position += v * t;
	}

	void Jogador::desenhar(GerenciadorGrafico& gg)
	{
		gg.centralizar(position);
		gg.desenhar(caminho, position);
	}

	void Jogador::tratar_eventos()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			v.x += 0.0001f;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			v.x -= 0.0001f;
		}
		else
		{
			v.x = 0;
		}
		if (v.x > 0.1f) { v.x = 0.1f; }
		if (v.x < -0.1f) { v.x = -0.1f; }
	}

}
