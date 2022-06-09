#include "Menu.h"
#include "Jogador.h"
#include "Fase.h"
#include "Jogo.h"

#define MENU_PRINCIPAL 1
#define SELETOR 2
#define PLACAR 3
#define SAVES 4
#define FASE_1 5
#define FASE_2 6
#define GAMEOVER 7
using namespace std;

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
		num_menu(MENU_PRINCIPAL)
	{
		fonte->loadFromFile("assets/ethn.otf");
	}
	Menu::~Menu()
	{
		delete fonte;
	}

	void Menu::iniciar()
	{
		recuperar();
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
		case GAMEOVER:
			GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo_pausa);
			valores_gameover();
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
		opcoes = { "Mario++", "Jogar", "Placar", "Saves", "quit" };
		coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
		tamanho = { 18, 22, 18, 22, 22 };
	}
	void Menu::valores_seletor_fase()
	{
		textos.resize(5);
		opcoes = { "Mario++", "Fase 1", "Fase 2", "Voltar", "Quit" };
		coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
		tamanho = { 18, 22, 18, 18, 22 };
	}
	void Menu::valores_placar()
	{
		textos.resize(5);
		opcoes = { "Mario++", jogadores[0], jogadores[1], jogadores[2], jogadores[3], to_string(pontos[0]), to_string(pontos[1]), to_string(pontos[2]) , to_string(pontos[3]) };
		coords = { {345, 36} , {250, 215}, {250, 315}, {250, 410}, {250, 510} };
		tamanho = { 18, 22, 18, 18, 22 };
	}
	void Menu::valores_saves()
	{
	}

	void Menu::valores_gameover()
	{
		textos.resize(2);
		opcoes = { "Digite o seu nome:", GerenciadorEventos::get_nome() };
		coords = { {250, 215}, {300, 400} };
		tamanho = { 22, 30 };
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
		textos[3].setOutlineThickness(0);//nao ta mudando
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
		GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo_pausa);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			sf::sleep(sf::milliseconds(300));
			Jogo::na_fase = false;
			Fases::Fase::set_pausa(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
		{
			sf::sleep(sf::milliseconds(300));

		}

	}

	void Menu::menu_gameOver()
	{

		set_valores(GAMEOVER);
		GerenciadorEventos::escrever_nome(true);
		for (auto t : textos)
		{
			GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			GerenciadorEventos::escrever_nome(false);
			tratar_pontos();
			gravar();
			num_menu = MENU_PRINCIPAL;
			fase = 0;
		}
	}

	void Menu::executar(float t)
	{
		//printf("%u", num_menu);
		if (num_menu == 1)
			menu_principal();
		else if (num_menu == SELETOR)
			menu_seletor();
		else if (num_menu == PLACAR)
			menu_placar();
		else if (num_menu == SAVES)
			menu_saves();
		else if (num_menu == FASE_1)
			fase = 1;
		else if (num_menu == FASE_2)
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
		else
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

	void Menu::tratar_pontos()
	{
		unsigned int ponto = Entidades::Jogador::get_pontuacao();
		unsigned int i;
		for (i = 0; i < 5; i++)
		{
			if (pontos[i] < ponto)
			{
				pontos[i] = ponto;
				jogadores[i] = nome_a_salvar;
			}
		}
	}

	void Menu::gravar()
	{
		ofstream dat_jogadores;
		dat_jogadores.open("assets/jogadores.dat", ios::out);
		for (int i = 0; i < 5; i++)
		{
			dat_jogadores << jogadores[i] << " " << pontos[i];
		}
		dat_jogadores.close();
	}

	void Menu::recuperar()
	{
		ifstream dat_jogadores;
		dat_jogadores.open("assets/jogadores.dat", ios::in);
		string nome;
		unsigned int p;
		while (dat_jogadores >> nome >> p)
		{
			jogadores.push_back(nome);
			pontos.push_back(p);
		}
		dat_jogadores.close();
	}


}