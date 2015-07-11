#include <c2d2/chien2d2.h>
#include <c2d2\chien2d2mapa.h>
#include "AtorManager.h"
#include "Ocorrencia.h"
#include "Shutar.h"
#include <math.h>
//Animacao
// Vetor com as anima��es da nave (3 no total)
Animacao animaOcorrencia[] = {
	// Ordem: n�mero de quadros, tempo entre os quadros, vetor com a seq��ncia de quadros

	{ 5, 12, { 0,1,2,3,4 } }

};



// A fun��o que carrega o Player
//
bool Ocorrencia_Carrega()
{
	return ATOR_CarregaAtorEstatico(OCORRENCIA, "bo_sheet.png", 96, 96, 36, 36, 12, 12, animaOcorrencia, true, 0, 0, &Ocorrencia_Atualiza);
}

// A fun��o para fazer a l�gica do Tiro
//
// Data: 06/06/2015
// �ltima atualiza��o: 04/07/2015


bool Ocorrencia_Atualiza(Ator *a, unsigned int idMapa)
{
	Evento ev;
	switch (a->estado.estado)
	{
		case ATOR_NASCENDO:
			ATOR_TrocaEstado(a, OCORRENCIA_PARADA, false);
			break;

		case OCORRENCIA_PARADA:
		{
			if (a->estado.subestado == ESTADO_INICIO)
			{

				ATOR_TrocaAnimacao(a, 0);
				// Troca o sub-estado
				a->estado.subestado = ESTADO_RODANDO;
				// O tiro existe por 1 segundo

			}

			// Enquanto houverem eventos
			while (ATOR_ProximoEvento(a, &ev))
			{
				switch (ev.tipoEvento)
				{
				
					case EVT_COLIDIU_PERSONAGEM:
						ATOR_TrocaEstado(a, ATOR_ENCERRADO, false);
						//tiro = 0;
						break;
				}
			}

		break;
		}
	}
	return true;
}


