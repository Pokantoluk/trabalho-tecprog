#pragma once
#include "Fase.h"
#include "Fogo.h"
#include "Gosma.h"
#include "Pedra.h"
#include "Bandeira.h"

namespace Jogo {
    namespace Fases {
        class Fase_2 :
            public Fase
        {
        private:
            const char* fundo_fase_2;
            Entidades::Obstaculos::Bandeira* bandeira;

        public:
            Fase_2();
            ~Fase_2();

            void inicializar_entidades();
            void carregar_fundo() const;
            bool get_fim();
        };

    }
}

