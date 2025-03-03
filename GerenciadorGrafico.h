#pragma once
#include "stdafx.h"
#include "Vector2D.h"


namespace Jogo 
{
	namespace Gerenciadores
	{

		class GerenciadorGrafico
		{
		private:
			sf::RenderWindow* janela;
			sf::View camera;
			std::map<const std::string, sf::Texture*> texturas;
			static GerenciadorGrafico* instancia;

		public:
			
			GerenciadorGrafico();
			~GerenciadorGrafico();
			void mostrar() const;
			void limpar() const;
			void desenhar(const std::string caminho, const Vector2F pos);
			void desenhar_menu(sf::Text t) const;
			void desenharUI(const std::string caminho, const Vector2F pos);
			void desenharUI(sf::Text t, const Vector2F pos);
			bool carregar_textura(const std::string caminho);
			void centralizar(Vector2F centro_1 = Vector2F(0.f,0.f), Vector2F centro_2 = Vector2F(0.f, 0.f));
			sf::RenderWindow* get_janela() const { return janela; }
			const Vector2F get_tamanho(const std::string& caminho);
			static GerenciadorGrafico* get_gerenciador();



		};

	}
}
