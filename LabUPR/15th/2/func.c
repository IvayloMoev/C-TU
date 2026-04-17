#include "head.c"

node *makeSrtLst(node *head, FILE *f)
{
    node *p;

    while(1)
    {
        p = (node*)malloc(sizeof(node));

        if(p == NULL)
        {
            printf("Memory Error!");
            exit(1);
        }

        if(!fread(&(p->prs), sizeof(Person), 1, f))
        {
            free(p);
            break;
        }

        p->next = head;
        head = p;
    }

    fclose(f);
    return head;
}

void prt(node *crnt)
{
    if(crnt)
    {
        printf("\nThe list is:\n");

        while(crnt)
        {
            printf("%s has %d\n", crnt->prs.name, crnt->prs.n);
            crnt = crnt->next;
        }
    }
    else
        printf("Prazen spisak!\n");
}

void find_sum(node *crnt)
{
    int sum = 0;

    while(crnt)
    {
        sum += crnt->prs.n;
        crnt = crnt->next;
    }

    printf("\nSum = %d\n", sum);
}

void changeName(node *crnt)
{
    int key;
    char newName[30];
    int found = 0;

    printf("\nVavedete nomer za promyana: ");
    scanf("%d", &key);

    while(crnt)
    {
        if(crnt->prs.n == key)
        {
            printf("Vavedete novo ime: ");
            scanf("%29s", newName);

            strcpy(crnt->prs.name, newName);

            printf("Imeto beshe promeneno uspeshno.\n");
            found = 1;
            break;
        }

        crnt = crnt->next;
    }

    if(!found)
        printf("Nяма takav vazel.\n");
}

node *free_m(node *crnt)
{
    node *next;

    printf("\nMemory free!\n");

    while(crnt)
    {
        next = crnt->next;
        free(crnt);
        crnt = next;
    }

    return NULL;
}