#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, newSize;
    int *p, *p1 = NULL;

    printf("Vavedete nachalen broi elementi: ");
    scanf("%d", &n);

    p = (int *)calloc(n, sizeof(int));

    if (p == NULL)
    {
        printf("error!");
        return 1;
    }

    printf("Nachalen blok:\n");
    for (i = 0; i < n; i++)
    {
        printf("element %d = %d\n", i, *(p + i));
    }

    printf("Vavedete chisla v bloka:\n");
    for (i = 0; i < n; i++)
    {
        printf("element %d = ", i);
        scanf("%d", (p + i));
    }

    printf("Vie vavedohte:\n");
    for (i = 0; i < n; i++)
    {
        printf("element %d = %d\n", i, *(p + i));
    }

    // 🔥 нов размер от потребителя
    printf("Vavedete nov razmer: ");
    scanf("%d", &newSize);

    p1 = (int *)realloc(p, newSize * sizeof(int));

    if (p1 == NULL && newSize != 0)
    {
        printf("error!");
        free(p);
        return 1;
    }

    p = p1;

    printf("Nov blok:\n");

    for (i = 0; i < newSize; i++)
    {
        printf("element %d = %d\n", i, *(p + i));
    }

    printf("Razmer na bloka: %lu bytes\n", newSize * sizeof(int));

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }

    printf("Pametta e svobodna!\n");

    return 0;
}