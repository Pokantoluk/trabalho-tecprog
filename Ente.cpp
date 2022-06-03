#include "Ente.h"

Game::Ente::Ente()
{
}

Game::Ente::~Ente()
{
}

void Game::Ente::imprimir(GerenciadorGrafico& gg, const char* caminho, Vector2F posicao)
{
	gg.desenhar(caminho, posicao);
}


