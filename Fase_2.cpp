#include "Fase_2.h"

namespace Jogo {
	namespace Fases {

		Fase_2::Fase_2() :
			Fase("assets / fundo_2.png"),
			bandeira(new Entidades::Obstaculos::Bandeira(Vector2F(2600.0f, 500.0f), "assets/bandeira_mario.png"))
		{

		}

		Fase_2::~Fase_2()
		{
		}

		void Fase_2::inicializar_entidades()
		{
			randomizar_inimigos();
			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}

		bool Fase_2::get_fim()
		{
			if (bandeira->get_fim())
			{
				music.stop();
			}
			return bandeira->get_fim();
		}
	}
}
