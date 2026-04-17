#include <stdio.h>
#include <string.h>

int main() {
    char str[100], ch1, ch2;
    int i, ctr1 = 0, ctr2 = 0;

    printf("Vavedete string: ");
    fgets(str, sizeof str, stdin);
    str[strlen(str) - 1] = '\0';

    printf("Vavedete purvi simvol: ");
    scanf(" %c", &ch1);

    printf("Vavedete vtori simvol: ");
    scanf(" %c", &ch2);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch1)
            ctr1++;
        if (str[i] == ch2)
            ctr2++;
    }

    printf("Simvol '%c' se sreshta: %d puti\n", ch1, ctr1);
    printf("Simvol '%c' se sreshta: %d puti\n", ch2, ctr2);

    if (ctr1 > ctr2) {
        printf("Simvol '%c' se sreshta po-chesto.\n", ch1);
    } else if (ctr2 > ctr1) {
        printf("Simvol '%c' se sreshta po-chesto.\n", ch2);
    } else {
        printf("Dvata simvola se sreshtat ednakav broi puti.\n");
    }

    return 0;
}