#include "Ente.h"

Jogo::Ente::Ente()
{
}

Jogo::Ente::~Ente()
{
}

void Jogo::Ente::imprimir(const char* caminho, Vector2F posicao)
{
	Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
}


