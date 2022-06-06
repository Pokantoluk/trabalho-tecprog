#include "Inimigo.h"

namespace Game
{
	namespace Entidades
	{
		Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura) :
			Personagem(IDsEntidades::Inimigo, pos, vel, caminho_textura, 1)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::executar(float t)
		{
			if (vidas >= 1)
			{
				atualizar(t);
				imprimir(caminho, posicao);
			}
			else
			{

			}
		}

		void Inimigo::inicializar()
		{
			v.x = -50.f;
			GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
			dimensao = GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
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
