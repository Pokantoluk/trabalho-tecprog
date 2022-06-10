#pragma once
#include "stdafx.h"
#include "Ente.h"
#include "Vector2D.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "Jogador.h"
using namespace std;

namespace Jogo
{

    class Menu :
        public Ente
    {
    private:
        unsigned int num_menu;
        unsigned int fase;
        unsigned int num_jogadores;
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

        /*valores exibidos no menu*/
        void set_valores(unsigned int qual_menu);
        void valores_principal();
        void valores_seletor_fase();
        void valores_placar();
        void valores_qtd_jogadores();
        void valores_gameover_1();
        void valores_gameover_2();

        /*metodos do menu*/
        void menu_principal();
        void menu_seletor();
        void menu_placar();
        void menu_qtd_jogadores();
        void menu_pausa();
        void menu_gameover();


        void executar(float t);
        void ler_teclado();
        const unsigned int get_fase() const { return fase; }
        void tratar_pontos();
        unsigned int get_jogadores();

        /*metodos de arquivo*/

        void gravar();
        void recuperar();
    };

}

