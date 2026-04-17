#include <stdio.h>

long long factorial_iterative(int n) {
    if (n < 0) {
        printf("Error: n must be positive\n");
        return -1;
    }

    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}
long long factorial_recursive(int n) {
    if (n < 0) {
        printf("Error: n must be positive\n");
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    return n * factorial_recursive(n - 1);
}
double power_iterative(double base, int exp) {
    if (exp < 0) {
        printf("Error: power must be not negative\n");
        return -1;
    }

    double result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}
double power_recursive(double base, int exp) {
    if (exp < 0) {
        printf("Error: power must be not negative\n");
        return -1;
    }

    if (exp == 0) {
        return 1;
    }

    return base * power_recursive(base, exp - 1);
}
int main() {
    int n = 5;

    printf("factorial(iterative): %lld\n", factorial_iterative(n));
    printf("factorial(recursive): %lld\n", factorial_recursive(n));

    double a = 2.5;
    int b = 3;

    printf("Power(iterative): %.2f\n", power_iterative(a, b));
    printf("Power(recursive): %.2f\n", power_recursive(a, b));

    return 0;
}