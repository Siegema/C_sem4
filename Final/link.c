/*
*Authors
*Oluwabiyi Akinsara 991358865
*zhixuanzhao 991333454
**/

#include "link.h"

GamePtr head = NULL;

//upcoming head
GamePtr uHead = NULL;

GamePtr makeNode(int year, char name[50], char type[50], char pub[50], int stock)
{

    GamePtr gp = (GamePtr)malloc(sizeof(Game));
    gp->year = year; //set element
    strcpy(gp->name, name);
    strcpy(gp->type, type);
    strcpy(gp->publisher, pub);
    gp->stock = stock;
    gp->next = NULL; //set successor
    return gp;
}

void addGame(int year, char name[50], char type[50], char pub[50], int stock)
{
    // create node
    GamePtr newGame = makeNode(year, name, type, pub, stock);

    //Add to the list
    // Condition 1: List is empty
    if (head == NULL) {
        head = newGame;
    }

    // Condition 2: List is not empty
    else {
        GamePtr pred = head;
        while (pred->next != NULL) { //loop to find last element in list
            pred = pred->next;
        }
        pred->next = newGame;
    }
}

void addUpc(int year, char name[50], char type[50], char pub[50], int stock)
{
    // create node
    GamePtr newGame = makeNode(year, name, type, pub, stock);

    //Add to the list
    // Condition 1: List is empty
    if (uHead == NULL) {
        uHead = newGame;
    }

    // Condition 2: List is not empty
    else {
        GamePtr pred = uHead;
        while (pred->next != NULL) { //loop to find last element in list
            pred = pred->next;
        }
        pred->next = newGame;
    }
}

void printList(void)
{

    GamePtr temp = head;

    //notify the user list is empty
    if (temp == NULL) {
        printf("List is Empty");
    }
    printf("\n\n");
    while (temp != NULL) {
        printf("year: %d Name: %s Genre: %s Published by: %s In Stock: %d\n",
               temp->year, temp->name, temp->type, temp->publisher, temp->stock);
        temp = temp->next;
    }
}

void printListU(void)
{

    GamePtr temp = uHead;

    //notify the user list is empty
    if (temp == NULL) {
        printf("List is Empty");
    }
    printf("\n\n");
    while (temp != NULL) {
        printf("year: %d Name: %s Genre: %s Published by: %s In Stock: %d\n",
               temp->year, temp->name, temp->type, temp->publisher, temp->stock);
        temp = temp->next;
    }
}


void load()
{
    FILE* fp;
    fp = fopen("Inventory.txt", "r");
    if (fp == NULL)
        printf("File does not exist");

    else {

        // temp variables for input
        int year;
        char name[50];
        char type[50];
        char pub[50];
        int stock;

        while (fscanf(fp, "%d %s %s %s %d",
                &year, &name, &type, &pub, &stock)!= EOF) {

            // copy the information
            addGame(year, name, type, pub, stock);
        }
        fclose(fp);
    }
}


void loadPre()
{
    FILE* fp;
    fp = fopen("preOrder.txt", "r");
    if (fp == NULL)
        printf("File does not exist");

    else {

        // temp variables for input
        int year;
        char name[50];
        char type[50];
        char pub[50];
        int stock;

        while (fscanf(fp, "%d %s %s %s %d",
                      &year, &name, &type, &pub, &stock)
               != EOF) {

            // copy the information to the array
            addUpc(year, name, type, pub, stock);
        }
        fclose(fp);
    }
}

void saveList(GamePtr game)
{
    GamePtr temp = head;
    FILE* fp;
    fp = fopen("Inventory.txt", "w");//writing to file
    while (temp != NULL) {
        fprintf(fp, "%d  %s  %s  %s  %d \n", temp->year, temp->name, temp->type, temp->publisher, temp->stock);
        temp = temp->next;
    }
    fclose(fp);
}
void saveListTwo(GamePtr game)
{
    GamePtr temp = head;
    FILE* fp;
    fp = fopen("preOrder.txt", "w");//writing to file
    while (temp != NULL) {
        fprintf(fp, "%d  %s  %s  %s  %d \n", temp->year, temp->name, temp->type, temp->publisher, temp->stock);
        temp = temp->next;
    }
    fclose(fp);
}

void search(char name[])
{
	//*(lower->name) = tolower(*(temp->name));

	
	GamePtr temp = head;
	*name = tolower(*name);
	*(temp->name) = tolower(*(temp->name));

	// loop through linked list
	while(temp!=NULL)
	{

		// check to see if the element matches the key
		if(strcmp(temp->name, name) == 0)
		{
			// if it does return the index
      		printf("year: %d Name: %s Genre: %s Published by: %s In Stock: %d\n",
               temp->year, temp->name, temp->type, temp->publisher, temp->stock);
		}
		//step to next node
		temp = temp->next;
	}
	//if we do not return a count, means list is empty or key is not in list, return -1
	return;
}


void delete(char name[])
{
	GamePtr succ = head;
	GamePtr pre = head;
	*name = tolower(*name);
	*(succ->name) = tolower(*(succ->name));
	*(pre->name) = tolower(*(pre->name));


	//check if it is the first item you are deleting
	if(strcmp(succ->name, name) == 0)
	{
		// update the head to the next node in the list
		head = head->next;
		// free the memory
		free(succ);
		return;
	}

	// loop through linked list
	while(succ!=NULL)
	{
		// check to see if the element matches the key
		if(strcmp(succ->name, name) == 0)
		{
			// update the previous next to point to succ next
			pre->next = succ->next;
			// free the memory
			free(succ);
			// if it does return the index
			return;
		}
		
		//step to next node
		pre = succ;
		succ = succ->next;
	}
	//if we do not return an index, means list is empty or num is not in list, return -1
	return;

}

void addStock(void)
{
	GamePtr temp = head;
	int n;
	char name[50];
	printf("Enter the name of the game you wish to restock \n");
	scanf("%s", name);
    search(name);
	printf("\nHow many copies need to be added \n");
	scanf("%d", &n); 

	while(temp!=NULL)
	{

		// check to see if the element matches the key
		if(strcmp(temp->name, name) == 0)
		{
			// if it does return the index
      		temp->stock += n;
			printf("Stock has been updated");
		}
		//step to next node
		temp = temp->next;
	}
	menu();
}
void partition(GamePtr head, GamePtr *front, GamePtr *back){

	GamePtr first;//Link list #1
    GamePtr second;//Link list #2

    if (head == NULL || head->next == NULL){
        *front = head; // &a
        *back = NULL; // &b
    }else{
        second = head;
        first = head->next;
        while(first != NULL){
            first = first->next;

            if(first != NULL){
                second = second->next;
                first = first->next;
            }
        }
        *front = head; // a
        *back = second->next; // b
        second->next = NULL;
    }
}

GamePtr mergeLists(GamePtr a, GamePtr b){
    
	// A == First Linked list
	// B == Second Linked list
	GamePtr mergedList = NULL;
 
   	if (a == NULL){
        return b;
    }else if (b == NULL){
        return a;
    }

    if (strcmp(a->name , b->name) < 0){
        mergedList = a;
        mergedList->next = mergeLists(a->next, b);
    }else{
        mergedList = b;
        mergedList->next = mergeLists(a, b->next);
    }

    return mergedList;
}

void mergeSort(GamePtr *source){

	// A == First Linked list
	// B == Second Linked list

    GamePtr head = *source;
    GamePtr a = NULL;
    GamePtr b = NULL;

    if(head == NULL || head->next == NULL){
        return;
    }

    partition(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *source = mergeLists(a, b);
}



void menu(void)
{

    int num = 0;    //variable to store input
    int option = 0; //variable to store menu option
    int year;
    char name[50];
    char type[50];
    char pub[50];
    int stock;
	char gName[50];

    //menu
    printf("\nWhat would you like to do\n"
           "\n 1: Add to Inventory"
           "\n 2: Delete from Inventory"
           "\n 3: Print Inventory"
           "\n 4: Sort Inventory"
           "\n 5: Search Inventory"
           "\n 6: Save Inventory"
		   "\n 7: Upcoming games"
		   "\n 8: Restock games"
           "\n 9: Save & Exit\n\n");
    scanf("%d", &option);

	

	if(option < 1 || option > 9/*!isdigit(option)*/){
		printf("Please enter a number between 1-9");
		menu();
	}

    switch (option) {
	
	//Add
    case 1:
        printf("\nEnter game year\n");
        scanf("%d", &year);
        printf("\nEnter the game title\n");
        scanf("%s", &name);
		*name = tolower(*name);
        printf("\nEnter the Genre\n");
        scanf("%s", &type);
        printf("\nEnter the publisher\n");
        scanf("%s", &pub);
        printf("\nEnter the num of copies\n");
        scanf("%d", &stock);
        addGame(year, name, type, pub, stock);
        menu();
        break;

    //delete
    case 2:
        printf("\n");
		printf("Please enter the name of the game you wish to delete");
		printf("\n");
		scanf("%s", &gName);//Game Name
        delete(gName);
        menu();
        break;

    //read
    case 3:
        printf("\n");
        printList();
        printf("\n");
        menu();
        break;

    case 4:
        printf("\n");
        //printList();
		mergeSort(&head);
		printList();
        printf("\n");
		menu();
        break;
    //sortMenu();

    case 5:
        printf("\n");
		printf("Please enter the name of the game you wish to see");
		printf("\n");
		scanf("%s", &gName);//Game Name
        search(gName);
        printf("\n");
		menu();
        break;
   
    //save
    case 6:
        saveList(head);
        printf("It's been saved");
		menu();
        break;

    case 7:
		//order menu
  		menuO();
		break;

    case 8:
		//adding to copies
  		addStock();
		break;

    //save & exit
    case 9:
        saveList(head);
        exit(0);
    
	
	default :
			menu();
		}

}



void menuO(void)
{

    int option = 0; //variable to store menu option


    //menu
    printf("\nWhat would you like to do\n"
           "\n 1: View Upcoming games"
           "\n 2: Preorder"
           "\n 3: Go back"
	       "\n");
    scanf("%d", &option);

	if(option < 1 || option > 5){
		printf("Please enter a number between 1-5");
		menu();
	}

    switch (option) {

    case 1:
        printf("\n");
        printListU();
        printf("\n");
        menuO();
        break;

    //delete
    case 2:
        printf("\n");
		printf("Please go see a salse person to help you with the game you want.");
		printf("\n");  
        menuO();
        break;

    case 3:
		//exit to upper menue
        menu();
    }
}
