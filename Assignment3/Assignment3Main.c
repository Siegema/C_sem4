/*
*Author: OLuwabiyi Akinsara
*/

#include<stdio.h>
#include <time.h>
#include "linkedlist.h"
#include "array.h"
	
#define MAX 20

NodePtr head1, head2;
int numbers1[MAX], numbers2[MAX];
int count1 = 0;
int count2 = 0;

int readFromFile(void);
extern void exit(int);

int main(void)
{
	// read in data from file and add to both array and linked list

	int success = readFromFile();

	if(success == -1)
		exit(1);

	print(head1);
	printArray(numbers1,count1);
	print(head2);
	printArray(numbers2,count2);

	
	clock_t begin, end;
	double time_spent;


	begin = clock();

	// merge two arrays
	printf("\n");
	mergeArray(numbers1, numbers2, count1, count2);


	end = clock();
	printArray(numbers1, (count1+count2));

	time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
	printf("Array took :%f to sort\n \n", time_spent);
	
	begin = clock();

	// merge two linked lists
	NodePtr head3 = mergeList(head1, head2);


	end = clock();
	print(head3);	

	time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
	printf("List took :%f  to sort \n", time_spent);
}

int readFromFile(void)
{
	int temp = 0;
	int count = 1;
	// open file
	FILE * fp;
	fp = fopen("DATA.txt", "r");
	
	// check to see if error opening file
	if(fp == NULL)
	{
		//display error and return -1
		printf("File does not exist");
		return -1;
	}
	else
	{
		while(fscanf(fp,"%d",&temp) == 1)
		{
			if(count%2 == 0)
			{
				// add to list 1
				// add to array
				count1 = addToArray(temp, numbers1, count1);

				// add to linked list
				head1 = add(temp, head1);
			}			
			else
			{
				// add to list 2
				// add to array
				count2 = addToArray(temp, numbers2, count2);

				// add to linked list
				head2 = add(temp, head2);
			}
			count++;
		} 
		return 0;
	}

}

