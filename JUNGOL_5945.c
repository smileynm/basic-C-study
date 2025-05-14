#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int n, cnt = 1;
	scanf("%d", &n);									          // 사용자로부터 정수 입력
	if (n <= 0 || n > 50 || n % 2 == 0) {				// n이 50이하의 홀수가 아니라면
		printf("INPUT ERROR!");							      // 에러 문구 출력 후
		return 0;										              // 프로그램 종료
	}

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {								          // 홀수 행
			for (int j = 1; j <= i; j++) {		
				printf("%d ", ((cnt - 1) * i) + j);
			}
			printf("\n");
		}
		else {											              // 짝수 행
			for (int j = 0; j < i; j++) {
				printf("%d ", ((i + 1) * cnt) - j);
			}
			printf("\n");
			cnt++;
			
		}
	}


	return 0;
}
