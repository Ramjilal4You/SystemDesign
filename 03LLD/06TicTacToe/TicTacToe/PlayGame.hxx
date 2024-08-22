/*	TicTacToe Game for 2 player
*	
**	Requirements
*	1. Number for Players -> 2
*	2. Board Size	-> N*N
*	3. Win Condtion -> Row straight, Column Straight, diagnal
*	4. Draw condition -> Board full
*	5. print board at each step
*
**	Actors
*	1. Player
*	2. Board
* 
* 
*/
#pragma once

#include "Player.hxx"
#include "GameBoard.hxx"

class PlayGame {
public:
	static void play2PlayerGame();

	static void play3PlayerGame();
	
};