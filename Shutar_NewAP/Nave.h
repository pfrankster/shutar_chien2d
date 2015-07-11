#ifndef NAVE_H
#define NAVE_H

#include <c2d2/ator.h>

#define VNAVE	6

//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	NAVE_PARADA = ATOR_PROG_INI, 
	NAVE_DESLOCANDO,
	NAVE_ESTABILIZANDO
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool Nave_Carrega();
// A fun��o para fazer a l�gica da atriz
bool Nave_Atualiza(Ator *a, unsigned int mapa);
void Nave_ProcessaControle(Ator *a); 

#endif
