#include <stdlib.h>
#include <stdio.h>
int main() {
	int value[10];

	for (int i = 0; 10 > i; i++) {
		printf("PLEASE ENTER THE %d. NUMBER :", i + 1);
		scanf_s("%d", &value[i]);
	}
	
	int temp = 0;//we need to use flag.
	
	for (int i = 0; 10 > i; i++) {
		for (int j = 0; 9-i > j; j++) {
			if (value[j] > value[j + 1]) {
				temp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = temp;
			}
		}
	}
	for (int i = 0; 10 > i; i++) {
		printf("%d\n", value[i]);
	}

	return 0;
}