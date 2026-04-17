#include <stdio.h>

int main() {
    int num;
    int count = 0;
    int sum = 0;

    printf("Въвеждайте цели числа (0 за край):\n");

    while (1) {
        int result = scanf("%d", &num);

        // Проверка дали е въведено число
        if (result != 1) {
            printf("Грешен вход! Моля въведете цяло число.\n");
            // изчистване на буфера
            while (getchar() != '\n');
            continue;
        }

        if (num == 0) {
            break;
        }

        sum += num;
        count++;
    }

    if (count > 0) {
        double average = (double)sum / count;
        printf("Средно аритметично: %.3lf\n", average);
    } else {
        printf("Няма въведени числа!\n");
    }

    return 0;
}