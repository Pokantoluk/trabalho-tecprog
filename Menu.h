#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorMenu.h"
using namespace std;

namespace Jogo
{

    class Menu :
        public Ente
    {
    protected:
        int pos;
        bool enter;
        sf::Font* fonte;
        Gerenciadores::GerenciadorMenu* gm;

        
        vector<string> opcoes;
        vector<Vector2F> coords;
        vector<sf::Text> textos;
        vector<unsigned int> tamanho;

    public:
        Menu(const char* fundo = nullptr);
        ~Menu();
        void set_gm(Gerenciadores::GerenciadorMenu* gm = nullptr){ this->gm = gm; }

        virtual void executar(float t = 0) {}
        void ler_teclado();     
    };

}

