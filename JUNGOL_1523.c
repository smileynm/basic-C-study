#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void make_1(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}
}

void make_2(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i; j--) {
			printf("*");
		}
		printf("\n");
	}
}

void make_3(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= 2 * i - 1; j++) {
			printf("*");
		}
		for (int j = 0; j < n - i; j++) {
			printf(" ");
		}
		printf("\n");
	}
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	if ((n > 100) || (n < 0) || (m < 1) || (m > 3)) {
		printf("INPUT ERROR!");
		return 0;
	}
	switch (m) {
	case 1: make_1(n);
		break;
	case 2: make_2(n);
		break;
	case 3: make_3(n);
		break;
	default: printf("INPUT ERROR!");
		return 0;
	}
	
	return 0;
}
