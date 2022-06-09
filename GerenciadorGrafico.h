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
			sf::Texture textura_fundo;
			sf::Sprite fundo;
			sf::RenderWindow* janela;
			sf::View camera;
			std::map<const std::string, sf::Texture*> texturas;

			static GerenciadorGrafico* instancia;

		public:
			static GerenciadorGrafico* get_gerenciador();

			GerenciadorGrafico();
			~GerenciadorGrafico();
			void mostrar() const;
			void limpar(int r = 0, int g = 0, int b = 0);
			void desenhar(const std::string caminho, const Vector2F pos);
			void desenhar_menu(sf::Text t);
			bool carregar_textura(const std::string caminho);
			void centralizar(Vector2F centro_1, Vector2F centro_2);
			void set_textura_fundo(const char* caminho);
			sf::RenderWindow* get_janela() const { return janela; }
			const Vector2F get_tamanho(const std::string& caminho);

		};

	}
}
