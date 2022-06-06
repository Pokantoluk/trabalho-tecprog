#pragma once
#include "Ente.h"
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "ListaEntidades.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"
#include "GerenciadorColisoes.h"

namespace Game
{
	namespace Fases
	{
		class Fase:
			public Ente
		{
		protected:
			Entidades::Obstaculos::Obstaculo* o1;
			ListaEntidades entidades_estaticas;
			ListaEntidades entidades_moveis;
			GerenciadorColisoes gc;
			const char* fundo;
			static bool pausado;

		public:
			Fase();
			~Fase();

			void carregar_fundo() const;
			void randomizar_inimigos();
			void inserir_jogador(Entidades::Jogador* j);
			virtual void inicializar_entidades();
			virtual void executar(float t);
			void gerenciar_colisoes();

			static void set_pausa(bool pausa) { pausado = pausa; }
			bool get_pausa() { return pausado; }
		};

	}
}

