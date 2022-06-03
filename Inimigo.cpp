#include "Inimigo.h"

namespace Game
{
	namespace Entidades
	{
		Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura) :
			Personagem(IDsEntidades::Inimigo, pos, vel, caminho_textura, 1),
			no_chao(false)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::executar(float t, GerenciadorGrafico& gg)
		{
			if (vidas >= 1)
			{
				atualizar(t);
				imprimir(gg, caminho, posicao);
			}
			else
			{

			}
		}

		void Inimigo::inicializar(GerenciadorGrafico& gg)
		{
			v.x = -50.f;
			gg.carregar_textura(caminho);
			dimensao = gg.get_tamanho(caminho);
		}

		void Inimigo::atualizar(float t)
		{
			bordas();
			if(!no_chao)
				v.y += GRAVIDADE * t;
			posicao += v * t;
		}


		void Inimigo::colidir(Entidade* ente, Vector2F intersse)
		{
			if (ente->get_id() == IDsEntidades::Jogador)
			{
				
			}
			if (ente->get_id()== IDsEntidades::Inimigo)
			{
				v.x *= -1;
			}
		}
		void Inimigo::bordas()
		{
			if (posicao.x < 0) 
			{ 
				posicao.x = 0; 
				v.x *= -1;
			}
			if (posicao.y + dimensao.y >= 800)
			{
				posicao.y = 800 - dimensao.y;
				no_chao = true;
			}
			else
			{
				no_chao = false;
			}
		}
	}
}
