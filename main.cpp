/*
Name: Joey Macauley
Date: October 29, 2021
*/

#include "header.h"

int main(void)
{
	PlayerCard player1;
	PlayerCard *player1Ptr = &player1;
	ifstream infile;
	string inputFilename = "playercards.txt";
	vector<PlayerCard> scoreCards;

	bool isOpen = false;
	char decision = '\0';
	int hit = 0;

	srand(time(0));
	isOpen = openInputFile(infile, inputFilename);

	cout << "Welcome to VIRTUAL Skee-Ball, glad you are here!\nNow, let's see how much skill you really have!\n...\n"
		 << endl;
	initializePlayerScoreCard(player1Ptr);
	importPlayerScoreCards(infile, scoreCards);
	printPlayerScoreCard(player1);

	cout << "\nShall we play? Press 'y' to roll: ";
	cin >> decision;

	while (decision == 'y')
	{
		cout << "You rolled a ball!" << endl;
		determinePointsScored(hit);
		player1.setTotalScore(player1.getTotalScore() + hit);
		player1.setGamesPlayed(player1.getGamesPlayed() + 1);
		cout << "Want to keep playing? (y/n) ";
		cin >> decision;
	}
	player1.updateAverageScore();

	printPlayerScoreCard(player1);
	cout << "\nSee how your score compares to previous players: " << endl;
	printPlayerCards(scoreCards);

	infile.close();
	return 0;
}