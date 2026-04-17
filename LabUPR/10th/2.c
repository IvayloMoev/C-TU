#include <stdio.h>
#include <ctype.h> // за islower, isupper, tolower, toupper

int main() {
    char str[100];
    int i;

    printf("Vavedete string: ");
    fgets(str, sizeof str, stdin);

    for (i = 0; str[i] != '\0'; i++) {

        if (islower(str[i])) {
            str[i] = toupper(str[i]); // малка → главна
        }
        else if (isupper(str[i])) {
            str[i] = tolower(str[i]); // главна → малка
        }
        // всички други символи остават без промяна
    }

    printf("Rezultat: %s", str);

    return 0;
}