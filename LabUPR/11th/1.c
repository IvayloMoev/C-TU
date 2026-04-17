#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 7

char *M[SIZE] = {
    "1-Vavejdane",
    "2-Izvejdane",
    "3-Suma",
    "4-Max",
    "5-Min",
    "6-Suma na chetnite",
    "7-Izhod"
};

int* input(int *br, int *mas);
void out(int br, int *mas);
int sum(int br, int *mas);
int max(int br, int *mas);
int min(int br, int *mas);
int sumEven(int br, int *mas);

int main()
{
    int cod, n = 0, *p = NULL, flag = 0;

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
                    out(n, p);
                    printf("Sum = %d\n", sum(n, p));
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 4:
                if(flag)
                {
                    out(n, p);
                    printf("Max = %d\n", max(n, p));
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 5:
                if(flag)
                {
                    out(n, p);
                    printf("Min = %d\n", min(n, p));
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 6:
                if(flag)
                {
                    out(n, p);
                    printf("Suma na chetnite = %d\n", sumEven(n, p));
                }
                else
                    printf("Izberete parvo 1!\n");
                _getch();
                break;

            case 7:
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
    int k;
    printf("Vavedete razmer: ");
    scanf("%d", &k);

    mas = (int*)malloc(k * sizeof(int));

    if(mas == NULL)
    {
        printf("Niama pamet!");
        exit(1);
    }

    for(int i = 0; i < k; i++)
    {
        printf("[%d] = ", i);
        scanf("%d", (mas + i));
    }

    *br = k;
    return mas;
}

void out(int br, int *mas)
{
    for(int i = 0; i < br; i++)
        printf("[%d] = %d\n", i, *(mas + i));
}

int sum(int br, int *mas)
{
    int s = 0;
    for(int i = 0; i < br; i++)
        s += *(mas + i);

    return s;
}

int max(int br, int *mas)
{
    int m = mas[0];

    for(int i = 1; i < br; i++)
        if(*(mas + i) > m)
            m = *(mas + i);

    return m;
}

int min(int br, int *mas)
{
    int m = mas[0];

    for(int i = 1; i < br; i++)
        if(*(mas + i) < m)
            m = *(mas + i);

    return m;
}

int sumEven(int br, int *mas)
{
    int s = 0;

    for(int i = 0; i < br; i++)
        if(*(mas + i) % 2 == 0)
            s += *(mas + i);

    return s;
}