#pragma once
#include <stdio.h>
#include <iostream>

typedef struct cell
{
	char val[64];
	struct cell* prev;
	struct cell* next;
}CELL;

class List
{
public:
	static void create(CELL* currentCell, char val[64]);
	static void erase(CELL* currentCell);
	static void replace(CELL* currentCell, char val[64]);
	static void swap(CELL* CellA, CELL* CellB);

public:
	CELL head = {};

public:
	List();
	CELL* GetInsertCellAddress(int iterator);
	void Index();
	int GetSize();
};