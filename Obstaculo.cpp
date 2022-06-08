#include "Obstaculo.h"

namespace Game
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			Obstaculo::Obstaculo(Vector2F pos, const char* caminho_textura) :
				Entidade(IDsEntidades::obstaculo, pos, Vector2F(0.0f, 0.0f), caminho_textura)
			{

			}
			Obstaculo::~Obstaculo()
			{
			}
			void Obstaculo::executar(float t)
			{
				atualizar(t);
				imprimir(caminho, posicao);
			}
			void Obstaculo::colidir(Entidade* ente, Vector2F intersse)
			{
			}

			void Obstaculo::inicializar()
			{
				GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
				dimensao = GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
			}
			void Obstaculo::atualizar(float t)
			{
			}
			void Obstaculo::desenhar()
			{
				GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
			}

		}
	}
}