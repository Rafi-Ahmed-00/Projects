#include "Game.h"
#include <iostream>
#include <ctime>
#include <string>

// construrcor to seed the rand.
Game::Game(){
	if(!seeded){
        srand(time(NULL));
        seeded = true;
    }
    getRules();
    deal(2, playerScore);
    deal(2, dealerScore);
}

void Game::deal(int num,int& score){
	if(seeded){
		while(num > 0){
		suite = rand() % 4;
		card = rand() % 13;
		score += calculateScore(deck[suite].getCard(card));
		num--;
		}
	}else{
		cout << "Something is wrong contact administrator -- seeder failed";
	}
}



void Game::playerDeal(){

	if(getScore("player") > 21){
		cout << "Your score is more than 21 you lose! ";
	}else{
		deal(1, playerScore);
	}
	cout << getScore("player") << endl;
}

void Game::dealerDeal(){
	if(getScore("dealer") > 21){
		cout << "Player wins dealer score more than 21";
	}else{
		deal(1, dealerScore);
	}
	cout << getScore("dealer") - rand() % 8 << endl;
}

int Game::getScore(string who){
	if(who == "player"){
		return playerScore;
	}else if (who == "dealer"){
		return dealerScore;
	}
	return 0;
}

int Game::calculateScore(string card){
	
	if (card == "10" || card == "J" || card == "Q" || card == "K"){
		return 10;
	}
	if(card == "A" && playerScore <= 11){
		return 11;
	}else if(card == "A" && playerScore > 11){
		return 1;
	}else{
		return stoi(card);
	}
}

void Game::getRules()
{
		cout << "\t-----Rules-----\n"
			<< "\tClosest to 21 wins\n"
			<< "\tAce can either be 1 or 11\n"
		<< "\tAll face cards have a value of 10\n";
}

void Game::whoWin()
{
	if (((playerScore < 22) && (dealerScore < playerScore)) ||
		((dealerScore > 21) && (playerScore < 22)))
	{
		cout << "\n";
		winner = "player";
		cout << "You Win!" <<endl;
	}
	else if (((dealerScore < 22) && (playerScore < dealerScore)) ||
			 ((playerScore > 21) && (dealerScore < 22)))
	{
		cout << "\n";
		winner = "dealer";
		cout << "You Win!" <<endl;
	}
	else {
		winner = "";
	}
}

string Game::getWinner()
{
	return winner;
}
