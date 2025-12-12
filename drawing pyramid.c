#include <stdlib.h>
#include <stdio.h>
int main() {
	int high = 0;

	printf("PLEASE ENTER THE SIZE OF HIGH OF THE PYRAMID:");
	scanf_s("%d", &high);

	for (int i = 0; high > i; i++) {
		for (int j = 0; high - 1 -i > j; j++) {
			printf(" ");
		}
		for (int p = 0; p < ((2 * i) +1); p++) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");

	return 0;
}