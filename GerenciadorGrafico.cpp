#include "GerenciadorGrafico.h"

namespace Game
{
	Game::GerenciadorGrafico::GerenciadorGrafico() :
		janela(new sf::RenderWindow(sf::VideoMode(800, 800), "Jogo", sf::Style::Default)),
		camera()
	{
		camera.setSize(800.f, 800.f);
		camera.setCenter(400.f, 400.f);
		janela->setView(camera);
	}

	Game::GerenciadorGrafico::~GerenciadorGrafico()
	{
		delete janela;
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
			std::cerr << "textura em " << caminho << " nao carregada no desenhar" << std::endl;
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
			texturas.emplace(caminho, text);
			return true;
		}
	}

	void Game::GerenciadorGrafico::centralizar(Vector2F centro)//centraliza a camera no personagem
	{
		if (centro.x < 400.f) { centro.x = 400.f; }
		camera.setCenter(centro.x, 400.f);
		janela->setView(camera);
	}
	
	const Vector2F GerenciadorGrafico::get_tamanho(const std::string& caminho)
	{
		if (!texturas.count(caminho))
		{
			std::cerr << "textura em " << caminho << " nao carregada" << std::endl;
			exit(1);
		}
		sf::Vector2u tamanho = (texturas[caminho]->getSize());
		return Vector2F(tamanho.x, tamanho.y);
	}
	
}