#include "head.h"
#include "masiv.h"

int main()
{
    int br = 0;
    float s;

    do
    {
        printf("Vavedete broi danni (max do 10): ");
        scanf("%d", &br);
    }
    while((br > 10) || (br < 0));

    input(br);

    printf("Vie vavedohte slednite danni:\n");
    output(br);

    s = sum(br);

    printf("\nSuma: %.3f\n", s);

    if(br > 0)
    {
        printf("Sredna stoinost: %.3f\n", s / br);

        /* ✅ НОВ РЕЗУЛТАТ */
        printf("Broi elementi >= srednata stoinost: %d\n",
               countAboveAverage(br));
    }
    else
    {
        printf("Broiat na dannite e raven na 0!\n");
    }

    _getch();

    return 0;
}