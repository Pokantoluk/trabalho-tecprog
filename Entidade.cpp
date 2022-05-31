#include "Entidade.h"
#include <iostream>


namespace Game
{

	Entidade::Entidade(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		posicao(pos),
		v(vel),
		caminho(caminho_textura),
		id(id),
		encostou(false)
	{
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::inicializar(GerenciadorGrafico& gg, GerenciadorColisoes& gc)
	{
		gg.carregar_textura(caminho);
		dimensao = gg.get_tamanho(caminho);
		gc.add_Entidade(this);
	}

	void Entidade::atualizar(float t)
	{
	}

	void Entidade::desenhar(GerenciadorGrafico &gg)
	{
		gg.desenhar(caminho, posicao);
	}
	
}
