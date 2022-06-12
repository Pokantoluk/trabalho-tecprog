#include "Menu.h"
#include "Jogador.h"
#include "Fase.h"
#include "Jogo.h"



using namespace std;

namespace Jogo
{
	Menu::Menu(const char* fundo):
		Ente(Vector2F(0.f, 0.f), fundo),
		pos(1),
		enter(false),
		fonte(new sf::Font())
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(fundo);
		fonte->loadFromFile("assets/ethn.otf");
	}
	Menu::~Menu()
	{
		delete fonte;
	}
	
	void Menu::ler_teclado()
	{
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				if (pos < 4)
				{
					++pos;
					textos[pos].setOutlineThickness(8);
					textos[pos - 1].setOutlineThickness(0);
					sf::sleep(sf::milliseconds(300));
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (pos > 1)
				{
					--pos;
					textos[pos].setOutlineThickness(5);
					textos[pos + 1].setOutlineThickness(0);
					sf::sleep(sf::milliseconds(300));
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enter)
			{
				enter = true;
			}
	}
}