#ifndef BOMBA_H
#define BOMBA_H

#include <c2d2/ator.h>

#define VBOMBA	1


//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	BOMBA_DESLOCANDO = ATOR_PROG_INI
	};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool Bomba_Carrega();
// A fun��o para fazer a l�gica da atriz
bool Bomba_Atualiza(Ator *a, unsigned int mapa);
//void Bomba_ProcessaControle(Ator *a);

#endif
