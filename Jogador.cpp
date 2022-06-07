#include "jogador.h"
#include "Fase.h"
#include <iostream>

using namespace std;
namespace Game
{
	namespace Entidades
	{
		int Jogador::pontos = 0;

		Jogador::Jogador(Vector2F pos, Vector2F vel) :
			Personagem(IDsEntidades::Jogador, pos, vel, "assets/mario.png", 1),
			andando(false),
			olhando_esquerda(false),
			pode_pular(false),
			morto(false),
			caminho_e("assets/mario_e.png")
		{

		}

		Jogador::~Jogador()
		{
		}

		void Jogador::executar(float t)
		{
			atualizar(t);
			GerenciadorGrafico::get_gerenciador()->centralizar(posicao);
			if (olhando_esquerda)
			{
				imprimir(caminho_e, posicao);
			}
			else
			{
				imprimir(caminho, posicao);
			}
		}

		void Jogador::inicializar()
		{
			GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho_e);
			GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
			dimensao = GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
		}

		void Jogador::atualizar(float t)
		{
			tratar_eventos();
			bordas();
			if (andando)
			{
				v.x = VEL_JOGADOR;//coloca a velocidade do jogador
				if (olhando_esquerda)
				{
					v.x *= -1;//anda para o outro lado

				}
			}
			else
			{
				v.x *= 0.99;
			}
			if (!pode_pular)
			{
				v.y += GRAVIDADE * t;
			}
			posicao += v * t;
			if (!no_chao)
				pode_pular = false;
			else
				pode_pular = true;
		}


		void Jogador::tratar_eventos()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				Fases::Fase::set_pausa(true);
				sf::sleep(sf::milliseconds(300));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				andar(false);//anda com falso para esquerda
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				andar(true);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				//posicao.y -= 0.1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				//posicao.y += 0.1;
			}
			else
			{
				andando = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				pular();
			}
		}

		void Jogador::colidir(Entidade* ente, Vector2F intersse)
		{
			if (ente->get_id() == IDsEntidades::Inimigo)
			{
			}
			else if (ente->get_id() == IDsEntidades::obstaculo)
			{
				
				if (posicao.y + dimensao.y - 10 <= ente->get_pos().y)
				{
					v.y = 0;
					posicao.y = ente->get_pos().y - dimensao.y;
					pode_pular = true;
				}
				else if (posicao.x < ente->get_pos().x)
				{
					v.x = 0;
					posicao.x = ente->get_pos().x - dimensao.x;
				}
				else if (posicao.x > ente->get_pos().x)
				{
					v.x = 0;
					posicao.x = ente->get_pos().x + ente->get_dim().x;
				}
			}
		}

		void Jogador::pular() //para fazer o personagem pular
		{
			if (pode_pular)
			{
				v.y = -sqrtf(2.0f * GRAVIDADE * PULO);
			}
			no_chao = false;
		}

		void Jogador::andar(bool esquerda)
		{
			andando = true;
			olhando_esquerda = esquerda;
		}

		void Jogador::bordas()//para não sair da tela
		{
			if (posicao.x < 0) { posicao.x = 0; }
			if (posicao.y + dimensao.y >= 800)
			{
				posicao.y = 800 - dimensao.y;
				//pode_pular = true;
				no_chao = true;
			}
			else
			{
				//pode_pular = false;
			}
		}
		bool Jogador::get_morto()
		{
			if (vidas == 0)
				return true;
			else
				return false;
		}
		unsigned int Jogador::get_pontuacao()
		{
			return pontos;
		}
	}
}
