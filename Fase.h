#pragma once
#include "Ente.h"
#include "Lista.h"
#include "Jogador.h"
#include "Goomba.h"
#include "Obstaculo.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"
#include "VidaUI.h"
#include "PontuacaoUI.h"
#include "NuvemMal.h"
#include "Projetil.h"


namespace Jogo
{
	namespace Fases
	{
		class Fase:
			public Ente
		{
		protected:
			Listas::ListaEntidades entidades_estaticas;
			Listas::ListaEntidades entidades_moveis;
			Gerenciadores::GerenciadorColisoes gc;
			VidaUI* vidaui;
			PontuacaoUI* pontuacaoui;
			
			sf::Music music;
      
			static bool pausado;


		public:
			Fase();
			~Fase();

			void destruir_fase();
			virtual void carregar_fundo() const;
			virtual void randomizar_inimigos();
			void inserir_jogador(Entidades::Personagens::Jogador* j);
			virtual void inicializar_entidades();
			void executar(float t);
			void gerenciar_colisoes();
			void musica(); 
		    void add_projetil(Entidades::Projetil* proj);
			static void set_pausa(bool pausa) { pausado = pausa; }
			static bool get_pausa() { return pausado; }
			
		};

	}
}

