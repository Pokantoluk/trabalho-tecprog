/**
 * Project Untitled
 */


#ifndef _OBSTACULO_H
#define _OBSTACULO_H

class obstaculo {
public: 
    
/**
 * @param pos
 * @param caminho_textura
 */
void Obstaculo(Vector2F pos, const char* caminho_textura);
    
void Obstaculo();
    
/**
 * @param t
 * @param gg
 */
void void executar(float t, GerenciadorGrafico& gg);
    
/**
 * @param ente
 * @param intersse
 */
void void colidir(Entidade* ente, Vector2F intersse);
    
/**
 * @param gg
 * @param gc
 */
void void inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc);
    
/**
 * @param t
 */
void void atualizar(float t);
    
/**
 * @param gg
 */
void void desenhar(GerenciadorGrafico& gg);
};

#endif //_OBSTACULO_H