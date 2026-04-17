#include "head.h"

extern float data[N];

void input(int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("data[%d]=", i + 1);
        scanf("%f", &data[i]);
    }
}

void output(int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        printf("data[%d]=%.3f ", i + 1, data[i]);
    }
}

float sum(int num)
{
    int i;
    float s = 0.0;

    for(i = 0; i < num; i++)
        s += data[i];

    return s;
}

/* ✅ НОВА ФУНКЦИЯ */
int countAboveAverage(int num)
{
    float s = 0.0;
    float avg;
    int count = 0;
    int i;

    for(i = 0; i < num; i++)
        s += data[i];

    avg = s / num;

    for(i = 0; i < num; i++)
    {
        if(data[i] >= avg)
            count++;
    }

    return count;
}