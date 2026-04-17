#include <stdio.h>

#define N 10

float data[N];

void input(int num);
void output(int num);
float sum(int num);
int countAboveAverage(int num);

int main()
{
    int br;
    float s;

    do
    {
        printf("Vavedete broi danni (max 10): ");
        scanf("%d", &br);
    }
    while(br > 10 || br < 0);

    input(br);

    printf("\nVavedeni danni:\n");
    output(br);

    s = sum(br);

    printf("\nSuma: %.3f\n", s);
    printf("Sredna stoinost: %.3f\n", s / br);

    printf("Broi elementi >= srednata stoinost: %d\n",
           countAboveAverage(br));

    return 0;
}

void input(int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("data[%d] = ", i + 1);
        scanf("%f", &data[i]);
    }
}

void output(int num)
{
    for(int i = 0; i < num; i++)
    {
        printf("data[%d] = %.3f\n", i + 1, data[i]);
    }
}

float sum(int num)
{
    float s = 0.0;

    for(int i = 0; i < num; i++)
        s += data[i];

    return s;
}

int countAboveAverage(int num)
{
    float s = 0.0;
    float avg;
    int count = 0;

    for(int i = 0; i < num; i++)
        s += data[i];

    avg = s / num;

    for(int i = 0; i < num; i++)
        if(data[i] >= avg)
            count++;

    return count;
}