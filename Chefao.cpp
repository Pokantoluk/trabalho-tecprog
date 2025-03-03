#include "Chefao.h"
#include "Jogador.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{

			Chefao::Chefao(Vector2F pos, Vector2F vel, const char* caminho_textura) :
				Inimigo(pos, vel, caminho_textura, 3)
			{

			}
			Chefao::~Chefao()
			{

			}
			void Chefao::colidir(Entidade* ente, Vector2F intersse)
			{

				if (ente->get_id() == IDsEntidades::Jogador)
				{

					if (ObjetoEmCima(ente))
					{
						this->machucar(1);
					}
					else
					{
						ente->machucar(2);

					}
					v.x *= -1;

				}
				else if (ente->get_id() == IDsEntidades::Inimigo)
				{
					v.x *= -1;
				}
				else if (ente->get_id() == IDsEntidades::obstaculo)
				{
					v.x *= -1;
				}


			}
		}
	}
}