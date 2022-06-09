#include "VidaUI.h"
#define CHEIO "assets/vida.jpg"
#include "Jogador.h"


namespace Game
{

	VidaUI::VidaUI(Entidades::Jogador* jog):
		ComponenteGrafico(jog)
	{
		poss[0] = Vector2F(0.0f, 400.0f);
		poss[1] = Vector2F(50.0f, 400.0f);
		poss[2] = Vector2F(100.0f, 0.0f);
		poss[3] = Vector2F(150.0f, 0.0f);
		poss[4] = Vector2F(200.0f, 0.0f);

		GerenciadorGrafico::get_gerenciador()->carregar_textura(VAZIO);
		GerenciadorGrafico::get_gerenciador()->carregar_textura(CHEIO);
	}


	VidaUI::~VidaUI() {}

	void VidaUI::executar()
	{
		if(jogador)
		{ 
			  for (unsigned int i = 0; i < jogador->get_vida(); i++)
			  {
				 GerenciadorGrafico::get_gerenciador()->desenhar(CHEIO, Vector2F(poss[i].x + jogador->get_pos().x, poss[i].y));
			  }
        }

	}
}