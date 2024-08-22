#pragma once

#include <string>

using namespace std;

class Player {
private:
	string playerName;
	int playerId;
	char playerSymbol;
public:
	Player(string pName, int pId, char pSymbol);
	string getPlayerName();
	int getPlayerId();
	char getPlayerSymbol();
};