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
	int cards[ROUNDS];
	int score;
}player;

// function prototypes
void initializePLayer(player* players, int numPPlayers);
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
	
} // main

void initializePLayer(player* players, int numPPlayers)
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