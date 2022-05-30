#include "Entidade.h"
#include <iostream>


namespace Game
{

	Entidade::Entidade(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		position(pos),
		v(vel),
		caminho(caminho_textura),
		id(id)
	{
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::inicializar(GerenciadorGrafico& g, GerenciadorColisoes& gc)
	{
		g.carregar_textura(caminho);
	}

	void Entidade::atualizar(float t)
	{

		position += v * t;
	}

	void Entidade::desenhar(GerenciadorGrafico &g)
	{
		g.desenhar(caminho, position);
	}

	const Vector2F Entidade::get_dimentions() const
	{
		return dimension;
	}

	const IDsEntidades::IDsEntidades Entidade::get_id() const
	{
		return id;
	}
	
}
