
typedef struct node{
	int num;//data	
	struct node *next;
}Node, *NodePtr;


NodePtr head = NULL;

NodePtr makeNode(int n){
	

	NodePtr np = (NodePtr) malloc (sizeof(Node));
	np->num = n;//set element
	np->next = NULL;//set successor
	return np;
}



//searching for requested number
NodePtr search(NodePtr head, int key){ 

	//setting local ptr to the head that was sent in
	NodePtr lPtr = head;
	
	while(head != NULL){

		
		if(head->num == key){
			printf("\n\nYour number has already been added \n"); 

		}

		// continue loop if no match found
		else{
			head = head->next;
		}
	}


	//finding the next available spot
	while(lPtr->next != NULL){
		lPtr = lPtr->next;
	}

	//returning the value of the pointer 
	return lPtr;			
}



//Printing the Linked list
void printList(void){

	NodePtr temp = head;
	
	//notify the user list is empty
	if(temp == NULL){
		printf("List is Empty");
	}
	printf("\n\n");
	while(temp != NULL){
		printf("%d ", temp->num);
		temp = temp->next;
	}
}



//adding to linked list
void add(int n)
{
	//ignoring input if input = 0
	if(n != 0){

		//create node
		NodePtr newNode = makeNode(n);

		//Add to the list
		//Condition 1: List is empty
		if(head == NULL){
			head = newNode;
		}else{
			NodePtr pred = head;
			NodePtr curr = head;

			//searching for duplicated
			//Condition 2: no duplicates
			NodePtr temp = search(pred, n);

			//getting the current position of the smaller number
			//was for sorting
			while(curr != NULL && curr->num < n){
				curr = curr->next;
			}
			
			temp->next = newNode;
		}
	}
					
	printList();//print recently added nodes
}



//removing from linked list user input
void removeNum(int n){

	//2 pointers to keep track 
	NodePtr delete = head;
	NodePtr pred = head;
	
	//checking if there is a stored node
	if(head == NULL){
		printf("Node doesnt exist\n");
		menu();
	}

	//searching through link list
	if(head->num == n){
		head = head->next;
	}else{
		while(delete != NULL && delete->num != n){
			pred = delete;
			delete = delete->next;
		}
		if(delete != NULL){
			pred->next = delete->next;
		}else{
			//notifying user List doesn't exist
			printf("\n Node doesnt exist\n");
			printList();
			menu();			
		}
	}

	if(removeNum != NULL){
		free(delete);
		printList();
		menu();	
	}

}
