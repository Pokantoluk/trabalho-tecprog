#include "Inimigo.h"

namespace Game
{
	namespace Entidades
	{
		Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura) :
			Entidade(IDsEntidades::Inimigo, pos, vel, caminho_textura)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
		{
			gg.carregar_textura(caminho);
			dimensao = gg.get_tamanho(caminho);
		}

		void Inimigo::atualizar(float t)
		{
			posicao += v * t;
		}

		void Inimigo::desenhar(GerenciadorGrafico& gg)
		{
			gg.desenhar(caminho, posicao);
		}

		void Inimigo::colidir(Entidade* ente, Vector2F intersse)
		{
			if (ente->get_id() == IDsEntidades::Jogador)
			{
				std::cout << "encostou" << std::endl;
			}
			if (ente->get_id()== IDsEntidades::Inimigo)
			{
				std::cout << "" << std::endl;
			}
		}
	}
}
