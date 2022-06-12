#include "Plataforma.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            Plataforma::Plataforma(Vector2F pos, const char* caminho_textura) :
                Obstaculo(IDsEntidades::obstaculo, pos, caminho_textura)
            {

            }
            Plataforma::~Plataforma()
            {
            }
            void Plataforma::colidir(Entidade* ente, Vector2F intersse)
            {

            }
        }
    }
}