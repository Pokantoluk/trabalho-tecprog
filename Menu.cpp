#include "Menu.h"


namespace Game
{
	Menu::Menu(GerenciadorGrafico& gg) :
		fundo("assets/menu.png"),
		pos(0),
		pressionado(false),
		enter(false)
	{
		gg.carregar_textura(fundo);
		gg.set_textura_fundo(fundo);
	}
	Menu::~Menu()
	{
	}
	void Menu::executar(float t, GerenciadorGrafico& gg)
	{
		gg.desenhar(fundo, (0,0));
	}
}