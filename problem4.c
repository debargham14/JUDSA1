#include <stdio.h>
#include<stdlib.h>

int main()
{
	FILE* fp;
	fp = fopen("Problem4file.txt", "w");
	
	const int n = 1e5;
	int arr[n];
	
	//	Initialising to identity permutation.
	for(int i = 0; i < n; ++i)
	{
		arr[i] = i + 1;
	}
	
	//	Generating a random permutation by swapping between random indices
	for(int i = 0; i < n; ++i)
	{
		int j = rand() % n;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	//	Printing the array
	fprintf(fp, "First 100 of the 100000 randomly generated elements are: \n");
	for(int i = 0; i < 100; ++i)
	{
		fprintf(fp, "%d ", arr[i]);
	}
	fprintf(fp, "\n");
	fclose(fp);
	
	return 0;
}
