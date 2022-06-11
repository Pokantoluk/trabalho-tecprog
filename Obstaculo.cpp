#include "Obstaculo.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			Obstaculo::Obstaculo(IDsEntidades::IDsEntidades id, Vector2F pos, const char* caminho_textura) :
				Entidade(id, pos, Vector2F(0.0f, 0.0f), caminho_textura)
			{

			}
			Obstaculo::~Obstaculo()
			{
			}
			void Obstaculo::executar(float t)
			{
				atualizar(t);
				imprimir_se();
				
			}
			void Obstaculo::colidir(Entidade* ente, Vector2F intersse)
			{
			}

			void Obstaculo::inicializar()
			{
				Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
				dimensao = Gerenciadores::GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
			}
			void Obstaculo::atualizar(float t)
			{
			}
			void Obstaculo::desenhar()
			{
				Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
			}

		}
	}
}