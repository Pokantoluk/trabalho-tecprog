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
			sf::Clock relogio;
		public:
			Fase();
			~Fase();
			virtual void inicializar_entidades();
			virtual void executar() = 0;
			void gerenciar_colisoes();
		};

	}
}

