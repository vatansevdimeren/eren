#include <stdlib.h>
#include <stdio.h>
int main() {
	char array[1000];
	for (int i = 0; 1000 > i; i++) {
		array[i] = '\0';
	}
	printf("please enter a word without any spaces:");
	scanf_s("%s", array, 1000);

	char* ptr = &array;
	int length_of_word = 0;
	for (int i = 0; 1000 > i; i++) {
		if (*ptr != '\0') length_of_word++;
		else   break;
		ptr++;
	}
	
	printf("the lentg of the word is :%d\n", length_of_word);
	printf("reversed word is:");
	ptr--;
	for  (length_of_word; length_of_word>0; length_of_word--) {
		printf("%c", *(ptr));
		ptr--;
	}


	return 0;
}