#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[30];
    int n;
} Person;

typedef struct node
{
    Person prs;
    struct node *next;
} node;

node *makeSrtLst(node *head, FILE *f);
void prt(node *crnt);
void find_sum(node *crnt);
void searchNode(node *crnt);
node *free_m(node *crnt);