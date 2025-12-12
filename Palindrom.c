#include <stdlib.h>
#include <stdio.h>
#include <string.h>//we will use the library to find the length of the world whıch user entered.
int main() {
	char world[25];
	int checker = 0;//we need to use flag to determine if it is palindromic or not.
	
	printf("PLEASE ENTER A WORLD:");
	scanf_s("%s", world, 25);//here,we dont have to use & to get string from by the user.

	int length = 0;
	length = strlen(world);
	for (int i = 0; length / 2 > i; i++) {
	
		if (world[i] != world[length - 1 - i]) {
			checker++;
		}



	}
	
	if (checker != 0) {
		printf("IT IS NOT A POLINDROMIC STRING!\n");
	}
	else {
		printf("IT IS A POLINDROMIC!\n");
	}



	return 0;
}