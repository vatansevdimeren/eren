#include <stdlib.h>
#include <stdio.h>
int main() {
	int array[10];
	int reversed_array[10];
	printf("TO QIUT PRESS -1\n");
	for (int i = 0; 10 > i; i++) {
		array[i] = 0;
		reversed_array[i] = 0;
	}
	for (int j = 0; 10 > j; j++) {
		printf("PLEASE ENTER ANY NUMBER:");
		
		scanf_s("%d", &array[j]);
		if (array[j] == -1) break;

	}
	
	for (int p = 0; 10 > p; p++) {
		reversed_array[9 - p] = array[p];
	}
	for (int k = 0; 10 > k; k++) {

		if (reversed_array[k] != 0 && reversed_array[k]!=-1) {
			printf("REVERSED ARRAY %d.=%d\n", k + 1, reversed_array[k]);
		}
		

	}
	system("pause");

	return 0;
}