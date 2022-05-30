#include "Entidade.h"
#include <iostream>


namespace Game
{

	Entidade::Entidade(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		posicao(pos),
		v(vel),
		caminho(caminho_textura),
		id(id)
	{
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
	}

	void Entidade::atualizar(float t)
	{
	}

	void Entidade::desenhar(GerenciadorGrafico &g)
	{
	}

	const Vector2F Entidade::get_dim() const
	{
		return dimensao;
	}

	const IDsEntidades::IDsEntidades Entidade::get_id() const
	{
		return id;
	}
	
}
