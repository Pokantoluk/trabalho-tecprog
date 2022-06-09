#pragma once
#include "Fase.h"
namespace Jogo {
    namespace Fases {
        class Fase_2 :
            public Fase
        {
        private:
            const char* fundo_fase_2;
        public:
            Fase_2();
            ~Fase_2();

            void inicializar_entidades();
            void carregar_fundo() const;
        };

    }
}

