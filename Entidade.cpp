#include "Entidade.h"
#include "Fase.h"


namespace Game
{

	Entidade::Entidade(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		posicao(pos),
		v(vel),
		caminho(caminho_textura),
		id(id),
		destruir(false)
	{
	}

	Entidade::~Entidade()
	{
	}

	void Entidade::inicializar()
	{
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
		dimensao = Gerenciadores::GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
	}

	void Entidade::atualizar(float t)
	{
	}

	void Entidade::set_lista(Listas::ListaEntidades& l)
	{
		l.inserir(this);
	}
}
