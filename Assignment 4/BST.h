
typedef struct BST{ 
	NodeData data; 
	struct BST *lchild, *rchild; 
} TreeNode, *TreeNodePtr;

TreeNodePtr rootInsert(TreeNodePtr node, int num){

	//Null checking
	if(node == NULL){
		TreeNodePtr np = (TreeNodePtr)malloc(sizeof(TreeNodePtr));
		np->lchild = (TreeNodePtr)malloc(sizeof(TreeNodePtr));
		np->lchild = NULL;
		np->rchild = (TreeNodePtr)malloc(sizeof(TreeNodePtr));
		np->rchild = NULL;
		np->data.num = num;
		return np;
	}	
	//ignore duplicates/ duplicate handling 
 	else if(node->data.num == num){
		return node;
	}
	else if(node->data.num < num){
		//setting the right child 
		TreeNodePtr right = rootInsert(node->rchild, num);
		node->rchild = right;
		return node;
	}
	else if(node->data.num > num){
		//setting left child
		TreeNodePtr left = rootInsert(node->lchild, num);
		node->lchild = left;
		return node;
	}
}


void printInOrder(TreeNodePtr node){
	if(node != NULL){
		printInOrder(node->lchild);
		printf("%d \n", node->data.num);
		printInOrder(node->rchild);
	}
}

void printRoot(TreeNodePtr node){
	//The root should be the first node in tree
	if(node != NULL){
		//printing first tree node
		printf("The root is %d \n ", node->data.num);
	}
}

int numOfNodes(TreeNodePtr node){
	if(node == NULL){
		return 0;
	}
	return 1 + numOfNodes(node->lchild) + numOfNodes(node->rchild);
}

int countLeaves(TreeNodePtr node){
	if(node == NULL){
		return 0;
	}
	if(node->lchild == NULL || node->rchild == NULL){
		return 1;
	}
	return countLeaves(node->lchild) + countLeaves(node->lchild);
}


