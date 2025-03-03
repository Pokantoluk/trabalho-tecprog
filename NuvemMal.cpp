#include "NuvemMal.h"
#include "Fase.h"
#define FORCA_DA_NUVEM  GRAVIDADE*100000000

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			NuvemMal::NuvemMal(Vector2F pos, Vector2F vel, const char* caminho_textura, Fases::Fase* f):
				Inimigo(pos, vel, caminho_textura),
				fase(f)
			{
				cont_lancar = 0;
				temp_lancar = 2;
				temp_mover = 5;
				cont_mover = 0;
				
			
			}
			NuvemMal::~NuvemMal()
			{
			
			}
			void NuvemMal::atualizar(float t)
			{
				cont_lancar += t;
				cont_mover += t;
				if (cont_lancar >= temp_lancar)
				{
					lancar();
					cont_lancar = 0;
				}
				if (cont_mover >= temp_mover)
				{
					mover();
					cont_mover = 0;
				}
				
				v.y += (GRAVIDADE * t) / (FORCA_DA_NUVEM* t);
				posicao += v * t;
				
			}
			void NuvemMal::colidir(Entidade* ente, Vector2F intersse)
			{
				if (ente->get_id() == IDsEntidades::Inimigo)
					v.x *= -1;
			}
			void NuvemMal::lancar()
			{
				int i = rand() % 2 == 1 ? -1 : 1;
				Vector2F vel(i * rand() % 80, 0);
				Projetil* proj;
				proj = new Projetil(Vector2F(posicao.x, posicao.y + dimensao.y + 40), vel, PROJETIL);
				if (proj)
				{
					fase->add_projetil(proj);
			    
				}

			}
			
			void NuvemMal::mover()
			{
				v.x = static_cast<float>(rand() % 100 - 50);

			}
		} 
	}
}