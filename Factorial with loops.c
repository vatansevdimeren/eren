#include <stdlib.h>
#include <stdio.h>
int main() {
	int number = 0;
	long long int product = 1;

	printf("PLEASE ENTER A NUMBER:");
	scanf_s("%d", &number);
	if (number < 0) { system("pause"); }
	if (number == 0 || number == 1) {
		printf("THE RESULT OF 0 AND 1 FACTORIAL IS EQUAL TO : 1");
		system("pause");
	}

	for (int i = 1; number >= i; i++) {
		product *= i;
	}
	printf("%d! = %lld", number, product);

	return 0;
}