#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n <= 0 || n > 50 || n % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}
	for (int i = 0; i < n; i++) {							// 열 변수 i

		for (int j = 1; j <= i; j++) {
			printf("  ");
		}

		for (int j = 0; j < (2 * (n - i)) - 1; j++) {		// 행 출력 j
			printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}
