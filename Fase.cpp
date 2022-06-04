#include "Fase.h"
#include <Windows.h>

namespace Game
{
	namespace Fases
	{
		Fase::Fase(GerenciadorEventos* ge):
			fundo("assets/fundo_1.png"),
			gc(&entidades_moveis, &entidades_estaticas),
			ge(ge),
			o1(new Entidades::Obstaculos::Obstaculo(Vector2F(600.0f, 670.0f), "assets/rectangle6.png"))
		{
			o1->set_lista(entidades_estaticas);
			randomizar_inimigos();;
		}

		Fase::~Fase()
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
		}

		void Fase::carregar_fundo(GerenciadorGrafico& gg) const
		{
			gg.set_textura_fundo(fundo);
		}

		void Fase::randomizar_inimigos()
		{
			SYSTEMTIME st;
			GetSystemTime(&st);
			srand(st.wSecond);
			int qtd = rand() % 10 + 1;
			for (int i = 0; i < 1; i++)
			{
				float posX = static_cast<float>(rand() % 100 + 500);
				Entidades::Inimigo* e = new Entidades::Inimigo(Vector2F(posX, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
		}

		void Fase::inserir_jogador(Entidades::Jogador* j)
		{
			entidades_moveis.inserir(j);
		}

		void Fase::inicializar_entidades(GerenciadorGrafico& gg)
		{
			entidades_moveis.inicializar_entidades(gg);
			entidades_estaticas.inicializar_entidades(gg);
			ge->set_janela(gg.get_janela());
		}

		void Fase::executar(float t, GerenciadorGrafico& gg)
		{
			entidades_moveis.percorrer_executar(t, gg);
			entidades_estaticas.percorrer_executar(t, gg);
			gerenciar_colisoes();
		}

		void Fase::gerenciar_colisoes()
		{
			gc.verificar_colisoes();
		}

	}
}
