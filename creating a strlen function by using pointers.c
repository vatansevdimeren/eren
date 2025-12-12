#include <stdlib.h>
#include <stdio.h>
int main() {
	char array[50] = "IKNOWYOUWHATCHMERIDVAN";
	char* ptri;
	ptri = array;
	int counter = 0;
	while (*ptri != '\0') {
		counter++;
		ptri++;
	}
	printf("%d", counter);


	return 0;
}