#include "Inimigo.h"

namespace Game
{
	Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura) :
		Entidade(IDsEntidades::Inimigo,pos, vel, caminho_textura)
	{
	}

	Inimigo::~Inimigo()
	{
	}

	void Inimigo::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
		gg.carregar_textura(caminho);
		dimensao = gg.get_tamanho(caminho);
		gc.add_Entidade(this);
	}

	void Inimigo::atualizar(float t)
	{
		posicao += v * t;
	}

	void Inimigo::desenhar(GerenciadorGrafico& gg)
	{
		gg.desenhar(caminho, posicao);
	}

	void Inimigo::colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro)
	{
		if (id_outro == IDsEntidades::Jogador)
		{
			std::cout << "encostou"<<std::endl;
		}
		if (id_outro == IDsEntidades::Inimigo)
		{
			std::cout << "" << std::endl;
		}
	}

}
