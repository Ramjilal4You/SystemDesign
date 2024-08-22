#include "Player.hxx"

Player::Player(string pName, int pId, char pSymbol)
{
	playerName = pName;
	playerId = pId;
	playerSymbol = pSymbol;
}

string Player::getPlayerName()
{
	return playerName;
}

int Player::getPlayerId()
{
	return playerId;
}

char Player::getPlayerSymbol()
{
	return playerSymbol;
}