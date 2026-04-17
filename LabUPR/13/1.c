#include <stdio.h>
#include <ctype.h>

FILE *writeFile(char *fname);
int readFile(FILE *fp, char *fname);

int main()
{
    FILE *text;
    int symbols = 0;

    text = writeFile("Test.txt");

    if(text == NULL)
    {
        printf("Failat ne moje da bade otvoren!");
        return 0;
    }

    symbols = readFile(text, "Test.txt");

    if(symbols >= 0)
        printf("\nBroi simvoli: %d\n", symbols);
    else
        printf("Failat ne moje da bade otvoren!\n");

    return 0;
}

FILE *writeFile(char *fname)
{
    FILE *fp;
    int ch;

    fp = fopen(fname, "w");
    if(!fp) return NULL;

    printf("Vavejdaite simvoli. Za krai: #\n");

    while((ch = getchar()) != '#')
        fputc(ch, fp);

    fclose(fp);
    return fp;
}

int readFile(FILE *fp, char *fname)
{
    int ch, n = 0;

    fp = fopen(fname, "r");
    if(!fp) return -1;

    while((ch = fgetc(fp)) != EOF)
    {
        if(ispunct(ch))
            ch = 'x';

        putchar(ch);
        n++;
    }

    fclose(fp);
    return n;
}