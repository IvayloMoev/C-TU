#include <stdio.h>

int main() {
    double a, b;

    // Въвеждане на две реални числа
    printf("Въведете две реални числа:\n");
    scanf("%lf %lf", &a, &b);

    // Изчисления
    double sum = a + b;
    double difference = a - b;
    double product = a * b;

    // Извеждане с точност до 3 знака след десетичната запетая
    printf("Сума: %.3lf\n", sum);
    printf("Разлика: %.3lf\n", difference);
    printf("Произведение: %.3lf\n", product);

    return 0;
}