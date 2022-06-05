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
        bool enter;
        const char* fundo;
        Vector2U pos_mouse;
        Vector2F coord_mouse;
        sf::Font* fonte;

        std::vector<const char*> opcoes;
        std::vector<Vector2F> coords;
        std::vector<sf::Text> textos;
        std::vector<std::size_t> tamanho;
        
    public:
        Menu();
        ~Menu();
        void set_valores();
        void iniciar(GerenciadorGrafico& gg);
        void executar(float t, GerenciadorGrafico& gg);
        void ler_teclado();
    };

}

