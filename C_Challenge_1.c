#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/* Challenge 1-1 */
//////////////////////////////////////////////////////////////////
/*
int main(void) {
	int num;
	scanf_s("%d", &num);								// 사용자가 정수를 직접 입력

	printf("%#x", num);									// #x 지시자를 통해 값 변환 없이 바로출력
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-2 */
//////////////////////////////////////////////////////////////////
/*
void mul_table(int val_1, int val_2) {					// 구구단 출력 함수
	int temp;
	if (val_1 >= val_2) {								// 대소 구별
		temp = val_1;									// (순서에 상관없이 동일한 결과 출력을 위해)
		val_1 = val_2;
		val_2 = temp;
	}
	for (int i = val_1; i <= val_2; i++) {				// 연산 후 구구단 출력
		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %2d\n", i, j, i * j);
		}
		printf("\n");
	}
}

int main(void) {
	int num1, num2;
	scanf_s("%d %d", &num1, &num2);						// 사용자에게 연산할 범위 입력받음
	mul_table(num1, num2);								// 구구단 출력 함수에 변수 전달

	return 0;
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-3 */
//////////////////////////////////////////////////////////////////
/*
void compare_max(int *val_1, int *val_2) {		// 대소 구별 후 값 변환 함수
	int temp;									// (입력순서에 상관없이 동일한 출력을 위해)
	if (*val_1 <= *val_2) {
		temp = *val_1;
		*val_1 = *val_2;
		*val_2 = temp;
	}
}
int cal_gcd(int val_1, int val_2) {				// 최대공약수 계산 함수 (유클리드 호제법 사용)
	int r = val_1 % val_2;						// 나머지 계산 변수
	int temp = val_2;
	int result;
	if (r != 0) {								// r값이 0이라면 연산과정 skip
		do {
			result = temp % r;
			temp = r;
			r = result;
		} while (r != 0);						// r값이 0이 될때까지 반복
		return temp;
	}
	return temp;

}
int main(void) {

	int num1, num2;
	scanf_s("%d %d", &num1, &num2);				

	compare_max(&num1, &num2);					// 대소 구별 후 값 변환 함수

	printf("%d", cal_gcd(num1, num2));

	return 0;
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-4 */
//////////////////////////////////////////////////////////////////
/*
int main(void) {
	int total = 3500;																		// 예산 선언
	int cream = 500;																		// 크림빵 가격
	int shrimp = 700;																		// 새우깡 가격
	int coke = 400;																			// 콜라 가격

	total -= (cream + shrimp + coke);														// 각 상품을 하나이상 구매하고 시작

	for (int i = 0; i * cream <= total; i++) {												// 크림빵 개수 계산
		for (int j = 0; j * shrimp <= total; j++) {											// 새우깡 개수 계산
			for (int k = 0; k * coke <= total; k++) {										// 콜라 개수 계산
				if ((i * cream) + (j * shrimp) + (k * coke) == total) {						// 가격 총합이 예산과 동일할 경우만 출력
					printf("크림빵 %d개, 새우깡 %d개, 콜 라 %d개\n", i + 1, j + 1, k + 1);	// 먼저 구매했던 1개씩 더한 후 출력
				}
			}
		}
	}
	return 0;
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-5 */
//////////////////////////////////////////////////////////////////
/*
int main(void) {
	int prime[10] = { 2, };											// 소수로 판정된 수들을 담을 배열 선언 (2로 시작)
	int cnt = 1;													// 소수로 판정된 수들의 개수를 가리키는 변수
	int number = 2;
	int flag = 2;

	while (cnt < 10) {
		for (int i = 2; i < number; i++) {
			if (number % i == 0) {
				flag = 2;
				continue;
			}
			else {
				flag++;
			}
			if (flag >= number) {
				prime[cnt++] = number;
			}
		}
		number++;
		flag = 2;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", prime[i]);
	}

	return 0;
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-6 */
//////////////////////////////////////////////////////////////////
/*
int main(void) {
	int time;											// 입력받을 시간 변수 선언
	int hour, min, sec;									// 계산된 시간을 담을 변수 선언
	scanf("%d", &time);
	
	sec = time % 60;									// 초 계산
	hour = time / 3600;									// 시간 계산
	min = (time % 3600) / 60;							// 분 계산

	printf("[h: %d, m: %d, s: %d]", hour, min, sec);	// 시간, 분, 초 순서로 출력

	return 0;
}*/
//////////////////////////////////////////////////////////////////





/* Challenge 1-7 */
//////////////////////////////////////////////////////////////////
/*
int main(void) {
	int n;
	int temp = 1;						// 시작 수: 1로 설정
	int cnt = 0;						// 반복 횟수 판단할 변수 선언
	scanf("%d", &n);

	while (temp*2 <= n) {				// 현재 수에 2를 곱했을 때, n을 넘어가지 않도록 제한
		temp = 2 * temp;				// 제곱 실행
		cnt++;							// 반복 횟수 증가
	}

	printf("%d", cnt);
	

	return 0;
}*/





/* Challenge 1-8 */
//////////////////////////////////////////////////////////////////
/*
int square_two(int n) {									// 거듭제곱 재귀함수 
	if (n > 0) {
		return 2 * square_two(n - 1);					// n이 0이 될때까지 2를 계속 곱함
	}
	else
		return 1;										// n이 0에 도달하면 초항을 1로 설정
}

int main(void) {
	int number;											// 사용자에게 입력받을 변수 선언
	int result;											// 결과값을 저장할 변수 선언
	printf("정수 입력: ");
	scanf("%d", &number);

	result = square_two(number);						// square_two 함수의 결과값을 result에 저장

	printf("2의 %d승은 %d", number, result);

	return 0;
}*/
//////////////////////////////////////////////////////////////////
