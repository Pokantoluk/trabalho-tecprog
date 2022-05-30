#include "Inimigo.h"

namespace Game
{
	Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura) :
		colidivel(IDsEntidades::Inimigo,pos, vel, caminho_textura)
	{
	}

	Inimigo::~Inimigo()
	{
	}

	void Inimigo::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
		gg.carregar_textura(caminho);
		dimension = gg.get_tamanho(caminho);
		gc.add_colidivel(this);
	}

	void Inimigo::atualizar(float t)
	{
		position += v * t;
	}

	void Inimigo::desenhar(GerenciadorGrafico& gg)
	{
		gg.desenhar(caminho, position);
	}

	void Inimigo::colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro)
	{
		if (id_outro == IDsEntidades::Jogador)
		{
			std::cout << "uwu"<<std::endl;
		}
		if (id_outro == IDsEntidades::Inimigo)
		{
			std::cout << "uwu" << std::endl;
		}
	}

}
