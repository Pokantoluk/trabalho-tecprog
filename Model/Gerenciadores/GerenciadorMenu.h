/**
 * Project Untitled
 */


#ifndef _GERENCIADORMENU_H
#define _GERENCIADORMENU_H

class GerenciadorMenu {
public: 
    
void GerenciadorMenu();
    
void GerenciadorMenu();
    
void executar();
    
void set_pausa();
    
void set_gameover();
    
/**
 * @param const string nome
 */
void tratar_pontos(void const string nome);
    
void gravar();
    
void recuperar();
    
/**
 * @param unsigned int n
 */
void set_menu(void unsigned int n);
    
/**
 * @param unsigned int f
 */
void set_fase(void unsigned int f);
    
/**
 * @param unsigned int g
 */
void set_jog(void unsigned int g);
    
const unsigned int get_fase();
    
const unsigned int get_num_jogadores();
    
const vector<unsigned int> get_pontos();
    
const vector<string> get_jogadores();
private: 
    unsigned int num_menu;
    unsigned int fase;
    unsigned int num_jogadores;
    MenuPrincipal* mPr;
    MenuPersonagens* mPe;
    MenuSeletor* mSe;
    MenuPlacar* mPl;
    MenuPausa* mPa;
    MenuGameOver* mGo;
    vector<unsigned int> pontos;
    vector<string> jogadores;
};

#endif //_GERENCIADORMENU_H