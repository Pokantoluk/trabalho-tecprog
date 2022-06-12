/**
 * Project Untitled
 */


#include "Entidade.h"

/**
 * Entidade implementation
 */


/**
 * @param id
 * @param pos
 * @param vel
 * @param caminho_textura
 */
void Entidade::Entidade(IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) {

}

void Entidade::virtual Entidade() {

}

/**
 * @param t
 * @param gg
 */
void Entidade::virtual void executar(float t, GerenciadorGrafico& gg) {

}

/**
 * @param ente
 * @param interssec
 */
void Entidade::virtual void colidir(Entidade* ente, Vector2F interssec) {

}

/**
 * @param gg
 */
void Entidade::virtual void inicializar(GerenciadorGrafico& gg) {

}

/**
 * @param t
 */
void Entidade::virtual void atualizar(float t) {

}

/**
 * @param l
 */
void Entidade::void set_lista(ListaEntidades& l) {

}

/**
 * @return const Vector2F
 */
const Vector2F Entidade::const get_dim() {
    return null;
}

/**
 * @return const Vector2F
 */
const Vector2F Entidade::const get_pos() {
    return null;
}

/**
 * @return const IDsEntidades
 */
const IDsEntidades Entidade::const  get_id() {
    return null;
}

void Entidade::Operation11() {

}