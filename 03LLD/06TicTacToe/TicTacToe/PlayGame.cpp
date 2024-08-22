#include "PlayGame.hxx"
#include "Player.hxx"
#include "GameBoard.hxx"

#include <string>
#include <iostream>
using namespace std;

void PlayGame::play2PlayerGame()
{
	string playerName;
	cout << "Please enter player 1 name : ";
	cin >> playerName;
	Player* p1 = new Player(playerName, 1, '*');

	cout << "Please enter player 2 name : ";
	cin >> playerName;
	Player* p2 = new Player(playerName, 1, '#');

	cout << "Player 1 Info : Name " + p1->getPlayerName() + " Id : " << p1->getPlayerId() 
		<< " Symbol : " << p1->getPlayerSymbol() << endl;

	cout << "Player 2 Info : Name " + p2->getPlayerName() + " Id : " << p2->getPlayerId() 
		<< " Symbol : " << p2->getPlayerSymbol() << endl;

	cout << "Starting the Game(3*3)\n";
	GameBoard board(3, { p1,p2 });

	board.startGame();
}


void PlayGame::play3PlayerGame()
{
	string playerName;
	cout << "Please enter player 1 name : ";
	cin >> playerName;
	Player* p1 = new Player(playerName, 1, '*');

	cout << "Please enter player 2 name : ";
	cin >> playerName;
	Player* p2 = new Player(playerName, 1, '#');

	cout << "Please enter player 3 name : ";
	cin >> playerName;
	Player* p3 = new Player(playerName, 1, '$');

	cout << "Player 1 Info : Name " + p1->getPlayerName() + " Id : " << p1->getPlayerId()
		<< " Symbol : " << p1->getPlayerSymbol() << endl;

	cout << "Player 2 Info : Name " + p2->getPlayerName() + " Id : " << p2->getPlayerId()
		<< " Symbol : " << p2->getPlayerSymbol() << endl;

	cout << "Player 3 Info : Name " + p3->getPlayerName() + " Id : " << p3->getPlayerId()
		<< " Symbol : " << p3->getPlayerSymbol() << endl;

	cout << "Starting the Game(5*5)\n";
	GameBoard board(5, { p1,p2, p3});

	board.startGame();
}
