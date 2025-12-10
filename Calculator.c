#include <stdlib.h>
#include <stdio.h>
int main() {
	
	do {
		int user_wants = 0;
		double number1 = 0, number2 = 0;
		
		
		printf("1-SUM\n2-MINUS\n3-PRODUCT\n4-DIVIDE\n5-QIUT\n");
		
		printf("PLEASE CHOSE ONE OF THEM:");
		scanf_s("%d", &user_wants);
	
		switch (user_wants) {
		double execution = 0;
		case 1:
			printf("PLEASE ENTER THE FIRST NUMBER:");
			scanf_s("%lf", &number1);
			printf("PLEASE ENTER THE SECOND NUMBER:");
			scanf_s("%lf", &number2);
			execution = number1 + number2;
			printf("THE SUM OF THEM IS : %0.3lf\n", execution);
			break;
		case 2:
			printf("PLEASE ENTER THE FIRST NUMBER:");
			scanf_s("%lf", &number1);
			printf("PLEASE ENTER THE SECOND NUMBER:");
			scanf_s("%lf", &number2);
			execution = number1 - number2;
			printf("THE MINUS OF THEM IS : %0.3lf\n", execution);
			break;
		case 3:
			printf("PLEASE ENTER THE FIRST NUMBER:");
			scanf_s("%lf", &number1);
			printf("PLEASE ENTER THE SECOND NUMBER:");
			scanf_s("%lf", &number2);
			execution = number1 * number2;
			printf("THE PRODUCT OF THEM IS : %0.3lf\n", execution);
			break;
		case 4:
			printf("PLEASE ENTER THE FIRST NUMBER:");
			scanf_s("%lf", &number1);
			printf("PLEASE ENTER THE SECOND NUMBER:");
			scanf_s("%lf", &number2);
			if (number2 == 0) {
				printf("ANY NUMBER CANT BE DIVIDED BY 0!!\n");
				break;
			}
			execution = number1 / number2;
			printf("THE DIVIDE OF THEM IS : %0.3lf\n", execution);
			break;
		case 5:
			printf("THE PROGRAM IS CLOSING!\n");
			system("pause");
			return 0;
		default:
			printf("INVALID INPUT!!\n");
			break;
		}
	} while (1);




	return 0;
}