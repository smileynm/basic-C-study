#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n <= 0 || n > 100 || n % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i <= (n + 1) / 2) {						// 상층부
			for (int j = 0; j < i - 1; j++) {			// 공백 출력
				printf(" ");
			}
			for (int j = 1; j <= 2 * i - 1; j++) {			// 별 출력
				printf("*");
			}
			printf("\n");
		}
		else {								// 하층부
			for (int j = 0; j < n - i; j++) {			// 공백 출력
				printf(" ");
			}
			for (int j = 1; j <= 2 * (n - i) + 1; j++) {		// 별 출력
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
