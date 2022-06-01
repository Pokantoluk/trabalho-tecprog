#pragma once
#include <iostream>

namespace Game
{
	template<typename TL>
	class Lista
	{
	private:
		template<typename TE>
		class Elemento
		{
		private:
			TE* data;
			Elemento<TE>* ante;
			Elemento<TE>* prox;

		public:
			Elemento():
				data(nullptr),
				ante(nullptr),
				prox(nullptr)
			{
			}
			~Elemento(){}

			/*gets*/
			Elemento<TE>* get_ante() { return ante; }
			Elemento<TE>* get_prox() { return prox; }
			TE* get_data() { return data; }

			/*sets*/
			void set_ante(Elemento<TE>* ante) { this->ante = ante; }
			void set_prox(Elemento<TE>* prox) { this->prox = prox; }
			void set_data(TE* data) { this->data = data; }
		};

		Elemento<TL>* inicio;
		Elemento<TL>* fim;
		Elemento<TL>* atual;
	public:
		Lista();
		~Lista();

		void inserir(TL* info);
		void esvaziar();
		TL* voltar_inicio();
		TL* proximo();
		TL* operator[](int x);
	};

	template<typename TL>
	inline Lista<TL>::Lista()
	{
	}

	template<typename TL>
	inline Lista<TL>::~Lista()
	{
	}

	template<typename TL>
	inline void Lista<TL>::inserir(TL* info)
	{
		if (info)
		{
			Elemento<TL>* novo = new Elemento<TL>();
			novo->set_data(info);
			if (!inicio)
			{
				inicio = novo;
				fim = novo;
			}
			else
			{
				fim->set_prox(novo);
				novo->set_ante(fim);
				fim = novo;
			}
		}
	}
	template<typename TL>
	inline void Lista<TL>::esvaziar()
	{
		Elemento<TL>* aux = inicio;
		atual = inicio;
		while (atual)
		{
			aux = atual->get_prox();
			delete atual;
			atual = aux;
		}
		inicio = nullptr;
		fim = nullptr;
		atual = nullptr;
	}
	template<typename TL>
	inline TL* Lista<TL>::voltar_inicio()
	{
		atual = inicio;
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}
	template<typename TL>
	inline TL* Lista<TL>::proximo()
	{
		atual = atual->get_prox();
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}

	template<typename TL>
	TL* Lista<TL>::operator[](int index)
	{
		Elemento<TL>* aux = inicio;
		for (int i = 0; i < index; i++)
		{
			aux = aux->get_prox();
		}
		if (aux == nullptr)
		{
			std::cout << "Erro no operator[] aux == nullptr." << std::endl;
			exit(1);
		}
		return aux->get_data();
	}
}



