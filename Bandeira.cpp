#include "Bandeira.h"

Jogo::Entidades::Obstaculos::Bandeira::Bandeira(Vector2F pos, const char* caminho_textura) :
    Obstaculo(IDsEntidades::IDsEntidades::bandeira, pos, caminho_textura),
    terminou_fase(false)
{
}

Jogo::Entidades::Obstaculos::Bandeira::~Bandeira()
{
}

void Jogo::Entidades::Obstaculos::Bandeira::colidir(Entidade* ente, Vector2F intersse)
{
    if (ente && ente->get_id() == IDsEntidades::Jogador)
    {
        terminou_fase = true;
    }
}
