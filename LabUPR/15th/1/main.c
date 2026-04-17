#include "head.c"

int main()
{
    FILE *f;
    Person p;
    node *head = NULL;

    if((f = fopen("person.dat", "wb")) != NULL)
    {
        do
        {
            printf("Next name: ");
            scanf("%29s", p.name);

            if(!strcmp(p.name, "*"))
                break;

            printf("Next number: ");
            scanf("%d", &p.n);

            fwrite(&p, sizeof(Person), 1, f);

            printf("Writing structure in file\n");

        } while(1);

        fclose(f);
        printf("The file was created\n");
    }
    else
    {
        printf("File opening error!\n");
        exit(1);
    }

    if((f = fopen("person.dat", "rb")) == NULL)
    {
        printf("File opening error!\n");
        exit(1);
    }

    head = makeSrtLst(head, f);

    prt(head);
    find_sum(head);

    searchNode(head);

    head = free_m(head);

    return 0;
}