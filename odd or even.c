#include <stdlib.h>
#include <stdio.h>
int main() {
	int number = 0;
	
	printf("PLEASE ENTER A NUMBER WHICH YOU WANT TO FIND OUT IF IT IS ODD OR EVEN:");
	scanf_s("%d", &number);

	if (number % 2 == 0) {
		printf("THE NUMBER %d MUST BE EVEN!\n",number);
	}
	else {
		printf("THE NUMBER %d MUST BE ODD!\n",number);
	}

	return 0;
}