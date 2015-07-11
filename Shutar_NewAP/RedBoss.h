#ifndef REDBOSS_H
#define REDBOSS_H

#include <c2d2/ator.h>

#define VELOCIDADEBOSS 0.5f


//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	REDBOSS_PARADO = ATOR_PROG_INI, REDBOSS_DESLOCANDO
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool RedBoss_Carrega();
// A fun��o para fazer a l�gica da atriz
bool RedBoss_Atualiza(Ator *a, unsigned int mapa);


#endif
