#ifndef BATROBO_H
#define BATROBO_H

#include <c2d2/ator.h>

#define VELOCIDADEBOSS 0.5f


//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	BATROBO_PARADO = ATOR_PROG_INI, BATROBO_DESLOCANDO
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool BatRobo_Carrega();
// A fun��o para fazer a l�gica da atriz
bool BatRobo_Atualiza(Ator *a, unsigned int mapa);


#endif
