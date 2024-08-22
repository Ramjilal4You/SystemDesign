#include "GameBoard.hxx"

#include <iostream>
using namespace std;


GameBoard::GameBoard(int bSize, vector<Player*> playerlist)
{
	boardSize = bSize;
	int actualBoardSize = 2 * boardSize - 1;
	board = new char* [actualBoardSize];
	
	for (int row = 0;row < actualBoardSize;row++) {
		board[row] = new char[actualBoardSize];
	}

	initializeBoard();
	printBoard();
	for (auto p : playerlist) {
		nextTurn.push(p);
	}
}


void GameBoard::initializeBoard()
{
	for (int i = 0;i < 2 * boardSize - 1;i++) {
		for (int j = 0;j < 2 * boardSize - 1;j++) {
			if (i % 2 == 0 && j % 2 != 0)
				board[i][j] = '|';
			else if (i % 2 != 0 && j % 2 == 0)
				board[i][j] = '-';
			else if (i % 2 != 0 && j % 2 != 0)
				board[i][j] = '+';
			else
				board[i][j] = ' ';
		}
	}
}
/* Board Layout
	 | | |
	-+-+-+-
	 | | |
	-+-+-+-
	 | | |
*/

void GameBoard::printBoard()
{
	for (int i = 0;i < 2 * boardSize - 1;i++) {
		for (int j = 0;j < 2 * boardSize - 1;j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void GameBoard::startGame()
{
	try {
		int count = 0;
		while (1) {
			count++;
			if (count > boardSize * boardSize) {
				cout << "Match Draw\n";
				break;
			}

			Player* p = nextTurn.front();
			nextTurn.pop();
			pair<int, int> pos = getPlayerInput(p);
			int row = pos.first;
			int col = pos.second;
			board[row][col] = p->getPlayerSymbol();
			printBoard();

			if (count >= boardSize && isGameOver(p, row, col)) {
				break;
			}

			nextTurn.push(p);
		}
	}
	catch (const char* msg) {
		if (msg == "EXIT") {
			cout << "Terminating the game.\n";
		}
	}
	catch (...) {
		cout << "Some execption occurred, Terminating the game.\n";
	}
}

pair<int, int> GameBoard::getPlayerInput(Player* iPlayer)
{
	//printBoard();
	cout << "Hi Player " << iPlayer->getPlayerName() << ", Please enter a number between 1 - " << boardSize * boardSize << " : ";
	int val;
	cin >> val;
	if (val == -1) {
		cout << "Player " + iPlayer->getPlayerName() + " Exiting from game\n";
		throw "EXIT";
	}
	while (!validateUserInput(val)) {
		cout << "Wrong Position Entered "<<val<<" Player " + iPlayer->getPlayerName() + " Please Enter a number between 1 - " << boardSize * boardSize << " : ";
		cin >> val;
	}
	return getPosition(val);
}
pair<int, int> GameBoard::getPosition(int val) {
	int row = 2 * (val % boardSize == 0 ? (val / boardSize) - 1 : val / boardSize);
	int col = 2 * ((val % boardSize == 0 ? boardSize : val % boardSize) - 1);
	return make_pair(row, col);
}

bool GameBoard::validateUserInput(int val)
{
	if (val < 1 || val > boardSize * boardSize)
		return false;

	//check for position value, if already filled than do not accept it
	pair<int, int> pos = getPosition(val);
	if (board[pos.first][pos.second]!=' ')
		return false;

	return true;
}

//check after each move
bool GameBoard::isGameOver(Player* p, int row, int col)
{
	string winString = "";
	for (int i = 0;i < boardSize;i++) {
		winString += p->getPlayerSymbol();
	}

	string rowString = "";
	string colString = "";
	string diagonaStr = "";
	string revDiagonalStr = "";

	for (int i = 0;i < 2 * boardSize - 1; i += 2) {
			rowString += board[row][i];
			colString += board[i][col];

			if (row == col)
				diagonaStr += board[i][i];

			if (row + col == 2 * boardSize - 1 - 1)
				revDiagonalStr += board[2 * boardSize - 1 - i - 1][i];
	}

	if (winString == rowString || winString == colString || winString == diagonaStr || winString == revDiagonalStr) {
		cout << "Player " << p->getPlayerName() << " won the match\n";
		return true;
	}

	return false;
}


