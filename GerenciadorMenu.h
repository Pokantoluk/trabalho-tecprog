#pragma once
#include "stdafx.h"
#include "Mario.h"
#include "Luigi.h"
using namespace std;

namespace Jogo
{
	class MenuPrincipal;
	class MenuPersonagens;
	class MenuSeletor;
	class MenuPlacar;
	class MenuGameover;
	class MenuPausa;
	namespace Gerenciadores
	{
		class GerenciadorMenu
		{
		private:
			unsigned int num_menu;
			unsigned int fase;
			unsigned int num_jogadores;
			
			MenuPrincipal* mPr;
			MenuPersonagens* mPe;
			MenuSeletor* mSe;
			MenuPlacar* mPl;
			MenuGameover* mGo;
			MenuPausa* mPa;
			vector<int> pontos;
			vector<string> jogadores;


		public:
			GerenciadorMenu();
			~GerenciadorMenu();


			void executar();
			void set_pausa();
			bool set_gameover();

			void tratar_pontos();
			void gravar();
			void recuperar();

			void set_menu(unsigned int n) { num_menu = n; }
			void set_fase(unsigned int f) { fase = f; }
			void set_jog(unsigned int j) { num_jogadores = j; }
			

			const unsigned int get_fase() const { return fase; }
			const unsigned int get_num_jogadores() const { return num_jogadores; }
			const vector<int> get_pontos() const { return pontos; }
			const vector<string> get_jogadores() const { return jogadores; }
		};

	}
}

