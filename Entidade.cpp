#include "Entidade.h"
#include "Fase.h"


namespace Jogo
{

	Entidade::Entidade(IDsEntidades::IDsEntidades id, Vector2F pos, Vector2F vel, const char* caminho_textura) :
		Ente(pos, caminho_textura, id),
		v(vel),
		destruir(false),
		gosma(false)
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
