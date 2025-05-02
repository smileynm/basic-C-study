#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cal_gcd(int x, int y) {
	int result;
	if (x <= y) {
		int temp;
		temp = x;
		x = y;
		y = temp;
	}
	while (y != 0) {
		int temp;
		temp = y;
		y = x % y;
		x = temp;
	}
	return x;
}

int cal_lcm(int x, int y, int gcd) {
	return (x * y) / gcd;
}

int main(void) {
	int n;
	int GCD, LCM;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	GCD = LCM = arr[0];
	for (int i = 1; i < n; i++) {
		GCD = cal_gcd(GCD, arr[i]);
		LCM = LCM / cal_gcd(LCM, arr[i]) * arr[i];
	}
	//for (int i = 1; i < n - 1; i++) {
	//	LCM = LCM * arr[i] / GCD;
	//}
	printf("%d %d", GCD, LCM);

	return 0;
}
