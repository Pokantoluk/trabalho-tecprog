#include "Fase_2.h"

namespace Jogo {
	namespace Fases {

		Fase_2::Fase_2() :
			Fase(),
			fundo_fase_2("assets/fundo_2_atual.png")
		{

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

		void Fase_2::carregar_fundo() const
		{
			Gerenciadores::GerenciadorGrafico::get_gerenciador()->set_textura_fundo(fundo_fase_2);
		}
	}
}
