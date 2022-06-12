#include "GerenciadorGrafico.h"

namespace Jogo
{
	namespace Gerenciadores 
	{
		GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;
		GerenciadorGrafico::GerenciadorGrafico() :
			janela(new sf::RenderWindow(sf::VideoMode(800, 800), "Jogo", sf::Style::Default)),
			camera()
		{
			camera.setSize(800.f, 800.f);
			camera.setCenter(400.f, 400.f);
			janela->setView(camera);
			instancia = this;
		}
		GerenciadorGrafico::~GerenciadorGrafico()
		{
			delete janela;
			for (auto i : texturas)
			{
				delete i.second;
			}
		}
		void GerenciadorGrafico::mostrar() const
		{
			janela->display();
		}
		void GerenciadorGrafico::limpar() const
		{
			janela->clear(sf::Color(0, 0, 0));
		}
		void GerenciadorGrafico::desenhar(const std::string caminho, const Vector2F pos)
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
				sprite.setTexture(*text);	
				sprite.setPosition(pos.x, pos.y);
				janela->draw(sprite);
			}
		}
		void GerenciadorGrafico::desenharUI(const std::string caminho, const Vector2F pos)
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

				sprite.setTexture(*text);
				sprite.setPosition(camera.getCenter().x + pos.x, camera.getCenter().y + pos.y);
				janela->draw(sprite);
			}
		}
		void GerenciadorGrafico::desenharUI(sf::Text t, Vector2F pos)
		{
			t.setPosition(camera.getCenter().x + pos.x, camera.getCenter().y + pos.y);
			janela->draw(t);
		}
		void GerenciadorGrafico::desenhar_menu(sf::Text t) const
		{
			janela->draw(t);
		}
		bool GerenciadorGrafico::carregar_textura(const std::string caminho)
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
		void GerenciadorGrafico::centralizar(Vector2F centro_1, Vector2F centro_2)
		{
			float centro = (centro_1.x + centro_2.x) / 2.0;
			
			if (centro < 400.f) { centro = 400.f; }
			else if (centro > 2600.f) { centro = 2600.f; }
			camera.setCenter(centro, 400.f);
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
		GerenciadorGrafico* GerenciadorGrafico::get_gerenciador()
		{
			return instancia;
		}
	}
}