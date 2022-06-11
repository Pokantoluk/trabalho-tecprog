#pragma once
#include "Inimigo.h"
#include "Projetil.h"
#define PROJETIL "assets/bomba.png"


namespace Jogo
{
	namespace Fases
	{
		class Fase;
	}
	namespace Entidades
	{
		namespace Personagens
		{
			class NuvemMal :
				public	Inimigo
			{
			private:
				Fases::Fase* fase;
				float cont_lancar, temp_lancar, temp_mover, cont_mover;
			public:
				NuvemMal(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr,Fases::Fase* f =nullptr);
				~NuvemMal();
				void atualizar(float t);
				void colidir(Entidade* ente, Vector2F intersse);
				void lancar();
				void mover();



			};

		}
	}
}