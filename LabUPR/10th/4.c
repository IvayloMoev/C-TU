#include <stdio.h>

void removeChar(char *s, char ch);

int main()
{
    char s[100];
    char ch;

    printf("Input string: ");
    fgets(s, sizeof(s), stdin);

    printf("Enter symbol to remove: ");
    scanf(" %c", &ch);

    removeChar(s, ch);

    printf("Result: %s\n", s);

    return 0;
}

void removeChar(char *s, char ch)
{
    int i = 0, j = 0;

    while (s[i] != '\0')
    {
        if (s[i] != ch)
        {
            s[j] = s[i];
            j++;
        }
        i++;
    }

    s[j] = '\0';
}