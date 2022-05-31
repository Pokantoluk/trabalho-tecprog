#include "Obstaculo.h"

namespace Game 
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			Obstaculo::Obstaculo(Vector2F pos, const char* caminho_textura):
				Entidade(IDsEntidades::obstaculo,pos, Vector2F(0.0f, 0.0f), caminho_textura)
			{

			}
			Obstaculo::~Obstaculo()
			{
			}
			void Obstaculo::colidir(IDsEntidades::IDsEntidades id_outro, Vector2F pos_outro, Vector2F dimension_outro)
			{
			}

			void Obstaculo::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
			{
				gg.carregar_textura(caminho);
				dimensao = gg.get_tamanho(caminho);
				gc.add_Entidade(this);
			}
			void Obstaculo::atualizar(float t)
			{
			}
			void Obstaculo::desenhar(GerenciadorGrafico& gg)
			{
				gg.desenhar(caminho, posicao);
			}
			
		}
	}
}