#include <stdlib.h>
#include <stdio.h>
int main() {
	int number = 0;

	printf("PLEASE ENTER A NUMBER WHICH YOU WANT TO LEARN PRIME NUMBERS TO THE YOU ENTERED NUMBER:");
	scanf_s("%d", &number);
	if (number < 0) return 0;
	else if (number == 2) { printf("2 IS A SPECICAL PRIME NUMBER!\n"); system("pause"); }

	//we need to use flag to the determine if it is prime or not 
	//I am sorry for my bad english :/
	int isPrime = 0;//0 represents not prime 1 is prime
	for (int i = 3; number>= i; i++) {
		isPrime = 0;
		for (int j = 2; i > j; j++)
		{
			if ((i % j) == 0) {
				//the number isnt a prime so we put here break not to continue to the loop
				isPrime = 1;
				
			}
		}
		if (isPrime == 0) {
			printf("THE NUMBER IS A PRIME :%d\n", i);
		}
		else {
			//we dont need to write anything
		}
	}

	return 0;
}