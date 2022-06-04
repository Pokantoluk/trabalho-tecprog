#pragma once
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"

namespace Game
{
    
    class Menu :
        public Ente
    {
    private:
        int pos;
        bool pressionado;
        bool enter;
        const char* fundo;
        Vector2U pos_mouse;
        Vector2F coord_mouse;
        std::vector<const char*> opcoes;
        std::vector<Vector2F> coords;

        
    public:
        Menu(GerenciadorGrafico& gg);
        ~Menu();
        void executar(float t, GerenciadorGrafico& gg);
    };

}

