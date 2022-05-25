#pragma once
#include "Personagem.h"

namespace Game
{
	class ListaPersonagens
	{
	private:
		class ElementoLista
		{
		private:
			Personagem* data;
			ElementoLista* prev;
			ElementoLista* next;
			
		public:
			ElementoLista(Personagem* data = nullptr, ElementoLista* prev = nullptr, ElementoLista* next = nullptr);
			~ElementoLista();

			/*gets*/
			ElementoLista* get_prev() { return prev; }
			ElementoLista* get_next() { return next; }
			Personagem* get_data() { return data; }

			/*sets*/
			void set_prev(ElementoLista* prev) { this->prev = prev; }
			void set_next(ElementoLista* next) { this->next = next; }
			void set_data(Personagem* data) { this->data = data; }
		};
		ElementoLista* inicio;
		ElementoLista* fim;
		ElementoLista* atual;
	public:
		ListaPersonagens();
		~ListaPersonagens();
		void inserir(Personagem* info);
		void esvaziar();
		Personagem* voltar_inicio();
		Personagem* proximo();

		void update(float t);
		void draw(sf::RenderWindow* janela);
		void destruir();

	};

}

