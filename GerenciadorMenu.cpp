#include "GerenciadorMenu.h"
#include "MenuPrincipal.h"
#include "MenuPersonagens.h"
#include "MenuSeletor.h"
#include "MenuPlacar.h"
#include "MenuGameover.h"
#include "MenuPausa.h"
#define MENU_PRINCIPAL 1
#define SELETOR 2
#define PLACAR 3
#define PERSONAGENS 4
#define FASE_1 5
#define FASE_2 6
#define GAMEOVER_1 7
#define GAMEOVER_2 8



namespace Jogo
{
	namespace Gerenciadores
	{
		GerenciadorMenu::GerenciadorMenu():
			fase(0),
			num_menu(MENU_PRINCIPAL),
			num_jogadores(1), 
			mPr(new MenuPrincipal), 
			mPe(new MenuPersonagens), 
			mSe(new MenuSeletor), 
			mGo(new MenuGameover),
			mPl(new MenuPlacar),
			mPa(new MenuPausa)
		{
			mPr->set_gm(this);
			mPe->set_gm(this);
			mSe->set_gm(this);
			mGo->set_gm(this);
			mPl->set_gm(this);
			mPa->set_gm(this);
			recuperar();
			mPl->valores();
		}
		GerenciadorMenu::~GerenciadorMenu()
		{
			delete mPr;
			delete mPe;
			delete mSe;
			delete mGo;
			delete mPl;
			delete mPa;
		}
		void GerenciadorMenu::executar()
		{
			//cout << fase << endl;
			if (num_menu == MENU_PRINCIPAL)
				mPr->executar();
			else if (num_menu == SELETOR)
				mSe->executar();
			else if (num_menu == PLACAR)
				mPl->executar();
			else if (num_menu == PERSONAGENS)
				mPe->executar();
			else if (num_menu == FASE_1)
				fase = 1;
			else if (num_menu == FASE_2)
				fase = 2;
		}

		void GerenciadorMenu::set_pausa()
		{
			mPa->executar();
		}

		bool GerenciadorMenu::set_gameover()
		{
			mGo->executar();
			if (!fase) 
			{
				return true; 
			}
			else { return false; }
		}

		void GerenciadorMenu::tratar_pontos(string nome)
		{
			int ponto = Entidades::Personagens::Mario::get_pontuacao();
			for (int i = 0; i < 4; i++)
			{
				if (pontos[i] < ponto)
				{
					pontos[i] = ponto;
					jogadores[i] = nome;
				}
			}
		}
		
		void GerenciadorMenu::gravar()
		{
			ofstream dat_jogadores;
			dat_jogadores.open("assets/jogadores.dat", ios::out);
			for (int i = 0; i < 4; i++)
			{
				dat_jogadores << jogadores[i] << " " << pontos[i] << endl;
			}
			dat_jogadores.close();
		}
		void GerenciadorMenu::recuperar()
		{
			ifstream dat_jogadores;
			dat_jogadores.open("assets/jogadores.dat", ios::in);
			string nome;
			unsigned int p;
			while (dat_jogadores >> nome >> p)
			{
				jogadores.push_back(nome);
				pontos.push_back(p);
			}
			dat_jogadores.close();
			int i;
			try
			{
				for (i = 0; i < 4; i++)
				{
					int a = pontos.at(i);
					string b = jogadores.at(i);
				}
			}
			catch (const std::exception& e)
			{
				cout << "Erro de leitura do placar: " << e.what();
				pontos.push_back(0);
				jogadores.push_back("jogador");
			}
		}

	}
}