#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 20
#define SIZE 5

typedef struct
{
    char ime[30];
    long fnum;
    int grup;
    float ocenka;
} STD;

char *M[SIZE] = {
    "1-Vavejdane",
    "2-Izvejdane",
    "3-Sreden uspeh po grupa",
    "4-Otlichnici",
    "5-Izhod"
};

void my_line_flush();
STD inputStd(void);
void outputStd(STD a);
void uspeh(STD s[N], int br);
void excellentStudents(STD s[N], int br);

int main()
{
    int cod, num = 0, flag = 0;
    STD s[N];

    do
    {
        for(int i = 0; i < SIZE; i++)
            puts(M[i]);

        printf("Izberete kod: ");
        scanf("%d", &cod);

        switch(cod)
        {
            case 1:
                do
                {
                    printf("Vavedete broi studenti (max %d): ", N);
                    scanf("%d", &num);
                }
                while(num <= 0 || num > N);

                for(int i = 0; i < num; i++)
                    s[i] = inputStd();

                flag = 1;
                break;

            case 2:
                if(flag)
                {
                    printf("\nSpisak na studenti:\n");
                    for(int i = 0; i < num; i++)
                        outputStd(s[i]);
                }
                else
                    printf("Purvo izberete 1!\n");
                _getch();
                break;

            case 3:
                if(flag)
                    uspeh(s, num);
                else
                    printf("Purvo izberete 1!\n");
                _getch();
                break;

            case 4:
                if(flag)
                    excellentStudents(s, num);
                else
                    printf("Purvo izberete 1!\n");
                _getch();
                break;

            case 5:
                exit(1);

            default:
                printf("Nekorekten kod!\n");
                _getch();
        }

        system("cls");

    } while(1);

    return 0;
}

void my_line_flush()
{
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

STD inputStd(void)
{
    STD a;

    printf("Ime: ");
    my_line_flush();
    gets(a.ime);

    printf("Nomer: ");
    scanf("%ld", &a.fnum);

    printf("Grupa: ");
    scanf("%d", &a.grup);

    printf("Ocenka: ");
    scanf("%f", &a.ocenka);

    return a;
}

void outputStd(STD a)
{
    printf("\nIme: %s", a.ime);
    printf("\nNomer: %ld", a.fnum);
    printf("\nGrupa: %d", a.grup);
    printf("\nOcenka: %.2f\n", a.ocenka);
}

void uspeh(STD s[N], int br)
{
    float sum = 0.0;
    int gr = 0, key;

    printf("Vavedete nomer na grupa: ");
    scanf("%d", &key);

    for(int i = 0; i < br; i++)
    {
        if(s[i].grup == key)
        {
            sum += s[i].ocenka;
            gr++;
        }
    }

    if(gr > 0)
        printf("Sreden uspeh na grupa %d: %.2f\n", key, sum / gr);
    else
        printf("Niama studenti ot grupa %d!\n", key);
}

void excellentStudents(STD s[N], int br)
{
    int found = 0;

    printf("\nStudenti s otlichen uspeh:\n");

    for(int i = 0; i < br; i++)
    {
        if(s[i].ocenka >= 5.50)
        {
            outputStd(s[i]);
            found = 1;
        }
    }

    if(!found)
        printf("Niama studenti s otlichen uspeh.\n");
}