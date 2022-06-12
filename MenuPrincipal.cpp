#include "MenuPrincipal.h"


Jogo::MenuPrincipal::MenuPrincipal(const char* fundo) :
	Menu(fundo)
{
	textos.resize(5);
	opcoes = { "Mario++", "Jogar", "Placar", "Jogadores", "Sair" };
	coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
	tamanho = { 18, 22, 18, 12, 22 };

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

Jogo::MenuPrincipal::~MenuPrincipal()
{
}

void Jogo::MenuPrincipal::executar(float t)
{
	enter = false;
	imprimir_se();
	for (auto t : textos)
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
	}
	ler_teclado();
	if (enter)
	{
		switch (pos)
		{

		case 1:
			gm->set_menu(2);
			break;
		case 2:
			gm->set_menu(3);
			break;
		case 3:
			gm->set_menu(4);
			break;
		case 4:
			exit(1);
			break;
		}
		sf::sleep(sf::milliseconds(200));
	}
}

