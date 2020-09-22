#include<stdio.h>
#include<string.h>

//four digit prime considered
const int prime = 1009;


//fucntion to evaluate (10^x) % prime
int powmodp(int pow){
	
	int val = 1;
	while(pow--){
		val = ((val % prime) * 10) % prime;
	}
	
	return val;
}

int main() {
	char name[] = "DEBARGHA";
	char surname[] = "MUKHERJEE";
	
	//printing the name
	printf("Name :- %s\n", name);
	printf("Surname :- %s\n", surname);
	
	int number[strlen(name) + strlen(surname)];
	int len = strlen(name) + strlen(surname);
	
	for(int i = 0; i < strlen(name); i++){
		number[i] = (int)name[i];
	}
	for(int i = strlen(name); i < len; i++){
		number[i] = (int)surname[i - strlen(name)];
	}	
	

	//making the string;
	char numstr[len * 2];
	
	
	for(int i = 0, st = 0; i < 2 * len, st < len; i += 2, st++){
		
		char last = (char)(number[st] % 10 + 48);
		number[st]  /= 10;
		char first = (char)(number[st] % 10 + 48);
		numstr[i] = first;
		numstr[i + 1] = last;
	}
	// the number formed by juxaposing the ascii characters
	printf("The number formed by juxatposing the ASCII characters :- ");
	for(int i = 0; i < 2 * len; i++)
		printf("%c", numstr[i]);
	printf("\n");
	
	
	char half1[len];
	char half2[len];
	
	for(int i = len; i < 2 * len; i++){
		half2[i - len] = numstr[i];
	}
	
	for(int i = 0; i < len; i++){
		half1[i] = numstr[i]; 
	}
	
	//first half of the string
	printf("The first number is :- ");
	for(int i = 0; i < (len); i++)
		printf("%c", half1[i]);
	printf("\n");
	
	//second half of the string
	printf("The first number is :- ");
	for(int i = 0; i < (len); i++)
		printf("%c", half2[i]);
	printf("\n");
	
	// implementing the adddition operation of two large numbers of equal length
	int carry = 0;
	
	char addstr[len + 1];
	for(int i = len - 1; i >= 1; i--){
		int num1 = (int)half1[i] - 48;
		int num2 = (int)half2[i] - 48;
		//printf("%d %d\n", num1, num2);
		
		int sum = num1 + num2 + carry;
		if(sum / 10 == 0)
			carry = 0;
		else
			carry = (sum / 10) % 10;
		
		addstr[i + 1] = (char)(sum % 10 + 48);
	}
	int num1 = (int)half1[0] - 48;
	int num2 = (int)half2[0] - 48;
		
	int sum = num1 + num2 + carry;
	
	addstr[1] = (char)(sum % 10 + 48);
	addstr[0] = (char)((sum / 10) % 10 + 48);
	
	// printing the sum of the two halves
	printf("The sum of the two halves :- ");
	for(int i = 0; i < (1 + len); i++)
		printf("%c", addstr[i]);
	printf("\n");
	
	// performing the remainder extraction process
	int pow = len;
	int rem = 0;
	
	
	for(int i = 0; i < (1 + len); i++){
		int num = (int)addstr[i] - 48;
		printf("%d\n", powmodp(pow));
		
		rem = ((rem % prime) + (addstr[i] % prime * powmodp(pow)) % prime) % prime ; 
		pow--;
	}
	
	// printing the remainder
	printf("The remainder obtained after dividing with 1009 is :- %d\n", rem);
	return 0;
}
