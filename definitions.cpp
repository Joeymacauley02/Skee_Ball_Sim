/*
Name: Joey Macauley
Date: October 29, 2021
*/

#include "header.h"

/*************************************************************
 * Function: ()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description:
 * Input parameters:
 * Returns: void
 **************************************************************/
bool openInputFile(ifstream &infile, string infileName)
{
	infile.open(infileName);

	if (!infile.is_open())
	{
		return false;
	}
	else if (infile.fail())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/*************************************************************
 * Function: setPlayerID()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: private setter
 * Input parameters: int id
 * Returns: void
 **************************************************************/
void PlayerCard::setPlayerID(int id)
{
	playerID = id;
}

/*************************************************************
 * Function: setAvgScore()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: private setter
 * Input parameters: double average
 * Returns: void
 **************************************************************/
void PlayerCard::setAvgScore(double average)
{
	avgScore = average;
}

/*************************************************************
 * Function: PlayerCard()
 * Date Created: October 26, 2021
 * Date Last Modified: October 26, 2021
 * Description: Defintion of overloaded constructor
 * Input parameters: string newName, int newID
 * Returns: overloaded structure
 **************************************************************/
PlayerCard::PlayerCard(string newName, int newID)
{
	playerID = newID;
	name = newName;
	totalScore = 0;
	gamesPlayed = 0;
	avgScore = 20;
}

/*************************************************************
 * Function: ~PlayerCard()
 * Date Created: October 26, 2021
 * Date Last Modified: October 26, 2021
 * Description: deconstructor of PlayerCard()
 * Input parameters: void
 * Returns: void
 **************************************************************/
PlayerCard::~PlayerCard()
{
}

/*************************************************************
 * Function: setName()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: public setter
 * Input parameters: string newName
 * Returns: void
 **************************************************************/
void PlayerCard::setName(string newName)
{
	name = newName;
}

/*************************************************************
 * Function: setTotalScore()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: public setter
 * Input parameters: int total
 * Returns: void
 **************************************************************/
void PlayerCard::setTotalScore(int total)
{
	totalScore = total;
}

/*************************************************************
 * Function: setGamesPlayed()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: public setter
 * Input parameters: int games
 * Returns: void
 **************************************************************/
void PlayerCard::setGamesPlayed(int games)
{
	gamesPlayed = games;
}

/*************************************************************
 * Function: generatePlayerId()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: randomly generate player id for user
 * Input parameters: void
 * Returns: void
 **************************************************************/
void PlayerCard::generatePlayerId(void)
{
	int randPlayerID = rand() % 9000 + 1000;
	setPlayerID(randPlayerID);
}

/*************************************************************
 * Function: generatePlayerId()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: set player id for those read in from input file
 * Input parameters: int id
 * Returns: void
 **************************************************************/
void PlayerCard::generatePlayerId(int id)
{
	setPlayerID(id);
}

/*************************************************************
 * Function: updateAverageScore()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: updates average score for user
 * Input parameters:
 * Returns: void
 **************************************************************/
void PlayerCard::updateAverageScore(void)
{
	if (gamesPlayed == 0)
		setAvgScore(0.0);
	else
		setAvgScore(static_cast<double>(totalScore) / gamesPlayed);
}

/*************************************************************
 * Function: initializePlayerScoreCard()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: Initialize user score card
 * Input parameters: PlayerCard* player
 * Returns: void
 **************************************************************/
void initializePlayerScoreCard(PlayerCard *player)
{
	string name = "";
	cout << "Please enter a player name (first and last seperated by a space): ";
	getline(cin, name);
	(*player).setName(name);
	(*player).generatePlayerId();
	(*player).setGamesPlayed(0);
	(*player).setTotalScore(0);
	(*player).updateAverageScore();
}

/*************************************************************
 * Function: printPlayerScoreCard()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: Output user score card to the consol
 * Input parameters: const PlayerCard& player
 * Returns: void
 **************************************************************/
void printPlayerScoreCard(const PlayerCard &player)
{
	if (player.getGamesPlayed() == 0)
	{
		cout << "\nYour score card: " << endl;
	}
	else
	{
		cout << "\nHere's your final score card!" << endl;
	}

	cout << "-----------------------|PID: " << player.getPlayerID() << "|" << endl;
	cout << player.getName() << "'s Score Card" << endl;
	cout << "---------------------------------" << endl;
	cout << "Games Played: " << player.getGamesPlayed() << endl;
	cout << "Running Score: " << player.getTotalScore() << endl;
	if (player.getAvgScore() == 0)
	{
		cout << "Average Score: [No games played]" << endl;
	}
	else
	{
		cout << "Average Score: " << fixed << setprecision(2) << player.getAvgScore() << endl;
	}
	cout << "---------------------------------" << endl;
}

/*************************************************************
 * Function: importPlayerScoreCards()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: Read in data from input file
 * Input parameters: ifstream& inputFile, vector<PlayerCard>& scoreCards
 * Returns: void
 **************************************************************/
void importPlayerScoreCards(ifstream &inputFile, vector<PlayerCard> &scoreCards)
{
	PlayerCard temp;
	int playerID = 0;
	string firstName = "";
	string lastName = "";
	string fullName = "";
	int totalScore = 0;
	int gamesPlayed = 0;
	double avgScore = 0.0;

	while (!inputFile.eof())
	{
		if (inputFile.good())
		{
			inputFile >> playerID;
			if (!inputFile.fail())
			{
				temp.generatePlayerId(playerID);
				inputFile >> firstName;
				inputFile >> lastName;
				fullName = firstName + " " + lastName;
				temp.setName(fullName);
				inputFile >> totalScore;
				temp.setTotalScore(totalScore);
				inputFile >> gamesPlayed;
				temp.setGamesPlayed(gamesPlayed);
				inputFile >> avgScore;
				temp.updateAverageScore();
				scoreCards.push_back(temp);
			}
		}
	}
}

/*************************************************************
 * Function: printPlayerCards()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: Output data for previous score cards
 * Input parameters: vector<PlayerCard> scoreCards
 * Returns: void
 **************************************************************/
void printPlayerCards(vector<PlayerCard> scoreCards)
{
	for (int i = 0; i < scoreCards.size(); i++)
	{
		cout << "-----------------------|PID: " << scoreCards.at(i).getPlayerID() << "|" << endl;
		cout << scoreCards.at(i).getName() << "'s Score Card" << endl;
		cout << "---------------------------------" << endl;
		cout << "Games Played: " << scoreCards.at(i).getGamesPlayed() << endl;
		cout << "Running Score: " << scoreCards.at(i).getTotalScore() << endl;
		if (scoreCards.at(i).getAvgScore() == 0)
		{
			cout << "No games played" << endl;
		}
		else
		{
			cout << "Average Score: " << fixed << setprecision(2) << scoreCards.at(i).getAvgScore() << endl;
		}
		cout << "---------------------------------" << endl;
	}
}

/*************************************************************
 * Function: determinePointsScored()
 * Date Created: October 25, 2021
 * Date Last Modified: October 25, 2021
 * Description: Determine points per game
 * Input parameters: int& hit
 * Returns: void
 **************************************************************/
void determinePointsScored(int &hit)
{
	hit = rand() % 11;
	if (hit > 6)
	{
		cout << "AWESOME! You scored " << hit << " points. Let's move on!" << endl;
	}
	else if (hit > 0)
	{
		cout << "Ehh, not bad. You score " << hit << " points. Let's give it another try!" << endl;
	}
	else
	{
		cout << "Sheesh... you missed and scored " << hit << " points. Try again?" << endl;
	}
}
