#include "Inimigo.h"

namespace Game
{
	Inimigo::Inimigo(bool vivo, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		Entidade(vivo, pos, vel, caminho_textura)
	{
	}

	Inimigo::~Inimigo()
	{
	}

}
