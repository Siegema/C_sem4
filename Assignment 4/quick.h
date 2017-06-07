void quickSort(int A[], int lo, int hi){
	//while the array isn't traversed
	if(lo < hi){
		int p = partition(A, lo, hi);
		quickSort(A, lo, p-1);
		quickSort(A, p+1, hi);
	}
}	

int partition(int A[], int lo, int hi){
	int pivot, i; 
	pivot = A[lo];
	int small = lo;
	
	//swapping all smaller numbers to the left 
	for(i = lo+1; i<=hi; i++){
		if(A[i] < pivot){
			++small;
			int temp = A[i];
			A[i] = A[small];
			A[small] = temp;
		}
	}

	//inserting pivot into place
	int temp = A[lo];
	A[lo] = A[small];
	A[small] = temp;

	return small;
}
