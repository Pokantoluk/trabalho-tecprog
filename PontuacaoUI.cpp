#include "PontuacaoUI.h"
#include "Jogador.h"


namespace Jogo
{

	PontuacaoUI::PontuacaoUI():
		ComponenteGrafico(),
		texto_pontuacao(),
		fonte(new sf::Font())
	{
		fonte->loadFromFile("assets/eth.otf");
		texto_pontuacao.setFont(*fonte);
		texto_pontuacao.setCharacterSize(30);
		texto_pontuacao.setOutlineColor(sf::Color::Black);
		texto_pontuacao.setString("0");
		texto_pontuacao.setPosition(0, 0);
	}


	PontuacaoUI::~PontuacaoUI() 
	{
		if (fonte)
			delete fonte;
	}

	void PontuacaoUI::executar()
	{
		texto_pontuacao.setString("pontuação: " + std::to_string(Entidades::Personagens::Jogador::get_pontuacao()));
		Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenharUI(texto_pontuacao, Vector2F(-400, -350));
	}

}