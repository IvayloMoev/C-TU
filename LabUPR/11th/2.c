#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 5
#define STEP 5

char *M[SIZE] = {
    "1-Vavejdane",
    "2-Izvejdane",
    "3-Sortirane",
    "4-Suma v interval",
    "5-Izhod"
};

int* input(int *br, int *mas);
void out(int br, int *mas);
void sort(int br, int *mas);
int sumInterval(int br, int *mas, int a, int b);

int main()
{
    int cod, n = 0, *p = NULL, flag = 0;
    int a, b;

    do
    {
        for(int i = 0; i < SIZE; i++)
            puts(M[i]);

        printf("Izberete kod: ");
        scanf("%d", &cod);

        switch(cod)
        {
            case 1:
                p = input(&n, p);
                flag = 1;
                break;

            case 2:
                if(flag)
                    out(n, p);
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 3:
                if(flag)
                {
                    printf("Nachalen masiv:\n");
                    out(n, p);
                    sort(n, p);
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 4:
                if(flag)
                {
                    printf("Vavedete nachalo na intervala: ");
                    scanf("%d", &a);

                    printf("Vavedete krai na intervala: ");
                    scanf("%d", &b);

                    printf("Suma v interval [%d, %d] = %d\n",
                           a, b, sumInterval(n, p, a, b));
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 5:
                if(p != NULL)
                {
                    free(p);
                    printf("Osvobojdavane na pametta!\n");
                    p = NULL;
                }
                exit(1);

            default:
                printf("Nekorekten kod!");
                _getch();
        }

        system("cls");

    } while(1);

    return 0;
}

int* input(int *br, int *mas)
{
    int n = 5, i = 0, *p1 = NULL;

    mas = (int*)calloc(n, sizeof(int));

    if(mas == NULL)
    {
        printf("Niama pamet!");
        exit(1);
    }

    printf("Vavejdane na masiv. Natisnete 0 za krai!\n");

    do
    {
        if(i < n)
        {
            printf("[%d] = ", i);
            scanf("%d", (mas + i));
            i++;
        }
        else
        {
            n += STEP;

            p1 = (int*)realloc(mas, n * sizeof(int));

            if(p1 == NULL)
            {
                printf("Niama pamet!");
                exit(1);
            }

            mas = p1;

            printf("[%d] = ", i);
            scanf("%d", (mas + i));
            i++;
        }

    } while(*(mas + (i - 1)) != 0);

    *br = i - 1;
    return mas;
}

void out(int br, int *mas)
{
    for(int i = 0; i < br; i++)
        printf("[%d] = %d\n", i, *(mas + i));
}

void sort(int br, int *mas)
{
    int i, j;
    int x;

    for(i = 1; i < br; i++)
    {
        x = *(mas + i);

        for(j = i - 1; j >= 0; j--)
        {
            if(x < *(mas + j))
                *(mas + j + 1) = *(mas + j);
            else
                break;
        }

        *(mas + j + 1) = x;
    }

    printf("Sortiran masiv:\n");
    out(br, mas);
}

int sumInterval(int br, int *mas, int a, int b)
{
    int sum = 0;

    for(int i = 0; i < br; i++)
    {
        if(*(mas + i) >= a && *(mas + i) <= b)
            sum += *(mas + i);
    }

    return sum;
}