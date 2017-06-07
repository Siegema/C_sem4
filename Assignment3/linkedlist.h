n/*
*Author: OLuwabiyi Akinsara
*/

//Linked List header
typedef struct node{ 
	int num; 
	struct node *next; 
}Node, *NodePtr; 
// a name for struct node 

extern void *malloc(size_t);
extern void free(void *);


/*
* make a new node 
* parameter: the integer to be added
* returns: the pointer to the node created
*/
NodePtr makeNode( int n)
{ 
	// Allocate memory for the new Node
	NodePtr np=(NodePtr) malloc (sizeof(Node)); 
	np->num=n; // set the element (integer)
	np->next= NULL; // set the successor 
	return np; 
} 

/*
* add a new integer to the list in sorted order
* parameter: the number to be added and node pointing to the head of the list
* returns: new head of list
*/
NodePtr add(int n, NodePtr head)
{
	NodePtr element = makeNode(n);

	// check to see if list is empty
	if(head == NULL)
	{
		// if empty, new element is first element
		head = element;
		return head;
	}
	else // list isn't empty
	{
		//Check 1st element
		if(element->num < head->num)
		{
			// add to beginning of list
			element->next = head;
			head=element;
			return head;
		}

		// loop until we find where the new item belongs
		NodePtr curr = head;
		NodePtr pre = NULL;

		while(curr != NULL && element->num >= curr->num)
		{
			// advance the pointers
			pre = curr;
			curr = curr->next;
		}

		//prev is NULL, adding to head
		if(pre == NULL)
		{
			element->next = curr;
			return head;
		}
		else
		{
			// set new node to point to current node
			element->next = curr;
			// set previous node to point to new node
			pre->next = element;
			return head;
		}
	}
}

/*
* prints the linked list
*/
void print(NodePtr head)
{
	printf("List: ");
	NodePtr temp = head;
	while(temp!=NULL)
	{
		// print the integer
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");
}


/*
* delete: delete a node from a linked list based on given integer
* parameter: the integer we are looking to delete and the pointer
* to the head of the list
* returns: the pointer to the head of the list
*/
NodePtr delete(int num, NodePtr head)
{
	NodePtr succ = head;
	NodePtr pre = head;
	int index = 0;

	//check if it is the first item you are deleting
	if(succ->num == num)
	{
		// update the head to the next node in the list
		head = head->next;
		// free the memory
		free(succ);
		return head;
	}

	// loop through linked list
	while(succ!=NULL)
	{
		// check to see if the element matches the key
		if(succ->num == num)
		{
			// update the previous next to point to succ next
			pre->next = succ->next;
			// free the memory
			free(succ);
			// if it does return the index
			return head;
		}
		//increment count
		index ++;
		//step to next node
		pre = succ;
		succ = succ->next;
	}
	return head;
}

/*
* merges two linked lists
* parameter: pointers to the two head variables
* return: pointer to the new linked list
*/
NodePtr mergeList(NodePtr head1, NodePtr head2)
{
	NodePtr temp1 = head1;
	NodePtr curr = head1;
	int pred;
	int small;

	//storing list inside temp1
	while(temp1->next != NULL){
		temp1 = temp1->next;
	}

	//appending the second list
	temp1->next = head2;


	//sorting
	while(curr != NULL){
		//reinitializing temp2 so loop always starts at 1rst node
		NodePtr temp2 = head1;
		while(temp2 != NULL && temp2->next != NULL){
			pred = temp2->num;
			small = temp2->next->num;
			if(small < pred ){
				temp2->next->num = pred;
				temp2->num = small;
				temp2 = temp2->next;
			}else{	
				temp2 = temp2->next;
			}

		}
		curr = curr->next;
	}

	return head1;
	
}
