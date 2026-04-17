#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char ime[30];
    long fnum;
    int grup;
    float ocenka;
} STD;

void my_line_flush();
STD* inputStd(int b, STD *s);
void outputStd(int b, STD *s);
void uspeh(int b, STD *s);
void grupaList(int b, STD *s);

int main()
{
    int num = 0;
    STD *s;

    printf("Vavedete broi studenti: ");
    scanf("%d", &num);

    s = (STD*)malloc(num * sizeof(STD));

    if(s == NULL)
    {
        printf("ERROR!\n");
        exit(1);
    }

    s = inputStd(num, s);

    printf("\nSpisak na studenti:\n");
    outputStd(num, s);

    uspeh(num, s);
    grupaList(num, s);

    free(s);

    return 0;
}

void my_line_flush()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

STD* inputStd(int b, STD *s)
{
    for(int i = 0; i < b; i++)
    {
        printf("Ime: ");
        my_line_flush();
        gets((s + i)->ime);

        printf("Nomer: ");
        scanf("%ld", &(s + i)->fnum);

        printf("Grupa: ");
        scanf("%d", &(s + i)->grup);

        printf("Ocenka: ");
        scanf("%f", &(s + i)->ocenka);
    }

    return s;
}

void outputStd(int b, STD *s)
{
    for(int i = 0; i < b; i++)
    {
        printf("\nIme: %s", (s + i)->ime);
        printf("\nNomer: %ld", (s + i)->fnum);
        printf("\nGrupa: %d", (s + i)->grup);
        printf("\nOcenka: %.2f\n", (s + i)->ocenka);
    }
}

void uspeh(int b, STD *s)
{
    float sum = 0.0;
    int gr = 0, key;

    printf("\nVavedete nomer na grupa za sreden uspeh: ");
    scanf("%d", &key);

    for(int i = 0; i < b; i++)
    {
        if((s + i)->grup == key)
        {
            sum += (s + i)->ocenka;
            gr++;
        }
    }

    if(gr > 0)
        printf("Sreden uspeh na studenti ot grupa %d: %.2f\n", key, sum / gr);
    else
        printf("Niama studenti ot grupa %d!\n", key);
}

void grupaList(int b, STD *s)
{
    int key, found = 0;

    printf("\nVavedete grupa za spisak: ");
    scanf("%d", &key);

    printf("\nStudenti ot grupa %d:\n", key);

    for(int i = 0; i < b; i++)
    {
        if((s + i)->grup == key)
        {
            printf("\nIme: %s", (s + i)->ime);
            printf("\nNomer: %ld", (s + i)->fnum);
            printf("\nOcenka: %.2f\n", (s + i)->ocenka);
            found = 1;
        }
    }

    if(!found)
        printf("Niama studenti ot tazi grupa.\n");
}