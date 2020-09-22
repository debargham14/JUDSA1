#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to sort the array of words
void sort_words(char names[][100], int n, FILE* fp){
	// performing insertion sort to sort the names in ascending order
	char word[90];
	for(int i = 1; i < n; i++){
		strcpy(word, names[i]);
		int j = i - 1;
		
		while(j >= 0 && strcmp(names[j], word) > 0)
		{
			strcpy(names[j + 1], names[j]);
			j--;
		} 
		strcpy(names[j + 1], word); 
	}
	
	fprintf(fp, "The names in sorted order (ascending order) :- ");
	for(int i = 0; i < n; i++){
		fprintf(fp, "%d. %s", i + 1, names[i]);
	} 
}

int main() {
	FILE* fp;
	FILE* fp1;
	
	fp = fopen("classmate.txt", "r");
	fp1 = fopen("problem6file.txt", "w");
	
	char names[90][100];
	
	for(int i = 0; i < 90; i++){
		fgets(names[i], 30, fp);
	}
	
	int max_char = -1, min_char = 100;
	for(int i = 0; i < 90; i++){
		int len = 0;
		//to avoid spaces in the names we re counting the number of characters excluding spaces
		
		for(int j = 0; j < (int)strlen(names[i]); j++)
			if(names[i][j] != ' ')
				len++;
		if(len > max_char){
			max_char = len;
		}
		if(len < min_char){
			min_char = len;
		}
	}
	int k = 0, k1 = 0;
	
	//counting names with min and max number of characters
	for(int i = 0; i < 90; i++){
		int len = 0;
		for(int j = 0; j < (int)strlen(names[i]); j++)
			if(names[i][j] != ' ')
				len++;
		if(len == max_char)
		{
			k++; 
		}
		if(len == min_char)
		{
			k1++;
		}
	}
	
	
	// extracting the names having max and min number of characters
	int st = 0;
	char **names2 = (char**)malloc(k1 * sizeof(char*)); 
	for(int i = 0; i < 90; i++){
		int len = 0;
		for(int j = 0; j < (int)strlen(names[i]); j++)
			if(names[i][j] != ' ')
				len++;
		if(len == max_char)
		{
			names2[st] = names[i];
			st++;
		}
	}
	
	// extracting the names having least number of characters
	st = 0;
	char **names3 = (char**)malloc(k1 * sizeof(char*)); 
	for(int i = 0; i < 90; i++){
		int len = 0;
		for(int j = 0; j < (int)strlen(names[i]); j++)
			if(names[i][j] != ' ')
				len++;
		if(len == min_char)
		{
			names3[st] = names[i];
			st++;
		}
	}
	
	// printing the names having most number of characters
	fprintf(fp1, "The names having max number of characters are :- ");
	for(int i = 0; i < k; i++){
		
		fprintf(fp1, "%d. %s", i + 1, names2[i]);
		fprintf(fp1, "with %d characters\n", max_char - 1);
	}
	
	// printing the names having least number of characters
	fprintf(fp1, "The names having least number of characters are :- ");
	for(int i = 0; i < k1; i++){
		
		fprintf(fp1, "%d. %s", i + 1, names3[i]);
		fprintf(fp1, "with %d characters\n", min_char - 1);
	}
	
	
	// finally printing the sorted order of names
	sort_words(names, 90, fp1);
	
	//closing the file using relevant function
	fclose(fp);
	fclose(fp1);
	return 0;
}
