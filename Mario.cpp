#include "Mario.h"
#include "Fase.h"

namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens
		{
			Mario::Mario(Vector2F pos):
				Jogador(pos,"assets/mario.png", "assets/mario_e.png")
			{

			}
			Mario::~Mario()
			{
			}
			void Mario::tratar_eventos()
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					Fases::Fase::set_pausa(true);
					sf::sleep(sf::milliseconds(300));
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					andar(false);//anda com falso para esquerda
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					andar(true);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					//posicao.y -= 0.1;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					//posicao.y += 0.1;
				}
				else
				{
					andando = false;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					pular();
				}
			}
		}
	}
}