#include "Pedra.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            Pedra::Pedra(Vector2F pos, const char* caminho_textura) :
                Obstaculo(pos, caminho_textura)
            {

            }
            void Pedra::colidir(Entidade * ente, Vector2F intersse)
            {

            }
        }
    }
}