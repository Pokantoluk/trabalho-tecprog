#include "Menu.h"
#include <conio.h>

namespace Game
{
	Menu::Menu() :
		fundo("assets/menu.png"),
		pos(1),
		enter(false),
		fonte(new sf::Font())
	{
		set_valores();
	}
	Menu::~Menu()
	{
		delete fonte;
	}
	void Menu::set_valores()
	{
		textos.resize(5);
		opcoes = { "CocKnight", "Jogar", "Placar", "Config", "quit"};
		coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
		tamanho = { 18, 22, 18, 22, 22 };
		for (std::size_t i{}; i < textos.size(); i++)
		{
			textos[i].setFont(*fonte);
			textos[i].setString(opcoes[i]);
			textos[i].setCharacterSize(tamanho[i]);
			textos[i].setOutlineColor(sf::Color::Black);
			textos[i].setPosition(coords[i].x, coords[i].y);
		}
		textos[pos].setOutlineThickness(8);
	}
	void Menu::iniciar(GerenciadorGrafico& gg)
	{
		fonte->loadFromFile("assets/ethn.otf");
		gg.carregar_textura(fundo);
		gg.set_textura_fundo(fundo);
	}

	void Menu::executar(float t, GerenciadorGrafico& gg)
	{
		for (auto t : textos)
		{
			gg.desenhar_menu(t);
		}
		ler_teclado();
	}
	void Menu::ler_teclado()
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (pos < 4)
			{
				++pos;
				textos[pos].setOutlineThickness(8);
				textos[pos-1].setOutlineThickness(0);
				sf::sleep(sf::milliseconds(300));
				enter = false;
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
				enter = false;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !enter)
		{
			enter = true;

		}
	}
}