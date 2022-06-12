#include "Projetil.h"

namespace Jogo
{
    namespace Entidades
    {
        
        Projetil::Projetil(Vector2F pos, Vector2F vel, const char* caminho_textura):
            Entidade(IDsEntidades::Projetil, pos, vel, caminho_textura)
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
                
            } 

            if (ente && ente->get_id() != IDsEntidades::Projetil)
            {
                this->Destruir();
                std::cout << "mandei destruir" << std::endl;
            }

        }
    }

}