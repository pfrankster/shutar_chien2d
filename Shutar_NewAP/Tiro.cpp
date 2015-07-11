#include <c2d2/chien2d2.h>
#include <c2d2\chien2d2mapa.h>
#include "AtorManager.h"
#include "Tiro.h"
#include "Shutar.h"
#include <math.h>
//Animacao
// Vetor com as anima��es da nave (3 no total)
Animacao animaTiro[] = {
	// Ordem: n�mero de quadros, tempo entre os quadros, vetor com a seq��ncia de quadros

	{ 1, 4, { 0 } },
	{ 1, 4, { 2 } },
	{ 1, 4, { 3 } },
	{ 1, 4, { 4 } }

};



// A fun��o que carrega o Player
//
bool Tiro_Carrega()
{
	//return ATOR_CarregaAtorEstatico(TIRO_NAVE, "shoots.png", 96, 96, 21, 12, 6, 22, animaTiro, true, 0, 0, &Tiro_Atualiza);
	return ATOR_CarregaAtorEstatico(TIRO_NAVE, "singleshoot.png", 22, 6, 0, 0, 22, 6, animaTiro, true, 0, 0, &Tiro_Atualiza);

}

// A fun��o para fazer a l�gica do Tiro
//
// Data: 06/06/2015
// �ltima atualiza��o: 04/07/2015


bool Tiro_Atualiza(Ator *a, unsigned int idMapa)
{
	Evento ev;
	switch (a->estado.estado)
	{
	case ATOR_NASCENDO:
		// Muda para o estado adequado
		ATOR_TrocaEstado(a, TIRO_DESLOCANDO, false);
		// Usa valores auxiliares para guardar a posi��o inicial do tiro


		a->aux_real[0] = a->x;
		a->aux_real[1] = a->y;

		// D� a velocidade e muda a dire��o em que est� olhando
		a->velocidade = VTIRO;
		
		a->olhandoPara = a->direcao;
		break;


	case TIRO_DESLOCANDO:
	{
		if (a->estado.subestado == ESTADO_INICIO)
		{
			ATOR_TrocaAnimacao(a, 0);

			// Troca o sub-estado
			a->estado.subestado = ESTADO_RODANDO;
			// O tiro existe por 1 segundo
			a->temporizadores[0] = 20;
		}
		// Enquanto houverem eventos
		while (ATOR_ProximoEvento(a, &ev))
		{
			switch (ev.tipoEvento)
			{


			case EVT_TEMPO:
				if (ev.subtipo == 0)
				{
					// Se passou a dist�ncia, encerra o ator
					ATOR_TrocaEstado(a, ATOR_ENCERRADO, false);
					return false;
				}
				break;

			case EVT_PERDE_FOCO_TELA:
				if (a->x < 0 || a->x > LARGURA_TELA || a->y < 0 || a->y > ALTURA_TELA)
				{// Se passou a dist�ncia, encerra o ator
					ATOR_TrocaEstado(a, ATOR_ENCERRADO, false);
					//tiro = 0;
					return false;
				}
				break;

			case EVT_COLIDIU_PERSONAGEM:
				ATOR_TrocaEstado(a, ATOR_ENCERRADO, false);
				//tiro = 0;
				break;



			}
		}

		break;
	}

	case ATOR_ENCERRADO:
		ev.tipoEvento = EVT_PRESSIONOU_BAIXO;
		ATOR_EnviaEventoJogo(&ev);
		return false;
	}
	return true;
}


