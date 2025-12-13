#include <stdlib.h>
#include <stdio.h>
int main() {
	char message[100];
	int key = 0;
	
	printf("PLEASE ENTER WHAT DO YOU WANNA ENCRYPTO:");
	scanf_s("%s", message,100);

	printf("PLEASE ENTER THE VALUE OF KEY:");
	scanf_s("%d", &key);

	for (int i = 0; 100 > i; i++) {
		if (message[i] != '\0') {
			message[i] = message[i] + key;
		}
		else {
			break;
		}
	}
	printf("NEW PASSWORD IS %s", message);


	return 0;
}