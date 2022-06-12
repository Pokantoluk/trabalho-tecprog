#include "GerenciadorColisoes.h"
#include "Entidade.h"
#include "ListaEntidades.h"
#include "IDsEntidades.h"

namespace Jogo
{
    namespace Gerenciadores 
    {
        GerenciadorColisoes::GerenciadorColisoes(Listas::ListaEntidades* m, Listas::ListaEntidades* e) :
            moveis(m),
            estaticos(e)
        {
          
        }
        GerenciadorColisoes::~GerenciadorColisoes()
        {
           
            moveis->destruir();
            estaticos->destruir();
        }
        const bool GerenciadorColisoes::tentar_destruir(Entidade* ente, int index, bool estatico)
        {
            if (ente && ente->get_destruir() && ente->get_id() != IDsEntidades::Jogador)
            {
                delete ente;
                ente = nullptr;
                if (estatico)
                {
                    estaticos->remover(index);
                }
                else
                { 
                    
                    moveis->remover(index);
                    
                }
                std::cout << "detruido" << std::endl;
                return true;
 
            }
            return false;
        }
        void GerenciadorColisoes::verificar_colisoes()
        {
            Entidade* ent1 = nullptr;
            Entidade* ent2 = nullptr;
            Vector2F interssec;
            Vector2F distancia_centros;
            unsigned int i, j;
           
 

  
            for(i=0; i< estaticos->get_tam(); i++)
            { 
                ent1 = (*estaticos)[i];
                if (tentar_destruir(ent1, i, true))
                {
                    if(i<0)
                     i--;
   
                }
            }
               
            for (i = 0; i < moveis->get_tam(); i++)
            {
                ent1 = (*moveis)[i];
                if (tentar_destruir(ent1, i, false))
                {    
                    if(i<0)
                      i--;
             
                }
            }
            

            /*colisão entre objetos moveis e estaticos.*/
            for (i = 0; i < estaticos->get_tam(); i++)
            {
                for (j = 0; j < moveis->get_tam(); j++)
                {
                    ent1 = (*estaticos)[i];
                    ent2 = (*moveis)[j];
                    
                    
                    if (ent1 && ent2)
                    {
                        distancia_centros.x = (ent2->get_pos().x + ent2->get_dim().x / 2.0) - (ent1->get_pos().x + ent1->get_dim().x / 2.0);
                        distancia_centros.y = (ent2->get_pos().y + ent2->get_dim().y / 2.0) - (ent1->get_pos().y + ent1->get_dim().y / 2.0);

                        interssec.x = fabs(distancia_centros.x) - (ent1->get_dim().x / 2.0f + ent2->get_dim().x / 2.0f);
                        interssec.y = fabs(distancia_centros.y) - (ent1->get_dim().y / 2.0f + ent2->get_dim().y / 2.0f);

                        if (interssec.x < 0.0f && interssec.y < 0.0f)
                        {
                            ent2->colidir(ent1, interssec);
                            ent1->colidir(ent2, interssec);
                        }
                    }
                    
                }

            }
            
            /*colisão entre objetos moveis*/
            for (i = 0; i < moveis->get_tam(); i++)
            {
                for (j = i + 1; j < moveis->get_tam(); j++)
                {
                    ent1 = (*moveis)[i];
                    ent2 = (*moveis)[j];
                    
                    
                    if (ent1 && ent2)
                    {
                        distancia_centros.x = ent2->get_pos().x - ent1->get_pos().x;
                        distancia_centros.y = ent2->get_pos().y - ent1->get_pos().y;

                        interssec.x = fabs(distancia_centros.x) - (ent1->get_dim().x / 2.0f + ent2->get_dim().x / 2.0f);
                        interssec.y = fabs(distancia_centros.y) - (ent1->get_dim().y / 2.0f + ent2->get_dim().y / 2.0f);
                        if (interssec.x < 0.0f && interssec.y < 0.0f)
                        {
                            ent2->colidir(ent1, interssec);
                            ent1->colidir(ent2, interssec);
                        }
                    }
                    

                }
            }
           
        }
    }
}