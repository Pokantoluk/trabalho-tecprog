#include "Fase_2.h"
#include "Chefao.h"

namespace Jogo {
	namespace Fases {

		Fase_2::Fase_2() :
			Fase("assets/fundo_2.png"),
			bandeira(new Entidades::Obstaculos::Bandeira(Vector2F(2900.0f, 500.0f), "assets/bandeira_mario.png"))
		{
			bandeira->set_lista(entidades_estaticas);
			// criar aqui as plataformas
		}

		Fase_2::~Fase_2()
		{
		}

		void Fase_2::inicializar_entidades()
		{
			randomizar_inimigos();
			entidades_moveis.inicializar_entidades();
			entidades_estaticas.inicializar_entidades();
		}

		void Fase_2::randomizar_inimigos()
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
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(600, 300.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
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
				Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1000, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
				e->set_lista(entidades_moveis);
				e = nullptr;
			}
			if (qtd == 4)
			{
				if (inimigos[3])
				{
					Entidades::Personagens::Goomba* e = new Entidades::Personagens::Goomba(Vector2F(1300, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png");
					e->set_lista(entidades_moveis);
					e = nullptr;
				}
			}
			if (inimigos[0])
			{
				Entidades::Personagens::Chefao* n = new Entidades::Personagens::Chefao(Vector2F(2800, 600.0f), Vector2F(0.0f, 0.0f), "assets/chefao.png");
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (inimigos[1])
			{
				Entidades::Personagens::Chefao* n = new Entidades::Personagens::Chefao(Vector2F(2300, 600.0f), Vector2F(0.0f, 0.0f), "assets/chefao.png");
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (inimigos[2])
			{
				Entidades::Personagens::Chefao* n = new Entidades::Personagens::Chefao(Vector2F(2000, 600.0f), Vector2F(0.0f, 0.0f), "assets/chefao.png");
				n->set_lista(entidades_moveis);
				n = nullptr;
			}
			if (qtd == 4)
			{
				if (inimigos[3])
				{
					Entidades::Personagens::Chefao* n = new Entidades::Personagens::Chefao(Vector2F(1500, 600.0f), Vector2F(0.0f, 0.0f), "assets/chefao.png");
					n->set_lista(entidades_moveis);
					n = nullptr;
				}
			}
			
		}

		void Fase_2::randomizar_obstaculos()
		{
			//utilizar o codigo da randomizar_inimigos para fazer o msm com os obstaculos
		}

		bool Fase_2::get_fim()
		{
			if (bandeira->get_fim())
			{
				music.stop();
			}
			return bandeira->get_fim();
		}
	}
}
