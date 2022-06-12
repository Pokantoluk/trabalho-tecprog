/**
 * Project Untitled
 */


#ifndef _ELEMENTO_H
#define _ELEMENTO_H

template<Class TE >
class Elemento {
public: 
    
void Elemento();
    
void Elemento();
    
TE* getData();
    
/**
 * @param value
 */
void setData(TE* value);
    
Elemento<TE>* getAnte();
    
/**
 * @param value
 */
void setAnte(Elemento<TE>* value);
    
Elemento<TE>* getProx();
    
/**
 * @param value
 */
void setProx(Elemento<TE>* value);
private: 
    TE* data;
    Elemento<TE>* ante;
    Elemento<TE>* prox;
};

#endif //_ELEMENTO_H