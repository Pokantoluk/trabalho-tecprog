#include "Fogo.h"
#include "Fogo.h"
#include "IDsEntidades.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            Fogo::Fogo(Vector2F pos, const char* caminho_textura) :
                Obstaculo(pos, caminho_textura)
            {

            }
            Fogo::~Fogo()
            {

            }
            void Fogo::colidir(Entidade* ente, Vector2F intersse)
            {
                if (ente && ente->get_id() == IDsEntidades::Jogador)
                {
                    ente->machucar(1);
                    Vector2F vel = ente->get_vel();
                    if (ente->get_vel().x > 0)
                        ente->set_vel(Vector2F(vel.x - 20, vel.y));
                    else
                        ente->set_vel(Vector2F(vel.x + 20, vel.y));
                }
            }
        }
    }
}