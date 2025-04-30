#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int j = n * n; j >= (n * n) - n + 1; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (((j - (i * n)) % 26) != 0) {
                printf("%c ", ((j - (i * n)) % 26) + 64);
            }
            else
                //printf("%c ", 90);
                printf("%c ", 90);
        }
        printf("\n");
    }
    return 0;
}
