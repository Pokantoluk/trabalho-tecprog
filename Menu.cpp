#include "Menu.h"


namespace Game
{
	Menu::Menu() :
		fundo("assets/menu.png"),
		pos(0),
		pressionado(false),
		enter(false)
	{
		GerenciadorGrafico* gg = GerenciadorGrafico::get_gerenciador();
		gg->carregar_textura(fundo);
		gg->set_textura_fundo(fundo);
	}
	Menu::~Menu()
	{
	}
	void Menu::executar(float t)
	{
		GerenciadorGrafico* gg = GerenciadorGrafico::get_gerenciador();
		gg->desenhar(fundo, (0,0));
	}
}