#include "VidaUI.h"
#define CHEIO "assets/vida.jpg"
#define VAZIO "asstes/estrela.png"


namespace Game
{

	VidaUI::VidaUI() :
		ComponenteGrafico()
	{
		poss[0] = Vector2F(50.0f, 0.0f);
		poss[1] = Vector2F(0.0f, 0.0f);
		poss[2] = Vector2F(0.0f, 0.0f);
		poss[3] = Vector2F(0.0f, 0.0f);
		poss[4] = Vector2F(5.0f, 0.0f);
		GerenciadorGrafico::get_gerenciador()->carregar_textura(VAZIO);
		GerenciadorGrafico::get_gerenciador()->carregar_textura(CHEIO);
	}

	VidaUI::~VidaUI() {}

	void VidaUI::executar()
	{
		for (int i = 0; i < n_vidas; i++)
		{
			GerenciadorGrafico::get_gerenciador()->desenhar(CHEIO, poss[i]);
		}

	}
	void VidaUI::atualizar(Entidades::Jogador* jogador)
	{

		n_vidas = jogador->get_vida();
	}
}