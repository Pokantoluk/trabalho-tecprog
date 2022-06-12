#include "jogador.h"
#include "Fase.h"
#include "ComponenteGrafico.h"
#include "VidaUI.h"


using namespace std;
namespace Jogo
{
	namespace Entidades
	{
		namespace Personagens 
		{

			
			int Jogador::pontuacao = 0;
			Jogador::Jogador(Vector2F pos, const char* caminho, const char* caminho_e) :
				Personagem(IDsEntidades::Jogador, pos, Vector2F(0,0), caminho, VIDA_MAX),
				andando(false),
				olhando_esquerda(false),
				pode_pular(false),
				morto(false),
				caminho_e(caminho_e),
				terminou_fase(false)
			{

			}
			Jogador::~Jogador()
			{

			}
			void Jogador::executar(float t)
			{
				atualizar(t);
				imprimir_se();
				cont_tempo_imune += t;
			}

			void Jogador::inicializar()
			{
				Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho_e);
				Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(caminho);
				dimensao = Gerenciadores::GerenciadorGrafico::get_gerenciador()->get_tamanho(caminho);
			}
			void Jogador::atualizar(float t)
			{
				tratar_eventos();
				bordas();
				if (gosma)
				{
					mod_vel = 0.3;

				}
				else if (mod_vel < 1)
				{
					mod_vel += (1 - mod_vel) * 0.00099;
				}
				if (andando)
				{
					v.x = VEL_JOGADOR*mod_vel;//coloca a velocidade do jogador
					gosma = false;
					if (olhando_esquerda)
					{
						v.x *= -1;//anda para o outro lado

					}
				}
				else
				{
					v.x *= 0.99f;
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
			void Jogador::imprimir_se()
			{
				if (olhando_esquerda)
					Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho_e, posicao);
				else
					Gerenciadores::GerenciadorGrafico::get_gerenciador()->desenhar(caminho, posicao);
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
					andar(false);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					andar(true);
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
					if (ente && ente->get_id() == IDsEntidades::Inimigo)
					{
						if (posicao.y + dimensao.y - 30 <= ente->get_pos().y)
						{

							posicao.y = ente->get_pos().y - dimensao.y;
							v.y = -sqrtf(2.0f * GRAVIDADE * PULO);
							pode_pular = true;
						}
						else if (posicao.x < ente->get_pos().x)
						{
							v.x = -500;

							posicao.x = ente->get_pos().x - dimensao.x - 20;
						}
						else if (posicao.x > ente->get_pos().x)
						{
							v.x = +500;
							posicao.x = ente->get_pos().x + ente->get_dim().x + 20;

						}

					}
					else if (ente && ente->get_id() == IDsEntidades::obstaculo)
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
					else if(ente && ente->get_id() == IDsEntidades::bandeira)
					{
						terminou_fase = true;
					}
			}
			void Jogador::pular()
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
			void Jogador::bordas()
			{
				if (posicao.x < 0) { posicao.x = 0; }
				if (posicao.y + dimensao.y >= 800)
				{
					posicao.y = 800 - dimensao.y;
				
					no_chao = true;
				}
				
			}
			bool Jogador::get_morto()
			{
				if (vidas <= 0)
				{
					return true;
				}
				else
					return false;
			}
			
		}
	}
}
