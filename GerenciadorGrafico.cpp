#include "GerenciadorGrafico.h"

namespace Game
{
	Game::GerenciadorGrafico::GerenciadorGrafico() :
		janela(new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo", sf::Style::Default)),
		camera(sf::Vector2f(400, 400), sf::Vector2f(800, 800))
	{
		janela->setView(camera);
	}

	Game::GerenciadorGrafico::~GerenciadorGrafico()
	{
		delete janela;
		/*
		for (auto i = texturas.begin(); i!= texturas.end(); i++)
		{
			delete i->second;
		}
		*/
		for (auto i : texturas)
		{
			delete i.second;
		}
	}

	void Game::GerenciadorGrafico::mostrar() const
	{
		janela->display();
	}

	void Game::GerenciadorGrafico::limpar(int r, int g, int b)
	{
		janela->clear(sf::Color(r, g, b));
	}

	void Game::GerenciadorGrafico::desenhar(const std::string caminho, const Vector2F pos)
	{
		if (!texturas.count(caminho))
		{
			std::cerr << "textura em " << caminho << " nao carregada" << std::endl;
			exit(1);
		}
		else
		{
			sf::Texture* text = texturas[caminho];
			sf::Sprite sprite;

			//TODO: verificar se a textura está completamente fora da camera e não desenhá-la.
			sprite.setTexture(*text);

			sprite.setPosition(pos.x, pos.y);

			janela->draw(sprite);
		}
	}

	bool Game::GerenciadorGrafico::carregar_textura(const std::string caminho)
	{
		if (texturas.count(caminho)) { return true; }
		else
		{
			sf::Texture* text = new sf::Texture();
			if (!text->loadFromFile(caminho))
			{
				std::cerr << "imagem não localizada em " << caminho << std::endl;
				exit(1);
			}
			//texturas.insert(std::pair<const std::string, sf::Texture*>(caminho, text));
			texturas.emplace(caminho, text);
			return true;
		}
	}

	void Game::GerenciadorGrafico::centralizar(const sf::Vector2f centro)
	{
		camera.setCenter(sf::Vector2f(centro.x, centro.y));
	}
}