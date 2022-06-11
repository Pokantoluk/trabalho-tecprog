#include "Projetil.h"
#include "NuvemMal.h"
namespace Jogo
{
    namespace Entidades
    {
        
        Projetil::Projetil(Vector2F pos, Vector2F vel, const char* caminho_textura, Personagens::NuvemMal* n) :
            Entidade(IDsEntidades::Projetil, pos, vel, caminho_textura),
            nuvem(n)
        {
           
        }
        Projetil::~Projetil()
        {

        }
        void Projetil::executar(float t)
        {
            imprimir_se();
            v.y += GRAVIDADE * t;
            posicao += v * t;

        }
        void Projetil::colidir(Entidade* ente, Vector2F intersse)
        {
            if (ente && ente->get_id() == IDsEntidades::Jogador)
            {
                ente->machucar(1);
                
                this->Destruir();
            } 
            else if (ente && ente->get_id() != IDsEntidades::Inimigo)
            {
                this->Destruir();
            }

        }
     

    }

}