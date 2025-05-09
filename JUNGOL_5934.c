#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n;
	scanf("%d", &n);
	if (n > 100 || n % 2 == 0 || n <= 0) {						// 허용 외 범위일 경우
		printf("INPUT ERROR!");									// 에러메시지 출력
		return 0;												// 프로그램 종료
	}
	
	for (int i = 1; i <= n; i++) {								// n 행
		if (i <= (n + 1) / 2) {									// 상층부 (i값이 n+1 의 반 이하일 경우)
			for (int j = 0; j < i - 1; j++) {					// 공백 출력 (i-1 이 될때까지)
				printf(" ");
			}
			for (int j = 1; j <= ((n + 3) / 2) - i; j++) {		// 별 출력 (현재 i값에 비례하여 점진적 감소)
				printf("*");
			}
			printf("\n");										// 다음 줄
		}
		else {
			for (int j = 1; j < (n + 1) / 2; j++) {				// 공백 출력 (이전값 유지하여 일정하게 출력)
				printf(" ");
			}
			for (int j = 1; j <= ((1 - n) / 2) + i; j++) {		// 별 출력 (i값에 비례하여 점진적 증가)
				printf("*");
			}

			printf("\n");										// 다음 줄
		}

	}
	return 0;
}
