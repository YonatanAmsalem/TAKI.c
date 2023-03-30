#include "Game.h"
#include "SpeicalCards.h"
void main()
{
	srand(time(NULL));
	DataPl data;
	DataPl* datap = &data;
	player* arrForPlayers = NULL;
	card upper;
	card* upperp = &upper;
	statisticParamaeter statsOfGame[NUMBER_OF_CARDS];
	printMenu();
	datap->numOfPlayers = numOfPlayersget();
	arrForPlayers = (player*)malloc((datap->numOfPlayers) * sizeof(player));
	if (arrForPlayers == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	inputData(arrForPlayers, datap->numOfPlayers);
	initialValuesArr(statsOfGame, NUMBER_OF_CARDS);
	initializeCardsToPlayers(arrForPlayers, datap, statsOfGame);
	createUpperCard(upperp, statsOfGame);
	gameTurn(arrForPlayers, datap, upperp, statsOfGame);
	printStatistics(statsOfGame, NUMBER_OF_CARDS);
	free(arrForPlayers);
}