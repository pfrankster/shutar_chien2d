#ifndef MINIRED_H
#define MINIRED_H

#include <c2d2/ator.h>

#define VELOCIDADEBOSS 0.5f


//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	MINIRED_PARADO = ATOR_PROG_INI, MINIRED_DESLOCANDO
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool MiniRed_Carrega();
// A fun��o para fazer a l�gica da atriz
bool MiniRed_Atualiza(Ator *a, unsigned int mapa);


#endif
