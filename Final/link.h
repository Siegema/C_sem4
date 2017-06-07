/*
*Authors
*Oluwabiyi Akinsara 991358865
*zhixuanzhao 991333454
**/
//header  file
#ifndef LINK_H
#define LINK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct game {
    int year;
    char name[50];
    char type[50];//Genre
    char publisher[50];
    int stock;
    struct game *next;
} Game, *GamePtr;

GamePtr makeNode(int year, char name[50], char type[50], char pub[50], int stock);

void addGame(int year, char name[50], char type[50], char pub[50], int stock);

void printList(void);

void load();

void loadPre();

void saveList(GamePtr game);

void search(char name[]);

void delete(char name[]);

void addStock(void);

void menu(void);

void menuO(void);

void mergeSort(GamePtr *source);

GamePtr mergeLists(GamePtr a, GamePtr b);

void partition(GamePtr head, GamePtr *front, GamePtr *back);

#endif
