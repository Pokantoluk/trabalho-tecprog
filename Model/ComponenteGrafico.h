/**
 * Project Untitled
 */


#ifndef _COMPONENTEGRAFICO_H
#define _COMPONENTEGRAFICO_H

class ComponenteGrafico {
public: 
    
/**
 * @param jog
 */
void ComponenteGrafico(Jogador* jog);
    
void ComponenteGrafico();
    
void virtual void executar();
protected: 
    Jogador* jogador;
};

#endif //_COMPONENTEGRAFICO_H