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
        unsigned int num_menu;
        unsigned int fase;
        int pos;
        bool enter;
        const char* fundo;
        Vector2U pos_mouse;
        Vector2F coord_mouse;
        sf::Font* fonte;
        GerenciadorGrafico* ger;

        std::vector<const char*> opcoes;
        std::vector<Vector2F> coords;
        std::vector<sf::Text> textos;
        std::vector<std::size_t> tamanho;

    public:
        Menu();
        ~Menu();
        void iniciar(GerenciadorGrafico& gg);
        void set_valores(unsigned int qual_menu);

        void valores_principal();
        void valores_seletor_fase();
        void valores_config();

        void menu_principal();
        void menu_seletor();
        void menu_placar();
        void menu_config();

        void executar(float t, GerenciadorGrafico& gg);
        void ler_teclado();
        const unsigned int get_fase() const { return fase; }
    };

}

