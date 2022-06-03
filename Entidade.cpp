#include "Entidade.h"
#include "Fase.h"


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

	void Entidade::inicializar(GerenciadorGrafico& gg)
	{
		gg.carregar_textura(caminho);
		dimensao = gg.get_tamanho(caminho);
	}

	void Entidade::atualizar(float t)
	{
	}

	void Entidade::set_lista(ListaEntidades& l)
	{
		l.inserir(this);
	}
}
