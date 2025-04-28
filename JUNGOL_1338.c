#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int temp = 0;
    scanf("%d", &n);

    for (int j = 1; j <= n; j++)
    {
        for (int space = 1; space <= n-j; space++)
            printf("  ");
        for (int i = 0; i <= j - 1; i++)
        {
            if (i == 0)
            {
                temp = j;
                if ((j%26)==0)    // Z일 경우
                {
                    printf("%c ", 90);
                }
                else            // Z 아닐경우
                {
                    printf("%c ", (j % 26) + 64);
                }
                    
            }
            else
            {
                if (((temp + (n - i)) % 26) == 0)    // Z일 경우
                {
                    printf("%c ", 90);
                }
                else            // Z 아닐경우
                {
                    printf("%c ", ((temp + (n - i)) % 26) + 64);
                }
                temp = temp + (n - i);
            }
        }
        printf("\n");
    }

    return 0;
}
