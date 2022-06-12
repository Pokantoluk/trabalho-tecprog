#pragma once
#include "Entidade.h"


namespace Jogo
{
    namespace Entidades
    {    
        
        class Projetil :
            public Entidade

        {
          
        public:
            Projetil(Vector2F pos = Vector2F(0.0f, 0.0f), Vector2F vel = Vector2F(0.0f, 0.0f), const char* caminho_textura = nullptr);
            ~Projetil();
            void executar(float t);
            void colidir(Entidade* ente, Vector2F intersse);
           
        };
    }


 }