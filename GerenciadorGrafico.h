#pragma once
#include "SFML/Graphics.hpp"
#include <map>
#include <iostream>
#include <string>
#include "Vector2D.h"


namespace Game 
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* janela;
		sf::View camera;
		std::map<const std::string, sf::Texture*> texturas;
		sf::RectangleShape piso;

	public:
		GerenciadorGrafico();
		~GerenciadorGrafico();
		void mostrar() const;
		void limpar(int r = 0, int g = 0, int b = 0);
		void desenhar(const std::string caminho, const Vector2F pos);
		bool carregar_textura(const std::string caminho);
		void centralizar(Vector2F centro);
		sf::RenderWindow* get_janela() const { return janela; }
		const Vector2F get_tamanho(const std::string& caminho);
	};

}
