#include "Inimigo.h"
#include "Jogador.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{

			Inimigo::Inimigo(Vector2F pos, Vector2F vel, const char* caminho_textura, const int vidas, const int pontuacao) :
				Personagem(IDsEntidades::Inimigo, pos, vel, caminho_textura, vidas),
				pontos(pontuacao)

			{
				cont_tempo_imune = 2;
			}

			Inimigo::~Inimigo()
			{
			}

			void Inimigo::executar(float t)
			{
				if (vidas >= 1)
				{
					atualizar(t);
					imprimir_se();
					cont_tempo_imune += t;
				}
				else
				{
					Jogador::incrementar_pontuacao(pontos);
					this->Destruir();
				}
			}

			void Inimigo::inicializar()
			{
				v.x = -50.f;
				Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
				dimensao = Gerenciadores::GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
			}

			void Inimigo::atualizar(float t)
			{

				bordas();
				if (!no_chao)
					v.y += GRAVIDADE * t;
				posicao += v * t;

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
			bool Inimigo::ObjetoEmCima(Entidade* ente)
			{
				return ente->get_pos().y + ente->get_dim().y - 30 <= this->get_pos().y;
			}
		}
	}
}
