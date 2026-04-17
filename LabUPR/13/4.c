#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{
    char name[30];
    long nmbr;
    int group;
    float mark;
} student;

student inputStudent(void);
void outputStudent(student);
FILE *writeFile(char *filename);
void readFile(FILE *fp, char *filename);
float avMark(FILE *fp, char *filename, int searchGroup);
void searchStudent(FILE *fp, char *filename, long facNum);

int main()
{
    FILE *fp;
    char filename[30];
    int searchGroup;
    float averageMark;
    long facNum;

    printf("Vavedete ime za faila: ");
    gets(filename);

    fp = writeFile(filename);

    printf("\nDanni za vsichki studenti:\n");
    readFile(fp, filename);

    printf("\nVavedete grupa: ");
    scanf("%d", &searchGroup);

    averageMark = avMark(fp, filename, searchGroup);

    if(averageMark == 0)
        printf("Nqma studenti ot tazi grupa!\n");
    else
        printf("Sreden uspeh: %.2f\n", averageMark);

    printf("\nVavedete fakulteten nomer: ");
    scanf("%ld", &facNum);

    searchStudent(fp, filename, facNum);

    return 0;
}

student inputStudent(void)
{
    student a;

    printf("\nName: ");
    fflush(stdin);
    gets(a.name);

    printf("Number: ");
    scanf("%ld", &a.nmbr);

    printf("Group: ");
    scanf("%d", &a.group);

    printf("Mark: ");
    scanf("%f", &a.mark);

    return a;
}

void outputStudent(student st)
{
    printf("\nName: %s\n", st.name);
    printf("Number: %ld\n", st.nmbr);
    printf("Group: %d\n", st.group);
    printf("Mark: %.2f\n", st.mark);
}

FILE *writeFile(char *filename)
{
    FILE *fp;
    student s;

    fp = fopen(filename, "ab");
    if(fp == NULL) exit(1);

    do
    {
        s = inputStudent();
        fwrite(&s, sizeof(s), 1, fp);

        printf("Nov student? Y/N: ");
    }
    while(toupper(getch()) == 'Y');

    fclose(fp);
    return fp;
}

void readFile(FILE *fp, char *filename)
{
    student s;

    fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);

    while(fread(&s, sizeof(s), 1, fp) == 1)
        outputStudent(s);

    fclose(fp);
}

float avMark(FILE *fp, char *filename, int searchGroup)
{
    student s;
    float sum = 0;
    int count = 0;

    fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.group == searchGroup)
        {
            sum += s.mark;
            count++;
        }
    }

    fclose(fp);

    if(count == 0) return 0;
    return sum / count;
}

void searchStudent(FILE *fp, char *filename, long facNum)
{
    student s;
    int found = 0;

    fp = fopen(filename, "rb");
    if(fp == NULL) exit(1);

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.nmbr == facNum)
        {
            printf("\nNameren student:\n");
            outputStudent(s);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Studentat ne e nameren.\n");

    fclose(fp);
}