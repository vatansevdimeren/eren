#include <stdlib.h>
#include <stdio.h>
int main() {
	int matrix[2][3];
	for (int a = 0; 2 > a; a++) {
		for (int b = 0; 3 > b; b++) {
			printf("PLEASE ENTER NUMBERS:");
			scanf_s("%d", &matrix[a][b]);
		}
	}
	printf("the normal matrix is printing....\n");
	for (int i = 0; 2 > i; i++) {
		for (int j = 0; 3 > j; j++) {
			printf("%3d", matrix[i][j]);
		}
		printf("\n");
	}
	printf("I Transporonz the matrix and it is printing too...\n");
	for (int i = 0; 3 > i; i++) {
		for (int j = 0; 2 > j; j++) {
			printf("%3d", matrix[j][i]);
		}
		printf("\n");
	}
	return 0;
}