#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	int temp;
	
	if (x <= y) {
		temp = y;
		y = x;
		x = temp;
	}
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}	
}

int main(void) {
	int num1, num2;
	int GCD, LCM;

	scanf("%d %d", &num1, &num2);
	GCD = gcd(num1, num2);
	LCM = (num1 * num2) / GCD;
	printf("%d\n%d", GCD, LCM);

	return 0;
	
}
