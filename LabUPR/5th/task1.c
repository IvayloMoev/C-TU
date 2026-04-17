#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, *p = NULL;

    printf("Vavedete broi elementi: ");
    scanf("%d", &n);

    p = (int *)calloc(n, sizeof(int)); // calloc вместо malloc

    if (p == NULL)
    {
        printf("error!");
        return 1;
    }

    // Въвеждане
    for (i = 0; i < n; i++)
    {
        printf("element %d = ", i);
        scanf("%d", (p + i));
    }

    printf("Vie vavedohte:\n");

    // Извеждане
    for (i = 0; i < n; i++)
    {
        printf("element %d = %d\n", i, *(p + i));
    }

    printf("Razmer na bloka: %lu bytes\n", n * sizeof(int));

    free(p);
    p = NULL;

    printf("Pametta e svobodna!\n");

    return 0;
}