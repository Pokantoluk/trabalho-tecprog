#include "Personagem.h"
#include <iostream>

namespace Game
{

	Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, const char* caminho_textura) :
		position(pos),
		v(vel),
		text(nullptr),
		corpo(pos)
	{
		if (caminho_textura)
		{
			text = new sf::Texture;
			text->loadFromFile("mario.png");
		}
		corpo.setTexture(text);
		corpo.setOrigin(corpo.getSize() / 2.0f);
	}

	Personagem::~Personagem()
	{
		if (text) { delete text; }
	}

	void Personagem::atualizar(float t)
	{
		
		position += v * t;
		corpo.setPosition(position);
	}

	void Personagem::desenhar(GerenciadorGrafico &g)
	{
		g.mostrar();
	}
}
