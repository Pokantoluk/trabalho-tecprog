#include "Fase.h"
#include <Windows.h>

namespace Game
{
	namespace Fases
	{
		bool Fase::pausado{ false };

		Fase::Fase() :
			gc(&entidades_moveis, &entidades_estaticas)
		{
			randomizar_inimigos();
			musica();
		}

		Fase::~Fase()
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
		}
		void Fase::musica()
		{
			
			if (!music.openFromFile("assets/SuperMarioBros.ogg"))
				return;// error
			music.play();
			music.setVolume(4);
		}

		void Fase::carregar_fundo() const
		{
		}

		void Fase::randomizar_inimigos()
		{
			SYSTEMTIME st;
			GetSystemTime(&st);
			srand(st.wSecond);
			int qtd = rand() % 3 + 3;
			for (int i = 0; i < qtd; i++)
			{
				float posX = static_cast<float>(rand() % 2100 + 500);
				Entidades::Inimigo* e = new Entidades::Inimigo(Vector2F(posX, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
		}

		void Fase::inserir_jogador(Entidades::Jogador* j)
		{
			entidades_moveis.inserir(j);

		}

		void Fase::inicializar_entidades()
		{
			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}

		void Fase::reiniciar_entidades(Vector2F pos_jogador)
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
			inicializar_entidades();
		}

		void Fase::executar(float t)
		{
			entidades_moveis.percorrer_executar(t);
			entidades_estaticas.percorrer_executar(t);
			gerenciar_colisoes();
			
		}

		void Fase::gerenciar_colisoes()
		{
			gc.verificar_colisoes();
		}
	}
}
