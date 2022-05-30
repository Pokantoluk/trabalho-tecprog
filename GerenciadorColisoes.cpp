#include "GerenciadorColisoes.h"
#include "Entidade.h"

namespace Game
{
	bool GerenciadorColisoes::colidiu(Entidade* p1, Entidade* p2)
	{
		Vector2F pos1 = p1->get_pos();
		Vector2F dim1 = p1->get_dim();
		Vector2F pos2 = p2->get_pos();
		Vector2F dim2 = p2->get_dim();
		Vector2F distancia = pos1 - pos2;
		return (fabs(distancia.x) <(dim1.x + dim2.x)/2.0) && (fabs(distancia.y) < (dim1.y + dim2.y) / 2.0);
	}
	GerenciadorColisoes::GerenciadorColisoes()
	{
	}
	GerenciadorColisoes::~GerenciadorColisoes()
	{
	}

	void GerenciadorColisoes::add_Entidade(Entidade* p)
	{
		colisions.insert(p);
	}
	void GerenciadorColisoes::rm_Entidade(Entidade* p)
	{
		colisions.erase(p);
	}
	void GerenciadorColisoes::rm_todos()
	{
		colisions.clear();
	}
	void GerenciadorColisoes::verificar_colisoes()
	{
		//std::cout<<colisions.size()<<std::endl;
		for (auto primeiro = colisions.begin(); primeiro != colisions.end(); primeiro++)
		{
			auto segundo = primeiro;
			segundo++;
			while (segundo != colisions.end())
			{
				Entidade* p1 = *primeiro;
				Entidade* p2 = *segundo;
				if (colidiu(p1, p2))
				{
					p1->colidir(p2->get_id(), p2->get_pos(), p2->get_dim());
					p2->colidir(p1->get_id(), p1->get_pos(), p1->get_dim());
				}
				segundo++;
			}
		}
	}
}