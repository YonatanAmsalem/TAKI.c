#include "Game.h"
#include "SpeicalCards.h"

void printMenu()
{
	printf("************* Welcome to TAKI game !! ****************\n");
}
void gameTurn(player arrForPlayers[], DataPl* dataP, card* upperp, statisticParamaeter* statsOfGame)
/*the function is the gameTurn and check the process of the game by each turn*/
{
	int i;
	dataP->winner = ZERO; //initial values to winner
	dataP->index = ZERO, dataP->direct = ONE; // initial values to the index player,direction
	while (dataP->winner == ZERO) // no winner
	{
		printByTurn(arrForPlayers[dataP->index], dataP, *upperp); // print table
		startGame(arrForPlayers, upperp, dataP, &arrForPlayers[dataP->index].numberOfCards, statsOfGame); // start game
		checkStatusOfTurn(dataP); // check status of the turn
	}
	for (i = 0; i < dataP->numOfPlayers; i++) // effecienty of o(datap.numofplayers))
	{
		free(arrForPlayers[i].card);
	}
}
int numOfPlayersget()
{
	/*the function get the number of players*/
	int nofPlayer;
	printf("Please Enter the number of the players:\n");
	scanf("%d", &nofPlayer);
	while (nofPlayer < ONE)
	{
		printf("Please Enter the number of the players:\n");
		scanf("%d", &nofPlayer);
	}
	return nofPlayer;
}
void inputData(player player[], int size)
/*the function is to input first name of each player*/
{
	int i;
	char names[SIZE];

	for (i = 0; i < size; i++) // effecienty of o(size)
	{
		printf("Please enter the first name of player #%d:\n", i + 1);
		scanf("%s", names);
		strcpy((player[i].name), names);
	}
}
void initializeCardsToPlayers(player player[], DataPl* datap, statisticParamaeter* statsOfGame)
/*the function is to initial cards to each player and making initial values to log and physical size*/
{
	int i, j;
	for (i = 0; i < datap->numOfPlayers; i++)
	{
		player[i].PhySize = INITIAL_NUM_CARDS;
		player[i].numberOfCards = INITIAL_NUM_CARDS;
		player[i].card = (card*)malloc(player[i].PhySize * sizeof(card));
		if (player[i].card == NULL)
		{
			exit(1);
		}
		for (j = 0; j < player[i].numberOfCards; j++)
		{
			player[i].card[j] = createcard(statsOfGame);
		}
	}
}
void rndType(int rnd, card* currentCard, statisticParamaeter* statsOfGame)
/*the function is to get a values to type of cards and counting the appears of each card in the game*/
{
	switch (rnd)
	{
	case ONE:
		strcpy(currentCard->type, "1");
		statsOfGame[ZERO].CountPerCardss++;
		break;
	case TWO:
		strcpy(currentCard->type, "2");
		statsOfGame[ONE].CountPerCardss++;
		break;
	case THREE:
		strcpy(currentCard->type, "3");
		statsOfGame[TWO].CountPerCardss++;
		break;
	case FOUR:
		strcpy(currentCard->type, "4");
		statsOfGame[THREE].CountPerCardss++;
		break;
	case FIVE:
		strcpy(currentCard->type, "5");
		statsOfGame[FOUR].CountPerCardss++;
		break;
	case SIX:
		strcpy(currentCard->type, "6");
		statsOfGame[FIVE].CountPerCardss++;
		break;
	case SEVEN:
		strcpy(currentCard->type, "7");
		statsOfGame[SIX].CountPerCardss++;
		break;
	case EIGHT:
		strcpy(currentCard->type, "8");
		statsOfGame[SEVEN].CountPerCardss++;
		break;
	case NINE:
		strcpy(currentCard->type, "9");
		statsOfGame[EIGHT].CountPerCardss++;
		break;
	case STOP:
		strcpy(currentCard->type, "STOP");
		statsOfGame[NINE].CountPerCardss++;
		break;
	case CHANGE_DIR:
		strcpy(currentCard->type, "<->");
		statsOfGame[10].CountPerCardss++;
		break;
	case TAKI:
		strcpy(currentCard->type, "TAKI");
		statsOfGame[11].CountPerCardss++;
		break;
	case CHANGE_COLOR:
		strcpy(currentCard->type, "COLOR");
		statsOfGame[12].CountPerCardss++;
		break;
	case PLUS:
		strcpy(currentCard->type, "PLUS");
		statsOfGame[13].CountPerCardss++;
		break;
	}
}
void rndColor(int rndColor, card* currentCard)
/*random colors values to cards */
{
	switch (rndColor)
	{
	case ONE:
		strcpy(currentCard->color, "Y");
		break;
	case TWO:
		strcpy(currentCard->color, "R");
		break;
	case THREE:
		strcpy(currentCard->color, "B");
		break;
	case FOUR:
		strcpy(currentCard->color, "G");
		break;
	}
}
void createUpperCard(card* upperp, statisticParamaeter* statsOfGame)
/*the function is to create a upper card without speical card*/
{
	int random;
	random = ONE + rand() % NINE;
	rndType(random, upperp, statsOfGame);
	random = ONE + rand() % FOUR_COLOR;
	rndColor(random, upperp);
}
void printcard(card toPrint)
/*the function is to print card by specific values*/
{
	printf("\n*********\n");
	printf("*       *\n");
	if (strcmp("9", toPrint.type) >= ZERO && strcmp("1", toPrint.type) <= ZERO)
	{
		printf("*   %s   *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	else if (strcmp(toPrint.type, "STOP") == ZERO)
	{
		printf("*  %s *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	else if (strcmp(toPrint.type, "<->") == ZERO)
	{
		printf("*  %s  *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	else if (strcmp(toPrint.type, "PLUS") == ZERO)
	{
		printf("*  %s *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	else if (strcmp(toPrint.type, "COLOR") == ZERO)
	{
		printf("* %s *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	else if (strcmp(toPrint.type, "TAKI") == ZERO)
	{
		printf("*  %s *\n", toPrint.type);
		printf("*   %s   *\n", toPrint.color);
	}
	printf("*       *\n");
	printf("*********\n");
}
void printByTurn(player player, DataPl* datap, card upper)
/*the function is print by turn and is print the deck by each player*/
{
	int i;
	printf("Upper card is:\n");
	printcard(upper);
	printf("%s's turn: \n", player.name);
	for (i = ZERO; i < player.numberOfCards; i++)
	{
		printf("card:%d\n", i + 1);
		printcard(player.card[i]);
	}
}
void startGame(player player[], card* upper, DataPl* dataP, int* amountCard, statisticParamaeter* statsOfGame)
/*the start of the game*/
{
	checkUserSelect(player, upper, dataP, amountCard, statsOfGame);

}
void checkStatusOfTurn(DataPl* dataP)
/*the function is to check status of turn*/
{
	if (dataP->winner == ZERO) // check winner
	{
		dataP->index = dataP->index + dataP->direct; // move to the next player
		if (dataP->index < ZERO) // check if the index is less from zero
		{
			dataP->index = dataP->numOfPlayers + dataP->index; // back to the required turn
		}
		else if (dataP->index >= dataP->numOfPlayers) // check if the index >= num of players
		{
			dataP->index = dataP->index - dataP->numOfPlayers; // back to the required turn 
		}
	}
}
void checkValidSelect(player player[], card* upper, DataPl* dataP, card* currentCard, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function get Valid input from the user and check if 0 draw card else check the type*/
{
	switch (dataP->playerinp)
	{
	case ZERO: // take card
		createRealloc(player, upper, dataP, cardAmount);
		increaseCard(player, upper, dataP, cardAmount, statsOfGame);
		break;
	default: // draw card
		typeOfInsert(currentCard, player, upper, dataP, cardAmount, statsOfGame);
		break;
	}
}

card createcard(statisticParamaeter* statsOfGame)
/*the function is from type of card and is return new card*/
{
	card res;
	int random, compare;
	random = rand() % MAX_ELEMENTS_RAND + ONE;
	rndType(random, &res, statsOfGame);
	compare = strcmp(res.type, "COLOR");
	if (compare != ZERO)
	{
		random = ONE + rand() % FOUR_COLOR;
		rndColor(random, &res);
	}
	else
	{
		strcpy(res.color, " ");
	}
	return res;
}

void checkUserSelect(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function is to check if the user input is valid*/
{
	card* current;
	printf("Please enter %d if you want to take a card from a deck\nor %d-%d if you want to put one of your cards in the middle:\n", ZERO, ONE, player[dataP->index].numberOfCards);
	scanf("%d", &dataP->playerinp);
	current = &player[dataP->index].card[dataP->playerinp - 1];
	getCompareElement(player, upper, dataP, cardAmount, current);
	while (((checkOverLimitInput(player, dataP) || ((checkCardIsLegit(dataP, current))))) && dataP->playerinp != ZERO)
	{
		printf("Invalid choice try again\n");
		printf("Please enter %d if you want to take a card from a deck\nor %d-%d if you want to put one of your cards in the middle:\n", ZERO, ONE, player[dataP->index].numberOfCards);
		scanf("%d", &dataP->playerinp);
		current = &player[dataP->index].card[dataP->playerinp - 1];
		getCompareElement(player, upper, dataP, cardAmount, current);
	}
	checkValidSelect(player, upper, dataP, current, cardAmount, statsOfGame);
}
void typeOfInsert(card* current, player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/* the function responsible about the type of the card the user is decide to insert*/
{
	if (strcmp("9", current->type) >= 0 && strcmp("1", current->type) <= ZERO) // if is regular card
	{
		decreaseCard(player, upper, dataP, cardAmount);
	}
	else if (strcmp(current->type, "STOP") == ZERO) // STOP
	{
		decreaseCard(player, upper, dataP, cardAmount);
		insertStopCard(player, upper, dataP, cardAmount, statsOfGame);
		return;

	}
	else if (strcmp(current->type, "<->") == ZERO) //change direct
	{
		decreaseCard(player, upper, dataP, cardAmount);
		insertChangeDirectCard(player, upper, dataP, cardAmount);

	}
	else if (strcmp(current->type, "PLUS") == ZERO) // PLUS
	{
		decreaseCard(player, upper, dataP, cardAmount);
		insertPlusCard(player, upper, dataP, cardAmount, statsOfGame);
	}
	else if (strcmp(current->type, "COLOR") == ZERO)//COLOR
	{
		*upper = player[dataP->index].card[dataP->playerinp - 1];
		insertChangeColorCard(player, upper, dataP, cardAmount);
		player[dataP->index].card[dataP->playerinp - 1] = player[dataP->index].card[*cardAmount - 1];
		*cardAmount = (*cardAmount) - ONE;
	}
	else if ((strcmp(current->type, "TAKI") == ZERO))//TAKI
	{
		decreaseCard(player, upper, dataP, cardAmount);
		if (player[dataP->index].numberOfCards != ZERO)
		{
			insertTakiCard(player, upper, dataP, cardAmount, statsOfGame);
			return;
		}
	}
	checkAmountCards(player, dataP, cardAmount);//check winner
}
void insertStopCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function care about speical card STOP*/
{
	if (dataP->numOfPlayers == TWO && player[dataP->index].numberOfCards == ZERO) //if two players and is the last card of the player
	{
		increaseCard(player, upper, dataP, cardAmount, statsOfGame);
	}
	else if (player[dataP->index].numberOfCards != ZERO)
	{
		dataP->index = dataP->index + dataP->direct; // make stop
	}
	else
	{
		checkAmountCards(player, dataP, cardAmount); //check winner
	}
}
void insertPlusCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
{
	if (player[dataP->index].numberOfCards == ZERO) // if the player finish the cards create card
	{
		increaseCard(player, upper, dataP, cardAmount, statsOfGame);
	}
	else
	{
		dataP->index = dataP->index - dataP->direct; // index = index - direct
	}
}
void insertChangeDirectCard(player player[], card* upper, DataPl* dataP, int* cardAmount)
/*the function care about the change direct speical card*/
{
	dataP->direct = dataP->direct * (CHANGE_DIRECT); // direct = direct * (-1)
}
void insertChangeColorCard(player player[], card* upper, DataPl* dataP, int* cardAmount)
/*the function care about the speical card change color */
{
	int colorInsert;
	printf("Please enter Your color Choice:\n%d - Yellow\n%d - Red\n%d - Blue\n%d - Green\n", ONE, TWO, THREE, FOUR_COLOR);
	scanf("%d", &colorInsert);
	rndColor(colorInsert, upper);
}
void checkAmountCards(player player[], DataPl* datap, int* cardAmount)
/*the function check if winner or not*/
{
	if (player[datap->index].numberOfCards == ZERO)
	{
		datap->winner = ONE;
		printWinner(player, datap);
	}
	else
	{
		return;
	}
}
void printWinner(player player[], DataPl* datap)
{
	printf("The winner is. . . %s! Congratulations! ", player[datap->index].name);
}
void createRealloc(player player[], card* upper, DataPl* dataP, int* cardAmount)
/*the function of realloc to the cards*/
{
	if (player[dataP->index].numberOfCards < player[dataP->index].PhySize)
	{
		return;
	}
	else
	{
		int i;
		card* newcard;
		player[dataP->index].PhySize *= TWO;
		newcard = (card*)malloc(player[dataP->index].PhySize * sizeof(card));
		if (newcard == NULL)
		{
			exit(1);
		}
		for (i = ZERO; i < player[dataP->index].numberOfCards; i++)
		{
			newcard[i] = player[dataP->index].card[i];
		}
		free(player[dataP->index].card);
		player[dataP->index].card = newcard;
	}
}
void insertTakiCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function is responsible on TAKI mode and the function is care about the speical CARD taki*/
{
	card* current;
	printByTurn(player[dataP->index], dataP, *upper);
	printf("Please enter %d if you want to take a card from a deck\nor %d-%d if you want to put one of your cards in the middle:\n", ZERO, ONE, player[dataP->index].numberOfCards);
	scanf("%d", &dataP->playerinp);
	current = &player[dataP->index].card[dataP->playerinp - ONE];
	getCompareElement(player, upper, dataP, cardAmount, current);
	while (player[dataP->index].numberOfCards != ZERO) // while no winner
	{
		if (dataP->playerinp == ZERO)
			break;
		if ((checkTakiSelect(player, upper, dataP, cardAmount, current))) // the input is not valid
		{
			printf("Invalid choice try again\n");
			printf("Please enter %d if you want to take a card from a deck\nor %d-%d if you want to put one of your cards in the middle:\n", ZERO, ONE, player[dataP->index].numberOfCards);
			scanf("%d", &dataP->playerinp);
			current = &player[dataP->index].card[dataP->playerinp - ONE];
			getCompareElement(player, upper, dataP, cardAmount, current);
		}
		else
		{
			if (((strcmp("COLOR", current->type) == ZERO))) // if the card is color
			{
				*upper = player[dataP->index].card[dataP->playerinp - ONE];
				insertChangeColorCard(player, upper, dataP, cardAmount);
				player[dataP->index].card[dataP->playerinp - ONE] = player[dataP->index].card[*cardAmount - ONE];
				*cardAmount = (*cardAmount) - ONE;
				return;
			}
			decreaseCard(player, upper, dataP, cardAmount);
			if (player[dataP->index].numberOfCards == ZERO) // check if is winner
				break;
			printByTurn(player[dataP->index], dataP, *upper); // [print the table again
			printf("Please enter %d if you want to take a card from a deck\nor %d-%d if you want to put one of your cards in the middle:\n", ZERO, ONE, player[dataP->index].numberOfCards);
			scanf("%d", &dataP->playerinp);
			if (dataP->playerinp != 0 && !checkOverLimitInput(player, dataP))
			{
				current = &player[dataP->index].card[dataP->playerinp - 1];
				getCompareElement(player, upper, dataP, cardAmount, current);
			}
			else if (dataP->playerinp == ZERO)
			{
				*current = *upper;
			}
		}
	}
	*current = *upper;
	typeOfInsertAfterTaki(current, player, upper, dataP, cardAmount, statsOfGame);
	if (dataP->winner == ZERO)
		checkAmountCards(player, dataP, cardAmount);
}
bool checkTakiSelect(player player[], card* upper, DataPl* dataP, int* cardAmount, card* current)
/*the function return true or false if the input is valid by the specific card and the specific input*/
{
	if (((checkOverLimitInput(player, dataP) || ((checkCardIsLegitTakiMode(dataP, current))))))
		return true;
	return false;
}
void typeOfInsertAfterTaki(card* current, player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function is to check what if the last card of the taki mode was a special card and the function check all the posible options*/
{
	if (strcmp(current->type, "STOP") == ZERO)
	{
		insertStopCard(player, upper, dataP, cardAmount, statsOfGame);
	}
	else if (strcmp(current->type, "<->") == ZERO)
	{
		insertChangeDirectCard(player, upper, dataP, cardAmount);
	}
	else if (strcmp(current->type, "PLUS") == ZERO)
	{
		insertPlusCard(player, upper, dataP, cardAmount, statsOfGame);
	}
}
void decreaseCard(player player[], card* upper, DataPl* dataP, int* cardAmount)
/*the function if the card is valid and the function is decrease the amount cards of specific player and replace the upper card*/
{
	*upper = player[dataP->index].card[dataP->playerinp - ONE];
	player[dataP->index].card[dataP->playerinp - ONE] = player[dataP->index].card[*cardAmount - 1];
	*cardAmount = (*cardAmount) - ONE;
}
void increaseCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame)
/*the function if the user press 0 and                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     uwant to draw card*/
{
	player[dataP->index].card[player[dataP->index].numberOfCards] = createcard(statsOfGame);
	*cardAmount = player[dataP->index].numberOfCards + ONE;
}
void getCompareElement(player player[], card* upper, DataPl* dataP, int* cardAmount, card* current)
/*the function making strcmp between upper card and current card by type and color*/
{
	dataP->compareType = strcmp(upper->type, current->type);
	dataP->compareColor = strcmp(upper->color, current->color);
}
bool checkOverLimitInput(player player[], DataPl* dataP)
/*the function get player array and datapl type and return true or false if the player input is legit*/
{
	if (dataP->playerinp < ZERO || dataP->playerinp > player[dataP->index].numberOfCards)
	{
		return true;
	}
	return false;
}
bool checkCardIsLegit(DataPl* dataP, card* current)
/* the function get dataPl type and card current and return true or false if the card is legit by the upper and current compere type and color*/
{
	bool res = false;
	if (!(dataP->compareType == ZERO))
	{
		if (!(dataP->compareColor == ZERO))
			res = true;
	}
	if (!(dataP->compareColor == ZERO))
	{
		if (!(dataP->compareType == ZERO))
			res = true;
	}
	if ((strcmp(current->type, "COLOR") == ZERO))
		res = false;
	return res;
}
void mergeSort(statisticParamaeter statsOfGame[], int size)
/* the function get a statisticParamaeter array and size and making a merge sort*/
{
	statisticParamaeter* tmpArr = NULL;
	if (size <= ONE)
		return;

	mergeSort(statsOfGame, size / TWO);
	mergeSort(statsOfGame + size / TWO, size - size / TWO);
	tmpArr = merge(statsOfGame, size / TWO, statsOfGame + size / TWO, size - size / TWO);
	if (tmpArr)
	{
		copyArr(statsOfGame, tmpArr, size); // copy values from tmpArr to arr
		free(tmpArr);
	}
	else
	{
		printf("Memory allocation failure!!!\n");
		exit(1);	// end program immediately with code 1 (indicating an error)
	}
}

statisticParamaeter* merge(statisticParamaeter* statsOfGame, int size1, statisticParamaeter* tmpArr, int size2)
/* the function get 2 statisticParamaeter array and 2 size and make a merge*/
{
	int ind1, ind2, resInd;
	statisticParamaeter* newTmpArr = (statisticParamaeter*)malloc((size1 + size2) * sizeof(statisticParamaeter));

	if (newTmpArr)
	{
		ind1 = ind2 = resInd = 0;

		while ((ind1 < size1) && (ind2 < size2)) {
			if (statsOfGame[ind1].CountPerCardss <= tmpArr[ind2].CountPerCardss)
			{
				newTmpArr[resInd] = statsOfGame[ind1];
				ind1++;
			}
			else {
				newTmpArr[resInd] = tmpArr[ind2];
				ind2++;
			}
			resInd++;
		}

		while (ind1 < size1) {
			newTmpArr[resInd] = statsOfGame[ind1];
			ind1++;
			resInd++;
		}
		while (ind2 < size2) {
			newTmpArr[resInd] = tmpArr[ind2];
			ind2++;
			resInd++;
		}
	}
	return newTmpArr;
}
void copyArr(statisticParamaeter statsOfGame[], statisticParamaeter tmpArr[], int size)
/*the function get 2 statisticParamaeter and size and make a copy from one to anohter*/
{
	int i;
	for (i = 0; i < size; i++)
	{
		statsOfGame[i].CountPerCardss = tmpArr[i].CountPerCardss;
		strcpy(statsOfGame[i].typeOfCard, tmpArr[i].typeOfCard);
	}
}
void printStatistics(statisticParamaeter statsOfGame[], int size)
{/*the function get statisticParamaeter array and size and call to merge sort and print the statistic of the game*/
	int i;
	mergeSort(statsOfGame, size);
	printf("\n");
	printf("***********************\n");
	printf("Card # | Frequency\n");
	printf("_____________________\n");
	for (i = 0; i < size; i++)
	{
		printAlignStats(statsOfGame, i, size);
		printf("\n");
	}
}
void initialValuesArr(statisticParamaeter statsOfGame[], int size)
/*the function get statisticParamaeter array and size and initial the required values in the array*/
{
	int i;
	for (i = 0; i < size; i++)
	{
		statsOfGame[i].CountPerCardss = ZERO;
		initialValuesStr(statsOfGame, i);
	}
}

bool checkCardIsLegitTakiMode(DataPl* dataP, card* current)
/*the function get DataOfGame* and current card and return true or false if is legit in taki mode*/
{
	bool res = false;
	if (!(dataP->compareColor == 0))
		res = true;
	if ((strcmp(current->type, "COLOR") == 0))
		res = false;
	return res;
}
void initialValuesStr(statisticParamaeter statsOfGame[], int size)
/*the function get statisticParamaeter array and size and initial the typeOfCard from the array*/
{
	switch (size)
	{
	case 0:
		strcpy(statsOfGame[size].typeOfCard, "1");
		break;
	case 1:
		strcpy(statsOfGame[size].typeOfCard, "2");
		break;
	case 2:
		strcpy(statsOfGame[size].typeOfCard, "3");
		break;
	case 3:
		strcpy(statsOfGame[size].typeOfCard, "4");
		break;
	case 4:
		strcpy(statsOfGame[size].typeOfCard, "5");
		break;
	case 5:
		strcpy(statsOfGame[size].typeOfCard, "6");
		break;
	case 6:
		strcpy(statsOfGame[size].typeOfCard, "7");
		break;
	case 7:
		strcpy(statsOfGame[size].typeOfCard, "8");
		break;
	case 8:
		strcpy(statsOfGame[size].typeOfCard, "9");
		break;
	case 9:
		strcpy(statsOfGame[size].typeOfCard, "STOP");
		break;
	case 10:
		strcpy(statsOfGame[size].typeOfCard, "<->");
		break;
	case 11:
		strcpy(statsOfGame[size].typeOfCard, "TAKI");
		break;
	case 12:
		strcpy(statsOfGame[size].typeOfCard, "COLOR");
		break;
	case 13:
		strcpy(statsOfGame[size].typeOfCard, "PLUS");
		break;

	}
}
void printAlignStats(statisticParamaeter statsOfGame[], int i, int size)
/*the function get statisticParameater type and size and index and print the required line*/
{
	if (strlen(statsOfGame[size - i - 1].typeOfCard) == ONE)
	{
		printf("    %s   |    %d   ", statsOfGame[size - i - 1].typeOfCard, statsOfGame[size - i - 1].CountPerCardss);
	}
	else if (strlen(statsOfGame[size - i - 1].typeOfCard) == THREE)
	{
		printf("   %s  |    %d    ", statsOfGame[size - i - 1].typeOfCard, statsOfGame[size - i - 1].CountPerCardss);
	}
	else if (strlen(statsOfGame[size - i - 1].typeOfCard) == FOUR)
	{
		printf("  %s  |    %d    ", statsOfGame[size - i - 1].typeOfCard, statsOfGame[size - i - 1].CountPerCardss);
	}
	else
	{
		printf(" %s  |    %d    ", statsOfGame[size - i - 1].typeOfCard, statsOfGame[size - i - 1].CountPerCardss);
	}
}