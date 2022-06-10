#include "Ente.h"

Jogo::Ente::Ente(Vector2F posicao, const char* caminho, IDsEntidades::IDsEntidades id):
	posicao(posicao),
	caminho(caminho),
	id(id)
{
}

Jogo::Ente::~Ente()
{
}

void Jogo::Ente::imprimir_se()
{
	Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
}


