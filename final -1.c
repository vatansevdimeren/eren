#include <stdlib.h>
#include <stdio.h>
int main() {
	int notes[10];

	for (int i = 0; 10 > i; i++) {
		printf("PLEASE ENETER %d student's note:", i + 1);
		scanf_s("%d", &notes[i]);
	}
	int temp = 0;
	for (int k = 0; 10 > k; k++) {
		for (int i = 0; 9 > i; i++) {
			if (notes[i + 1] > notes[i]) {
				temp = notes[i + 1];
				notes[i + 1] = notes[i];
				notes[i] = temp;
				temp = 0;
			}
		}
	}
	int sum_of_notes = 0;
	for (int i = 0; 10 > i; i++) {
		sum_of_notes += notes[i];
	}
	printf("THE MAX NOTE IS :%d\n", notes[0]);
	printf("THE MIN NOTE IS :%d\n", notes[9]);
	printf("THE AVARAGE OF THE LECTURE IS:%d\n", sum_of_notes / 10);
	return 0;
}