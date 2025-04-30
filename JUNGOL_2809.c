#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

    int N, cnt = 0;
    int div[100000];

    scanf("%d", &N);


    for (int i = 1; i <= sqrt(N); i++)
    {
        if (N % i == 0) {
            div[cnt++] = i;
            if (i != (N / i))
                div[cnt++] = N / i;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = cnt - 1; j >= 0; j--) {
            int temp;
            if (div[j] <= div[j - 1]) {
                temp = div[j];
                div[j] = div[j - 1];
                div[j - 1] = temp;
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        printf("%d ", div[i]);
    }
    return 0;
}
