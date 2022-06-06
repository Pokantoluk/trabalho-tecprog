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
        const char* fundo_placar;
        const char* fundo_pausa;
        sf::Font* fonte;

        std::vector<const char*> opcoes;
        std::vector<Vector2F> coords;
        std::vector<sf::Text> textos;
        std::vector<std::size_t> tamanho;

    public:
        Menu();
        ~Menu();
        void iniciar();
        void set_valores(unsigned int qual_menu);

        void valores_principal();
        void valores_seletor_fase();
        void valores_placar();
        void valores_saves();

        void menu_principal();
        void menu_seletor();
        void menu_placar();
        void menu_saves();
        void menu_pausa();

        void executar(float t);
        void ler_teclado();
        const unsigned int get_fase() const { return fase; }

    };

}

