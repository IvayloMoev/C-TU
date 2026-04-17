#include <stdio.h>

int main() {
    int a, b, sum = 0;

    printf("Въведете a: ");
    scanf("%d", &a);

    // Проверка дали a < b
    do {
        printf("Въведете b (трябва да е по-голямо от a): ");
        scanf("%d", &b);
    } while (b <= a);

    // Изчисляване на сумата
    for (int i = a; i <= b; i++) {
        sum += i;
    }

    printf("Сумата на числата в интервала [%d; %d] е: %d\n", a, b, sum);

    return 0;
}