#include <stdio.h>

int main() {
    double beg, end, delta, m, a, b;

    printf("Въведете beg: ");
    scanf("%lf", &beg);

    // Проверка beg < end
    do {
        printf("Въведете end (трябва да е по-голямо от beg): ");
        scanf("%lf", &end);
    } while (end <= beg);

    printf("Въведете delta: ");
    scanf("%lf", &delta);

    printf("Въведете m: ");
    scanf("%lf", &m);

    // Проверка дали m е в интервала
    while (m < beg || m > end) {
        printf("m трябва да е в интервала [%.2lf; %.2lf]. Въведете отново m: ", beg, end);
        scanf("%lf", &m);
    }

    printf("Въведете a и b: ");
    scanf("%lf %lf", &a, &b);

    printf("\nТаблица на функцията:\n");
    printf("x\t\ty\n");

    for (double x = beg; x <= end; x += delta) {

        // Проверка за деление на нула
        if (x > m && (4 - x) == 0) {
            continue;
        }

        double y;

        if (x <= m) {
            y = b + x;
        } else {
            y = (a * x) / (4 - x);
        }

        printf("%.3lf\t%.3lf\n", x, y);
    }

    return 0;
}