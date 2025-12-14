#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int isPolindrom = 0;//we declare a flag to chech it
	char word[100];

	printf("PLEASE ENTER A WORD:");
	scanf_s("%s", word, 100);

	int length_of_theword = strlen(word);

	for (int i = 0; length_of_theword / 2 > i; i++) {
		if (word[i] != '\0' && word[length_of_theword-i-1] != '\0') {
			if (word[i] != word[length_of_theword - i - 1]) {
				isPolindrom++;
				break;
			}
		}
		else {
			break;
		}
	}
	if(isPolindrom==0){
		printf("THE WORD %s IS A POLINDROMIC!", word);
	}
	else  {
		printf("IT IS NOT A POLINDROMIC WORD!");
	}
	
	return 0;
}