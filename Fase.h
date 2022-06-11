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
			
			sf::Music music;
      
			static bool pausado;


		public:
			Fase();
			~Fase();

			virtual void carregar_fundo() const;
			void randomizar_inimigos();
			void inserir_jogador(Entidades::Personagens::Jogador* j);
			virtual void inicializar_entidades();
			void reiniciar_entidades(Vector2F pos_jogador);
			void executar(float t);
			void gerenciar_colisoes();
			void musica(); 

			static void set_pausa(bool pausa) { pausado = pausa; }
			bool get_pausa() { return pausado; }
			
		};

	}
}

