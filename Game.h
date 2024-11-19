#ifndef GAME_H
#define GAME_H

#include "Suite.h"
#include <ctime>

class Game {
	private:
		// Private section
		Suite deck[4] = {Suite("Spade"),
						 Suite("Clubs"),
						 Suite("Diamond"),
						 Suite("Heart")};
		bool seeded = false;
		int suite, card;
		int playerScore;
		int dealerScore;
		bool win = false;
	public:
	Game();
	int cardPower(); // check card value if its numeric then its same if its J-Q-K then its 10, if Player Score is less than 10 Ace = 11 else 1
	void deal(); // start the game use function draw card and pass value 2 to draw two card else draw 1 when draw check card power <- for both player and dealer
	void faceCard(); //prints A,J,Q,K for numbers 1,11,12,13
		
};

#endif

// construrcor to seed the rand.
Game::Game(){
	if(!seeded){
        srand(time(NULL));
        seeded = true;
    }
}

void Game::deal(){
	suite = rand() % 4;
	card = rand() % 13;
	std::cout << deck[suite].getSuite() << deck[suite].getCard(card);
}

int cardPower()
{
	int value;
	switch (card % 13)
	{
		case 11:
		case 12:
		case 13:
			value = 10;
			break;
		default:
			value = (card % 13);
	}
	return value;
}

void faceCard()
{
	if (card == 0
		{
			cout << " ";
		}
	else
		{
		switch (card % 13)
			{
				case 1:
					cout << "A";
					break;
				case 11:
					cout << "J";
					break;
				case 12:
					cout << "Q";
					break;
				case 13:
					cout << "K";
					break;
				default:
					cout << card % 13;
			}
		}
}
