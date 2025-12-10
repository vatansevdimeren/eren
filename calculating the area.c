#include <stdlib.h>
#include <stdio.h>
#define PI 3.14

int main() {
	float  radius = 0;
	double area = 0;
	double circumference = 0;
	
	printf("PLEASE ENTER THE RADIUS OF THE CIRCLE:");
	scanf_s("%f", &radius);

	area = PI * radius * radius;
	circumference = 2 * PI * radius;

	printf("THE ARE OF THE CIRCLE IS :%.3f\n",area);
	printf("THE CIRFUMFERENCE OF THE CIRCLE IS :%.3f\n", circumference);

	return 0;
}