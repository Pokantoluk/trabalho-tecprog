#include "VidaUI.h"
#define CHEIO "assets/coracaocheio.png"
#define VAZIO "assets/coracaovazio.png"
#include "Jogador.h"


namespace Jogo
{

	VidaUI::VidaUI(Entidades::Personagens::Jogador* jog):
		ComponenteGrafico(jog)
	{

		Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(VAZIO);
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(CHEIO);
	}


	VidaUI::~VidaUI() {}

	void VidaUI::executar()
	{
		if(jogador)
		{ 
			  for (int i = 0; i < jogador->get_vida(); i++)
			  {
				  Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenharUI(CHEIO, Vector2F(-400 + (50 * i), -400));
			  }
			  for (int i = jogador->get_vida(); i < VIDA_MAX; i++)
			  {
				  Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenharUI(VAZIO, Vector2F(-400 + (50 * i), -400));
			  }
        }

	}
}