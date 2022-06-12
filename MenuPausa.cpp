#include "MenuPausa.h"
#include "Fase.h"

Jogo::MenuPausa::MenuPausa(const char* fundo):
	Menu(fundo)
{
	textos.resize(5);
	opcoes = { "Mario++", "Voltar", "Menu", "Salvar e sair", "Sair" };
	coords = { {340, 36} , {330, 215}, {350, 315}, {320, 410}, {350, 510} };
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

Jogo::MenuPausa::~MenuPausa()
{
}

void Jogo::MenuPausa::executar(float t)
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
			Fases::Fase::set_pausa(false);//voltar pra fase
			break;
		case 2:
			gm->set_fase(0);
			gm->set_menu(1);//sair da fase e voltar pro menu principal
			break;
		case 3:
			//nd por enquanto
			break;
		case 4:
			exit(1);//sair do game
			break;
		}
		sf::sleep(sf::milliseconds(200));
	}
}
