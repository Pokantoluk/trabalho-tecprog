#include "MenuGameover.h"

Jogo::MenuGameover::MenuGameover(const char* fundo) :
	Menu(fundo)
{
	textos.resize(2);
	opcoes = { "Digite o seu nome:", Gerenciadores::GerenciadorEventos::get_nome() };
	coords = { {250, 215}, {300, 400} };
	tamanho = { 22, 30 };

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

Jogo::MenuGameover::~MenuGameover()
{
}

void Jogo::MenuGameover::executar(float t)
{

	if (gm->get_num_jogadores() == 1) { executar_2(); }
	else {
	Gerenciadores::GerenciadorGrafico::get_gerenciador()->centralizar();
	imprimir_se();
	Gerenciadores::GerenciadorEventos::escrever_nome(true);
	textos[1].setString(Gerenciadores::GerenciadorEventos::get_nome());
	for (auto t : textos)
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		Gerenciadores::GerenciadorEventos::escrever_nome(false);
		gm->tratar_pontos(textos[1].getString());
		gm->gravar();
		gm->recuperar();
		gm->set_fase(0);
		gm->set_menu(1);
		sf::sleep(sf::milliseconds(200));
	}
	}
}

void Jogo::MenuGameover::executar_2()
{
	Gerenciadores::GerenciadorGrafico::get_gerenciador()->centralizar();
	imprimir_se();
	Gerenciadores::GerenciadorEventos::escrever_nome(true);
	textos[1].setString(Gerenciadores::GerenciadorEventos::get_nome());
	for (auto t : textos)
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar_menu(t);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		Gerenciadores::GerenciadorEventos::escrever_nome(false);
		gm->tratar_pontos(textos[1].getString());
		gm->gravar();
		gm->recuperar();
		gm->set_fase(0);
		gm->set_menu(1);
		sf::sleep(sf::milliseconds(200));
	}
}


