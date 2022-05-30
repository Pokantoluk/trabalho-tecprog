#pragma once

namespace Game
{
	template<typename T>
	class Lista
	{
	private:
		class ElementoLista
		{
		private:
			T* data;
			ElementoLista* prev;
			ElementoLista* next;

		public:
			ElementoLista(T* data = nullptr, ElementoLista* prev = nullptr, ElementoLista* next = nullptr):
				data(data),
				prev(prev),
				next(next)
			{
			}
			~ElementoLista(){}

			/*gets*/
			ElementoLista* get_prev() { return prev; }
			ElementoLista* get_next() { return next; }
			T* get_data() { return data; }

			/*sets*/
			void set_prev(ElementoLista* prev) { this->prev = prev; }
			void set_next(ElementoLista* next) { this->next = next; }
			void set_data(T* data) { this->data = data; }
		};
		ElementoLista* inicio;
		ElementoLista* fim;
		ElementoLista* atual;
	public:
		Lista();
		~Lista();
		void inserir(T* info);
		void esvaziar();
		T* voltar_inicio();
		T* proximo();



	};

	template<typename T>
	inline Lista<T>::Lista()
	{
	}

	template<typename T>
	inline Lista<T>::~Lista()
	{
	}

	template<typename T>
	inline void Lista<T>::inserir(T* info)
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
	template<typename T>
	inline void Lista<T>::esvaziar()
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
	template<typename T>
	inline T* Lista<T>::voltar_inicio()
	{
		atual = inicio;
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}
	template<typename T>
	inline T* Lista<T>::proximo()
	{
		atual = atual->get_next();
		if (atual) { return atual->get_data(); }
		else { return nullptr; }
	}

}



