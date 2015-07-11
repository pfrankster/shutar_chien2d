#pragma once


#define LARGURA_TELA 1024
#define ALTURA_TELA 578


class Shutar
{

public:
	Shutar();
	~Shutar();
	void Run();

	void GameLoop();
	void Setup();
	void Update(int gamestate);
	void Draw();
	void Dispose();
	void CollisionHandler();

	int GameState = 2; 	/*Estados Poss�veis  	1 - menu  		2 - Game		3 - Credito		4 - GameOver	*/


};

