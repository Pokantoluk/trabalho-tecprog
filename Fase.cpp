#include "Fase.h"

namespace Game
{
	namespace Fases
	{
		Fase::Fase(GerenciadorEventos* ge):
			gc(&entidades_moveis, &entidades_estaticas),
			ge(ge)
		{
			entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(300.0f, 700.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
			entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(600.0f, 650.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
			entidades_moveis.inserir(new Entidades::Inimigo(Vector2F(1000.0f, 650.0f), Vector2F(0.0f, 0.0f), "assets/goomba.png"));
		}

		Fase::~Fase()
		{
			entidades_moveis.destruir();
			entidades_estaticas.destruir();
		}

		void Fase::inserir_jogador(Entidades::Jogador* j)
		{
			entidades_moveis.inserir(j);
		}

		void Fase::inicializar_entidades(GerenciadorGrafico& gg)
		{
			entidades_moveis.inicializar_entidades(gg);
			entidades_estaticas.inicializar_entidades(gg);
			ge->set_janela(gg.get_janela());
		}

		void Fase::executar(float t, GerenciadorGrafico& gg)
		{
			entidades_moveis.percorrer_executar(t, gg);
			gerenciar_colisoes();
		}

		void Fase::gerenciar_colisoes()
		{
			gc.verificar_colisoes();
		}

	}
}
