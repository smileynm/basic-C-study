#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


unsigned long long cal_gcd(unsigned long a, unsigned long b) {
    unsigned long long temp, remainder;
    if (a <= b) {
        temp = a;
        a = b;
        b = temp;
    }
    remainder = a % b;
    if (remainder == 0)
        return b;
    else
        return cal_gcd(b, a % b);

}

unsigned long long cal_lsb(unsigned long long a, unsigned long long b) {
    return (a * b) / cal_gcd(a, b);
}

int main(void) {
    unsigned long long P, V, K;
    unsigned long long LSB;
    unsigned long long GCD;
    unsigned long long A = 0;
    unsigned long long B = 0;
    unsigned long long C = 0;
    unsigned long long  D = 0;

    scanf("%llu %llu %llu", &P, &V, &K);
    GCD = cal_gcd(P + 1, V + 1);
    LSB = cal_lsb(P + 1, V + 1);
    B = K / cal_lsb(P + 1, V + 1);
    C = (K / (V + 1)) - B;
    D = (K / (P + 1)) - B;
    A = K - (B + C + D);

    printf("%llu %llu %llu %llu", A, B, C, D);
    
    return 0;
}
