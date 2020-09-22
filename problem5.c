#include<stdio.h>
#include<stdlib.h>

int cnt = 0;
void permutation(char word[], int l, int r, FILE* fp) {
	if(l == r)
		{
			fprintf(fp, "%s\n", word);
			cnt++;
			if(cnt == 100000)
				exit(0);
		}
	else {
		for(int i = l; i <= r; i++){ 
			{
				// swap word[i] & word[l]
				char temp = word[i];
				word[i] = word[l];
				word[l] = temp;
			}
			// calling the function recursively to generate permutation
			permutation(word, l + 1, r, fp);
			
			{
				// backtracking part
				char temp = word[i];
				word[i] = word[l];
				word[l] = temp;
			}
		}
	}
}

int main() {
	FILE* fp;
	fp = fopen("problem5file.txt", "w");
	
	char word[10];
	for(int i = 65; i < 75; i++){
		word[i - 65] = (char)i;
	}
	
	//generating a random permutation by randomly swapping the integers
	for(int i = 0; i < 10; i++){
		int j = rand() % 10;
		int temp = word[j];
		word[j] = word[i];
		word[i] = temp;
	}
	//fprintf(fp, "%s", word);
	// print the permutation of the char array word
	permutation(word, 0, 9, fp);
	return 0;
}
