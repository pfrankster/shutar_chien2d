#ifndef MINISHOOTER_H
#define MINISHOOTER_H

#include <c2d2/ator.h>

#define VELOCIDADEBOSS 0.5f


//ALGUMAS PROPRIEDADES DA NAVE



// Enumera��o dos estados da atriz do jogo
enum {
	MINISHOOTER_PARADO = ATOR_PROG_INI
};

// A fun��o que carrega o personagem atriz (pra facilitar).
//
bool MiniShooter_Carrega();
// A fun��o para fazer a l�gica da atriz
bool MiniShooter_Atualiza(Ator *a, unsigned int mapa);
// A fun��o para fazer o ator atirar
bool MiniShooter_Atira(Ator *a, unsigned int idMapa);


#endif