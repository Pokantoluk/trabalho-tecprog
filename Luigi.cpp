#include "Luigi.h"
namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			Luigi::Luigi(Vector2F pos ):
				Jogador(pos, "assets/luigi.png", "assets/luigi_e.png")
			{

			}
			Luigi::~Luigi()
			{
			}
			void Luigi::tratar_eventos()
			{
			}
		}
	}
}