// warnings
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <string.h> // stings
#include <time.h> // random

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
	card hand[ROUNDS]; // card struct
	int score;
}player; // struct - player

// function prototypes
void initializeDeck(card* deck);
void shuffleCards(card* deck);
void dealCards(player* players, card* pack, int numPlayers);
void playRound(player* players, int numPlayers, int round);
void shufflePlayers(player* players, int numPlayers);
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

	// greetings
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
			printf("1. Start New Game\nExit the program\n");
			scanf("%d", &choice);

			if (choice == 2)
			{
				printf("Exiting the game");
				exit(0); // exiiting the game
			}// if

			// or else start a new game
			else 
				choice = 1; // else 
		} // if (!loadGame)

		else
			printf("Previous games loaded successfully");
	} // if (choice)

	if (choice == 1)
	{
		do
		{
			// prompting the user for input
			printf("Enter the number of players playing (2-4): ");
			scanf("%d", &numPlayers);

			// ensuring the players are between 2 and 4
			if (numPlayers < 2 || numPlayers > 4) {
				printf("There must be 2-4 players playing this game.\n");
			} // while

		} while (numPlayers < 2 || numPlayers > 4); // do-while

		// getting every players' name
		for (i = 0; i < numPlayers; i++)
		{
			printf("Enter the name for player %d: ", i + 1);
			scanf("%s", players[i].name);
			players[i].score = 0; // initilializing the player's score to 0
		} // for

		// overwriting file with the new saved game (current game that is being played)
		currentRound = 0;
		saveGame(players, numPlayers, currentRound);
	} // if	

	// calling the methods
	initializeDeck(pack);
	shuffleCards(pack);
	dealCards(players, pack, numPlayers);

	// looping the game
	while (currentRound < ROUNDS) // 13 rounds
	{
		printf("\n----Round %d ---\n", currentRound);

		// calling methods
		shufflePlayers(players, numPlayers);
		playRound(players, numPlayers, currentRound);

		currentRound++; // incrementing the currentRound variable
		
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
	// creating arrays
	char* suits[] = { "Spades", "Diamonds", "Clubs", "Hearts" };
	char* values[] = { "2", "3", "4", "5", "6" ,"7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

	int indexDeck = 0; // index of the deck
	for (int i = 0; i < 4; i++) // looping through suits
	{
		for (int j = 0; j < 13; j++) // looping through values
		{
			//printf("%s of %s\n", values[j], suits[i]); // printing out the cards

			strcpy(deck[indexDeck].name, values[j]); // copying
			strcat(deck[indexDeck].name, " of ");   // adding
			strcat(deck[indexDeck].name, suits[i]); // adding

			deck[indexDeck].value = j + 2; // value of the card deck
			indexDeck++; // incrementing
		} // for (j)
	} // for (i)
} // initializeDeck

void shuffleCards(card* deck)
{
	// shufflimg cards
	srand(time(NULL)); // random number generator

	for (int i = 0; i < 52; i++) 
	{
		int num = rand() % 52; //  picking a random card
		card temp = deck[i]; // swapping the current card with a random one
		deck[i] = deck[num];
		deck[num] = temp;
	} // for
} // shuffleCards

void shufflePlayers(player* players, int numPlayers) // similar to shuffleCards()
{
	// shufflimg players
	srand(time(NULL)); // random number generator

	for (int i = 0; i < numPlayers; i++)
	{
		int playerIndex = rand() % numPlayers; // picking a random player
		player temp = players[i]; // and them swapping the current player with a random one
		players[i] = players[playerIndex];
		players[playerIndex] = temp;
	} // for
} // shufflePlayers

void dealCards(player* players, card* deck, int numPlayers)
{
	// variables
	int indexCard = 0; /// first card

	for (int i = 0; i < ROUNDS; i++) 
	{
		for (int j = 0; j < numPlayers; j++)
		{
			// assigning cards to the players (in every round and to all players)
			players[j].hand[i] = deck[indexCard++]; 
		} // for (j)
	} // for (i)
} // dealCards

void playRound(player* players, int numPlayers, int round)
{
	// variables
	int playedCards[PLAYERS]; // cards which have been played
	int maxValue = 0;
	int indexWinner = 0; // player who played hightest card
	int pickCard;

	for (int i = 0; i < numPlayers; i++)
	{
		printf("%s, these are our cards\n\n", players[i].name);
		playedCards[i] = players[i].hand[round].value; // geting the value 

		for (int j = 0; j < ROUNDS; j++)
		{
			// giving an option of 13 cards for the player to chose from
			printf("%d: %s || ", j + 1, players[i].hand[j].name);
		} // for (j)

		printf("\n\n"); // skipping a line

		printf("Pick your card: ");
		scanf("%d", &pickCard);

		pickCard--; // decrement

		// if the card chosen is less than 0 or greater than 13
		if (pickCard <= 0 || pickCard > ROUNDS) 
		{
			printf("Invalid choice. Please chose a card between 1 and %d\n", ROUNDS);
		} // if

		// displaying the card to the player that they chose
		playedCards[i] = players[i].hand[pickCard].value; 
		printf("\n%s = %s\n", players[i].name, players[i].hand[pickCard].name);

		printf("\n");

		// Checking if there is a winner 
		if (playedCards[i] > maxValue)
		{
			maxValue = playedCards[i];
			indexWinner = i; // updating the winner of this round
		} // if
	} // for (i) 

	printf("Winner of this round is %s\n\n0", players[indexWinner].name); // displaying 
	players[indexWinner].score++; // incrementing the winner's score

	int choice;
	do
	{
		choice = menu(); // calling the ethod as the choice is prompted in the said method

		switch (choice)
		{
			case 1:
				printf("Continuing to the next round.\n");
				break;

			case 2:
				saveGame(players, numPlayers, round + 1);
				printf("Game Saved.\n");
				return;

			case 3:
				if (loadGame(players, &numPlayers, &round))
					printf("Previous Game Loaded\n");

				else
					printf("No previous Game to load\n");
				break;

			case 4:
				printf("Exiting the game without saving.\n");
				exit(0); // exiting the program

			default:
				printf("Invalid choice\n");
		} // switch
	} while (choice != 1);

} // playRound 

// finding the winner of the game similar to finding nner of the round
int findWinner(player* players, int numPlayers)
{
	// variables
	int maxScore = 0;
	int indexWinner = 0;

	for (int i = 0; i < numPlayers; i++)
	{
		if (players[i].score > maxScore)
		{
			maxScore = players[i].score; 
			indexWinner = i; // updating the winner
		} // if 
	} // for (i)

	return indexWinner; // returning the winner

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
	// vraiables
	int choice;

	// creating an options menu for the user/players to choose from (repeated after every round)
	printf("Choose an option:\n");
	printf("1. Continue\n");
	printf("2. Save Game\n");
	printf("3. Load Game\n");
	printf("4. Exit\n");
	scanf("%d", &choice);
	return choice;
} // menu
