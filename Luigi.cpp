#include "Luigi.h"
#include "Fase.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			

			Luigi::Luigi(Vector2F pos, unsigned int vidas):
				Jogador(pos, "assets/luigi.png", "assets/luigi_e.png", "assets/luigi_cinza.png", "assets/luigi_cinza_e.png", vidas)
			{

			}
			Luigi::~Luigi()
			{
			}
			void Luigi::tratar_eventos()
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					andar(false);//anda com falso para esquerda
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					andar(true);
				}
				
				else
				{
					andando = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					pular();
				}
			}
			void Luigi::reiniciar()
			{
				posicao = (50.0f, 650.0f);
				vidas = 6;
			}
		}
	}
}