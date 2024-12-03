// warnings
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h>
#include <time.h>

// constants
#define PLAYERS 4
#define ROUNDS 13

// creating a struct
typedef struct
{
	char name[100];
	int value;
}card; // struct - card

typedef struct
{
	char name[100];
	card hamd[ROUNDS]; // calling the card struct
	int score;
}player; // struct - player

// function prototypes
void initializeDeck(card* deck);
void shuffleCards(card* deck);
void dealCards(player* players, card* pack, int numPlayers);
void playRound(player* players, int numPlayers, int round);
int findWinner(int* playedCards, int numPlayers);
void saveGame(player* players, int numPlayers, int currentRound);
int loadGame(player* players, int* numPlayers, int* currentRound);
void displayGame(player* players, int numPlayers, int currentRound);
int menu();

void main()
{
	// variables
	player players[PLAYERS];
	card pack[52];
	int i;
	int numPlayers;
	int choice;
	int currentRound = 0;
	char startGame[20];

	printf("Welcome to the Card Game 'War'\n");

	// loading/starting  game
	printf("1. New Game\n2. Load Game\n");
	scanf("%d", &choice);

	if (choice == 2)
	{
		// trying to load the game
		if (!loadGame(players, &numPlayers, &currentRound))
		{
			printf("No saved game found!\n");

			// asking the user if they want to start a new game
			printf("Would you like to start a new game? (enter y or n)");
			scanf("%s", startGame);
			if (startGame == 'y' || startGame == 'Y')
			{
				choice = 1;
			} // if

			else //(startGame == 'n' || startGame == 'N')
			{
				choice = 0;
			} // else 
		} // if
	} // if

	if (choice == 1)
	{
		do
		{
			// prompting the user for input
			printf("Enter the number of players playing (2-4): ");
			scanf("%d", &numPlayers);

			if (numPlayers < 2 || numPlayers > 4) {
				printf("There must be 2-4 players playing this game.\n");
			} // while

		} while (numPlayers < 2 || numPlayers > 4); // do-while

		// initializing each player with a for loop
		for (i = 0; i < numPlayers; i++)
		{
			printf("Enter the name for player %d: ", i + 1);
			scanf("%s", &players[i].name);
			players[i].score = 0;
		} // for
	} // if	

	// calling the methods
	initializeDeck(pack);
	shuffleCards(pack);
	dealCards(players, pack, numPlayers);

	// looping the game
	while (currentRound < ROUNDS)
	{
		printf("\n----Round %d ---\n", currentRound);
		playRound(players, numPlayers, currentRound);
		currentRound++;

		saveGame(players, numPlayers, currentRound);
	} // while

	// winner variable calling the findWinner method
	int winner = findWinner(players, numPlayers);

	// displaying the winner
	printf("\n--- Game Over ---\n");
	printf("The winner is %s\n", players[winner].name);
} // main

void initializeDeck(card* deck)
{

} // initializeDeck

void shuffleCards(card* deck)
{

} // shuffleCards

void dealCards(player* players, card* deck, int numPlayers)
{

} // dealCards

void playRound(player* players, int numPlayers, int round)
{

} // playRound

int findWinner(int* playedCards, int numPlayers)
{

} // findWinner

void saveGame(player* players, int numPlayers, int currentRound)
{

} // saveGame

int loadGame(player* players, int* numPlayers, int* currentRound)
{

} // loadGame

void displayGame(player* players, int numPlayers, int currentRound)
{

} // displayGame

int menu()
{

} // menu