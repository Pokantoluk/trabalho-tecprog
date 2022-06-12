#include "Fase_1.h"


namespace Jogo
{
	namespace Fases
	{
		Fase_1::Fase_1() :
			Fase("assets/fundo_1.png"),
			o1(new Entidades::Obstaculos::Plataforma(Vector2F(600.0f, 670.0f), "assets/plataforma.jpg")),
			o2(new Entidades::Obstaculos::Plataforma(Vector2F(700.0f, 670.0f), "assets/plataforma.jpg")),
			o6(new Entidades::Obstaculos::Plataforma(Vector2F(1500.0f, 700.0f), "assets/rectangle6.png")),
			o7(new Entidades::Obstaculos::Plataforma(Vector2F(1550.0f, 680.0f), "assets/rectangle6.png")),
			o8(new Entidades::Obstaculos::Plataforma(Vector2F(1600.0f, 660.0f), "assets/rectangle6.png")),
			o9(new Entidades::Obstaculos::Plataforma(Vector2F(1650.0f, 640.0f), "assets/rectangle6.png")),
			o10(new Entidades::Obstaculos::Plataforma(Vector2F(1700.0f, 620.0f), "assets/rectangle6.png")),
			o11(new Entidades::Obstaculos::Plataforma(Vector2F(1750.0f, 640.0f), "assets/rectangle6.png")),
			o12(new Entidades::Obstaculos::Plataforma(Vector2F(1800.0f, 660.0f), "assets/rectangle6.png")),
			o13(new Entidades::Obstaculos::Plataforma(Vector2F(1850.0f, 680.0f), "assets/rectangle6.png")),
			o14(new Entidades::Obstaculos::Plataforma(Vector2F(1900.0f, 700.0f), "assets/rectangle6.png")),
			fogo(new Entidades::Obstaculos::Fogo(Vector2F(2350.0f, 750.0f), "assets/fogo1.png")),
			fogo1(new Entidades::Obstaculos::Fogo(Vector2F(2400.0f, 750.0f), "assets/fogo1.png")),
			fogo2(new Entidades::Obstaculos::Fogo(Vector2F(2450.0f, 750.0f), "assets/fogo1.png")),
			pedra(new Entidades::Obstaculos::Pedra(Vector2F(1000.0f, 750.0f), "assets/rocks1_5.png")),
			pedra2(new Entidades::Obstaculos::Pedra(Vector2F(1300.0f, 750.0f), "assets/rocks1_5.png")),
			gosma1( new Entidades::Obstaculos::Gosma(Vector2F(2000.0f,790.0f), "assets/gosma.png")),
			bandeira(new Entidades::Obstaculos::Bandeira(Vector2F(2900.0f, 500.0f), "assets/bandeira_mario.png"))
			//manter aqui apenas as plataformas e a bandeira
		{
		}

		Fase_1::~Fase_1()
		{
		}
		void Fase_1::inicializar_entidades()
		{
			randomizar_inimigos();
			o1->set_lista(entidades_estaticas);
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
			fogo->set_lista(entidades_estaticas);
			fogo1->set_lista(entidades_estaticas);
			fogo2->set_lista(entidades_estaticas);
			gosma1->set_lista(entidades_estaticas);
			bandeira->set_lista(entidades_estaticas);
			o2->set_lista(entidades_estaticas);

			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}
		void Fase_1::randomizar_obstaculos()
		{
			//utilizar o codigo da randomizar_inimigos para fazer o msm com os obstaculos
		}
		void Fase_1::randomizar_inimigos()
		{
			std::vector<int> inimigos;
			SYSTEMTIME st;
			GetSystemTime(&st);
			srand(st.wSecond);
			int aux = 0;
			int qtd = rand() % 2 + 3;
			while (aux < 3) {
				inimigos.clear();
				aux = 0;
				for (int i = 0; i < qtd; i++)
				{
					inimigos.push_back(rand() % 2 == 1 ? 0 : 1);
				}
				for (int i = 0; i < qtd; i++)
				{
					aux += inimigos[i];
				}
			}
			
			if (inimigos[0])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(650, 500.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (inimigos[1])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(900, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (inimigos[2])
			{
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1200, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (qtd == 4)
			{
				if (inimigos[3])
				{
					Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1600, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
					e->set_lista(entidades_moveis);
					e = nullptr;
				}
			}
			if (inimigos[0])
			{
				Entidades::Personagens::NuvemMal* n = new Entidades::Personagens::NuvemMal(Vector2F(500, 65.0f), Vector2F(0.0f, 0.0f), "assets/nuvem_malvada.png", static_cast<Fase*> (this));
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (inimigos[1])
			{
				Entidades::Personagens::NuvemMal* n = new Entidades::Personagens::NuvemMal(Vector2F(1200, 65.0f), Vector2F(0.0f, 0.0f), "assets/nuvem_malvada.png", static_cast<Fase*> (this));
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (inimigos[2])
			{
				Entidades::Personagens::NuvemMal* n = new Entidades::Personagens::NuvemMal(Vector2F(1800, 65.0f), Vector2F(0.0f, 0.0f), "assets/nuvem_malvada.png", static_cast<Fase*> (this));
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (qtd == 4)
			{
				if (inimigos[3])
				{
					Entidades::Personagens::NuvemMal* n = new Entidades::Personagens::NuvemMal(Vector2F(2400, 65.0f), Vector2F(0.0f, 0.0f), "assets/nuvem_malvada.png", static_cast<Fase*> (this));
					n->set_lista(entidades_moveis);
					n = nullptr;
				}
			}

		}

		bool Fase_1::get_fim()
		{
			if (bandeira->get_fim())
			{
				music.stop();
			}

			return bandeira->get_fim();
		}
	}
}