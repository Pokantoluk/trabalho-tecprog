/**
 * Project Untitled
 */


#ifndef _ENTIDADE_H
#define _ENTIDADE_H

class Entidade {
public: 
    
/**
 * @param id
 * @param pos
 * @param vel
 * @param caminho_textura
 */
void Entidade(IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura);
    
void virtual Entidade();
    
/**
 * @param t
 * @param gg
 */
void virtual void executar(float t, GerenciadorGrafico& gg);
    
/**
 * @param ente
 * @param interssec
 */
void virtual void colidir(Entidade* ente, Vector2F interssec);
    
/**
 * @param gg
 */
void virtual void inicializar(GerenciadorGrafico& gg);
    
/**
 * @param t
 */
void virtual void atualizar(float t);
    
/**
 * @param l
 */
void void set_lista(ListaEntidades& l);
    
const Vector2F const get_dim();
    
const Vector2F const get_pos();
    
const IDsEntidades const  get_id();
    
void Operation11();
protected: 
    Vector2F posicao;
    Vector2F v;
    Vector2F dimensao;
    const char* caminho;
    IDsEntidades id;
};

#endif //_ENTIDADE_H