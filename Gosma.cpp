#include "Gosma.h"
#include "IDsEntidades.h"

namespace Jogo
{
    namespace Entidades
    {
        namespace Obstaculos
        {
            Gosma::Gosma(Vector2F pos, const char* caminho_textura) :
                Obstaculo(pos, caminho_textura)
            {}
            void Gosma::colidir(Entidade* ente, Vector2F intersse)
            {
                if (ente && ente->get_id() == IDsEntidades::Jogador)
                {
                    ente->set_gosma(true);
                    
                }
            }
        }
    }
}