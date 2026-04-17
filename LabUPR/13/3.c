#include <stdio.h>
#include <stdlib.h>

FILE *writeFile(char *fname);
void readFile(FILE *fp, char *fname);
int countNumbers(FILE *fp, char *fname);

int main()
{
    FILE *text;
    char fname[20];

    printf("Vavedete ime na fail:\n");
    scanf("%s", fname);

    text = writeFile(fname);

    if(text == NULL)
    {
        printf("Failat ne moje da bade otvoren!");
        return 0;
    }

    readFile(text, fname);

    printf("\nBroi chisla: %d\n", countNumbers(text, fname));

    return 0;
}

FILE *writeFile(char *fname)
{
    FILE *fp;
    int a;

    fp = fopen(fname, "w");
    if(!fp) return NULL;

    printf("Vavejdaite chisla. Krai: Ctrl+Z\n");

    while(scanf("%d", &a) == 1)
        fprintf(fp, "%d ", a);

    fclose(fp);
    return fp;
}

void readFile(FILE *fp, char *fname)
{
    int a;

    fp = fopen(fname, "r");
    if(!fp) exit(1);

    while(fscanf(fp, "%d", &a) == 1)
        printf("%d ", a);

    fclose(fp);
}

int countNumbers(FILE *fp, char *fname)
{
    int a, count = 0;

    fp = fopen(fname, "r");
    if(!fp) return -1;

    while(fscanf(fp, "%d", &a) == 1)
        count++;

    fclose(fp);
    return count;
}