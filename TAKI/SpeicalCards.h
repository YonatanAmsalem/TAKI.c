#pragma once
#include "Game.h"
void insertTakiCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
bool checkTakiSelect(player player[], card* upper, DataPl* dataP, int* cardAmount, card* current);
void decreaseCard(player player[], card* upper, DataPl* dataP, int* cardAmount);
void increaseCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
void getCompareElement(player player[], card* upper, DataPl* dataP, int* cardAmount, card* current);
void typeOfInsert(card* current, player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
void insertStopCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
void insertPlusCard(player player[], card* upper, DataPl* dataP, int* cardAmount, statisticParamaeter* statsOfGame);
void insertChangeDirectCard(player player[], card* upper, DataPl* dataP, int* cardAmount);
void startGame(player player[], card* upper, DataPl* dataP, int* amountCard, statisticParamaeter* statsOfGame);
void insertChangeColorCard(player player[], card* upper, DataPl* dataP, int* cardAmount);