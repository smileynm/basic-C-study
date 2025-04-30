#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int temp = 1;   // 초항상수
    int cur = 0;    // 초항

    scanf("%d", &n);
    if (n % 2 == 0 || n >= 100 || n <= 0) {
        printf("INPUT ERROR");
        return 0;
    }

    if (n == 1)
        printf("%c", 65);
    else if (n > 1 && n % 2 == 1)
    {
        for (int i = 1; i <= (n - 1) / 2; i++) {
            temp = temp + 2 * i - 1;
        }

        for (int j = 1; j <= n; j++) {
            // 첫 열 출력 후 시작
            if (((temp + (j - 1)) % 26) == 0) {             //  A ~ Y 일 경우
                printf("%c", 90);           
            }
            else                                            //  Z 일 경우
                printf("%c", ((temp + (j - 1)) % 26) + 64);

            cur = temp + (j - 1);                           // 첫 열 저장변수
            if (j <= (n + 1) / 2) {                         // 상부 (증가 구간)
                for (int i = 0; i <= j - 2; i++) {
                    cur = cur - (n - 1) + 2 * i;
                    if ((cur % 26) == 0) {                  //  Z 일 경우
                        printf("%2c", 90);
                    }
                    else {                                  //  A ~ Y 일 경우
                        printf("%2c", (cur % 26) + 64);
                    }
                }
            }
            else {                                          // 하부 (감소 구간)
                for (int i = 0; i <= n - j - 1; i++) {
                    cur = cur - (n - 1) + 2 * i;
                    if ((cur % 26) == 0) {                  //  Z 일 경우
                        printf("%2c", 90);
                    }
                    else {                                  //  A ~ Y 일 경우
                        printf("%2c", (cur % 26) + 64);
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
