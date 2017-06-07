/*
*Author: OLuwabiyi Akinsara
*/

#include <stdio.h>

typedef struct{
	int num;
}NodeData;

#include "BST.h"
#include "quick.h"


int main(void)
{
	//11 elements
	//int array[] = {50, 3, 93, 27, 5, 21, 100, 29, 58, 84, 34};

	//20 elements
	//int array[] = {50, 3, 93, 27, 5, 21, 100, 29, 58, 84, 34, 32, 17, 44, 60, 72, 88, 81, 45, 90};
	
	//11 elements 3 duplicates of 50
	int array[] = {50, 3, 93, 50, 5, 21, 100, 29, 50, 84, 34};
	

	int size = sizeof(array)/4;

	quickSort(array, 0, size-1);

	//setting the root 
	int middle = size/2;
	int root = array[middle];

	/* Testing quicksort
	for(int i =0; i<size; i++)
		printf("%d  ", array[i]);
	*/

	//Declarations
	TreeNodePtr node = NULL;


	node = rootInsert(node, root);

	//Feeding BST inputs 1 at a time
	for(int i =0; i<size; i++){		
		int num = array[i];
		node = rootInsert(node, num);
	}
		

	/***PRINTING***/
	printf("****BST******\n");
	printInOrder(node);

	printf("\n****ROOT******\n");
	printRoot(node);

	printf("\n****NON******\n");
	printf("Number of nodes in the tree: %d \n", numOfNodes(node));

	printf("\n****Leaves******\n");
	printf("The number of leaves: %d \n\n", countLeaves(node));
}
