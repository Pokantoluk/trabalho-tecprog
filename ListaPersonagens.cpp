#include "ListaPersonagens.h"

namespace Game
{
	ListaPersonagens::ElementoLista::ElementoLista(Personagem* data, ElementoLista* prev, ElementoLista* next) :
		data(data),
		prev(prev),
		next(next)
	{
	}

	ListaPersonagens::ElementoLista::~ElementoLista()
	{
	}

	ListaPersonagens::ListaPersonagens():
		inicio(nullptr),
		fim(nullptr),
		atual(nullptr)
	{
	}

	ListaPersonagens::~ListaPersonagens()
	{
	}

	void ListaPersonagens::inserir(Personagem* info)
	{
		if (info)
		{
			ElementoLista* novo = new ElementoLista(info);//cria um elementolista com data = info;
			if (!inicio)
			{
				inicio = novo;
				fim = novo;
			}
			else
			{
				fim->set_next(novo);
				novo->set_prev(fim);
				fim = novo;
			}
		}
	}

	void ListaPersonagens::esvaziar()
	{
		ElementoLista* aux = inicio;
		atual = inicio;
		while (atual)
		{
			aux = atual->get_next();
			delete atual;
			atual = aux;
		}
		inicio = nullptr;
		fim = nullptr;
		atual = nullptr;
	}

	Personagem* ListaPersonagens::voltar_inicio()
	{
		atual = inicio;
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}

	Personagem* ListaPersonagens::proximo()
	{
		atual = atual->get_next();
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}

	void ListaPersonagens::update(float t)
	{
		Personagem* p = voltar_inicio();
		while (p)
		{
			p->atualizar(t);
			p = proximo();
		}
	}

	void ListaPersonagens::draw(sf::RenderWindow* janela)
	{
		Personagem* p = voltar_inicio();
		while (p)
		{
			p->desenhar(janela);
			p = proximo();
		}
	}

	void ListaPersonagens::destruir()
	{
		Personagem* p = voltar_inicio();
		while (p)
		{
			delete p;
			p = proximo();
		}
		esvaziar();
	}

}
