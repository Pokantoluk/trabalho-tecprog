#include "Bandeira.h"

Jogo::Entidades::Obstaculos::Bandeira::Bandeira(Vector2F pos, const char* caminho_textura) :
    Obstaculo(IDsEntidades::IDsEntidades::bandeira, pos, caminho_textura)
{
}

Jogo::Entidades::Obstaculos::Bandeira::~Bandeira()
{
}
