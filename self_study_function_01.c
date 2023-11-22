#include <stdio.h>

int NumberCompare(int num1, int num2);
int Scanner();
void Message(int num3);

int main(void) {
	int num1, num2, num3;
	num1 = Scanner();
	num2 = Scanner();
	num3 = NumberCompare(num1, num2);
	NumberCompare(num1, num2);
	Message(num3);
	return 0;
}

int NumberCompare(int num1, int num2) {
	int num3 = (num1 > num2) ? num1 : num2;
	return num3;
}

int Scanner(void) {
	int num;
	printf("Hello! I'm Scanner! Insert Number: ");
	scanf_s("%d", &num);
	return num;
}

void Message(int num3) {
	printf("%d is bigger \n", num3);
}