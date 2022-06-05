#include "Fase.h"
#include <Windows.h>

namespace Game
{
	namespace Fases
	{
		Fase::Fase():
			fundo("assets/fundo_1.png"),
			gc(&entidades_moveis, &entidades_estaticas),
			o1(new Entidades::Obstaculos::Obstaculo(Vector2F(600.0f, 670.0f), "assets/rectangle6.png")),
			o2(new Entidades::Obstaculos::Obstaculo(Vector2F(650.0f, 670.0f), "assets/rectangle6.png")),
			o3(new Entidades::Obstaculos::Obstaculo(Vector2F(700.0f, 670.0f), "assets/rectangle6.png")),
			o4(new Entidades::Obstaculos::Obstaculo(Vector2F(750.0f, 670.0f), "assets/rectangle6.png")),
			o5(new Entidades::Obstaculos::Obstaculo(Vector2F(800.0f, 670.0f), "assets/rectangle6.png")),
			o6(new Entidades::Obstaculos::Obstaculo(Vector2F(1500.0f, 650.0f), "assets/rectangle6.png")),
			o7(new Entidades::Obstaculos::Obstaculo(Vector2F(1550.0f, 630.0f), "assets/rectangle6.png")),
			o8(new Entidades::Obstaculos::Obstaculo(Vector2F(1600.0f, 610.0f), "assets/rectangle6.png")),
			o9(new Entidades::Obstaculos::Obstaculo(Vector2F(1650.0f, 590.0f), "assets/rectangle6.png")),
			o10(new Entidades::Obstaculos::Obstaculo(Vector2F(1700.0f, 570.0f), "assets/rectangle6.png")),
			o11(new Entidades::Obstaculos::Obstaculo(Vector2F(1750.0f, 590.0f), "assets/rectangle6.png")),
			o12(new Entidades::Obstaculos::Obstaculo(Vector2F(1800.0f, 610.0f), "assets/rectangle6.png")),
			o13(new Entidades::Obstaculos::Obstaculo(Vector2F(1850.0f, 630.0f), "assets/rectangle6.png")),
			o14(new Entidades::Obstaculos::Obstaculo(Vector2F(1900.0f, 650.0f), "assets/rectangle6.png")),
			fogo(new Entidades::Obstaculos::Obstaculo(Vector2F(2300.0f, 750.0f), "assets/fogo1.png")),// fazer a classe fogo com eles randomizados feat dando dano e feat animação
			pedra(new Entidades::Obstaculos::Obstaculo(Vector2F(1000.0f, 750.0f), "assets/rocks1_5.png")),
			pedra2(new Entidades::Obstaculos::Obstaculo(Vector2F(1400.0f, 750.0f), "assets/rocks1_5.png")),
			bandeira(new Entidades::Obstaculos::Obstaculo(Vector2F(2600.0f, 500.0f), "assets/bandeira_mario.png"))
		{
			o1->set_lista(entidades_estaticas);
			o2->set_lista(entidades_estaticas);
			o3->set_lista(entidades_estaticas);
			o4->set_lista(entidades_estaticas);
			o5->set_lista(entidades_estaticas);
			o6->set_lista(entidades_estaticas);
			o7->set_lista(entidades_estaticas);
			o8->set_lista(entidades_estaticas);
			o9->set_lista(entidades_estaticas);
			o10->set_lista(entidades_estaticas);
			o11->set_lista(entidades_estaticas);
			o12->set_lista(entidades_estaticas);
			o13->set_lista(entidades_estaticas);
			o14->set_lista(entidades_estaticas);
			pedra->set_lista(entidades_estaticas);
			pedra2->set_lista(entidades_estaticas);
			bandeira->set_lista(entidades_estaticas);
			fogo->set_lista(entidades_estaticas);
			randomizar_inimigos();
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
			music.setVolume(5);
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
			for (int i = 0; i < 10; i++)
			{
				float posX = static_cast<float>(rand() % 3000 + 500);
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
			musica();
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
