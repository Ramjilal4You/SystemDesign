#pragma once

#include <vector>
#include <queue>
using namespace std;

#include "Player.hxx"

class GameBoard {
private:
	int boardSize;	//eg. N*N
	char** board;
	queue<Player*> nextTurn;

	void initializeBoard();
	void printBoard();

	pair<int, int> getPlayerInput(Player* iPlayer);	//to take player input when his turn comes
	bool validateUserInput(int val);
	pair<int, int> getPosition(int val);

	bool isGameOver(Player* p, int row, int col);


public:
	GameBoard(int bSize, vector<Player*> playerlist);

	void startGame();


	
};