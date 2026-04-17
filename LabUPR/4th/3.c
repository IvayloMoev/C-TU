#include <stdio.h>

int main() {
    int num;
    int negativeCount = 0;
    int sumMultiplesOf5 = 0;

    while (1) {
        printf("Въведете число (0 за край): ");
        scanf("%d", &num);

        if (num == 0) {
            break;
        }

        if (num < 0) {
            negativeCount++;
        }

        if (num % 5 == 0) {
            sumMultiplesOf5 += num;
        }
    }

    printf("Брой отрицателни числа: %d\n", negativeCount);
    printf("Сума на кратните на 5: %d\n", sumMultiplesOf5);

    return 0;
}