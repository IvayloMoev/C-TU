#include <stdio.h>

int main()
{
    int input, sum = 0;

    while (1)
    {
        printf("Enter value: ");
        scanf("%d", &input);

        if (input == -999)
        {
            break; // прекъсване при специалната стойност
        }

        sum += input;
    }

    printf("The sum is: %d.\n", sum);

    return 0;
}