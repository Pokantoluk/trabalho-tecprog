#include "Menu.h"
#include "Jogador.h"
#define MENU_PRINCIPAL 1
#define SELETOR 2
#define PLACAR 3
#define SAVES 4
#define FASE_1 5
#define FASE_2 6

namespace Game
{
	Menu::Menu() :
		fundo("assets/menu.png"),
		fundo_placar("assets/placar.png"),
		fundo_pausa("assets/pausa.png"),
		pos(1),
		enter(false),
		fonte(new sf::Font()),
		fase(0),
		num_menu(MENU_PRINCIPAL),
		ir(true)
	{
		fonte->loadFromFile("assets/ethn.otf");
	}
	Menu::~Menu()
	{
		delete fonte;
	}

	void Menu::iniciar()
	{
		set_valores(MENU_PRINCIPAL);
	}
	void Menu::set_valores(unsigned int qual_menu)
	{
		switch (qual_menu)
		{
		case MENU_PRINCIPAL:
			valores_principal();
			GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo);
			break;
		case SELETOR:
			valores_seletor_fase();
			GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo);
			break;
		case PLACAR:
			valores_placar();
			GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo_placar);
			break;
		}
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
	void Menu::valores_principal()
	{
		textos.resize(5);
		opcoes = { "CocKnight", "Jogar", "Placar", "Saves", "quit" };
		coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
		tamanho = { 18, 22, 18, 22, 22 };
	}
	void Menu::valores_seletor_fase()
	{
		textos.resize(5);
		opcoes = { "CocKnight", "Fase 1", "Fase 2", "Voltar", "Quit" };
		coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
		tamanho = { 18, 22, 18, 18, 22 };
	}
	void Menu::valores_placar()
	{
		textos[2].setOutlineThickness(0);
		textos.resize(5);
		opcoes = { "CocKnight", "fulano", "ciclano", "beltrano", " baiano" };
		coords = { {345, 36} , {250, 215}, {250, 315}, {250, 410}, {250, 510} };
		tamanho = { 18, 22, 18, 18, 22 };
	}
	void Menu::valores_saves()
	{
	}

	void Menu::menu_principal()
	{
		enter = false;
		set_valores(MENU_PRINCIPAL);
		for (auto t : textos)
		{
			GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
		}
		ler_teclado();
		if (enter)
		{
			switch (pos)
			{

			case 1:
				num_menu = SELETOR;//seletor de fase
				break;
			case 2:
				num_menu = PLACAR;
				break;
			case 3:
				num_menu = SAVES;
				break;
			case 4:
				exit(1);
				break;
			}
			sf::sleep(sf::milliseconds(200));
		}
	}

	void Menu::menu_seletor()
	{
		enter = false;
		set_valores(SELETOR);
		for (auto t : textos)
		{
			GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
		}
		ler_teclado();
		if (enter)
		{
			switch (pos)
			{

			case 1:
				num_menu = FASE_1;//fase 1;
				break;
			case 2:
				num_menu = FASE_2;//fase 2;
				break;
			case 3:
				num_menu = MENU_PRINCIPAL;//retornar;
				break;
			case 4:
				exit(1); //quit game
				break;
			}
			sf::sleep(sf::milliseconds(200));
		}
	}

	void Menu::menu_placar()
	{
		textos[pos].setOutlineThickness(0);//nao ta mudando
		enter = false;
		set_valores(PLACAR);
		GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo_placar);
		for (auto t : textos)
		{
			GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);// colocar os escores
		}
		ler_teclado();
	}

	void Menu::menu_saves()
	{
	}

	void Menu::menu_pausa()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			ir = true;
		}
	}

	void Menu::executar(float t, GerenciadorGrafico& gg)
	{
		//printf("%u", num_menu);
		if (num_menu == 1)
			menu_principal();
		else if (num_menu == 2)
			menu_seletor();
		else if (num_menu == 3)
			menu_placar();
		else if (num_menu == 4)
			menu_saves();
		else if (num_menu == 5)
			fase = 1;
		else if (num_menu == 6)
			fase = 2;
	}
	void Menu::ler_teclado()
	{
		if (num_menu == PLACAR)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				num_menu = MENU_PRINCIPAL;
			}
		}
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

	bool Menu::continuar()
	{
		return ir;
	}

}