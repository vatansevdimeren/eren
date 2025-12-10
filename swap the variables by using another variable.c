#include <stdlib.h>
#include <stdio.h>
int main() {
	int number0 = 0, number1 = 0;
	int temp = 0;//we have already used one temporory variable to cath the value of the first integer. 
	//by using this method we understand that we shouldnt fall out the value of any variable so we can use a new variable to keep the value.
	
	printf("ENTER THE FIRST VALUE :");
	scanf_s("%d", &number0);
	
	printf("ENTER THE SECOND VALUE :");
	scanf_s("%d", &number1);
	
	printf("THE FIRST VALUE IS : %d\n",number0);
	printf("THE SECOND  VALUE IS : %d\n",number1);
	
	
	temp = number0;
	number0 = number1;
	number1 = temp;
	
	printf("THE SWITCHED  FIRST VALUE IS : %d\n",number0);

	return 0;
}