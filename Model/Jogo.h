/**
 * Project Untitled
 */


#ifndef _JOGO_H
#define _JOGO_H

class Jogo {
public: 
    
void Jogo();
    
void Jogo();
    
void estatic bool na_fase();
    
void void inicializar_fase_1();
    
void void inicializar_fase_2();
    
void void reiniciar_fase();
    
void void reiniciar_fase_2();
    
void void executar();
private: 
    Menu menu;
    Mario* jogador_1;
    Luigi* jogador_2;
    Fase_1 fase_1;
    Fase_2 fase_2;
    GerenciadorGrafico gg;
    GerenciadorEventos ge;
    Clock relogio;
    bool dois_jogadores;
};

#endif //_JOGO_H