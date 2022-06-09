#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Jogador.h"
using namespace std;

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
        string nome_a_salvar;
        sf::Font* fonte;


        vector<unsigned int> pontos;
        vector<string> jogadores;
        vector<string> opcoes;
        vector<Vector2F> coords;
        vector<sf::Text> textos;
        vector<unsigned int> tamanho;

    public:
        Menu();
        ~Menu();
        void iniciar();

        /*valores exibidos no menu*/
        void set_valores(unsigned int qual_menu);
        void valores_principal();
        void valores_seletor_fase();
        void valores_placar();
        void valores_saves();
        void valores_gameover();

        /*metodos do menu*/
        void menu_principal();
        void menu_seletor();
        void menu_placar();
        void menu_saves();
        void menu_pausa();
        void menu_gameOver();


        void executar(float t);
        void ler_teclado();
        const unsigned int get_fase() const { return fase; }
        void tratar_pontos();

        /*metodos de arquivo*/

        void gravar();
        void recuperar();
    };

}

