#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, C, result, temp;
    int num[10] = { 0, };
    scanf("%d %d %d", &A, &B, &C);

    result = A * B * C;

    // 0번째 자리
    if(result >= 100000000){
        temp = result / 100000000;
        num[temp]++;
    }
    // 1번째 자리
    if(result >= 10000000){
       temp = (result / 10000000) % 10;
       num[temp]++;
    }
    // 2번째 자리
    if(result >= 1000000){
    temp = (result / 1000000) % 10;
    num[temp]++;
    }
    // 3번째 자리
    if(result >= 100000){
    temp = (result / 100000) % 10;
    num[temp]++;
    }

    // 4번째 자리
    if(result >= 10000){
    temp = (result / 10000) % 10;
    num[temp]++;
    }

    // 5번째 자리
    if(result >= 1000){
    temp = (result / 1000) % 10;
    num[temp]++;
    }
    // 6번째 자리
    if(result >= 100){
    temp = (result / 100) % 10;
    num[temp]++;
    }
    // 7번째 자리
    if(result >= 10){
    temp = (result / 10) % 10;
    num[temp]++;
    }
    // 8번째 자리
    temp = result % 10;
    num[temp]++;

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", num[i]);
    }

    return 0;
}
