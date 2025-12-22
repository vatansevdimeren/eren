#include <stdlib.h>
#include <stdio.h>
int main() {
	int array[5];
	for (int i = 0; 5 > i; i++) {
		printf("please enter %d. number:", i + 1);
		scanf_s("%d", &array[i]);
	}
	int* ptr = &array[0];
	int max = 0;
	int min = 0;
	for (int a=0; 5 > a; a++) {
		if (*ptr > max) max = *ptr;
		if (*ptr < min)min = *ptr;
		ptr++;
	}
	printf("the max value is:%d\n", max);
	printf("the min value is:%d\n", min);


	return 0;
}