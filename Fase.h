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
			ListaEntidades entidades_estaticas;
			ListaEntidades entidades_moveis;
			GerenciadorColisoes gc;
			GerenciadorEventos* ge;

		public:
			Fase(GerenciadorEventos* ge);
			~Fase();
			void inserir_jogador(Jogador* j);
			virtual void inicializar_entidades(GerenciadorGrafico& gg);
			virtual void executar(float t, GerenciadorGrafico& gg);
			void gerenciar_colisoes();
		};

	}
}

