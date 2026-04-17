    #include <stdio.h>

int main() {
    char str[100];
    int i, j = 0;

    printf("Vavedete string: ");
    fgets(str, sizeof str, stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0'; // край на новия стринг

    printf("Rezultat: %s", str);

    return 0;
}