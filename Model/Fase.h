/**
 * Project Untitled
 */


#ifndef _FASE_H
#define _FASE_H

#include "Ente.h"


class Fase: public Ente {
public: 
    
void Fase();
    
void Fase();
    
void virtual void carregar_fundo();
    
void void randomizar_inimigos();
    
/**
 * @param j
 */
void void inserir_jogador(Jogdaor* j);
    
void void inicializar_entidades();
    
/**
 * @param pos_jogador
 */
void void reiniciar_entidades(Vector2F pos_jogador);
    
virtual virtual void executar() = 0;
    
void void gerenciar_colisoes();
    
/**
 * @param proj
 */
void void add_projetil(Projetil* proj);
    
/**
 * @param pausa
 */
void static void set_pausa(bool pausa);
    
void bool get_pausa();
protected: 
    ListaEntidades entidades_estaticas;
    ListaEntidades entidades_moveis;
    GerenciadorColisoes gc;
    VidaUI* vidaui;
    PontuacaoUI* pontuacaoui;
    Music music;
    static bool pausado;
};

#endif //_FASE_H