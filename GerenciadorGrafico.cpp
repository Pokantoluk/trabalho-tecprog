#include "GerenciadorGrafico.h"

namespace Game
{
	GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

	Game::GerenciadorGrafico::GerenciadorGrafico() :
		janela(new sf::RenderWindow(sf::VideoMode(800, 800), "Jogo", sf::Style::Default)),
		camera(),
		textura_fundo(),
		fundo()
	{
		camera.setSize(800.f, 800.f);
		camera.setCenter(400.f, 400.f);
		janela->setView(camera);
		instancia = this;
	}

	Game::GerenciadorGrafico::~GerenciadorGrafico()
	{
		//delete instancia;
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
		janela->draw(fundo);
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
			sf::RectangleShape ret;
			float x = get_tamanho(caminho).x;

			ret.setSize(sf::Vector2f(get_tamanho(caminho).x, get_tamanho(caminho).y));
			ret.setFillColor(sf::Color::Black);
			ret.setPosition(pos.x, pos.y);
			sprite.setPosition(pos.x, pos.y);
			//janela->draw(ret);//para verificar o hitbox da textura.
			janela->draw(sprite);
		}
	}

	void GerenciadorGrafico::desenhar_menu(sf::Text t)
	{
		janela->draw(t);
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

	void GerenciadorGrafico::set_textura_fundo(const char* caminho)
	{
		textura_fundo.loadFromFile(caminho);
		fundo.setTexture(textura_fundo);
		fundo.setOrigin(0.f, 0.f);
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
	
	GerenciadorGrafico* GerenciadorGrafico::get_gerenciador()
	{
		return instancia;
	}
	
}