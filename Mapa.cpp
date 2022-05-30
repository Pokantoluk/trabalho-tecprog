#include "Mapa.h"

Game::Mapa::Mapa(Vector2F pos, Vector2F vel, const char* caminho_textura):
	Entidade(IDsEntidades:: obstaculo, pos, vel, caminho_textura)
{
}

Game::Mapa::~Mapa()
{
}
