#include "MenuPlacar.h"

Jogo::MenuPlacar::MenuPlacar(const char* fundo):
	Menu(fundo)
{
	
}

Jogo::MenuPlacar::~MenuPlacar()
{
}

void Jogo::MenuPlacar::valores()
{
	textos.resize(9);
	opcoes = { "Mario++", gm->get_jogadores()[0], gm->get_jogadores()[1], gm->get_jogadores()[2], gm->get_jogadores()[3], to_string(gm->get_pontos()[0]), to_string(gm->get_pontos()[1]), to_string(gm->get_pontos()[2]) , to_string(gm->get_pontos()[3]) };
	coords = { {345, 36} , {250, 215}, {250, 315}, {250, 410}, {250, 510}, {450, 215}, {450, 315}, {450, 410}, {450, 510} };
	tamanho = { 18, 22, 18, 18, 22, 22, 18, 18, 22 };
	for (std::size_t i{}; i < textos.size(); i++)
	{
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(tamanho[i]);
		textos[i].setOutlineColor(sf::Color::Black);
		textos[i].setPosition(coords[i].x, coords[i].y);
	}
	textos[pos].setOutlineThickness(0);
}

void Jogo::MenuPlacar::executar(float t)
{
	valores();
	imprimir_se();
	for (auto t : textos)
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);// colocar os escores
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		gm->set_menu(1);
	}
}

