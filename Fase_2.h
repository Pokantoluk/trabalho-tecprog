#pragma once
#include "Fase.h"
#include "Fogo.h"
#include "Gosma.h"
#include "Pedra.h"
#include "Bandeira.h"
#include "Plataforma.h"

namespace Jogo {
    namespace Fases {
        class Fase_2 :
            public Fase
        {
        private:
            Entidades::Obstaculos::Bandeira* bandeira;
            Entidades::Obstaculos::Plataforma* o1;
            Entidades::Obstaculos::Plataforma* o2;
            Entidades::Obstaculos::Plataforma* o3;
            Entidades::Obstaculos::Plataforma* o4;
            Entidades::Obstaculos::Plataforma* o5;
            Entidades::Obstaculos::Plataforma* o6;
            Entidades::Obstaculos::Plataforma* o7;
            Entidades::Obstaculos::Plataforma* o8;
            Entidades::Obstaculos::Plataforma* o9;
            Entidades::Obstaculos::Plataforma* o10;
            Entidades::Obstaculos::Plataforma* o11;
            Entidades::Obstaculos::Plataforma* o12;
            Entidades::Obstaculos::Plataforma* o13;
            Entidades::Obstaculos::Plataforma* o14;

        public:
            Fase_2();
            ~Fase_2();

            void inicializar_entidades();
            void randomizar_inimigos();
            void randomizar_obstaculos();
            bool get_fim();
        };

    }
}

