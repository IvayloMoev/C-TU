#include <stdio.h>

int main()
{
    float input;
    int cnt, k;
    float min;
    int min_num;

    printf("Enter count: ");
    scanf("%d", &cnt);

    printf("Enter value: ");
    scanf("%f", &input);

    min = input;
    min_num = k = 1;

    while (k < cnt)
    {
        printf("Enter value: ");
        scanf("%f", &input);
        k++;

        if (input < min)
        {
            min = input;
            min_num = k;
        }
    }

    printf("Minimum is %.2f.\n", min);
    printf("Number is %d.\n", min_num);

    return 0;
}