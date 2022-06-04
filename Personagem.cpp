#include "Personagem.h"

namespace Game
{
	namespace Entidades
	{
		Personagem::Personagem(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura, unsigned int vidas) :
			Entidade(id, pos, vel, caminho_textura),
			vidas(vidas),
			no_chao(false)
		{
		}
	}
}
