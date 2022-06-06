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
			Entidades::Obstaculos::Obstaculo* o2;
			Entidades::Obstaculos::Obstaculo* o3;
			Entidades::Obstaculos::Obstaculo* o4;
			Entidades::Obstaculos::Obstaculo* o5;
			Entidades::Obstaculos::Obstaculo* o6;
			Entidades::Obstaculos::Obstaculo* o7;
			Entidades::Obstaculos::Obstaculo* o8;
			Entidades::Obstaculos::Obstaculo* o9;
			Entidades::Obstaculos::Obstaculo* o10;
			Entidades::Obstaculos::Obstaculo* o11;
			Entidades::Obstaculos::Obstaculo* o12;
			Entidades::Obstaculos::Obstaculo* o13;
			Entidades::Obstaculos::Obstaculo* o14;
			Entidades::Obstaculos::Obstaculo* fogo;
			Entidades::Obstaculos::Obstaculo* fogo2;
			Entidades::Obstaculos::Obstaculo* pedra;
			Entidades::Obstaculos::Obstaculo* pedra2;
			Entidades::Obstaculos::Obstaculo* bandeira;
      
			ListaEntidades entidades_estaticas;
			ListaEntidades entidades_moveis;
			GerenciadorColisoes gc;
      
			const char* fundo;
			sf::Music music;
      
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
			void musica(); 

			static void set_pausa(bool pausa) { pausado = pausa; }
			bool get_pausa() { return pausado; }
		};

	}
}

