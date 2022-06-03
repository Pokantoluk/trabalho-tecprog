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
			Entidades::Inimigo* e1;
			Entidades::Inimigo* e2;
			Entidades::Inimigo* e3;

		public:
			Fase(GerenciadorEventos* ge);
			~Fase();
			void inserir_jogador(Entidades::Jogador* j);
			virtual void inicializar_entidades(GerenciadorGrafico& gg);
			virtual void executar(float t, GerenciadorGrafico& gg);
			void gerenciar_colisoes();

			ListaEntidades* get_lista_estatica();
			ListaEntidades* get_lista_movel();
		};

	}
}

