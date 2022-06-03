#include "Fase.h"

namespace Game
{
	namespace Fases
	{
		Fase::Fase():
			gc(&entidades_moveis, &entidades_estaticas)
		{
			entidades_moveis.inserir(new Jogador());
			
		}

		Fase::~Fase()
		{
		}

		void Fase::inicializar_entidades()
		{
		}

		void Fase::gerenciar_colisoes()
		{

		}

	}
}
