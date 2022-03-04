/*
Name: Joey Macauley
Date: October 29, 2021
*/

#ifndef SKEE_BALL
#define SKEE_BALL

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

class PlayerCard
{
private:
	int playerID;
	void setPlayerID(int id); // PRIVATE setter
	string name;
	int totalScore;
	int gamesPlayed;
	double avgScore;
	void setAvgScore(double average); // PRIVATE setter
public:
	PlayerCard() : PlayerCard("", -1){};
	PlayerCard(string newName, int newID = 0); // OPTIONAL VS REQUIRED!!!!!!!!!!!!!!!!!!!
	~PlayerCard();
	int getPlayerID() const { return playerID; }	   // public getter
	void setName(string newName);					   // public setter
	string getName() const { return name; }			   // public getter
	void setTotalScore(int total);					   // public setter
	int getTotalScore() const { return totalScore; }   // public getter
	void setGamesPlayed(int games);					   // public setter
	int getGamesPlayed() const { return gamesPlayed; } // public getter
	double getAvgScore() const { return avgScore; }	   // public getter
	void generatePlayerId(void);					   // req. public class member function
	void generatePlayerId(int);						   // req. public class member function
	void updateAverageScore(void);					   // req. public class member function
};

bool openInputFile(ifstream &infile, string infileName);
void initializePlayerScoreCard(PlayerCard *player);
void printPlayerScoreCard(const PlayerCard &player);
void importPlayerScoreCards(ifstream &inputFile, vector<PlayerCard> &scoreCards);
void printPlayerCards(vector<PlayerCard> scoreCards);
void determinePointsScored(int &hit);

#endif
