#include "Ente.h"

Game::Ente::Ente()
{
}

Game::Ente::~Ente()
{
}

void Game::Ente::imprimir(const char* caminho, Vector2F posicao)
{
	Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
}


