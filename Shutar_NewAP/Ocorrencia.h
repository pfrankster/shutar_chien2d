#ifndef OCORRENCIA_H
#define OCORRENCIA_H

#include <c2d2/ator.h>



//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	OCORRENCIA_PARADA = ATOR_PROG_INI
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool Ocorrencia_Carrega();
// A fun��o para fazer a l�gica da atriz
bool Ocorrencia_Atualiza(Ator *a, unsigned int mapa);
//void Tiro_ProcessaControle(Ator *a);

#endif
