#include "MenuSeletor.h"
#define FASE_1 5
#define FASE_2 6

Jogo::MenuSeletor::MenuSeletor(const char* fundo) :
	Menu(fundo)
{
	textos.resize(5);
	opcoes = { "Mario++", "Fase 1", "Fase 2", "Voltar", "Quit" };
	coords = { {345, 36} , {360, 215}, {363, 315}, {360, 410}, {375, 510} };
	tamanho = { 18, 22, 18, 18, 22 };

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

Jogo::MenuSeletor::~MenuSeletor()
{
}

void Jogo::MenuSeletor::executar(float t)
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
			gm->set_menu(FASE_1);
			break;
		case 2:
			gm->set_menu(FASE_2);
			break;
		case 3:
			gm->set_menu(1);
			break;
		case 4:
			exit(1);
			break;
		}
		sf::sleep(sf::milliseconds(200));
	}
}

