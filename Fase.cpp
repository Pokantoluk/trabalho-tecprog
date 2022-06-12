#include "Fase.h"
#include "stdafx.h"
using namespace std;

namespace Jogo
{
	namespace Fases
	{
		bool Fase::pausado{ false };

		Fase::Fase(const char* fundo) :
			gc(&entidades_moveis, &entidades_estaticas),
			vidaui(nullptr),
			pontuacaoui(new PontuacaoUI()),
			Ente(Vector2F(0,0),fundo, IDsEntidades::Fase)
		{
			musica();
			Gerenciadores::GerenciadorGrafico::get_gerenciador()->carregar_textura(fundo);
		}

		Fase::~Fase()
		{
			destruir_fase();
		}
		void Fase::musica()
		{
			
			if (!music.openFromFile("assets/SuperMarioBros.ogg"))
				return;// error
			music.play();
			music.setVolume(4);
			
		}

		void Fase::destruir_fase()
		{
			pausado = false;
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
			if (vidaui)
			{
				delete vidaui;
				vidaui = nullptr;

			}
			if (pontuacaoui)
			{
				delete pontuacaoui;
				pontuacaoui = nullptr;
			}
		}

	

		void Fase::randomizar_inimigos()
		{
		}

		void Fase::inserir_jogador(Entidades::Personagens::Jogador* j)
		{
			entidades_moveis.inserir(j);
			vidaui = new VidaUI(j);
		}

		void Fase::inicializar_entidades()
		{
			randomizar_inimigos();
			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}



		void Fase::executar(float t)
		{
			imprimir_se();
			entidades_moveis.percorrer_executar(t);
			//std::cout << "banana" << std::endl;
			entidades_estaticas.percorrer_executar(t);
			//std::cout << "morango" << std::endl;
			gerenciar_colisoes();
			//std::cout << "abacate" << std::endl;
			vidaui->executar();
			//std::cout << "tangerina" << std::endl;
			pontuacaoui->executar();

			//std::cout << "melancia" << std::endl;



		}

		void Fase::gerenciar_colisoes()
		{
			gc.verificar_colisoes();
		}
		void Fase::add_projetil(Entidades::Projetil* proj)
		{
			if (proj)
			{
				proj->inicializar();
				proj->set_lista(entidades_moveis);
				
			}
		}
	}
}
