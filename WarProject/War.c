// warnings
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <ctype.h>

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
	card game[ROUNDS];
	int score;
}player; // struct - player


// function prototypes
void initializePLayer(player* players, int numPlayers);
void shuffleCards(int* deck, int size);
void dealCards(player* players, int numPlayers);
void playRound(player* players, int numPlayers, int round);
int winner(int* playedCards, int numPlayers);
void saveGame(player* players, int numPlayers, int currentRound);
int loadGame(player* players, int* numPlayers, int* currentRound);
void displayGame(player* players, int numPlayers, int currentRound);
int menu();

void main()
{
	// variables
	player players;
	card cards;
	int i;
	int numPlayers;
	int choice;
	int currentRound = 0;

	printf("Welcome to the Card Game 'War'\n");

	do 
	{
		printf("Enter the number of players playing (2-4): ");
		scanf("%d", &numPlayers);

		if (numPlayers < 2 || numPlayers > 4) {
			printf("There must be 2-4 players playing this game.\n");
		} // while

	} while (numPlayers < 2 || numPlayers > 4); // do-while

	for (i = 0; i < numPlayers; i++)
	{
		printf("Enter the name for player %d: ", i + 1);
		scanf("%s", &players.name);
	} // for
} // main

void initializePLayer(player* players, int numPlayers)
{

} // initializePLayer

void shuffleCards(int* deck, int size)
{

} // shuffleCards

void dealCards(player* players, int numPlayers)
{

} // dealCards

void playRound(player* players, int numPlayers, int round)
{

} // playRound

int winner(int* playedCards, int numPlayers)
{

} // winner

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