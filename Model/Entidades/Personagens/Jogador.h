/**
 * Project Untitled
 */


#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "../../Personagem.h"


class Jogador: public Personagem {
public: 
    
/**
 * @param pos
 * @param caminho
 * @param caminho_e
 */
void Jogador(Vector2F pos, const char* caminho, const char* caminho_e);
    
void Jogador();
    
/**
 * @param t
 * @param gg
 */
void void executar(float t, GerenciadorGrafico& gg);
    
/**
 * @param gg
 */
void void inicializar(GerenciadorGrafico& gg);
    
/**
 * @param t
 */
void void atualizar(float t);
    
void void tratar_eventos();
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
    
void void pular();
    
/**
 * @param esquerda
 */
void void andar(bool esquerda);
    
void void bordas();
    
/**
 * @param pode
 */
void void set_pode_pular(bool pode);
    
const unsigned int const get _pontuacao();
    
void Operation1();
    
void void imprimir_se();
    
/**
 * @param pos
 */
void void set_posicao(Vector2F pos);
    
void bool get_morto();
    
void const unsigned int get_vida();
private: 
    void pontos: unsigned int;
    void andando: bool;
    void pode_pular: bool;
    void olhando_esquerda: bool;
    void caminho_e : const char*;
    bool morto;
};

#endif //_JOGADOR_H