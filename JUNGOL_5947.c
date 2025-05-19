#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int counter;
    scanf("%d", &n);
    counter = (n + 1) / 2;
    if (n <= 0 || n > 50 || n % 2 == 0) {
        printf("INPUT ERROR!");
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (i <= (n + 1) / 2) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
        else {
            for (int j = 1; j < counter; j++) {
                printf("%d ", j);
            }
            counter--;
            printf("\n");
        }
    }
    return 0;
}
