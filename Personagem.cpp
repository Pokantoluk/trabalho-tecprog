#include "Personagem.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			Personagem::Personagem(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura, unsigned int vidas) :
				Entidade(id, pos, vel, caminho_textura),
				vidas(vidas),
				no_chao(false),
				mod_vel(1),
				cont_tempo_imune(0),
				tempo_imune(2)
			{
			}
			void Personagem::machucar(int dano)
			{
				if (cont_tempo_imune >= tempo_imune) 
				{
					vidas -= dano;
					vidas = vidas < 0 ? 0 : vidas;
					cont_tempo_imune = 0;
					std::cout << "vidas do jogador:"<< vidas << std::endl;
				}
			}
			

		}
	}
}
