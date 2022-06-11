#include "MenuPersonagens.h"

Jogo::MenuPersonagens::MenuPersonagens(const char* fundo) :
	Menu(fundo)
{
	textos.resize(5);
	opcoes = { "Mario++", "Um", "Dois", "Voltar", "Sair" };
	coords = { {345, 36} , {380, 215}, {380, 315}, {360, 410}, {375, 510} };
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

Jogo::MenuPersonagens::~MenuPersonagens()
{
}

void Jogo::MenuPersonagens::executar(float t)
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
		if (pos == 1)
		{
			gm->set_jog(1);
			gm->set_menu(1);
		}
		else if (pos == 2)
		{
			gm->set_jog(2);
			gm->set_menu(1);
		}
		else if (pos == 3)
		{
			gm->set_menu(1);
		}
		else
		{
			exit(1);
		}
		sf::sleep(sf::milliseconds(200));
	}
}


