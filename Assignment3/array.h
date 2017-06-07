// Array header
/*
*Author: OLuwabiyi Akinsara
*/

/*
* add a new integer to the list
* parameter: the number to be added, the array and the size of the array
* returns: new size of the list
*/
int addToArray(int n, int array[], int count)
{
	int success = 0;
	// find sorted placement
	for(int i = 0; i < count; i++)
	{
		// search for point where n belongs in the array
		if(array[i] > n)
		{
			//shift elements as required
			for(int j=count; j>i; j--)
			{
				array[j] = array[j-1];
			}
			array[i] = n;
			success = 1;
			break;
		}
	}
	if(success == 0)
	{
		array[count]=n;
	}

	return (count+1);
}

/*
* prints the array
*/
void printArray(int array[], int size)
{
	printf("Array : ");
	for(int i = 0; i<size; i++)
	{
		// print the integer
		printf("%d ", array[i]);
	}
	printf("\n");
}

/*
* merges two arrays into array1
* parameter: the two arrays and their sizes
*/
void mergeArray(int array1[], int array2[], int size1, int size2)
{

	//creating a bigger array to merge into
	int array3[size1+size2];
	int size = size1+size2;
	int i = 0;
	int j = 0;
	int m = 0;

	//sort + merge
	while(i < size){
		if(array1[m] <= array2[j] && array1[m] != 0){
			array3[i] = array1[m];
			m++;
		}else{
			array3[i] = array2[j];
			j++;
		}
		i++;
	}

	//copying to array1 to print array1 reference
	for(i = 0; i < size; i++){
		array1[i] = array3[i];
	}

}
