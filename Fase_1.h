#pragma once
#include "Fase.h"
#include "Fogo.h"
#include "Gosma.h"
#include "Pedra.h"
#include "Plataforma.h"
#include "Bandeira.h"

namespace Jogo
{
	namespace Fases
	{
		class Fase_1 :
			public Fase
		{
		private:
			Entidades::Obstaculos::Plataforma* o1;
			Entidades::Obstaculos::Plataforma* o2;
			Entidades::Obstaculos::Plataforma* o6;
			Entidades::Obstaculos::Plataforma* o7;
			Entidades::Obstaculos::Plataforma* o8;
			Entidades::Obstaculos::Plataforma* o9;
			Entidades::Obstaculos::Plataforma* o10;
			Entidades::Obstaculos::Plataforma* o11;
			Entidades::Obstaculos::Plataforma* o12;
			Entidades::Obstaculos::Plataforma* o13;
			Entidades::Obstaculos::Plataforma* o14;
			Entidades::Obstaculos::Fogo* fogo;
			Entidades::Obstaculos::Fogo* fogo1;
			Entidades::Obstaculos::Fogo* fogo2;
			Entidades::Obstaculos::Pedra* pedra;
			Entidades::Obstaculos::Pedra* pedra2;
			Entidades::Obstaculos::Gosma* gosma1;
			Entidades::Obstaculos::Bandeira* bandeira;
		public:
			Fase_1();
			~Fase_1();

			void inicializar_entidades();
			void randomizar_obstaculos();
			void randomizar_inimigos();
			bool get_fim();
		};
	}
}
