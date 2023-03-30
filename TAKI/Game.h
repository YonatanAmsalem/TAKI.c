#pragma once
//Yonatan Amsalem
//TAKI.C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define STOP 10
#define CHANGE_DIR 11
#define TAKI 12
#define CHANGE_COLOR 13
#define PLUS 14
#define FOUR_COLOR 4
#define TEN 10
#define CHANGE_DIRECT -1
#define INITIAL_NUM_CARDS 4
#define MAX_ELEMENTS_RAND 14
#define NUMBER_OF_CARDS 14
#define MAX_ELEMENTS_RAND_UPPER 10
#define MAX_SIZE_NAME 21
#define MAX_SIZE_OF_CHAR_CARD 7
/*struct of card,include type and specific char*/
struct cards {
	char type[MAX_SIZE_OF_CHAR_CARD]
		, color[TWO];
};
typedef struct cards card;
/*struct of player include the full name,cardp number of cards and physical size*/
struct Player {
	char  name[MAX_SIZE_NAME];
	card* card;
	int numberOfCards;
	int PhySize;

};
typedef struct Player player;
/*struct of data of the game with variables from the game like:player input,winner,direction,comparing,index and num of players*/
struct DataOfVar {
	int numOfPlayers;
	int winner, index, direct;
	int playerinp;
	int compareColor;
	int compareType;

};
typedef struct DataOfVar DataPl;
/*struct of statistic count with int countpercards and string of type of card*/
struct statisticCount {
	char typeOfCard[TEN];
	int CountPerCardss;
};
typedef struct statisticCount statisticParamaeter;


void printWinner(player player[], DataPl* datap);
void createRealloc(player player[], card* upper, DataPl* dataP, int* cardAmount);
void initialValuesStr(statisticParamaeter statsOfGame[], int size);
void printAlignStats(statisticParamaeter statsOfGame[], int i, int size);
void printStatistics(statisticParamaeter statsOfGame[], int size);
void mergeSort(statisticParamaeter statsOfGame[], int size);
statisticParamaeter* merge(statisticParamaeter* statsOfGame, int size1, statisticParamaeter* tmpArr, int size2);
void copyArr(statisticParamaeter statsOfGame[], statisticParamaeter tmpArr[], int size);
void initialValuesArr(statisticParamaeter* statsOfGame, int size);
void typeOfInsertAfterTaki(card* current, player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
bool checkCardIsLegitTakiMode(DataPl* dataP, card* current);
void mergeSort(statisticParamaeter* statsOfGame, int size);
void printMenu();
int numOfPlayersget();
void inputData(player player[], int size);
bool checkCardIsLegit(DataPl* dataP, card* current);
card createcard(statisticParamaeter* statsOfGame);
void initializeCardsToPlayers(player p[], DataPl* datap, statisticParamaeter* statsOfGame);
void rndType(int rnd, card* currentCard, statisticParamaeter* statsOfGame);
void rndColor(int rndColor, card* currentCard);
void createUpperCard(card* upperp, statisticParamaeter* statsOfGame);
void printcard(card toPrint);
bool checkOverLimitInput(player player[], DataPl* dataP);
void checkAmountCards(player player[], DataPl* datap, int* cardAmount);
void printByTurn(player player, DataPl* datap, card upper);
void checkStatusOfTurn(DataPl* dataP);
void gameTurn(player arrForPlayers[], DataPl* dataP, card* upperp, statisticParamaeter* statsOfGame);
void checkValidSelect(player player[], card* upper, DataPl* dataP, card* currentCard, int* cardAmount, statisticParamaeter* statsOfGame);
void checkUserSelect(player player[], card* upper, DataPl* dataP, int* cardAmoun, statisticParamaeter* statsOfGamet);