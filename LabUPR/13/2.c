#include <stdio.h>
#include <stdlib.h>

FILE *writeFile(char *fname);
void readFile(FILE *fp, char *fname);
int countLines(FILE *fp, char *fname);

int main()
{
    FILE *text;
    char fname[20];

    printf("Vavedete ime na fail:\n");
    scanf("%s", fname);

    getchar();

    text = writeFile(fname);

    if(text == NULL)
    {
        printf("Failat ne moje da bade otvoren!");
        return 0;
    }

    readFile(text, fname);

    printf("\nBroi redove: %d\n", countLines(text, fname));

    return 0;
}

FILE *writeFile(char *fname)
{
    FILE *fp;
    char s[81];

    fp = fopen(fname, "w");
    if(!fp) return NULL;

    printf("Vavejdaite tekst. Krai: Ctrl+Z\n");

    while(fgets(s, 80, stdin) != NULL)
        fputs(s, fp);

    fclose(fp);
    return fp;
}

void readFile(FILE *fp, char *fname)
{
    char s[81];

    fp = fopen(fname, "r");
    if(!fp) exit(1);

    while(fgets(s, 80, fp) != NULL)
        fputs(s, stdout);

    fclose(fp);
}

int countLines(FILE *fp, char *fname)
{
    char s[81];
    int count = 0;

    fp = fopen(fname, "r");
    if(!fp) return -1;

    while(fgets(s, 80, fp) != NULL)
        count++;

    fclose(fp);
    return count;
}